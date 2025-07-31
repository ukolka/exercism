class NaturalNumber {
    private int number;
    
    NaturalNumber(int n) {
        if (n <= 0) {
            throw new IllegalArgumentException("You must supply a natural number (positive integer)");
        }
        this.number = n;
    }
    
    public Classification getClassification() {
        int sumOfFactors = 0;
        for (int candidateFactor = 1; candidateFactor <= this.number / 2; candidateFactor++) {
            if (this.number % candidateFactor == 0) {
                sumOfFactors += candidateFactor;
            }
        }

        if (sumOfFactors == this.number) {
            return Classification.PERFECT;
        }

        if (sumOfFactors > this.number) {
            return Classification.ABUNDANT;
        }

        return Classification.DEFICIENT;
    }

}