use std::f32;

pub fn nth(n: u32) -> Result<u32, u32> {
    if n < 1 {
        return Err(0);
    }

    let mut found_count = 0;
    let mut candidate = 2;
    
    while found_count < n {
        if is_prime(candidate) {
            found_count += 1;
        }
        candidate += 1;
    }
    
    Ok(candidate - 1)
}

fn is_prime(n: u32) -> bool {
    if n % 2 == 0 { return n == 2; }
    if n % 3 == 0 { return n == 3; }
    
    let mut step = 4;
    let m = (n as f32).sqrt() as u32 + 1;
    let mut i = 5;
    
    while i < m {
        if n % i == 0 {
            return false;
        }
        step = 6 - step;
        i += step;
    }
    
    true
}