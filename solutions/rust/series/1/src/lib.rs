pub fn series(digits: &str, len: usize) -> Vec<String> {
    if len == 0 {
        return vec!["".to_string(); digits.len() + 1];
    }
    
    if len > digits.len() {
        return vec![];
    }

    let mut rv = vec![];
    
    for i in 0..(digits.len() - len + 1) {
        rv.push(digits[i..(i + len)].to_string());
    }

    rv
}