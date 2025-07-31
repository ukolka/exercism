#ifndef PYTHAGOREAN_TRIPLET_H
#define PYTHAGOREAN_TRIPLET_H

#define MAX_TRIPLET_COUNT 16 

typedef struct {
    unsigned int a;
    unsigned int b;
    unsigned int c;
} triplet_t;

typedef struct {
    triplet_t triplets[MAX_TRIPLET_COUNT];
    unsigned int count;
} triplets_t;

triplets_t* triplets_with_sum(unsigned int sum);
void free_triplets(triplets_t* triplets);

#endif
