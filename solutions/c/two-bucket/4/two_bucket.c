#include <stdlib.h>
#include "two_bucket.h"
#include <stdio.h>

typedef struct {
    int a;
    int b;
    int gcd;
} bezout_result_t;

static void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// GCD with benefits.
static bezout_result_t bezout(
    bucket_liters_t bucket_1_size,
    bucket_liters_t bucket_2_size
) {
    if (bucket_1_size < bucket_2_size) {
        bezout_result_t result = bezout(bucket_2_size, bucket_1_size);
        swap(&result.a, &result.b);
        return result;
    }

    int prev_r, tmp, prev_s, prev_t;
    int curr_q, curr_r, curr_s, curr_t;

    prev_r = bucket_1_size;
    curr_r = bucket_2_size;
    prev_s = 1; curr_s = 0;
    prev_t = 0; curr_t = 1;

    while (curr_r > 0) {
        curr_q = prev_r / curr_r;

        tmp = curr_r;
        curr_r = prev_r % curr_r;
        prev_r = tmp;

        tmp = curr_s;
        curr_s = prev_s - curr_q * curr_s; 
        prev_s = tmp;

        tmp = curr_t;
        curr_t = prev_t  - curr_q * curr_t;
        prev_t = tmp;
    }

    return (bezout_result_t) {
        .a = prev_s,
        .b = prev_t,
        .gcd = prev_r
    };
}

static bucket_result_t actually_measure(
    bucket_liters_t bucket_1_size,
    bucket_liters_t bucket_2_size,
    bucket_liters_t goal_volume,
    bucket_id_t start_bucket_id,
    bucket_id_t other_bucket_id
) {
    // Can't fill more than one volume.
    if (bucket_1_size == bucket_2_size && bucket_2_size != goal_volume) {
        return (bucket_result_t) {.possible = false};
    }

    // Impossible goal.
    if (goal_volume > bucket_1_size && goal_volume > bucket_2_size) {
        return (bucket_result_t) {.possible = false};
    }

    // Shortcut: we already have the solution.
    if (goal_volume == bucket_1_size) {
        return (bucket_result_t) {
            .possible = true,
            .move_count = 1,
            .other_bucket_liters = 0,
            .goal_bucket = start_bucket_id 
        };
    }

    // Shortcut: the other bucket is the solution.
    if (goal_volume == bucket_2_size) {
        return (bucket_result_t) {
            .possible = true,
            .move_count = 2,
            .other_bucket_liters = bucket_1_size,
            .goal_bucket = other_bucket_id
        };
    }

    // Solve the linear Diophantine equation.
    bezout_result_t coeff = bezout(bucket_1_size, bucket_2_size);
    // Unfillable.
    if (goal_volume % coeff.gcd > 0) {
        return (bucket_result_t) {.possible = false};
    }

    // The above solution is for Bezout identity, so scale.
    int scale = goal_volume / coeff.gcd;
    coeff.a *= scale;
    coeff.b *= scale;

    while (coeff.a <= 0) {
        coeff.a += bucket_2_size / coeff.gcd;
        coeff.b -= bucket_1_size / coeff.gcd;
    }

    // Moves count to a solution, ending in the "other" bucket.
    // It's not the shortest solution though, sometimes it can 
    // be a couple of steps back.
    int moves_to_other = 2 * (abs(coeff.a) + abs(coeff.b));
    bool can_fit_start = bucket_1_size >= goal_volume;

    return (bucket_result_t) {
        .possible = true,
        .move_count = can_fit_start ? moves_to_other - 2 : moves_to_other,
        .goal_bucket = can_fit_start ? start_bucket_id : other_bucket_id, 
        .other_bucket_liters = can_fit_start ? bucket_2_size : 0  
    };
}

bucket_result_t measure(
    bucket_liters_t bucket_1_size,
    bucket_liters_t bucket_2_size,
    bucket_liters_t goal_volume,
    bucket_id_t start_bucket_id
) {
    if (start_bucket_id == BUCKET_ID_2) {
        return actually_measure(
            bucket_2_size,
            bucket_1_size,
            goal_volume,
            BUCKET_ID_2,
            BUCKET_ID_1
        );
    }
    return actually_measure(
        bucket_1_size,
        bucket_2_size,
        goal_volume,
        BUCKET_ID_1,
        BUCKET_ID_2
    );
}