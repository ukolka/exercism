extern crate itertools;
use itertools::Itertools;

const DICTIONARY: &str =  "abcdefghijklmnopqrstuvwxyz";
const GROUP_SIZE: usize = 5;

pub fn encode(input: &str) -> String {
    input
        .to_lowercase()
        .chars()
        .filter_map(translate)
        .chunks(GROUP_SIZE)
        .into_iter()
        .map(|s| s.collect::<String>())
        .join(" ")
}

pub fn decode(input: &str) -> String {
    input
        .to_lowercase()
        .chars()
        .filter_map(translate)
        .collect()
}


fn translate(input: char) -> Option<char> {
    match input {
        '0' ... '9' =>  Some(input),
        'a' ... 'z' => translate_alphabetic(input),
        _ => None,
    }
}

fn translate_alphabetic(input: char) -> Option<char> {
    match DICTIONARY.find(input) {
        Some(in_idx) => {
            let out_idx = DICTIONARY.len() - 1 - in_idx;
            DICTIONARY.chars().nth(out_idx)
        },
        None => None,
    }
}