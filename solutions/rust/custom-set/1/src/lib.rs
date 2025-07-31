#[derive(Debug)]
pub struct CustomSet<T>(Vec<T>);


impl<T> CustomSet<T>
    where T: Clone + PartialEq
{
    pub fn new(input: Vec<T>) -> Self {        
        CustomSet(input.clone())
    }

    pub fn add(&mut self, val: T) {
        if !self.contains(&val) {
            self.0.push(val);
        }
    }

    pub fn is_empty(&self) -> bool {
        self.0.len() == 0
    }

    
    pub fn contains(&self, val: &T) -> bool {
        self.0.contains(val)
    }

    pub fn is_subset(&self, other: &CustomSet<T>) -> bool {
        self.0.iter().all(|val| other.contains(val))
    }

    pub fn is_disjoint(&self, other: &CustomSet<T>) -> bool {
        self.0.iter().all(|val| !other.contains(val))
    }

    pub fn intersection(&self, other: &CustomSet<T>) -> CustomSet<T> {
        let mut rv: Vec<T> = vec![];        
        for val in self.0.iter() {
            if other.contains(val) {
                rv.push(val.clone());
            }
        }
        CustomSet(rv)
    }

    pub fn difference(&self, other: &CustomSet<T>) -> CustomSet<T> {
        let mut rv: Vec<T> = vec![];
        for val in self.0.iter() {
            if !other.contains(val) {
                rv.push(val.clone());
            }
        }
        CustomSet(rv)
    }

    pub fn union(&self, other: &CustomSet<T>) -> CustomSet<T> {
        let mut rv = CustomSet(self.0.clone());
        for val in other.0.iter() {
            rv.add(val.clone());
        }
        rv
    }
}

impl<T> PartialEq for CustomSet<T>
    where T: Clone + PartialEq
{
    fn eq(&self, other: &CustomSet<T>) -> bool {
        self.0.len() == other.0.len() && self.is_subset(other)
    }
}