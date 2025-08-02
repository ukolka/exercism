import java.util.List;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;

class LuhnValidator {

    boolean isValid(String candidate) {
        List<Integer> digits;
        try {
            digits = this.getDigits(candidate);
            if (digits.size() <= 1) return false;
        } catch (IllegalArgumentException e) {
            return false;
        }

        Collections.reverse(digits);

        Iterator<Integer> iter = digits.iterator();

        int sum = 0;
        int index = 1;
        while (iter.hasNext()) {
            int digit = iter.next();
            if (index % 2 == 0) {
                digit = this.doubleDigit(digit);
            }

            sum += digit;
            index++;
        }

        return sum % 10 == 0;
    }

    private int doubleDigit(int digit) {
        digit *= 2;
        if (digit > 9) {
            digit -= 9;
        }
        return digit;
    }

    private List<Integer> getDigits(String candidate) {
        List<Integer> digits = new ArrayList<Integer>();
        for (char ch: candidate.toCharArray()) {
            if (!Character.isDigit(ch) && !Character.isWhitespace(ch))
                throw new IllegalArgumentException("bad char");
            
            if (Character.isDigit(ch)) {
                digits.add(ch - '0');
            }
        }
        return digits;
    }

}