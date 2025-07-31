use std::fmt;

#[derive(Debug)]
pub struct Clock {
    hours: i64,
    minutes: i64,
}

impl Clock {
    pub fn new(hours: i64, minutes: i64) -> Clock {
        Clock {
            hours,
            minutes,
        }
    }

    pub fn add_minutes(self, minutes: i64) -> Clock {
        Clock {
            hours: self.hours,
            minutes: self.minutes + minutes,
        }
    }

    fn roll_hours(&self) -> i64 {
        let mut rv = (24 + *&self.hours) % 24;
        if *&self.minutes >= 60 {
            rv += *&self.minutes / 60;
        }

        if *&self.minutes < 0 {
            rv += (*&self.minutes / 60) - 1;
        }

        rv %= 24;
        
        if rv < 0 {
            return 24 + rv;
        }

        rv
    }

    fn roll_minutes(&self) -> i64 {
        let rv = &self.minutes % 60;

        if rv < 0 {
            return 60 + rv;
        }

        rv
    }
}

impl fmt::Display for Clock {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "{:02}:{:02}", self.roll_hours(), self.roll_minutes())
    }
}

impl PartialEq for Clock {
    fn eq(&self, other: &Clock) -> bool {
        self.roll_hours() == other.roll_hours() &&
            self.roll_minutes() == other.roll_minutes()
    }
}