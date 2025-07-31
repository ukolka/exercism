const PLAIN: &str =  "abcdefghijklmnopqrstuvwxyz";
const CIPHER: &str = "zyxwvutsrqponmlkjihgfedcba";
const GROUP_SIZE: usize = 5;

pub fn encode(input: &str) -> String {
    process(input, PLAIN, CIPHER, Some(' '))
}

pub fn decode(input: &str) -> String {
    process(input, CIPHER, PLAIN, None)
}

fn process(input: &str,
           plain: &str,
           cipher: &str,
           delimiter: Option<char>) -> String {

    input
        .to_lowercase()
        .chars()
        .filter_map(|ch| match ch {
            '0' ... '9' => translate(ch, plain, cipher),
            'a' ... 'z' => translate(ch, plain, cipher),
            _ => None,
        })
        .collect::<Vec<char>>()
        .chunks(GROUP_SIZE)
        .map(|chunk| -> String {
            let mut rv = String::with_capacity(GROUP_SIZE);
            for &ch in chunk {
                rv.push(ch);
            }
            rv
        })
        .fold(String::new(),
              |acc, word| match delimiter {
                  Some(d) => match acc.len() {
                      0 => format!("{}{}", acc, word),
                      _ => format!("{}{}{}", acc, d, word)
                  },
                  None => format!("{}{}", acc, word)
              })
}

fn translate(input: char, plain: &str, cipher: &str) -> Option<char> {
    match input {
        '0' ... '9' =>  Some(input),
        _ => {
            for (i, ch) in plain.chars().enumerate() {
                if ch == input {
                    return cipher.chars().nth(i);
                }
            }
            
            None
        }
    }
}