#include <stdlib.h>
#include "pythagorean_triplet.h"

static triplets_t* init_triplets(void) {
    triplets_t* triplets = malloc(sizeof(triplets_t));
    if (triplets == NULL) {
        return NULL;
    }
    triplets->count = 0;
    return triplets;
}

triplets_t* triplets_with_sum(unsigned int sum) {
    unsigned int minSquareOf = 3;

    if (sum < minSquareOf) {
        return NULL;
    }

    triplets_t* triplets = init_triplets();
    if (triplets == NULL) {
        return NULL;
    }

    for (unsigned int c = minSquareOf + 1; c < sum; c++) {
        unsigned int squareC = c * c;
        
        for (unsigned int b = minSquareOf; b < c; b++) { 
            unsigned int squareB = b * b;    
            unsigned int a = sum - c - b;
            unsigned int squareA = a * a;

            if (a < b && squareA + squareB == squareC) {
                    if (triplets->count < MAX_TRIPLET_COUNT) {
                        triplet_t triplet = {
                            .a = a,
                            .b = b,
                            .c = c
                        };
                        triplets->triplets[triplets->count++] = triplet;
                    }
            }
        }

    }

    return triplets;
}

void free_triplets(triplets_t* triplets) {
    free(triplets);
    triplets = NULL;
}
