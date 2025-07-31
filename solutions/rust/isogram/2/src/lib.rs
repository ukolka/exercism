use std::collections::{HashMap, HashSet};

pub fn check(input: &str) -> bool {
    if input.len() == 0 {
        return true;
    }

    let hist = char_hist(input.to_lowercase());
    
    for (ch, freq) in hist {
        if freq > 1 && !is_legal(ch) {
            return false;
        }
    }
    
    true
}

fn char_hist(input: &str) -> HashMap<char, usize> {
    let mut hist = HashMap::new();

    for ch in input.chars() {
        let counter = hist.entry(ch).or_insert(0);
        *counter += 1;
    }

    hist
}

fn is_legal(ch: char) -> bool {
    let mut legal_chars = HashSet::new();
    legal_chars.insert('-');
    legal_chars.insert(' ');

    legal_chars.contains(&ch)
}