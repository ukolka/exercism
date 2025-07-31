use std::fmt::Debug;

#[derive(Debug, Eq, PartialEq)]
pub enum Error {
    EmptyBuffer,
    FullBuffer,
}

pub struct CircularBuffer<T> {
    buffer: Vec<T>,
}

impl<T> CircularBuffer<T>
    where T: Debug
{
    pub fn new(size: usize) -> Self {
        Self {
            buffer: Vec::with_capacity(size),
        }
    }

    pub fn read(&mut self) -> Result<T, Error> {
        let val = self.buffer.pop();
        match val {
            Some(v) => Ok(v),
            None => Err(Error::EmptyBuffer),
        }
    }

    pub fn write(&mut self, item: T) -> Result<(), Error> {
        if self.buffer.capacity() == self.buffer.len() {
            return Err(Error::FullBuffer);
        }
        self.buffer.insert(0, item);
        Ok(())
    }

    pub fn clear(&mut self) {
        self.buffer.clear();
    }

    pub fn overwrite(&mut self, item: T) {
        let cap = self.buffer.capacity();
        let len = self.buffer.len();

        if cap > len {
            self.buffer.insert(0, item);
        } else if cap == len {
            self.buffer.pop();
            self.buffer.insert(0, item);
        }
    }
}