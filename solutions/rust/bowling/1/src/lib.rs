pub struct BowlingGame {
    rolls: [Option<u16>; 21],
    current_roll: usize,
}

impl BowlingGame {
    pub fn new() -> Self {
        Self {
            rolls: [None; 21],
            current_roll: 0,
        }
    }
    
    pub fn roll(&mut self, pins: u16) -> Result<(),()> {
        if pins > 10 || self.is_done() || self.is_over_frame_limit(pins) {
            return Err(());
        }

        self.rolls[self.current_roll] = Some(pins);
        self.current_roll += 1;

        Ok(())
    }

    pub fn score(&self) -> Result<u16,()> {
        if !self.is_done() {
            return Err(());
        }
        
        let mut score = 0;
        let mut frame_index = 0;

        for _ in 0..10 {
            if self.is_strike(frame_index) {
                score += 10 + self.strike_bonus(frame_index);
                frame_index += 1;
            } else if self.is_spare(frame_index) {
                score += 10 + self.spare_bonus(frame_index);
                frame_index += 2;
            } else {
                score += self.frame_sum(frame_index);
                frame_index += 2;
            }
        }

        Ok(score)
    }

    fn is_done(&self) -> bool {
        let (frame_index, frame_count) = self.current_frame();

        if frame_count == 10 {
            if self.is_strike(frame_index) ||
                self.is_spare(frame_index) {
                    return self.rolls[frame_index + 2].is_some()
                } else {
                    return self.rolls[frame_index + 1].is_some()
                }
        }
        
        false
    }

    fn current_frame(&self) -> (usize, usize) {
        let mut frame_index = 0;
        let mut frame_count = 0;
        let mut prev_frame_index = frame_index;
        for _ in 0..10 {
            if self.rolls[frame_index].is_none() {
                return (prev_frame_index, frame_count);
            }
            
            prev_frame_index = frame_index;
            
            if self.is_strike(frame_index) {
                frame_index += 1;
                frame_count += 1;
            } else {
                frame_index += 2;
                frame_count += 1;
            }
        }

        (prev_frame_index, frame_count)
    }

    fn is_over_frame_limit(&self, pins: u16) -> bool {
        let (frame_index, frame_count) = self.current_frame();

        if frame_count == 10 {
            if self.current_roll == frame_index + 1 &&
                self.rolls[frame_index].unwrap_or(0) < 10 {
                    return self.frame_sum(frame_index) + pins > 10;
                }

            if self.current_roll == frame_index + 2 {
                if self.is_strike(frame_index) &&
                    !self.is_strike(frame_index + 1) {
                        return self.frame_sum(frame_index + 1) + pins > 10;
                    }

                if self.is_spare(frame_index) {
                    return self.frame_sum(frame_index) + pins > 20;
                }
            }
        } else {
            if self.current_roll == frame_index + 1 && !self.is_strike(frame_index) {
                return self.frame_sum(frame_index) + pins > 10;
            }
        }

        false
    }

    fn is_strike(&self, frame_index: usize) -> bool {
        self.rolls[frame_index] == Some(10)
    }

    fn is_spare(&self, frame_index: usize) -> bool {
        self.frame_sum(frame_index) == 10
    }

    fn strike_bonus(&self, frame_index: usize) -> u16 {
        self.frame_sum(frame_index + 1)
    }

    fn spare_bonus(&self, frame_index: usize) -> u16 {
        self.rolls[frame_index + 2].unwrap_or(0)
    }

    fn frame_sum(&self, frame_index: usize) -> u16 {
        self.rolls[frame_index].unwrap_or(0) +
            self.rolls[frame_index + 1].unwrap_or(0)
    }
}