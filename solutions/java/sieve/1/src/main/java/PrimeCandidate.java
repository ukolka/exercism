class PrimeCandidate {
    private int value;
    private boolean is_prime;

    PrimeCandidate(int value) {
        this.value = value;
        this.is_prime = true;
    }

    public int getValue() {
        return this.value;
    }
    
    public boolean isPrime() {
        return this.is_prime;
    }

    public void markNotPrime() {
        this.is_prime = false;
    }
}