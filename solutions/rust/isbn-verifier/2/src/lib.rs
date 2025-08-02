use std::char;

/// Determines whether the supplied string is a valid ISBN number
pub fn is_valid_isbn(isbn: &str) -> bool {
    let mut sum = 0;
    let mut multiplier = 10;

    for candidate in isbn.chars() {
        if multiplier == 0 {
            return false;
        }
        
        let num = to_u32(candidate);
        
        if num == Some(10) && multiplier > 1 {
            return false;
        }
        
        sum += num.unwrap_or(0) * multiplier;

        if num.is_some() {
            multiplier -= 1;
        }
    }

    sum % 11 == 0
}

fn to_u32(ch: char) -> Option<u32> {
    match ch {
        '0' ... '9' => ch.to_digit(10),
        'X' => Some(10),
        _ => None
    }
}