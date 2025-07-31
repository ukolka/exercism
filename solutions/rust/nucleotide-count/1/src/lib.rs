use std::collections::HashMap;

const NUCLEOTIDES: &str = "ACGT";

pub fn count(nucleotide: char, seq: &str) -> Result<usize, &str> {
    let mut sum = 0;

    if !is_valid(nucleotide) {
        return Err("Invalid nucleotide");
    }

    for ch in seq.chars() {
        if is_valid(ch) {
            if ch == nucleotide {
                sum += 1;
            }
        } else {
            return Err("Invalid sequence");
        }
    }

    Ok(sum)
}

fn is_valid(nucleotide: char) -> bool {
    NUCLEOTIDES.chars().any(|valid_nucleotide| nucleotide == valid_nucleotide)
}

pub fn nucleotide_counts(seq: &str) -> Result<HashMap<char, usize>, &str> {
    let rv: HashMap<char, usize> = NUCLEOTIDES.chars()
        .map(|ch| (ch, count(ch, seq).unwrap_or(0)))
        .collect();

    for ch in seq.chars() {
        if !is_valid(ch) {
            return Err("Invalid sequence")
        }
    }
        
    Ok(rv)
}