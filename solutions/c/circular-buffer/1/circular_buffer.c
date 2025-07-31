#include <errno.h>
#include <stdio.h>
#include "circular_buffer.h"

circular_buffer_t* new_circular_buffer(size_t capacity) {
    circular_buffer_t* buffer = realloc(NULL, sizeof(circular_buffer_t));     
    buffer->writeIdx = capacity - 1;
    buffer->readIdx = capacity - 1;
    buffer->capacity = capacity;
    buffer->occupancy = 0;
    buffer->values = realloc(NULL, sizeof(buffer_value_t) * capacity);
    
    return buffer;
}

void delete_buffer(circular_buffer_t* buffer) {
    buffer->values = realloc(buffer->values, 0);
    buffer = realloc(buffer, 0);
}

int16_t read(circular_buffer_t* buffer, buffer_value_t* result) {
    if (buffer->occupancy == 0) {
        errno = ENODATA;
        return EXIT_FAILURE;
    }

    buffer->occupancy--;
    buffer->readIdx = (buffer->readIdx + 1) % buffer->capacity;
    *result = buffer->values[buffer->readIdx];
    return EXIT_SUCCESS;
}

int16_t write(circular_buffer_t* buffer, buffer_value_t value) {
    if (buffer->occupancy == buffer->capacity) {
        errno = ENOBUFS;
        return EXIT_FAILURE;
    }

    buffer->occupancy++;
    buffer->writeIdx = (buffer->writeIdx + 1) % buffer->capacity;
    buffer->values[buffer->writeIdx] = value;
    return EXIT_SUCCESS;
}

int16_t overwrite(circular_buffer_t* buffer, buffer_value_t value) {
    if (buffer->occupancy < buffer->capacity) {
        buffer->occupancy++;
        buffer->writeIdx = (buffer->writeIdx + 1) % buffer->capacity;
        buffer->values[buffer->writeIdx] = value;
    } else {
        buffer->readIdx = (buffer->readIdx + 1) % buffer->capacity;
        buffer->values[buffer->readIdx] = value;
    }

    return EXIT_SUCCESS;
}

void clear_buffer(circular_buffer_t* buffer) {
    buffer->readIdx = 0;
    buffer->writeIdx = 0;
    buffer->occupancy = 0;
}


