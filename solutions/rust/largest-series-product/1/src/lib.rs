pub fn lsp(input: &str, len: usize) -> Result<u32, &str> {
    if len == 0 {
        return Ok(1);
    }

    if input.chars().any(|ch| !ch.is_digit(10)) {
        return Err("Only digits are valid");
    }
    
    match input.chars().collect::<Vec<char>>()
        .windows(len)
        .map(|window| window.iter()
             .map(|ch| ch.to_digit(10).unwrap_or(1)).product())
        .max() {
            Some(x) => Ok(x),
            None => Err("Could not calculate the lsp")
        }
}