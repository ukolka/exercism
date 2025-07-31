#include "pascals_triangle.h"


triangle empty_triangle() {
  triangle t = malloc(sizeof(triangle));
  *t = malloc(sizeof(triangle_row));
  **t = 0;
  return t;
}

triangle_row first_row(size_t width) {
  triangle_row r = calloc(width, sizeof(size_t));
  *r = 1;
  return r;
}

triangle_row create_row(size_t width, triangle_row prev_row) {
  if (prev_row == NULL)
    return first_row(width);

  triangle_row r = malloc(width * sizeof(size_t));
  *r = 1;
  for (size_t elem_idx = 1; elem_idx < width; elem_idx++) {
    r[elem_idx] = prev_row[elem_idx - 1] + prev_row[elem_idx];
  }
  return r;
}

triangle create_triangle(int rows) {
  if (rows < 0) return NULL;
  
  if (rows == 0)
    return empty_triangle();

  triangle t = malloc(rows * sizeof(triangle_row));
  triangle_row prev_r = NULL;
  for (int row_n = 0; row_n < rows; row_n++) {
    triangle_row r = create_row(rows, prev_r);
    prev_r = r;
    t[row_n] = r;
  }

  return t;
}

void free_triangle(triangle t, size_t rows) {
  for (size_t i = 0; i < rows; i++)
    free(t[i]);
  free(t);
}