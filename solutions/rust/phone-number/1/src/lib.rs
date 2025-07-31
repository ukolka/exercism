pub fn number(input: &str) -> Option<String> {
    let mut rv = input.chars().filter_map(|ch| match ch {
        '0' ... '9' => Some(ch),
        _ => None,
    }).collect::<Vec<char>>();

    if rv[0] == '1' {
        rv = rv[1..].to_vec();
    }

    if rv[0] < '2' || rv[3] < '2' {
        return None;
    }

    if rv.len() != 10 {
        return None;
    }

    Some(rv.iter().collect::<String>())
}