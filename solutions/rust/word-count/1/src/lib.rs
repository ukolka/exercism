use std::collections::HashMap;

pub fn word_count(input: &str) -> HashMap<String, u32> {
    let mut map: HashMap<String, u32> = HashMap::new();

    input.to_lowercase()
        .split_whitespace()
        .for_each(|word| {
 
            let trimmed_word = word
                .trim_matches(|ch: char| !ch.is_alphanumeric())
                .to_string();
            
            if trimmed_word.len() > 0 {
                let counter = map
                    .entry(trimmed_word)
                    .or_insert(0);
                
                *counter += 1;
            }
        });
    
    map
}