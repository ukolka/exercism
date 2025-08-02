class RaindropConverter {

    String convert(int number) {
        StringBuilder out = new StringBuilder();
        boolean is_pling = number % 3 == 0;
        boolean is_plang = number % 5 == 0;
        boolean is_plong = number % 7 == 0;
        if (is_pling) {
            out.append("Pling");
        }

        if (is_plang) {
            out.append("Plang");
        }

        if (is_plong) {
            out.append("Plong");
        }

        if (!is_pling && !is_plang && !is_plong) {
            out.append(new Integer(number).toString());
        }

        return out.toString();
    }

}