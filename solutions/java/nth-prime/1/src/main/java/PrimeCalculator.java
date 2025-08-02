import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Iterator;

class PrimeCalculator {

    int nth(int nth) {
        if (nth < 1) throw new IllegalArgumentException("doh");
        
        LinkedList primes = new LinkedList();
        primes.addLast(2);

        int candidate = 3;
        while (primes.size() < nth) {
            if (this.isPrime(primes, candidate))
                primes.addLast(candidate);

            candidate++;
        }

        return (int) primes.peekLast();
    }

    private boolean isPrime(LinkedList primes, int candidate) {
        Iterator iter = primes.iterator();
        
        while (iter.hasNext())
            if (candidate % (int) iter.next() == 0)
                return false;

        return true;
    }
}