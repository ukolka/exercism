use std::collections::HashSet;

pub fn check(input: &str) -> bool {
    if input.len() == 0 {
        return true;
    }

    let mut set = HashSet::new();
    
    for ch in input.to_lowercase().chars() {
        if is_legal(ch) {
            if set.contains(&ch) {
                return false;
            }
            set.insert(ch);
        }
    }
    
    true
}

fn is_legal(ch: char) -> bool {
    let mut legal_chars = HashSet::new();
    legal_chars.insert('-');
    legal_chars.insert(' ');

    !legal_chars.contains(&ch)
}