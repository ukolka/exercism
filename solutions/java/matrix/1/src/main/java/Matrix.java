class Matrix {
    private int matrix[];
    private int rows;
    private int columns;
    
    Matrix(String matrixAsString) {
        int i = 0;
        String rows[] = matrixAsString.split("\n");
        this.rows = rows.length;
        for (String row: rows) {
            String cols[] = row.split("\\s+");
            this.columns = cols.length;

            if (this.matrix == null) {
                this.matrix = new int[this.rows * this.columns];
            }
            
            for (String val: cols) {
                Integer intVal = Integer.parseInt(val);
                this.matrix[i++] = intVal;
            }
        }

    }

    int[] getRow(int rowNumber) {
        int result[] = new int[this.columns];
        
        int current = rowNumber * this.columns;
        int last = current + columns;
        int i = 0;
        for (; current < last; current++)
            result[i++] = this.matrix[current];
        
        return result;
    }

    int[] getColumn(int columnNumber) {
        int result[] = new int[this.rows];

        int current = columnNumber;
        int i = 0;

        for (; i < this.rows; current += this.columns)
            result[i++] =
                this.matrix[current];
        return result;                              
    }

    int getRowsCount() {
        return this.rows;
    }

    int getColumnsCount() {
        return this.columns;
    }
}