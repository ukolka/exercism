pub fn encrypt(input: &str) -> String {
    let normalized = input.chars()
        .filter_map(normalize)
        .collect::<Vec<char>>();

    let len = normalized.len();
    let r = (len as f32).sqrt() as usize;
    
    if r == 0 {
        return "".to_string();
    }
    
    let c = (len as f32 / r as f32).ceil() as usize;

    let mut rv = String::with_capacity(r * c + c);

    for offset in 0..c {
        for base in 0..r {
            let idx = base * c + offset;
            if idx < len {
                rv.push(normalized[idx]);
            }
        }
        if offset < c - 1 {
            rv.push(' ');
        }
    }

    rv
}

fn normalize(ch: char) -> Option<char> {
    let ch_low = ch.to_lowercase().next();
    match ch_low {
        Some('a' ... 'z') => ch_low,
        _ => None
    }
}