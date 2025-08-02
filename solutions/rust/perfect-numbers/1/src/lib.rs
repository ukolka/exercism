use std::collections::HashSet;

#[derive(Debug, PartialEq, Eq)]
pub enum Classification {
    Abundant,
    Perfect,
    Deficient
}

pub fn classify(num: u64) -> Result<Classification, & 'static str> {
    if num == 0 {
        return Err("Number must be positive");
    }
    if num == 1 {
        return Ok(Classification::Deficient);
    }
    
    Ok(match Some(factor_sum(num)) {
        Some(x) if x == num => Classification::Perfect,
        Some(x) if x < num => Classification::Deficient,
        _ => Classification::Abundant,
    })
}

fn factor_sum(num: u64) -> u64 {
    let mut n = num;
    let mut curr_factor = 2;
    let mut prime_factors = HashSet::new();
    
    while n > 1 {
        if n % curr_factor == 0 {
            n /= curr_factor;
            prime_factors.insert(curr_factor);
        } else {
            curr_factor += 1;
        }
    }

    let mut rv = HashSet::new();
    for &pf in prime_factors.iter() {
        let mut mpf = pf;        
        while mpf < num {
            if num % mpf == 0 {
                rv.insert(mpf);
            }
            mpf += pf;
        }
    }

    rv.iter().sum::<u64>() + 1
}