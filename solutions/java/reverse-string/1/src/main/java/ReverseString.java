class ReverseString {

    String reverse(String inputString) {
        if (inputString.length() == 0) {
            return inputString;
        }
        return this.reverse(inputString.substring(1))
            .concat(inputString.substring(0, 1));
    }
  
}