use std::collections::HashSet;

pub fn is_pangram(input: &str) -> bool {    
    let test: HashSet<char> = input.to_lowercase()
        .chars()
        .filter(|&ch| match ch {
            'a' ... 'z' => true,
            _ => false
        })
        .collect();

    test.len() == 26
}