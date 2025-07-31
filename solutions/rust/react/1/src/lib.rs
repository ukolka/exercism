#[allow(unused_variables)]
use std::collections::HashMap;
use std::boxed::Box;
use std::cell::RefCell;
use std::rc::Rc;
use std::fmt::Debug;

// Because these are passed without & to some functions,
// it will probably be necessary for these two types to be Copy.
pub type CellID = usize;
pub type CallbackID = usize;

pub struct Reactor<'a, T> {
    // Just so that the compiler doesn't complain about an unused type parameter.
    // You probably want to delete this field.
    cells: Vec<Cell<'a, T>>,
    cell_count: usize,
    callback_count: usize,
}

struct Compute<'a, T> {
    last_computed: Option<T>,
    dependencies: Vec<CellID>,
    compute_func: Box<Fn(&[T]) -> T + 'a>,
}

impl<'a, T: Copy> Compute<'a, T> {
    fn compute(&self, cells: &Vec<Cell<T>>) -> T {
        let mut vals = Vec::with_capacity(16);
        for id in self.dependencies.iter() {
            vals.push(cells[id.clone()].value.clone());
        }

        (self.compute_func)(&vals)
    }
}

struct Cell<'a, T> {
    value: T,
    compute: Option<Compute<'a, T>>,
    callbacks: HashMap<usize, Rc<RefCell<FnMut(T) + 'a>>>,
}

impl<'a, T: Copy + PartialEq + Debug> Cell<'a, T> {
    fn invoke_callbacks(&mut self, val: T) {
        match self.compute {
            Some(ref compute) => match compute.last_computed {
                Some(last_computed) => {
                    if last_computed == val {
                        return;
                    }
                },
                None => {},
            },
            None => {},
        }

        for (_id, callback) in self.callbacks.iter() {
            let mut closure = callback.borrow_mut();
            (&mut *closure)(val);
        }
    }
}

// You are guaranteed that Reactor will only be tested against types that are Copy + PartialEq.
impl <'a, T: Copy + PartialEq + Debug> Reactor<'a, T> {
    pub fn new() -> Self {
        Self {
            cells: Vec::with_capacity(16),
            cell_count: 0,
            callback_count: 0,
        }
    }

    // Creates an input cell with the specified initial value, returning its ID.
    pub fn create_input(&mut self, initial: T) -> CellID {
        self.cells.push(Cell {
            value: initial,
            compute: None,
            callbacks: HashMap::with_capacity(0),
        });
        self.cell_count += 1;
        self.cell_count - 1
    }

    // Creates a compute cell with the specified dependencies and compute function.
    // The compute function is expected to take in its arguments in the same order as specified in
    // `dependencies`.
    // You do not need to reject compute functions that expect more arguments than there are
    // dependencies (how would you check for this, anyway?).
    //
    // Return an Err (and you can change the error type) if any dependency doesn't exist.
    //
    // Notice that there is no way to *remove* a cell.
    // This means that you may assume, without checking, that if the dependencies exist at creation
    // time they will continue to exist as long as the Reactor exists.
    pub fn create_compute<F: Fn(&[T]) -> T + 'a>(&mut self, dependencies: &[CellID], compute_func: F) -> Result<CellID, ()> {
        for dep in dependencies {
            if dep >= &self.cell_count {
                return Err(());
            }
        }
        
        let mut compute = Compute {
            last_computed: None,
            dependencies: dependencies.to_vec(),
            compute_func: Box::new(compute_func),
        };
        
        let val = compute.compute(&self.cells);
        compute.last_computed = Some(val.clone());
        
        let cell = Cell {
            value: val,
            compute: Some(compute),
            callbacks: HashMap::with_capacity(4),
        };
        
        self.cells.push(cell);
        self.cell_count += 1;
        
        Ok(self.cell_count - 1)
    }

    // Retrieves the current value of the cell, or None if the cell does not exist.
    //
    // You may wonder whether it is possible to implement `get(&self, id: CellID) -> Option<&Cell>`
    // and have a `value(&self)` method on `Cell`.
    //
    // It turns out this introduces a significant amount of extra complexity to this exercise.
    // We chose not to cover this here, since this exercise is probably enough work as-is.
    pub fn value(&self, id: CellID) -> Option<T> {
        if id >= self.cell_count {
            None
        } else {
            Some(self.cells[id].value)
        }
    }

    // Sets the value of the specified input cell.
    //
    // Return an Err (and you can change the error type) if the cell does not exist, or the
    // specified cell is a compute cell, since compute cells cannot have their values directly set.
    //
    // Similarly, you may wonder about `get_mut(&mut self, id: CellID) -> Option<&mut Cell>`, with
    // a `set_value(&mut self, new_value: T)` method on `Cell`.
    //
    // As before, that turned out to add too much extra complexity.
    pub fn set_value(&mut self, id: CellID, new_value: T) -> Result<(), ()> {
        if id >= self.cell_count {
            Err(())
        } else {
            if self.cells[id].compute.is_some() {
                return Err(());
            }

            if self.cells[id].value == new_value {
                return Ok(());
            }

            let changes = self.set_value_cascade(id, new_value);

            let mut seen = Vec::with_capacity(4);
            for &(id, val) in changes.iter().rev() {
                if seen.contains(&id) {
                    continue;
                }
                self.cells[id].invoke_callbacks(val);

                seen.push(id);
            }

            Ok(())
        }
    }

    fn set_value_cascade(&mut self, id: CellID, new_value: T) -> Vec<(CellID, T)> {
        self.cells[id].value = new_value;
        

        let mut changes = Vec::with_capacity(4);
        for (compute_id, cell) in self.cells.iter().enumerate() {
            match cell.compute {
                Some(ref compute) => {
                    if compute.dependencies.contains(&id) {
                        let new_value = compute.compute(&self.cells);
                        if new_value != cell.value {
                            changes.push((
                                compute_id,
                                new_value,
                            ));
                        }
                    }
                },
                None => {},
            }
        }

        let mut updates = Vec::with_capacity(4);
        
        for &(id, val) in changes.iter() {
            updates.push((id, val));
            updates.append(&mut self.set_value_cascade(id, val));
        }

        updates
    }


    // Adds a callback to the specified compute cell.
    //
    // Return an Err (and you can change the error type) if the cell does not exist.
    //
    // Callbacks on input cells will not be tested.
    //
    // The semantics of callbacks (as will be tested):
    // For a single set_value call, each compute cell's callbacks should each be called:
    // * Zero times if the compute cell's value did not change as a result of the set_value call.
    // * Exactly once if the compute cell's value changed as a result of the set_value call.
    //   The value passed to the callback should be the final value of the compute cell after the
    //   set_value call.
    pub fn add_callback<F: FnMut(T) -> () + 'a>(&mut self, id: CellID, callback: F) -> Result<CallbackID, ()> {
        if id >= self.cell_count {
            Err(())
        } else {
            match self.cells[id].compute {
                Some(_) => {
                    self.callback_count += 1;
                    
                    self.cells[id].callbacks.insert(
                        self.callback_count - 1,
                        Rc::new(RefCell::new(callback))
                    );
                    
                    Ok(self.callback_count - 1)
                },
                None => Err(()),
            }
        }
    }

    // Removes the specified callback, using an ID returned from add_callback.
    //
    // Return an Err (and you can change the error type) if either the cell or callback
    // does not exist.
    //
    // A removed callback should no longer be called.
    pub fn remove_callback(&mut self, cell: CellID, callback: CallbackID) -> Result<(), ()> {
        if cell >= self.cell_count {
            Err(())
        } else {
            match self.cells[cell].compute {
                Some(_) => {
                    if self.cells[cell].callbacks.contains_key(&callback) {
                        self.cells[cell].callbacks.remove(&callback);
                        Ok(())
                    } else {
                        Err(())
                    }
                },
                None => Err(()),
            }
        }
    }
}