pub struct Roman {
    number: u32
}

impl From<u32> for Roman {
    fn from(number: u32) -> Self {
        Roman {
            number
        }
    }
}

impl ToString for Roman {
    fn to_string(&self) -> String {
        let ones: Vec<&str> = vec!["", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"];
        let tens: Vec<&str> = vec!["", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"];
        let hundreds: Vec<&str> = vec!["", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"];

        let mut consumed_n = self.number;
        let mut idx = 0;
        let mut rv: Vec<&str> = Vec::new();

        while consumed_n > 0 {
            let digit = (consumed_n % 10) as usize;
        
            if idx == 0 {
                rv.push(ones[digit])
            } else if idx == 1 {
                rv.push(tens[digit])
            } else if idx == 2 {
                rv.push(hundreds[digit])
            } else {
                for _ in 0..digit * 10usize.pow(idx - 3) {
                    rv.push("M");
                }
            }

            idx += 1;
            consumed_n /= 10;
        }

        rv.into_iter().rev().collect::<String>()
    }
}