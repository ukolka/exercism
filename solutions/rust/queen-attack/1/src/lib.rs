use std::ops::Add;

const BOARD_SIZE: i8 = 8;

#[derive(Debug, Eq, PartialEq, Clone)]
pub struct ChessPosition {
    row: i8,
    col: i8,
}

pub struct Queen {
    position: ChessPosition,
}

impl ChessPosition {
    pub fn new(row: i8, col: i8) -> Result<Self, ()> {
        let result = Self {
            row,
            col,
        };

        match result.is_valid() {
            true => Ok(result),
            false => Err(())
        }
    }

    pub fn is_same_row(&self, other: &ChessPosition) -> bool {
        self.row == other.row
    }

    pub fn is_same_col(&self, other: &ChessPosition) -> bool {
        self.col == other.col
    }

    pub fn is_same_diagonal(&self, other: &ChessPosition) -> bool {
        if self == other {
            return true;
        }

        let increments = vec![
            Self { row: 1, col: 1},
            Self { row: 1, col: -1},
            Self { row: -1, col: 1},
            Self { row: -1, col: -1}];


        for increment in increments.into_iter() {

            let mut candidate_position =  Self { row: self.row, col: self.col };
            while candidate_position.is_valid() {

                candidate_position = candidate_position + increment.clone();
                if &candidate_position == other {
                    return true;
                }
            }
        }
        
        false
    }

    fn is_valid(&self) -> bool {
        !(self.row < 0 ||
            self.row >= BOARD_SIZE ||
            self.col < 0 ||
            self.col >= BOARD_SIZE)
    }
}

impl Add for ChessPosition {
    type Output = ChessPosition;

    fn add(self, other: ChessPosition) -> Self {
        Self {
            row: self.row + other.row,
            col: self.col + other.col,
        }
    }
}

impl Queen {
    pub fn new(position: ChessPosition) -> Self {
        Self {
            position
        }
    }

    pub fn can_attack(&self, other: &Queen) -> bool {
        self.position.is_same_diagonal(&other.position) ||
            self.position.is_same_row(&other.position) ||
            self.position.is_same_col(&other.position)
            
    }
}