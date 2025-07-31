mod luhn;

pub struct Luhn {
    is_valid: bool
}

impl Luhn {
    pub fn is_valid(&self) -> bool {
        self.is_valid
    }
}

impl<T> From<T> for Luhn
    where T: ToString
{
    fn from(src: T) -> Self {
        Self {
            is_valid: luhn::is_valid(&src.to_string())
        }
    }
}