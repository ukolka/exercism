pub fn find() -> Option<u32> {
    let sum = 1000;
    let ubond = 500;
    let mut rv = None;
    
    for a in 0..ubond {
        for b in a..ubond {
            for c in b..ubond {
                if (a*a + b*b == c*c) && (a + b + c == sum) {
                    rv = Some(a * b * c);
                }
            }
        }
    }

    rv
}