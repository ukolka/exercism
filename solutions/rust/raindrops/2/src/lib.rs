pub fn raindrops(n: usize) -> String {
    let nstr = n.to_string();
    let mut rv = String::new();
    
    if n % 3 == 0 {
        rv += "Pling";
    }

    if n % 5 == 0 {
        rv += "Plang";
    }

    if n % 7 == 0 {
        rv += "Plong";
    }

    if n % 3 > 0 && n % 5 > 0 && n % 7 > 0 {
        rv += &nstr;
    }

    rv
}