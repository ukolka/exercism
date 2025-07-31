class CollatzCalculator {

    int computeStepCount(int start) {
        if (start < 1) throw new IllegalArgumentException("Only natural numbers are allowed");
        return this.computeStepCountRecursive(start, 0);
    }

    private int computeStepCountRecursive(int start, int stepAcc) {
        if (start == 1)
            return stepAcc;

        if (start % 2 == 0) {
            start /= 2;
        } else {
            start *= 3;
            start++;
        }

        return this.computeStepCountRecursive(start, ++stepAcc);
    }

}