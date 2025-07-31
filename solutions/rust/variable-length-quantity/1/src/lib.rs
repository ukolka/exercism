const VALUE_MASK: u32 = 0x7F;
const HAS_NEXT_MASK: u32 = 0x80;
const MAX_BYTES: usize = 5;
const VALUE_SIZE: usize = 7;

/// Convert a list of numbers to a stream of bytes encoded with variable length encoding.
pub fn to_bytes(values: &[u32]) -> Vec<u8> {
    let mut rv = Vec::with_capacity(values.len());
    
    for value in values.iter() {
        rv.append(&mut int_to_bytes(*value));
    }

    rv
}

/// Given a stream of bytes, extract all numbers which are encoded in there.
pub fn from_bytes(bytes: &[u8]) -> Result<Vec<u32>, &'static str> {
    let mut rv = vec![];
    let mut output_byte = 0u64;
    let mut seen_next = false;
    
    for byte in bytes.iter() {
        let normalized = *byte as u64;
        let value = normalized & VALUE_MASK as u64;
        
        if normalized & HAS_NEXT_MASK as u64 == HAS_NEXT_MASK as u64 {
            seen_next = false;
            output_byte = output_byte | value;
            output_byte <<= VALUE_SIZE;
        } else {
            seen_next = true;
            if output_byte | value > std::u32::MAX as u64 {
                return Err("Overflow")
            }
            output_byte = output_byte | value;
            rv.push(output_byte as u32);
            output_byte = 0;
        }
    }

    if !seen_next {
        return Err("Incomplete byte sequence");
    }
    
    Ok(rv)
}

fn int_to_bytes(input: u32) -> Vec<u8> {
    let mut bytes = vec![0; MAX_BYTES];
    let mut msb = 0; // most significant byte

    for byte_no in 0..MAX_BYTES {
        let shift = byte_no * VALUE_SIZE;
        let byte = (input & (VALUE_MASK << shift)) >> shift;
        if byte > 0 {
            msb = byte_no;
        }
        bytes[byte_no] = byte;
    }

    msb += 1;
    
    bytes = bytes[0..msb].to_vec();
    for byte_no in 1..msb {
        bytes[byte_no] |= HAS_NEXT_MASK;
    }

    bytes.iter().rev()
        .map(|&byte| byte as u8)
        .collect::<Vec<u8>>()
}