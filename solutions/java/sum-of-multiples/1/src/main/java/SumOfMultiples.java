import java.util.HashSet;
import java.util.Iterator;

class SumOfMultiples {
    private int number;
    private int set[];
    
    SumOfMultiples(int number, int[] set) {
        this.number = number;
        this.set = set;
    }

    int getSum() {
        HashSet<Integer> multiples = new HashSet<Integer>();
        for (int n: this.set)
            this.fillSeqFor(n, multiples);
        
        Iterator<Integer> iter = multiples.iterator();

        int sum = 0;
        while (iter.hasNext())
            sum += iter.next();

        return sum;
    }

    private void fillSeqFor(int n, HashSet<Integer> multiples) {
        for (int i = n; i < this.number; i += n)
            multiples.add(i);
    }

}