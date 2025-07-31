pub fn raindrops(n: usize) -> String {
    let nstr = n.to_string();
    let mut rv = Vec::new();
    
    if n % 3 == 0 {
        rv.push("Pling");
    }

    if n % 5 == 0 {
        rv.push("Plang");
    }

    if n % 7 == 0 {
        rv.push("Plong");
    }

    if n % 3 > 0 && n % 5 > 0 && n % 7 > 0 {
        rv.push(&nstr);
    }

    rv.concat()
}