#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "pythagorean_triplet.h"

static triplets_t* init_triplets() {
    triplets_t* triplets = realloc(NULL, sizeof(triplets_t));
    triplets->count = 0;
    return triplets;
}

triplets_t* triplets_with_sum(unsigned int sum) {
    unsigned int minSquareOf = 3;

    if (sum < minSquareOf) {
        return NULL;
    }

    triplets_t* triplets = init_triplets();

    for (unsigned int c = minSquareOf + 1; c < sum; c++) {
        unsigned int squareC = c * c;
        
        for (unsigned int b = minSquareOf; b < c; b++) { 
            unsigned int squareB = b * b;    
            unsigned int candidateSquareA = squareC - squareB;
            unsigned int candidateA = sqrt(candidateSquareA);

            if (candidateSquareA < squareB && 
                candidateA * candidateA == candidateSquareA && 
                c + b + candidateA == sum) {

                    if (triplets->count < MAX_TRIPLET_COUNT) {
                        triplet_t triplet = {
                            .a = candidateA,
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
    triplets = realloc(triplets, 0);
}
