pub fn anagrams_for<'a>(candidate: &str, inputs: &[&'a str]) -> Vec<&'a str> {
    let len = candidate.len();
    let first_permutation = candidate.to_lowercase()
        .chars().collect::<Vec<char>>();

    inputs.iter().filter_map(|&input| {
        if input.len() != len
        {
            None
        } else if candidate.to_lowercase() != input.to_lowercase() &&
            Permutations::new(first_permutation.clone()).any(
                |p| p.to_string() == input.to_lowercase().to_string())
        {
            Some(input)
        } else {
            None   
        }
    }).collect::<Vec<&str>>()
}

#[derive(Clone, Debug)]
struct Permutation {
    length: usize,
    data: Vec<char>,
}

impl Permutation {
    pub fn new(data: Vec<char>) -> Self {
        let len = data.len();
        Self {
            data: data,
            length: len,
        }
    }

    pub fn swap(&mut self, m: usize, n: usize) {
        if n >= self.length || m >= self.length {
            return;
        }
        
        let tmp = self.data[m];
        self.data[m] = self.data[n];
        self.data[n] = tmp;
    }

    fn to_string(&self) -> String {
        let mut rv = String::with_capacity(self.length);
        self.data.iter().for_each(|&ch| rv.push(ch));
        rv
    }
}

struct Permutations {
    c: Vec<usize>,
    i: usize,
    current: Option<Permutation>,
}

impl Permutations {
    pub fn new(first_permutation: Vec<char>) -> Self {
        Self {
            c: vec![0; first_permutation.len()],
            i: 0,
            current: Some(Permutation::new(first_permutation)),
        }
    }

    fn advance(&mut self) {
        if self.i < self.c.len() {
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