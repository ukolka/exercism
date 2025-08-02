#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef int buffer_value_t;

typedef struct {
    size_t writeIdx;
    size_t readIdx;
    size_t capacity;
    size_t occupancy;
    buffer_value_t* values;
} circular_buffer_t;

circular_buffer_t* new_circular_buffer(size_t capacity);
int16_t read(circular_buffer_t* buffer, buffer_value_t* result);
int16_t write(circular_buffer_t* buffer, buffer_value_t value);
int16_t overwrite(circular_buffer_t* buffer, buffer_value_t value);
void delete_buffer(circular_buffer_t* buffer);
void clear_buffer(circular_buffer_t* buffer);

#endif
