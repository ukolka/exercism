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

    let square = normalized
        .chunks(c)
        .map(|chunk| {
            let mut rv = Vec::with_capacity(c);
            let mut ch = chunk.iter();
            for _ in 0..c {
                rv.push(ch.next().unwrap_or(&' '));
            }
            rv
        })
        .collect::<Vec<Vec<&char>>>();

    println!("{:?}", square);

    let mut transposed = (0..c)
        .map(|_| vec![&' '; r])
        .collect::<Vec<Vec<&char>>>();

    for row in 0..r {
        for col in 0..c {
            transposed[col][row] = square[row][col];
        }
    }
    
    transposed.iter()
        .map(|row| row.iter()
             .filter_map(|&ch| match ch {
                 &' ' => None,
                 _ => Some(ch),
             })
             .collect::<String>())
        .collect::<Vec<String>>()
        .join(" ")
}

fn normalize(ch: char) -> Option<char> {
    let ch_low = ch.to_lowercase().next();
    match ch_low {
        Some('a' ... 'z') => ch_low,
        _ => None
    }
}