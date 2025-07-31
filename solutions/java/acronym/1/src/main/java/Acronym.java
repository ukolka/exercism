class Acronym {
    private String phrase;
    
    Acronym(String phrase) {
        this.phrase = phrase;
    }

    String get() {
        char chars[] = this.phrase.toCharArray();
        int length = this.phrase.length();

        StringBuilder out = new StringBuilder();

        char prev_ch = ' ';
        
        for (int i = 0; i < length; i++) {
            char ch = chars[i];

            if (Character.isWhitespace(prev_ch) || prev_ch == '-') {
                out.append(Character.toUpperCase(ch));
            }
            
            prev_ch = ch;
        }

        return out.toString();
    }

}