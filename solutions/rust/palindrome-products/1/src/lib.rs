pub type Palindrome = u64;
pub fn get_palindrome_products(min: u64, max: u64) -> Vec<Palindrome> {
    let mut result: Vec<Palindrome> = vec![];
    
    for m in min..(max + 1) {
        for n in m..(max + 1) {
            if is_palindrome(m * n) {
                result.push(m * n);
            }
        }
    }

    result
}

pub fn min(palindromes: &[Palindrome]) -> Option<Palindrome> {
    match palindromes.iter().min() {
        Some(&m) => Some(m),
        None => None
    }
}

pub fn max(palindromes: &[Palindrome]) -> Option<Palindrome> {
    match palindromes.into_iter().max() {
        Some(&m) => Some(m),
        None => None
    }
}

fn is_palindrome(candidate: Palindrome) -> bool {
    let mut reverse = 0;
    let mut candidate_copy = candidate;
    while candidate_copy > 0 {
        reverse *= 10;
        reverse += candidate_copy % 10;
        candidate_copy /= 10;
    }
    reverse == candidate
}