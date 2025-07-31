class TwelveDays {
    private static String NTH_DAY[] = {
        "first",
        "second",
        "third",
        "fourth",
        "fifth",
        "sixth",
        "seventh",
        "eighth",
        "ninth",
        "tenth",
        "eleventh",
        "twelfth"
    };

    private static String COUNT[] = {
        " a Partridge in a Pear Tree.",
        " two Turtle Doves,",
        " three French Hens,",
        " four Calling Birds,",
        " five Gold Rings,",
        " six Geese-a-Laying,",
        " seven Swans-a-Swimming,",
        " eight Maids-a-Milking,",
        " nine Ladies Dancing,",
        " ten Lords-a-Leaping,",
        " eleven Pipers Piping,",
        " twelve Drummers Drumming,"
    };
    
    String verse(int verseNumber) {
        StringBuilder out = new StringBuilder(String.format("On the %s day of Christmas my true love gave to me,",
                                                            NTH_DAY[verseNumber - 1]));
        int i = verseNumber - 1;
        for (; i > 0; i--)
            out.append(COUNT[i]);

        if (verseNumber > 1)
            out.append(" and");

        out.append(COUNT[0]);

        out.append('\n');
        
        return out.toString();
    }

    String verses(int startVerse, int endVerse) {
        StringBuilder out = new StringBuilder();
        for (int i = startVerse; i <= endVerse; i++) {
            out.append(this.verse(i));
            if (i < endVerse)
                out.append("\n");
        }
        return out.toString();
    }
    
    String sing() {
        return this.verses(1, 12);
    }
}