use std::collections::BTreeMap;

pub fn transform(input: &BTreeMap<i32, Vec<char>>) -> BTreeMap<char, i32> {
    let mut result = BTreeMap::new();
    
    input.iter()
        .for_each(
            |(&score, letters)| letters.iter()
                .for_each(|&letter| {
                    result.insert(
                        letter.to_lowercase().next().unwrap(),
                        score
                    );
                })
        );
        
    result
}