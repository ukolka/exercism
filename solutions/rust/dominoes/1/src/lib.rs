pub fn chain(dominoes: &Vec<(usize, usize)>) -> Option<Vec<(usize, usize)>> {
    if dominoes.len() == 0 {
        return Some(vec![]);
    }
    
    for perm in Permutations::new(dominoes.clone()) {
        let chain = make_chain(&perm.data, vec![]);

        match chain {
            Some(c) => {
                if c.len() == dominoes.len() {
                    let last = c[c.len() - 1];
                    if c[0].0 == last.1 {
                        return Some(c);
                    }
                }
            },
            None => {
                continue;
            }
        }
    }
    
    None
}

fn make_chain(dominoes: &Vec<(usize, usize)>, mut acc: Vec<(usize, usize)>) -> Option<Vec<(usize, usize)>> {
    if dominoes.len() == 0 {
        return Some(acc);
    }
    
    let mut head = dominoes.clone();
    let tail = head.split_off(1);
    
    let to_append = can_append(&acc, &head[0]);
    let to_append_rev = can_append(&acc, &rev(&head[0]));
    
    match to_append {
        Some(d) => {
            acc.push(d);
            return make_chain(&tail, acc);
        },
        None => {
            match to_append_rev {
                Some(d) => {
                    acc.push(d);
                    return make_chain(&tail, acc);
                },
                None => {
                    return None;
                }
            }
        },
    }
}

fn rev(d: &(usize, usize)) -> (usize, usize) {
    (d.1, d.0)
}

fn can_append(dominoes: &Vec<(usize, usize)>, c: &(usize, usize)) -> Option<(usize, usize)> {
    if dominoes.len() == 0 {
        return Some(*c);
    }

    let d = dominoes.iter().last().unwrap();
     
    if d.1 == c.0 {
        return Some(*c);
    }
    
    if d.1 == rev(c).0 {
        return Some(rev(c));
    }

    None
}

#[derive(Clone, Debug)]
struct Permutation {
    length: usize,
    data: Vec<(usize, usize)>,
}

impl Permutation {
    pub fn new(data: Vec<(usize, usize)>) -> Self {
        let len = data.len();
        Self {
            data: data,
            length: len,
        }
    }

    fn swap(&mut self, m: usize, n: usize) {
        if n >= self.length || m >= self.length {
            return;
        }
        
        let tmp = self.data[m];
        self.data[m] = self.data[n];
        self.data[n] = tmp;
    }
}

struct Permutations {
    c: Vec<usize>,
    i: usize,
    current: Option<Permutation>,
    length: usize,
}

impl Permutations {
    pub fn new(first_permutation: Vec<(usize, usize)>) -> Self {
        let len = first_permutation.len();
        Self {
            c: vec![0; len],
            i: 0,
            current: Some(Permutation::new(first_permutation)),
            length: len,
        }
    }

    fn advance(&mut self) {
        if self.i < self.length {
            match self.current.as_mut() {
                Some(current) => {
                    if self.c[self.i] < self.i {
                        if self.i % 2 == 0 {
                            current.swap(0, self.i);
                        } else {
                            current.swap(self.c[self.i], self.i);
                        }
                        self.c[self.i] += 1;
                        self.i = 0;
                    } else {
                        self.c[self.i] = 0;
                        self.i += 1;
                    }
                },
                None => (),
            }
        } else {
            self.current = None;
        }
    }
}

impl Iterator for Permutations {
     type Item = Permutation;
    
     fn next(&mut self) -> Option<Permutation> {
        if self.current.is_some() {
            let permutation = self.current.clone();
            self.advance();            
            return permutation;
        }
         
        None
    }
}