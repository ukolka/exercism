#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "rail_fence_cipher.h"

typedef struct {
    size_t capacity;
    size_t length; // read position
    size_t current; // write position
    char* values;
} rail_t;

static rail_t make_rail(size_t capacity) { 
    rail_t rail;
    rail.values = calloc(capacity, sizeof(int));
    assert(rail.values != NULL);
    rail.capacity = capacity;
    rail.length = 0;
    rail.current = 0;
    for (size_t i = 0; i < capacity; i++) {
        rail.values[i] = '\0';
    }
    return rail;
}

static void append_to_rail(rail_t* rail, int value) {
    assert(rail->capacity >= rail->length);
    rail->values[rail->length++] = value;
}

static char next_rail_char(rail_t* rail) {
    return rail->values[rail->current++];
}

static rail_t* init_rails(size_t railsCount, size_t len) {
    rail_t* rails = calloc(railsCount, sizeof(rail_t));
    for (size_t i = 0; i < railsCount; i++) {
        rails[i] = make_rail(len);
    }
    return rails;
}

static void free_rail(rail_t rail) {
    free(rail.values);
    rail.values = NULL;
    rail.length = 0;
    rail.current = 0;
}

static void free_rails(rail_t* rail, size_t count) {
    for (size_t i = 0; i < count; i++) {
        free_rail(rail[i]);
    }
    free(rail);
}

#define FOR_EACH_IN_ZIG_ZAG(action) \
    for (size_t i = 0, rail = 0, direction = 1; i < len; i++) { \
        (action); \
        if (rail == 0) { \
            direction = 1; \
        } \
        if (rail == railsCount - 1) { \
            direction = -1; \
        } \
        rail += direction; \
    } 

static void fill_rails(rail_t rails[], size_t railsCount, char* text) {
    size_t len = strlen(text);
    FOR_EACH_IN_ZIG_ZAG(append_to_rail(&rails[rail], text[i]));
}

char *encode(char *text, size_t railsCount) {
    size_t len = strlen(text);
    rail_t result = make_rail(len);

    rail_t* rails = init_rails(railsCount, len);
    fill_rails(rails, railsCount, text);

    for (size_t i = 0; i < railsCount; i++) {
        for (size_t j = 0; j < rails[i].length; j++) {
            append_to_rail(&result, rails[i].values[j]);
        }
    }

    free_rails(rails, railsCount);

    return result.values;
}

char *decode(char *ciphertext, size_t railsCount) {
    size_t len = strlen(ciphertext);
    rail_t result = make_rail(len);
    
    rail_t* rails = init_rails(railsCount, len);
    // idle pass (encodes the encoded string) 
    // in which string length per rail is figured out
    fill_rails(rails, railsCount, ciphertext);

    for (size_t i = 0, offset = 0; i < railsCount; i++) {
        // using the sting lengths for each rail
        // copy the ciphertext into them 
        memcpy(rails[i].values, &ciphertext[offset], rails[i].length);
        offset += rails[i].length;
    }

    FOR_EACH_IN_ZIG_ZAG(
        append_to_rail(&result, next_rail_char(&rails[rail])));

    free_rails(rails, railsCount);

    return result.values;
}

#undef FOR_EACH_IN_ZIG_ZAG
