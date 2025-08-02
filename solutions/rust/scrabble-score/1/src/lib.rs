pub fn score(input: &str) -> u32 {
    input.to_uppercase().chars().map(|ch| score_char(ch)).sum()
}

fn score_char(input: char) -> u32 {
    let score_by_index: Vec<&str> = vec![
        "",
        "AEIOULNRST",
        "DG",
        "BCMP",
        "FHVWY",
        "K",
        "", "",
        "JX",
        "",
        "QZ"
    ];

    let mut sum: u32 = 0;
    for (i, candidate) in score_by_index.into_iter().enumerate() {
        if candidate.chars().any(|ch| ch == input) {
            println!("{} {}", candidate, i);
            sum += i as u32;
        }
    }
    sum
}