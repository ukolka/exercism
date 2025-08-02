import java.util.List;
import java.util.Set;
import java.util.HashSet;
import java.util.Collections;


class Matrix {

    private List<List<Integer>> data;
    private int rows;
    private int cols;
    private Set<MatrixCoordinate> saddlePoints;
    
    Matrix(List<List<Integer>> values) {
        this.data = values;
        this.rows = values.size();
        this.cols = this.rows > 0 ? values.get(0).size() : 0;
        this.saddlePoints = new HashSet();
    }

    Set<MatrixCoordinate> getSaddlePoints() {
        if (this.rows == 0) return Collections.emptySet();
        
        for (int row = 0; row < this.rows; row++)
            for (int col = 0; col < this.cols; col++) {
                MatrixCoordinate coord = new MatrixCoordinate(row, col);
                this.processSaddlePointCandidate(
                                                 this.data.get(row).get(col),
                                                 coord);
            }
        return this.saddlePoints;
    }

    private void processSaddlePointCandidate(int val, MatrixCoordinate coord) {
        int rowMax = val;
        int col = 0;
        int row = coord.getRow();
        int testVal;
        
        for (; col < this.cols; col++) {
            testVal = this.data.get(row).get(col);
            if (testVal > rowMax)
                rowMax = testVal;
        }

        int colMin = val;

        col = coord.getCol();
        row = 0;
        for (; row < this.rows; row++) {
            testVal = this.data.get(row).get(col);
            if (testVal < colMin)
                colMin = testVal;
        }

        if (rowMax == colMin && val == rowMax)
            this.saddlePoints.add(coord);
    }
    
}