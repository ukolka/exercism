enum LuhnError {
    InvalidEntry ,
    InvalidLength,
}

pub fn is_valid(input: &str) -> bool {
    match is_valid_result(input) {
        Err(_) => false,
        Ok(val) => val
    }
}

fn is_valid_result(input: &str) -> Result<bool, LuhnError> {
    is_valid_input(input)?;
    
    let rv = input.chars()
        .filter_map(|ch| ch.to_digit(10)).collect::<Vec<u32>>();

    is_valid_input_len(rv.len())?;

    Ok(rv.into_iter().rev()
        .enumerate()
        .map(|(idx, n)| if idx % 2 == 1 {
            match n {
                9 => n,
                _ => (n * 2) % 9,
            }
        } else {
            n
        }).sum::<u32>() % 10 == 0)
}

fn is_valid_input_len(len: usize) -> Result<bool, LuhnError> {
    match len {
        0 ... 1 => Err(LuhnError::InvalidLength),
        _ => Ok(true)
    }
}

fn is_valid_input(input: &str) -> Result<bool, LuhnError> {
    for ch in input.chars() {
        if !(ch.is_numeric() || ch == ' ') {
            return Err(LuhnError::InvalidEntry);
        }
    }

    Ok(true)
}