class RnaTranscription {

    String transcribe(String dnaStrand) {
        StringBuilder rna = new StringBuilder();
        
        for (char c: dnaStrand.toCharArray()) {
            switch (c) {
            case 'C':
                rna.append("G");
                break;
            case 'G':
                rna.append("C");
                break;
            case 'T':
                rna.append("A");
                break;
            case 'A':
                rna.append('U');
                break;
            }
        }

        return rna.toString();
    }

}