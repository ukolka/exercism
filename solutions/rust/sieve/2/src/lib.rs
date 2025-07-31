pub fn primes_up_to(limit: u32) -> Vec<u32> {
    let mut primes_so_far = Vec::new();
    
    if limit < 2 {
        return primes_so_far;
    }

    primes_so_far.push(2);
    
    for candidate in 2..limit + 1 {
        if primes_so_far.iter().all(|prime| candidate % prime > 0) {
            primes_so_far.push(candidate);
        }
    }

    primes_so_far
}