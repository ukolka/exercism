pub fn build_proverb(list: Vec<&str>) -> String {
    let mut i_list = list.iter();
    let mut left = i_list.next();
    let mut right = i_list.next();
    let first = left.unwrap_or(&"");

    let mut rv = String::from("");
    
    while left.unwrap_or(&"") != &"" {
        if let Some(r) = right {
            rv += "For want of a ";
            rv += left.unwrap_or(&"");
            rv += " the ";
            rv += r;
            rv += " was lost.\n";
        } else {
            rv += "And all for the want of a ";
            rv += first;
            rv += ".";
        }
        
        left = right;
        right = i_list.next();
    }
    
    rv
}