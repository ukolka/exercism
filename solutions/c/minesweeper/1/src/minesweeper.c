#include "minesweeper.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct {
  const char **minefield;
  size_t rows;
  size_t columns;
} minefield_t;

typedef struct {
  int row;
  int column;
} position_t;

bool is_legal_row(minefield_t minefield, int row) {
  return row >= 0 && row < ((int) minefield.rows);
}

bool is_legal_column(minefield_t minefield, int column) {
  return column >= 0 && column < ((int) minefield.columns);
}

size_t count_mines(minefield_t minefield, position_t position) {
  int first_row = position.row - 1;
  int last_row = position.row + 2;
  int first_column = position.column - 1;
  int last_column = position.column + 2;
  
  size_t count = 0; 
  for (int r = first_row; r < last_row; r++) {
    for (int c = first_column; c < last_column; c++) {
      if (!is_legal_row(minefield, r) ||
          !is_legal_column(minefield, c) ||
          (r == position.row && c == position.column))
        continue;

      if (minefield.minefield[r][c] == '*')
        count++;
    }
  }

  return count;
}

char **init_result(size_t rows, size_t columns) {
  char **result = malloc(rows * sizeof(char *));
  for (size_t i = 0; i < rows; i++) {
    result[i] = malloc((columns + 1) * sizeof(char));
    memset(result[i], ' ', columns);
    result[i][columns] = '\0';
  }
  return result;
}

char **annotate(const char **minefield, const size_t rows) {
  if (minefield == NULL || !rows)
    return NULL;
  
  size_t columns = strlen(minefield[0]);
  char **result = init_result(rows, columns);
  
  if (!columns)
    return result;

  minefield_t m = {
    minefield,
    rows,
    columns
  };
  
  for (size_t row = 0; row < rows; row++) {
    for (size_t column = 0; column < columns; column++) {
      position_t p = { row, column };

      if (minefield[row][column] != '*') {
        size_t mine_count = count_mines(m, p);
        if (mine_count > 0) 
          result[row][column] = '0' + mine_count;
        else
          result[row][column] = ' ';
      } else {
        result[row][column] = '*';
      }
    }
  }
    
  return result;
}