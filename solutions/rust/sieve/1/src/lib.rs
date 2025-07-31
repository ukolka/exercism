pub fn primes_up_to(limit: u32) -> Vec<u32> {
    (0..limit + 1)
        .filter_map(is_prime)
        .collect::<Vec<u32>>()
}

fn is_prime(n: u32) -> Option<u32> {
    if n < 2 {
        return None
    }
    
    if n % 2 == 0 {
        return match n == 2 {
            true => Some(n),
            false => None,
        }
    }
    if n % 3 == 0 {
        return match n == 3 {
            true => Some(n),
            false => None,
        }
    }
    
    let mut step = 4;
    let m = (n as f32).sqrt() as u32 + 1;
    let mut i = 5;
    
    while i < m {
        if n % i == 0 {
            return None;
        }
        step = 6 - step;
        i += step;
    }
    
    Some(n)
}