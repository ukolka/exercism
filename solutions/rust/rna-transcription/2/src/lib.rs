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
                'G' => 'C',
                'C' => 'G',
                'T' => 'A',
                'A' => 'U',
                _ => { return Err("Corrupt DNA"); },
            };

            rv.push(rna_nucleotide);
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
                'C' => 'G',
                'G' => 'C',
                'A' => 'T',
                'U' => 'A',
                _ => { return Err("Corrupt RNA"); },
            };

            rv.push(dna_nucleotide);
        }

        Ok(DNA::new(rv.as_str()))
    }
}

impl PartialEq for RNA {
    fn eq(&self, other: &RNA) -> bool {
        self.sequence == other.sequence
    }
}