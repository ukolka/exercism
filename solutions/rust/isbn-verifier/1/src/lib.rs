use std::collections::HashSet;
use std::char;

/// Determines whether the supplied string is a valid ISBN number
pub fn is_valid_isbn(isbn: &str) -> bool {
    let mut sum = 0;
    let mut multiplier = 10;

    for candidate in isbn.chars() {
        if multiplier == 0 {
            return false;
        }
        
        if candidate != '-' {
            if !is_valid(multiplier, &candidate) {
                return false;
            }
            
            sum += to_u32(candidate).unwrap() * multiplier;
            multiplier -= 1;        
        }
    }

    sum % 11 == 0
}

fn is_valid(multiplier: u32, ch: &char) -> bool {
    let mut valid = HashSet::new();
    if multiplier == 1 {
        valid.insert('X');
    }
    for i in 0..10 {
        valid.insert(char::from_digit(i, 10).unwrap());
    }
    valid.contains(ch)
}

fn to_u32(ch: char) -> Option<u32> {
    match ch {
        'X' => Some(10),
        _ => ch.to_digit(10)
    }
}