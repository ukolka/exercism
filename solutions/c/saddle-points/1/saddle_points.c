#include <stdlib.h>
#include "saddle_points.h"


saddle_points_t* saddle_points(size_t rows, size_t cols, uint8_t matrix[rows][cols]) {
    saddle_points_t* result = malloc(sizeof(saddle_points_t));
    result->count = 0;

    for (size_t row = 0; row < rows; row++) {
        for (size_t col = 0; col < cols; col++) {
            uint8_t minInCol = matrix[row][col];
            uint8_t maxInRow = matrix[row][col];
            
            for (size_t testRow = 0; testRow < rows; testRow++) {
                if (minInCol > matrix[testRow][col]) {
                    minInCol = matrix[testRow][col];
                }
            }

            for (size_t testCol = 0; testCol < cols; testCol++) {
                if (maxInRow < matrix[row][testCol]) {
                    maxInRow = matrix[row][testCol];
                }
            }

            if (matrix[row][col] == minInCol && matrix[row][col] == maxInRow) {
                result->points[result->count].row = row + 1;
                result->points[result->count].column = col + 1;
                result->count++;
            }
        }
    }

    return result;
}

void free_saddle_points(saddle_points_t* spoints) {
    free(spoints);
}
