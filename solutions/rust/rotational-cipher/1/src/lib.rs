const DICTIONARY: &str = "abcdefghijklmnopqrstuvwxyz";

pub fn rotate(input: &str, rotations: usize) -> String {
    input.chars()
        .filter_map(|ch| match ch {
            'a' ... 'z' => transpose(ch, DICTIONARY, rotations),
            'A' ... 'Z' => transpose(
                ch,
                DICTIONARY.to_uppercase().as_str(),
                rotations
            ),
            _ => Some(ch)
        })
        .collect::<String>()
}

fn transpose(ch: char, dict: &str, rotations: usize) -> Option<char> {
    let len = dict.len();
    let position = dict.find(ch);

    match position {
        Some(idx) => dict.chars().nth((idx + rotations) % len),
        None => None,
    }
}