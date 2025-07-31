pub fn hamming_distance(left: &str, right: &str) -> Result<u32, String> {
    let mut rv = 0;

    let mut l_iter = left.chars();
    let mut r_iter = right.chars();
    let mut lch = l_iter.next();
    let mut rch = r_iter.next();

    while lch != None && rch != None {
        if lch != rch {
            rv += 1;
        }
        
        lch = l_iter.next();
        rch = r_iter.next();
    }

    if lch != None || rch != None {
        return Err("Strings must be of equal length".to_string());
    }
    
    Ok(rv)
}