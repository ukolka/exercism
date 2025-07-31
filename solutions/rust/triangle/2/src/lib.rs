extern crate num;

#[derive(Eq, PartialEq)]
pub struct Triangle<T>
    where
    T: num::Num + PartialOrd + Copy
{
    side_a: T,
    side_b: T,
    side_c: T,
}

impl<T> Triangle<T>
    where
    T: num::Num + PartialOrd + Copy
{    
    pub fn build(sides: [T; 3]) -> Result<Self, String> {
        let rv = Self::new(sides[0], sides[1], sides[2]);

        match rv.exists() {
            true => Ok(rv),
            false => Err("Not a triangle".to_string())
        }
    }

    pub fn is_equilateral(&self) -> bool {
        self.side_a == self.side_b &&
            self.side_a == self.side_c
    }

    pub fn is_isosceles(&self) -> bool {
        self.side_a == self.side_b ||
            self.side_a == self.side_c ||
            self.side_b == self.side_c
    }

    pub fn is_scalene(&self) -> bool {
        !self.is_isosceles()
    }

    fn exists(&self) -> bool {
        self.side_a + self.side_b > self.side_c &&
            self.side_a + self.side_c > self.side_b &&
            self.side_b + self.side_c > self.side_a
    }

    fn new(side_a: T, side_b: T, side_c: T) -> Self {
        Self {
            side_a,
            side_b,
            side_c,
        }
    }

}