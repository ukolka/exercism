use std::f32;

pub fn factors(n: u64) -> Vec<u64> {
    if n == 1 {
        return vec![];
    }
    
    let mut cur_n = n;
    let mut prime_idx = 1;
    let mut prime:u64 = nth(prime_idx).unwrap() as u64;
    let mut rv:Vec<u64> = Vec::new();

    while cur_n > 0 {
        if cur_n == prime {
            rv.push(prime);
            break;
        }

        if is_prime(cur_n as u32) && cur_n * rv.iter().fold(1, |acc, x| { acc * x }) == n {
            rv.push(cur_n);
            break;
        }
        
        if cur_n.checked_rem(prime) == Some(0) {
            rv.push(prime);
            cur_n /= prime;
        } else {
            prime_idx += 1;
            prime = nth(prime_idx).unwrap() as u64;
        }
    }

    rv
}

fn nth(n: u32) -> Result<u32, u32> {
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