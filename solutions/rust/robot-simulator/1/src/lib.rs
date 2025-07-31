// The code below is a stub. Just enough to satisfy the compiler.
// In order to pass the tests you can add-to or change any of this code.

#[derive(PartialEq, Debug)]
pub enum Direction {
    North,
    East,
    South,
    West,
}

pub struct Robot {
    x: isize,
    y: isize,
    d: Direction
}

impl Robot {
    #[allow(unused_variables)]
    pub fn new(x: isize, y: isize, d: Direction) -> Self {
        Self {
            x,
            y,
            d,
        }
    }

    pub fn turn_right(self) -> Self {
        let new_direction = match self.d {
            Direction::North => Direction::East,
            Direction::East => Direction::South,
            Direction::South => Direction::West,
            Direction::West => Direction::North,
        };

        Self {
            x: self.x,
            y: self.y,
            d: new_direction,
        }
    }

    pub fn turn_left(self) -> Self {
        let new_direction = match self.d {
            Direction::North => Direction::West,
            Direction::East => Direction::North,
            Direction::South => Direction::East,
            Direction::West => Direction::South,
        };

        Self {
            x: self.x,
            y: self.y,
            d: new_direction,
        }
    }

    pub fn advance(self) -> Self {
        let mut new_x = self.x;
        let mut new_y = self.y;
        match self.d {
            Direction::North => new_y += 1,
            Direction::East => new_x += 1,
            Direction::South => new_y -= 1,
            Direction::West => new_x -= 1,            
        };

        Self {
            x: new_x,
            y: new_y,
            d: self.d,
        }
    }

    pub fn instructions(self, instructions: &str) -> Self {
        let mut rv = self;
        for instruction in instructions.chars() {
            rv = match instruction {
                'A' => rv.advance(),
                'R' => rv.turn_right(),
                'L' => rv.turn_left(),
                _ => rv,
            }
        }
        rv
    }

    pub fn position(&self) -> (isize, isize) {
        (self.x, self.y)
    }

    pub fn direction(&self) -> &Direction {
        &self.d
    }
}