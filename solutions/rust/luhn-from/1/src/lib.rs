mod luhn;
use std::char;

pub struct Luhn {
    string: String,
}

impl Luhn {
    pub fn is_valid(&self) -> bool {
        luhn::is_valid(self.string.as_str())
    }
}

impl<'a> From<&'a str> for Luhn {
    fn from(s: &'a str) -> Self {
        Self {
            string: s.to_string()
        }
    }
}

impl From<String> for Luhn {
    fn from(s: String) -> Self {
        Self {
            string: s
        }
    }
}

impl From<u8> for Luhn {
    fn from(input: u8) -> Self {
        Self::from(input as u64)
    }
}

impl From<u16> for Luhn {
    fn from(input: u16) -> Self {
        Self::from(input as u64)
    }
}

impl From<u32> for Luhn {
    fn from(input: u32) -> Self {
        Self::from(input as u64)
    }
}

impl From<u64> for Luhn {
    fn from(input: u64) -> Self {
        let mut n = input;
        let mut digits = Vec::new();
        while n > 0 {
            digits.push(char::from_digit((n % 10) as u32, 10));
            n /= 10;
        }
        
        Self {
            string: digits.iter()
                .filter_map(|&ch| ch)
                .rev().collect::<String>()
        }
    }
}

impl From<usize> for Luhn {
    fn from(input: usize) -> Self {
        Self::from(input as u64)
    }
}