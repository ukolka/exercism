pub fn verse(n: i32) -> String {
    match n {
        0 => String::from("No more bottles of beer on the wall, no more bottles of beer.\nGo to the store and buy some more, 99 bottles of beer on the wall.\n"),
        _ => format!(
            "{} of beer on the wall, {} of beer.\nTake {} down and pass it around, {} of beer on the wall.\n",
            bottles(n, Some(true)),
            bottles(n, Some(false)),
            it_one(n),
            bottles(dec(n), Some(false))
        ),
    }
}

pub fn sing(start: i32, end: i32) -> String {
    let mut cur = start;
    let mut rv = String::from("");

    while cur >= end {
        rv += &verse(cur);
        if cur > end {
            rv += "\n";
        }
        
        cur -= 1;
    }

    rv
}

fn dec(n: i32) -> i32 {
    match n {
        0 => 99,
        _ => n - 1,
    }
}

fn it_one(n: i32) -> String {
    match n {
        1 => String::from("it"),
        _ => String::from("one"),
    }
}

fn bottles(n: i32, capitalize: Option<bool>) -> String {
    let n_str = n.to_string();
    
    let no = match capitalize.unwrap_or(false) {
        true => "No",
        false => "no"
    };
    
    match n {
        0 => format!("{} more bottles", no),
        1 => String::from("1 bottle"),
        _ => n_str +  " bottles",
    }
}