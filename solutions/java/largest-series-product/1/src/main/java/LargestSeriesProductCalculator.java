class LargestSeriesProductCalculator {
    private String number;
    LargestSeriesProductCalculator(String inputNumber) {
        for (char ch: inputNumber.toCharArray()) {
            if (!Character.isDigit(ch))
                throw new IllegalArgumentException("String to search may only contain digits.");
        }
        this.number = inputNumber;
    }

    long calculateLargestProductForSeriesLength(int numberOfDigits) {
        if (numberOfDigits < 0)
            throw new IllegalArgumentException("Series length must be non-negative.");
        if (numberOfDigits > this.number.length())
            throw new IllegalArgumentException("Series length must be less than or equal to the length of the string to search.");
        
        if (numberOfDigits == 0 || this.number.length() == 0) return 1;
        long max = Long.MIN_VALUE;
        for (int i = 0; i <= this.number.length() - numberOfDigits; i++) {

            String series = this.number.substring(i, i + numberOfDigits);
            long product = this.product(series);
            if (product > max)
                max = product;
        }
        return max;
    }

    private long product(String series) {
        if (series.length() == 0) return 0;
        long prod = 1;
        for (char ch: series.toCharArray()) {    
            prod *= ch - '0';
        }
        return prod;
    }
}