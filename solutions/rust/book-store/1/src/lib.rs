use std::f64;

const PRICE: f64 = 8.0;

pub fn lowest_price(books: &[usize]) -> f64 {
    if books.len() == 0 {
        return 0.0;
    }

    if books.len() == 1 {
        return PRICE;
    }

    let mut min_price = f64::INFINITY;
    
    for i in 3..6 {
        let p = price(groups(books, i).unwrap());
        if p < min_price {
            min_price = p;
        }
    }

    min_price
}

fn price(groups: Vec<Vec<usize>>) -> f64 {
    let mut sum = 0.0;
    for i in 0..groups.len() {
        sum += match groups[i].len() {
            1 => PRICE,
            2 => 2.0 * PRICE * 0.95,
            3 => 3.0 * PRICE * 0.90,
            4 => 4.0 * PRICE * 0.80,
            5 => 5.0 * PRICE * 0.75,
            _ => 0.0,
        };
    }
    sum
}

fn groups(books: &[usize], max_size: usize) -> Result<Vec<Vec<usize>>, ()> {
    let mut h = hist(books)?;
    let mut groups = Vec::with_capacity(max(&h)?);

    while !is_empty(&h) {
        let mut group = Vec::with_capacity(books.len());
        
        for val in 0..h.len() {
            let count = h[val];
            if count > 0 {
                if group.len() >= max_size {
                    break;
                } else {
                    h[val] -= 1;
                    group.push(val);
                }
            }
        }

        groups.push(group);
    }

    Ok(groups)
}

fn is_empty(h: &Vec<usize>) -> bool {
    h.iter().sum::<usize>() == 0
}

fn hist(books: &[usize]) -> Result<Vec<usize>, ()> {
    let mut rv = vec![0; max(books)? + 1];
    
    for &book in books.iter() {
        rv[book] += 1;
    }

    Ok(rv)
}

fn max(books: &[usize]) -> Result<usize, ()> {
    if books.len() == 0 {
        return Err(());
    }

    let mut max = books[0];

    for &book in books.iter() {
        if book > max {
            max = book;
        }
    }

    Ok(max)
}