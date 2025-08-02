pub fn abbreviate(input: &str) -> String {
    let mut input_vec = Vec::with_capacity(input.len() + 1);
    input_vec.push(' ');
    input_vec.append(&mut input.chars().collect::<Vec<char>>());

    println!("{:?}", input_vec);
    
    input_vec.windows(2)
        .filter_map(
            |duplet|
            {
                let first = duplet[0];
                let second = duplet[1];
                
                if (
                    (first.is_whitespace() || first == '-') &&
                        second.is_alphabetic()) ||
                    
                    (first.is_lowercase() && second.is_uppercase())
                {
                    return second.to_uppercase().next();
                }
                
                None
            })
        .collect::<String>()
}