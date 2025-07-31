pub fn encode(input: &str) -> String {
    if input.len() == 0 {
        return "".to_string();
    }

    let mut cur_ch: char = ' ';
    let mut counter = 0;
    let mut rv = String::with_capacity(input.len());
    
    for (i, ch) in input.chars().enumerate() {
        if i == 0 {
            cur_ch = ch;
        }
        
        if cur_ch == ch {
            counter += 1;
        } else {
            rv = format!("{}{}{}", rv, count_to_str(counter), cur_ch);
            cur_ch = ch;
            counter = 1;
        }
    }

    rv = format!("{}{}{}", rv, count_to_str(counter), cur_ch);

    rv
}

fn count_to_str(n: u32) -> String {
    match n {
        1 => "".to_string(),
        _ => format!("{}", n)
    }
}

pub fn decode(input: &str) -> String {
    if input.len() == 0 {
        return "".to_string();
    }

    let mut repeat_s = String::new();
    let mut iter = input.chars();
    let mut ch = iter.next();
    let mut rv = String::new();
    
    while ch != None {        
        while ch.unwrap().is_numeric() {
            repeat_s.push(ch.unwrap());
            ch = iter.next();
        }

        for _ in 0..string_to_count(&repeat_s) {
            rv = format!("{}{}", rv, ch.unwrap());
        }
        
        repeat_s.clear();
        ch = iter.next();
    }

    rv
}

fn string_to_count(input: &String) -> u32 {
    input.parse::<u32>().unwrap_or(1)
}