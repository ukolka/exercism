use std::fmt;

const DAY: i64 = 24 * 60;
const HOUR: i64 = 60;

#[derive(Debug, Eq, PartialEq)]
pub struct Clock {
    hours: i64,
    minutes: i64,
}

impl Clock {
    pub fn new(hours: i64, minutes: i64) -> Clock {
        let minutes_wrapped_by_day =
            (((hours * HOUR + minutes) % DAY) + DAY) % DAY;
        let hours = minutes_wrapped_by_day / HOUR;
        let minutes = minutes_wrapped_by_day % HOUR;

        Clock {
            hours,
            minutes,
        }
    }

    pub fn add_minutes(self, minutes: i64) -> Clock {
        Clock::new(self.hours, self.minutes + minutes)
    }
}

impl fmt::Display for Clock {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "{:02}:{:02}", self.hours, self.minutes)
    }
}