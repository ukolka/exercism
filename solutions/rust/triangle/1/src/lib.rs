pub struct Triangle {
    side_a: u32,
    side_b: u32,
    side_c: u32,
}

impl Triangle {    
    pub fn build(sides: [u32; 3]) -> Result<Self, String> {
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
        self.side_a != self.side_b &&
            self.side_a != self.side_c &&
            self.side_b != self.side_c
    }

    fn exists(&self) -> bool {
        self.side_a + self.side_b > self.side_c &&
            self.side_a + self.side_c > self.side_b &&
            self.side_b + self.side_c > self.side_a
    }

    fn new(side_a: u32, side_b: u32, side_c: u32) -> Self {
        Self {
            side_a,
            side_b,
            side_c,
        }
    }

}