use std::fmt;

const DAY: i64 = 24 * 60;

#[derive(Debug, Eq, PartialEq)]
pub struct Clock {
    minutes: i64,
}

impl Clock {
    pub fn new(hours: i64, minutes: i64) -> Clock {
        Clock {
            minutes: modulus(hours * 60 + minutes, DAY)
        }
    }

    pub fn add_minutes(self, minutes: i64) -> Clock {
        Clock {
            minutes: modulus(self.minutes + minutes, DAY)
        }
    }
}

impl fmt::Display for Clock {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        let mut minutes = modulus(self.minutes, DAY);
        let hours = minutes / 60;
        minutes %= 60;
        write!(f, "{:02}:{:02}", hours, minutes)
    }
}

fn modulus(a: i64, b: i64) -> i64 {
    ((a % b) + b) % b
}