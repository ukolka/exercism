extern crate rand;
use std::str;
use rand::distributions::{Range, IndependentSample};
use rand::thread_rng;

pub struct Robot {
    name: [u8; 5],
}

impl Robot {
    pub fn new() -> Self {
        let mut rv = Self {
            name: [0; 5],
        };
        rv.reset_name();
        rv
    }

    pub fn name<'a>(&'a self) -> &'a str {
        str::from_utf8(&self.name).unwrap()
    }

    pub fn reset_name(&mut self) {
        let letters = Range::new(65, 91);
        let digits = Range::new(48, 58);
        let mut rng = thread_rng();
        self.name[0] = letters.ind_sample(&mut rng);
        self.name[1] = letters.ind_sample(&mut rng);
        self.name[2] = digits.ind_sample(&mut rng);
        self.name[3] = digits.ind_sample(&mut rng);
        self.name[4] = digits.ind_sample(&mut rng);
    }
}