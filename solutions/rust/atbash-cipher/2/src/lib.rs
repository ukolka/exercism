extern crate itertools;
use itertools::Itertools;

const PLAIN: &str =  "abcdefghijklmnopqrstuvwxyz";
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
        'a' ... 'z' => match PLAIN.find(input) {
            Some(in_idx) => {
                let out_idx = PLAIN.len() - 1 - in_idx;
                PLAIN.chars().nth(out_idx)
            },
            None => None,
        },
        _ => None,
    }
}