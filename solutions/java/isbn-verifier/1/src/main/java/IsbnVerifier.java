class IsbnVerifier {

    boolean isValid(String stringToVerify) {
        int currentMultiplier = 10;
        int sum = 0;
        int digitCount = 0;
        for (char ch: stringToVerify.toCharArray()) {
            if (ch == '-') continue;
            if (currentMultiplier == 0) return false;

            digitCount += 1;

            if (digitCount < 10 && ch == 'X') return false;
            
            sum += this.getDigit(ch) * currentMultiplier;
            currentMultiplier -= 1;            
        }

        return digitCount == 10 && sum % 11 == 0;
    }

    private int getDigit(char ch) {
        if (ch == 'X') return 10;
        return ch - '0';
    }

}