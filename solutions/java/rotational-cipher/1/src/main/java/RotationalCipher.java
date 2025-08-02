class RotationalCipher {
    private int shiftKey;
    RotationalCipher(int shiftKey) {
        this.shiftKey = shiftKey;
    }

    String rotate(String data) {
        StringBuilder out = new StringBuilder();
        
        for (char ch: data.toCharArray()) {
            if (Character.isAlphabetic(ch)) {
                boolean isUC = Character.isUpperCase(ch);
                int shift = isUC ? (ch - 'A') : (ch - 'a');
                shift += shiftKey;
                shift %= 26;
                out.append((char) ((isUC ? 'A' : 'a') + shift));
            } else {
                out.append(ch);
            }
        }

        return out.toString();
    }

}