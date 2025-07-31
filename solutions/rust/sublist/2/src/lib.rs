#[derive(Debug, Eq, PartialEq)]
pub enum Comparison {
    Sublist,
    Superlist,
    Equal,
    Unequal,
}

pub fn sublist<T: PartialOrd> (a: &[T], b: &[T]) -> Comparison {
    if a == b {
        return Comparison::Equal;
    }

    if is_sublist(a, b) {
        return Comparison::Sublist;
    }

    if is_sublist(b, a) {
        return Comparison::Superlist;
    }
    
    Comparison::Unequal
}

fn is_sublist<T: PartialOrd> (a: &[T], b: &[T]) -> bool {
    let len_a = a.len();
    let len_b = b.len();

    if len_a > len_b {
        return false;
    }
    
    let mut i = 0;
    
    while i < len_b {
        let mut idx_b = i;
        let mut idx_a = 0;

        while idx_b < len_b && idx_a < len_a && b[idx_b] == a[idx_a] {
            idx_a += 1;
            idx_b += 1;
        }

        if idx_a == len_a {
            return true;
        }

        i += 1;
    }

    false
}