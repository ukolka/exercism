//
// See Rust Language Specific Instructions
// below normal exercise description.
//
pub fn encode(input: u64) -> String {
    if input == 0 {
        return "zero".to_string();
    }

    let ones = vec!["", "one", "two", "three", "four",
                    "five", "six", "seven", "eight", "nine"];
    let teens = vec!["", "eleven", "twelve", "thirteen", "fourteen",
                     "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"];
    let tens = vec!["", "ten", "twenty", "thirty", "forty",
                    "fifty", "sixty", "seventy", "eighty", "ninety"];
    let triplet_names = vec!["", "thousand",
                             "million", "billion", "trillion",
                             "quadrillion", "quintillion"];
    
    let list = partition(make_digits(input));
    
    let mut rv:Vec<&str> = vec![];

    for (i, triplet) in list.iter().enumerate() {
        let mut iter = triplet.iter();

        let ones_place = iter.next();
        let tens_place = iter.next();
        let hundreds_place = iter.next();

        if triplet.iter().any(|&x| x > 0) {
            rv.push(triplet_names[i]);
        }

        if ones_place != None {
            match tens_place {
                Some(&1) => rv.push(""),
                _ => rv.push(ones[*(ones_place.unwrap()) as usize]),
            };
        }

        if tens_place != None {            
            match tens_place {
                Some(&0) => rv.push(tens[*(tens_place.unwrap()) as usize]),
                Some(&1) => if ones_place == Some(&0) {
                    rv.push("ten");
                } else {
                    rv.push(teens[*(ones_place.unwrap()) as usize])
                },
                _ => {
                    if ones_place.unwrap() > &0 {
                        rv.push("-");
                    }
                    rv.push(tens[*(tens_place.unwrap()) as usize])
                },
            };
        }

        if hundreds_place != None {
            match hundreds_place {
                Some(&0) => rv.push(""),
                _ => {
                    rv.push("hundred");
                    rv.push(ones[*(hundreds_place.unwrap()) as usize]);
                },
            };
        }
    }

    let mut rs = String::new();
    let mut i = rv.len().checked_sub(1);

    while i != None {
        let chunk = rv[i.unwrap()];
        if chunk == "-" {
            rs.pop();
            rs += chunk;
        } else if chunk.len() > 1 {
            rs += chunk;
            rs += " ";
        }

        i = i.unwrap().checked_sub(1);
    }
    rs.pop();
    rs
}

fn make_digits(input: u64) -> Vec<u64> {
    let mut rv: Vec<u64> = vec![];
    let mut n = input;

    while n > 0 {
        rv.push(n % 10);
        n /= 10;
    }

    rv
}

fn partition(digits: Vec<u64>) -> Vec<Vec<u64>> {
    let mut rv: Vec<Vec<u64>> = vec![];
    let mut count = 0;

    for i in 0..digits.len()  {
        if count % 3 == 0 {
            rv.push(Vec::with_capacity(3));
        }        
        let rv_len = rv.len();
        rv[rv_len - 1].push(digits[i]);
        count += 1;
    }

    rv
}