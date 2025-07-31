class Triangle {
    private double a, b, c;

    
    Triangle(double side1, double side2, double side3) throws TriangleException {
        if (
            side1 < side2 + side3 && side2 < side1 + side3 &&
            side3 < side1 + side2
            ) {
            
            this.a = side1;
            this.b = side2;
            this.c = side3;
        } else {
            throw new TriangleException();
        }
    }

    boolean isEquilateral() {
        return this.a == this.b && this.b == this.c;
    }

    boolean isIsosceles() {
        return this.a == this.b || this.b == this.c || this.c == this.a;
    }

    boolean isScalene() {
        return !isIsosceles();
    }

}