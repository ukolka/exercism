extern crate num_bigint;
use std::cmp::Ordering;
use std::ops::{Add, Sub, Mul};
use num_bigint::{Sign, BigInt, BigUint};

/// Type implementing arbitrary-precision decimal arithmetic
#[derive(Debug, PartialEq, Eq, Clone)]
pub struct Decimal {
    // implement your type here
    data: BigInt,
    exponent: u32,
}

impl Decimal {
    pub fn new(data: BigInt, exponent: u32) -> Self {
        let mut rv = Self {
            data: data,
            exponent: exponent,
        };
        rv.normalize();
        rv
    }
    
    pub fn try_from(input: &str) -> Option<Decimal> {
        
        let mut data = BigInt::default();
        let mut exponent = 0;

        if input.len() == 0 {
            return Some(Self::new(data, exponent));
        }

        let abs = input.replace("-", "");
        let mut parts = abs.split('.');
        let whole = parts.next().unwrap_or("");
        let fraction = parts.next().unwrap_or("");

        let sign = match input.chars().nth(0) {
            Some('-') => Sign::Minus,
            _ => Sign::Plus,
        };

        let data_opt = BigUint::parse_bytes(
            (whole.to_owned() + fraction).as_bytes(), 10);

        if data_opt.is_none() {
            return None;
        }
        
        data = BigInt::from_biguint(sign, data_opt.unwrap());
        exponent = fraction.len() as u32;

        Some(Self::new(data, exponent))
    }

    fn align(&self, exponent: u32) -> BigInt {
        let ten = BigInt::parse_bytes(b"10", 10).unwrap();
        let mut rv = self.data.clone();

        match self.exponent.cmp(&exponent) {
            Ordering::Equal => rv,
            Ordering::Less => {
                for _ in 0..(exponent - self.exponent) {
                    rv = rv * ten.clone();
                }
                rv
            },
            Ordering::Greater => {
                for _ in 0..(self.exponent - exponent) {
                    rv = rv / ten.clone();
                }
                rv
            },
        }
    }

    fn normalize(&mut self) {
        let mut data = self.data.clone();
        let mut exponent = self.exponent;

        let ten = BigInt::parse_bytes(b"10", 10).unwrap();
        let zero = BigInt::parse_bytes(b"0", 10).unwrap();
        
        while data.clone() % ten.clone() == zero && exponent > 0 {
            data = data.clone() / ten.clone();
            exponent -= 1;
        }

        self.data = data.clone();
        self.exponent = exponent;
    }
}

impl PartialOrd for Decimal {
    fn partial_cmp(&self, other: &Decimal) -> Option<Ordering> {
        Some(
            match self.exponent.cmp(&other.exponent) {
                Ordering::Equal => self.data.cmp(&other.data),
                Ordering::Less => self.align(other.exponent).cmp(
                    &other.align(other.exponent)),
                Ordering::Greater => self.align(self.exponent).cmp(
                    &other.align(self.exponent)),
            }
        )
    }
}

impl Add for Decimal {
    type Output = Decimal;
    
    fn add(self, other: Decimal) -> Decimal {
        match self.exponent.cmp(&other.exponent) {
            Ordering::Greater => Self::new(
                self.align(self.exponent) +
                    other.align(self.exponent),
                self.exponent),
            Ordering::Equal => Self::new(
                    self.data + other.data,
                    self.exponent),
            Ordering::Less => Self::new(
                self.align(other.exponent) +
                    other.align(other.exponent),
                other.exponent),
        }
    }
}

impl Sub for Decimal {
    type Output = Decimal;
    
    fn sub(self, other: Decimal) -> Decimal {
        self.add(Self {
            data: -other.data,
            exponent: other.exponent,
        })
    }
}

impl Mul for Decimal {
    type Output = Decimal;
    
    fn mul(self, other: Decimal) -> Decimal {
        Self::new(
            self.data * other.data,
            self.exponent + other.exponent
        )
    }
}