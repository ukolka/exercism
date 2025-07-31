use std::collections::HashSet;

const EN: &str = "abcdefghijklmnopqrstuvwxyz";

pub fn is_pangram(input: &str) -> bool {
    if input.len() == 0 {
        return false;
    }
    
    let en: HashSet<char> = EN.chars().collect();

    let test: HashSet<char> = input.to_lowercase().chars()
        .collect();

    en.is_subset(&test)
}