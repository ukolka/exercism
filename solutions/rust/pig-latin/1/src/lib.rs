extern crate regex;

use regex::Regex;

pub fn translate(input: &str) -> String {
    let vow = Regex::new(r"^(?P<c>xr|yt|[aeiou]+)(?P<r>\S+)$").unwrap();
    let cons = Regex::new(r"^(?P<c>qu|[bcdfjhjklmnpqrstvwxyz]qu|[bcdfjhjklmnpqrstvwxyz]+)(?P<r>\S+)$").unwrap();
    
    let mut rv = String::with_capacity(input.len());
    
    for word in input.split_whitespace() {
        if vow.is_match(word) {
            rv.push_str(&vow.replace_all(word, "${c}${r}ay"));
        } else {
            rv.push_str(&cons.replace_all(word, "${r}${c}ay"));
        }
        rv.push(' ');
    }

    rv.pop();
    
    rv
}