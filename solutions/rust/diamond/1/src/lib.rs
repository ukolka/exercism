fn make_row(ch: char, half_width: u8) -> String {
    let width = half_width * 2 - 1;
    let mut row = String::with_capacity(width as usize);
    let offset = ch as u8 - 'A' as u8;
    let center = half_width - 1;
    
    for i in 0..width {
        if i == (center - offset) { row.push(ch); }
        else if i == (center + offset) { row.push(ch); }
        else { row.push(' '); }
    }

    return row;
}

pub fn get_diamond(c: char) -> Vec<String> {
    if c < 'A' || c > 'Z' {
        return vec!["".to_string()];
    }

    let ch_a = 'A' as u8;
    let half_width = c as u8 - ch_a + 1;

    if half_width == 1 {
        return vec!["A".to_string()];
    }

    let mut result:Vec<String> = Vec::with_capacity(
        half_width as usize * 2 - 1);

    for ch in ch_a..((c as u8) + 1) {
        result.push(make_row(ch as char, half_width));
    }
    for ch in (ch_a..(c as u8)).rev() {
        result.push(make_row(ch as char, half_width));
    }
    result
}