pub fn square(s: u32) -> u64 {
    assert!(s > 0 && s <= 64, "Square must be between 1 and 64");

    let mut p : f32 = 1f32;
    
    for _ in 0..s {
        p *= 2f32;
    }

    (p / 2f32) as u64
}

pub fn total() -> u64 {
    let mut sum = 0;
    for i in 1..65 {
        sum += square(i);
    }
    sum
}