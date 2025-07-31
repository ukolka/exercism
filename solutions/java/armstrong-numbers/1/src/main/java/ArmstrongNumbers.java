import java.util.*;

class ArmstrongNumbers {
    
    boolean isArmstrongNumber(int numberToCheck) {
        if (numberToCheck < 10) {
            return true;
        }

        ArrayList digits = this.getDigits(numberToCheck);

        return this.armstrongSum(digits) == numberToCheck;
    }

    int armstrongSum(ArrayList digits) {
        int sum = 0;
        int exp = digits.size();
        Iterator d = digits.iterator();
        
        while (d.hasNext()) {
            int digit = (int) d.next();
            sum += Math.pow(digit, exp);
        }
        return sum;
    }

    ArrayList getDigits(int number) {
        ArrayList digits = new ArrayList();
        int copy = number;

        while (copy > 0) {
            digits.add(copy % 10);
            copy /= 10;
        }
        
        return digits;
    }

}