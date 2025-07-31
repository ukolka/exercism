class Scrabble {
    private String word;
    
    Scrabble(String word) {
        this.word = word;
    }

    int getScore() {
        int score = 0;

        for (char ch: this.word.toCharArray()) {
            score += this.getCharScore(ch);
        }

        return score;
    }

    int getCharScore(char ch) {
        String scoreMap[] = {
            "",
            "AEIOULNRST",
            "DG",
            "BCMP",
            "FHVWY",
            "K",
            "",
            "",
            "JX",
            "",
            "QZ"
        };

        for (int score = 0; score < 11; score++) {
            if (scoreMap[score].indexOf(Character.toUpperCase(ch)) >= 0) {
                return score;
            }
        }
        
        return 0;
    }

}