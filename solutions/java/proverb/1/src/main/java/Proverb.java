class Proverb {
    private String words[];
    private static final String FORMAT_MOST = "For want of a %s the %s was lost.\n";
    private static final String FORMAT_LAST = "And all for the want of a %s.";
    
    Proverb(String[] words) {
        this.words = words;
    }

    String recite() {
        StringBuilder out = new StringBuilder();
        
        for (int i = 0; i <= this.words.length - 2; i++) {
            out.append(String.format(FORMAT_MOST,
                                     words[i],
                                     words[i + 1]));
        }

        if (this.words.length > 0) {
            out.append(String.format(FORMAT_LAST, words[0]));
        }
        
        return out.toString();
    }

}