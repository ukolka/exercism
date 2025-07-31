pub fn sum_of_multiples(limit: u32, factors: &[u32]) -> u32 {
    let mut sum = 0;
    let mut multiples = Vec::with_capacity(factors.len());

    for i in 0..factors.len() {
        multiples.push(factors[i]);
        
        while multiples[i] < limit {
            let mut is_unique = true;
            for j in (i+1)..factors.len() {
                if multiples[i] % factors[j] == 0 {
                    is_unique = false;
                }
            }

            if is_unique {
                sum += multiples[i];
            }

            multiples[i] += factors[i];
        }
    }

    sum
}