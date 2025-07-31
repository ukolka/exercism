public class PangramChecker {

    public boolean isPangram(String input) {
        int seenSoFar = 0x00000000;

        for (char c: input.toCharArray()) {
            if (!Character.isLetter(c)) {
                continue;
            }
            
            int offset = Character.toLowerCase(c) - 'a';
            int mask = 0x00000001;
            mask <<= offset;
            
            seenSoFar |= mask;

            if (seenSoFar == 0x03FFFFFF) {
                return true;
            }
        }
        
        return false;
    }

}