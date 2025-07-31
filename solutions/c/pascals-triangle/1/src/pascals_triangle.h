#ifndef PASCALS_TRIANGLE_H
#define PASCALS_TRIANGLE_H
#include <stdlib.h>

typedef size_t ** triangle;
typedef size_t * triangle_row;

triangle create_triangle(int rows);

void free_triangle(triangle t, size_t rows);

#endif