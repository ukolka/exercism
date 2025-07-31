#[derive(Debug)]
pub struct DNA {
    sequence: String,
}

impl DNA {
    pub fn new(sequence: &str) -> Self {
        Self {
            sequence: sequence.to_string()
        }
    }

    pub fn to_rna(&self) -> Result<RNA, &str> {
        let mut rv = String::with_capacity(self.sequence.len());

        for nucleotide in self.sequence.chars() {
            let rna_nucleotide = match nucleotide {
                'G' => Some('C'),
                'C' => Some('G'),
                'T' => Some('A'),
                'A' => Some('U'),
                _ => None
            };

            if rna_nucleotide.is_none() {
                return Err("Corrupt DNA");
            }

            rv.push(rna_nucleotide.unwrap());
        }

        Ok(RNA::new(rv.as_str()))
    }
}

impl PartialEq for DNA {
    fn eq(&self, other: &DNA) -> bool {
        self.sequence == other.sequence
    }
}

#[derive(Debug)]
pub struct RNA {
    sequence: String,
}

impl RNA {
    pub fn new(sequence: &str) -> Self {
        Self {
            sequence: sequence.to_string()
        }
    }

    pub fn to_dna(&self) -> Result<DNA, &str> {
        let mut rv = String::with_capacity(self.sequence.len());

        for nucleotide in self.sequence.chars() {
            let dna_nucleotide = match nucleotide {
                'C' => Some('G'),
                'G' => Some('C'),
                'A' => Some('T'),
                'U' => Some('A'),
                _ => None
            };

            if dna_nucleotide.is_none() {
                return Err("Corrupt RNA");
            }

            rv.push(dna_nucleotide.unwrap());
        }

        Ok(DNA::new(rv.as_str()))
    }
}

impl PartialEq for RNA {
    fn eq(&self, other: &RNA) -> bool {
        self.sequence == other.sequence
    }
}