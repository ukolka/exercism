const EARTH_YEAR_SECS: f64 = 31557600.0;

pub struct Duration {
    seconds: u64,
}

impl From<u64> for Duration {
    fn from(s: u64) -> Self {
        Self {
            seconds: s,
        }
    }
}

pub trait Planet {
    const ORBITAL_PERIOD: f64;
    
    fn years_during(d: &Duration) -> f64 {
        d.seconds as f64 / Self::ORBITAL_PERIOD
    }
}

pub struct Mercury;
pub struct Venus;
pub struct Earth;
pub struct Mars;
pub struct Jupiter;
pub struct Saturn;
pub struct Uranus;
pub struct Neptune;

impl Planet for Mercury {
    const ORBITAL_PERIOD: f64 = EARTH_YEAR_SECS * 0.2408467;
}
impl Planet for Venus {
    const ORBITAL_PERIOD: f64 = EARTH_YEAR_SECS * 0.61519726;
}
impl Planet for Earth {
    const ORBITAL_PERIOD: f64 = EARTH_YEAR_SECS;
}
impl Planet for Mars {
    const ORBITAL_PERIOD: f64 = EARTH_YEAR_SECS * 1.8808158;
}
impl Planet for Jupiter {
    const ORBITAL_PERIOD: f64 = EARTH_YEAR_SECS * 11.862615;
}
impl Planet for Saturn {
    const ORBITAL_PERIOD: f64 = EARTH_YEAR_SECS * 29.447498;
}
impl Planet for Uranus {
    const ORBITAL_PERIOD: f64 = EARTH_YEAR_SECS * 84.016846;
}
impl Planet for Neptune {
    const ORBITAL_PERIOD: f64 = EARTH_YEAR_SECS * 164.79132;
}