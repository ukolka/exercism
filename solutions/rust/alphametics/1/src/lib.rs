use std::collections::HashMap;
use std::char;

const BASE: usize = 10;
const BASE_32: u32 = 10;

pub fn solve(input: &str) -> Option<HashMap<char, u8>> {

    for permutation in Permutations::new(first_permutation(input)) {
        if is_the_solution(input, &permutation) {
            return Some(permutation.to_map());
        }
    }

    None
}

fn is_the_solution(input: &str, permutation: &Permutation) -> bool {
    let mut sum = 0;
    let mut current_number: u32 = 0;
    
    for ch in input.chars() {
        match ch {
            'A' ... 'Z' => {
                match permutation.to_digit(&ch) {
                    Some(0) => {
                        if current_number == 0 {
                            return false;
                        }
                        current_number = current_number * BASE_32;
                    },
                    Some(digit) => {
                        current_number = current_number * BASE_32 +
                            digit;
                    },
                    None => (),
                }

            },
            '+' | '=' => {
                sum += current_number;
                current_number = 0;
            },
            _ => (),
        }
    }
    sum == current_number
}

fn first_permutation(input: &str) -> [char; BASE] {
    let mut rv = [' '; BASE];
    let mut i = 0;
    input.chars().for_each(|ch| match ch {
        'A' ... 'Z' => {
            if rv.iter().all(|&listed| ch != listed) {
                rv[i] = ch;
                i += 1;
            }
        },
        _ => (),
    });
    rv
}

#[derive(Clone, Debug)]
struct Permutation {
    data: [char; BASE],
}

impl Permutation {
    pub fn new(data: [char; BASE]) -> Self {
        Self {
            data: data
        }
    }

    pub fn swap(&mut self, m: usize, n: usize) {
        if n >= BASE || m >= BASE {
            return;
        }
        
        let tmp = self.data[m];
        self.data[m] = self.data[n];
        self.data[n] = tmp;
    }

    fn to_map(&self) -> HashMap<char, u8> {
        let mut hm = HashMap::new();
        let permutation = self.data.clone();
        permutation.iter()
            .enumerate()
            .for_each(|(idx, &ch)| {
                if ch != ' ' {
                    hm.insert(ch, idx as u8);
                }
            });
        hm
    }

    fn to_digit(&self, ch: &char) -> Option<u32> {
        match self.data.iter().position(|test_ch| test_ch == ch) {
            Some(index) => Some(index as u32),
            None => None,
        }
    }
}

struct Permutations {
    c: Vec<usize>,
    i: usize,
    current: Option<Permutation>,
}

impl Permutations {
    pub fn new(first_permutation: [char; BASE]) -> Self {
        Self {
            c: vec![0; BASE],
            i: 0,
            current: Some(Permutation::new(first_permutation)),
        }
    }

    fn advance(&mut self) {
        if self.i < BASE {
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