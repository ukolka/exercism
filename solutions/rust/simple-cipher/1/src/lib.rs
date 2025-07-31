extern crate rand;
use rand::{thread_rng, Rng};

fn forward(ch: char, k: char) -> char {
    let character: u8 = ch as u8;
    let key: u8 = k as u8;
    let a: u8 = 'a' as u8;
    let shift = key - a;
    (a + ((26 + character - a + shift) % 26)) as char
}

fn backward(ch: char, k: char) -> char {
    let character: u8 = ch as u8;
    let key: u8 = k as u8;
    let a: u8 = 'a' as u8;
    let shift = key - a;
    (a + ((26 + character - a - shift) % 26)) as char
}

pub fn encode(key: &str, s: &str) -> Option<String> {
    let mut result = String::with_capacity(s.len());
    let mut corrupt = false;
    
    if key.len() == 0 { return None };
    
    key.chars().cycle().zip(s.chars())
        .for_each(|(k, ch)| match k {
            'a' ... 'z' => result.push(forward(ch, k)),
            _ => { corrupt = true }
        });

    if corrupt {
        return None;
    }
    
    Some(result)
}

pub fn decode(key: &str, s: &str) -> Option<String> {
    let mut result = String::with_capacity(s.len());
    let mut corrupt = false;
    
    if key.len() == 0 { return None };

    key.chars().cycle().zip(s.chars())
        .for_each(|(k, ch)| match k {
            'a' ... 'z' => result.push(backward(ch, k)),
            _ => { corrupt = true }
        });

    if corrupt {
        return None;
    }
    
    Some(result)
}

fn random_key() -> String {
    let mut rng = thread_rng();
    let size = 101;
    let mut rv: String = String::with_capacity(size);
    for _ in 1..size {
        let n: u8 = rng.gen_range(0, 26);
        rv.push(('a' as u8 + n) as char);
    }
    rv
}

pub fn encode_random(s: &str) -> (String, String) {
    let key = random_key();    
    (key.clone(), encode(&key, s).unwrap())
}