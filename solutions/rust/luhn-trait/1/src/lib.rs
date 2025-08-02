mod luhn;

pub trait Luhn
    where Self: ToString
{
    fn valid_luhn(&self) -> bool {
        luhn::is_valid(self.to_string().as_str())
    }
}

impl Luhn for str {}
impl Luhn for usize {}
impl Luhn for u8 {}
impl Luhn for u16 {}
impl Luhn for u32 {}
impl Luhn for u64 {}