#include "two_bucket.h"

static bucket_t init_bucket(
    bucket_id_t id,
    bucket_liters_t size,
    bool is_filled
) {
    return (bucket_t) {
        .content = is_filled ? size : 0,
        .size = size,
        .id = id
    };
}

static bucket_result_t init_computable_result(
    int move_count,
    bucket_id_t result_bucket_id,
    bucket_liters_t other_bucket_liters
) {
    return (bucket_result_t) {
        .possible = true,
        .move_count = move_count,
        .goal_bucket = result_bucket_id,
        .other_bucket_liters = other_bucket_liters
    };
}

static bucket_result_t inverse_bucket(bucket_result_t result) {
    if (result.possible) {
        return init_computable_result(result.move_count,
            result.goal_bucket == BUCKET_ID_1 ?
                BUCKET_ID_2 : BUCKET_ID_1,
            result.other_bucket_liters);
    }
    return result;
}

bucket_result_t measure(
    bucket_liters_t bucket_1_size,
    bucket_liters_t bucket_2_size,
    bucket_liters_t goal_volume, 
    bucket_id_t start_bucket_id
) {
    #define IS_NOT_SOLVED (start_bucket.content != goal_volume && \
        end_bucket.content != goal_volume) 
    #define IMPOSSIBLE ((bucket_result_t) { .possible = false })
    #define IS_FINISHED (start_bucket.content == 0 && \
            end_bucket.content == end_bucket.size)

    if (goal_volume > bucket_1_size && goal_volume > bucket_2_size) {
        return IMPOSSIBLE;
    }

    if (start_bucket_id != BUCKET_ID_1) {
        return inverse_bucket(
            measure(bucket_2_size, bucket_1_size, goal_volume, BUCKET_ID_1));
    }

    bucket_t start_bucket = init_bucket(BUCKET_ID_1, bucket_1_size, true);
    bucket_t end_bucket = init_bucket(BUCKET_ID_2, bucket_2_size, false);
    
    int move_count = 1;
    while (IS_NOT_SOLVED && !IS_FINISHED) {
        move_count++;

        bucket_liters_t to_pour = end_bucket.size - end_bucket.content;
        if (start_bucket.content < to_pour) { to_pour = start_bucket.content; }

        if (end_bucket.size == goal_volume) {
            end_bucket.content = goal_volume;
        } else if (end_bucket.size == end_bucket.content) {
            end_bucket.content = 0;
        } else if (start_bucket.content == 0) {
            start_bucket.content = start_bucket.size;
        } else if (to_pour > 0) {
            start_bucket.content -= to_pour;
            end_bucket.content += to_pour;
        } 
    }

    if (IS_NOT_SOLVED) { return IMPOSSIBLE; }

    return start_bucket.content == goal_volume ?
        init_computable_result(
            move_count, start_bucket.id, end_bucket.content) :        
        init_computable_result(
            move_count, end_bucket.id, start_bucket.content);

    #undef IS_SOLVED
    #undef IMPOSSIBLE
    #undef IS_FINISHED
}
