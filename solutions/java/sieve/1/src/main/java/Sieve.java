import java.util.List;
import java.util.ArrayList;
import java.util.stream.Collectors;

class Sieve {
    private ArrayList<PrimeCandidate> candidates;
    private int maxPrime;

    Sieve(int maxPrime) {
        this.maxPrime = maxPrime;
        this.initCandidates();
        this.sieve();
    }

    List<Integer> getPrimes() {
        return this.candidates.stream()
            .filter(candidate -> candidate.isPrime())
            .map(PrimeCandidate::getValue)
            .collect(Collectors.toList());
    }

    private void initCandidates() {
        this.candidates = new ArrayList<PrimeCandidate>();
        for (int i = 2; i <= this.maxPrime; i++)
            this.candidates.add(new PrimeCandidate(i));
    }

    private void sieve() {
        for (int i = 0; i < this.candidates.size(); i++) {
            PrimeCandidate candidate = this.candidates.get(i);
            if (candidate.isPrime())
                this.markMultiplesOf(i, candidate);
        }
    }

    private void markMultiplesOf(int position, PrimeCandidate candidate) {
        int i = position + candidate.getValue();
    
        for (; i < this.candidates.size(); i += candidate.getValue()) {
            PrimeCandidate multiple = this.candidates.get(i);
            multiple.markNotPrime();
        }
    }
}