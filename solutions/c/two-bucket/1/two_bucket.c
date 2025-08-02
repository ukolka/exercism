//#include <stdio.h>
#include "two_bucket.h"


static bool is_empty(bucket_t* bucket) {
    return bucket->content == 0;
}

static bool is_full(bucket_t* bucket) {
    return bucket->content == bucket->size;
}

static void pour_between(bucket_t* from, bucket_t* to) {
    bucket_liters_t litersCanTake = to->size - to->content;
    bucket_liters_t litersToPour = from->content;

    if (litersToPour > litersCanTake) {
        litersToPour = litersCanTake;
    }

    from->content -= litersToPour;
    to->content += litersToPour;
}

static bool check_legal(bucket_t* a, bucket_t* b, bucket_id_t start_bucket_id) {
    bucket_t* start_bucket = a;
    bucket_t* end_bucket = b;

    if (start_bucket_id == end_bucket->id) {
        end_bucket = a;
        start_bucket = b;
    }

    return !(is_empty(start_bucket) && is_full(end_bucket));
}

static bucket_result_t bounce(
    bucket_t* start_bucket,
    bucket_t* end_bucket,
    bucket_liters_t goal_volume,
    bucket_id_t start_bucket_id
) {

    bucket_result_t result = {
        .possible = false,
        .move_count = 1,
        .goal_bucket = BUCKET_ID_1,
        .other_bucket_liters = 0
    };
    
    do {
        // check for solution
        if (start_bucket->content == goal_volume) {
            result.possible = true;
            result.goal_bucket = start_bucket->id;
            result.other_bucket_liters = end_bucket->content;
            //printf("found in start bucket\n");
            break;
        } else if (end_bucket->content == goal_volume) {
            result.possible = true;
            result.goal_bucket = end_bucket->id;
            result.other_bucket_liters = start_bucket->content;
            //printf("found in end bucket\n");
            break;
        }

        // make the moves
        if (!is_empty(start_bucket) && !is_full(end_bucket)) {
            //printf("pour to end bucket\n");
            pour_between(start_bucket, end_bucket);
        } else if (is_empty(start_bucket)) {
            //printf("fill up start bucket\n");
            start_bucket->content = start_bucket->size;
        } else if (is_full(end_bucket)) {
            //printf("empty end bucket\n");
            end_bucket->content = 0;
        }
        result.move_count++;

        //printf("move: %d, %d-bucket: %d, %d-bucket: %d\n", 
            //result.move_count, 
            //start_bucket->id,
            //start_bucket->content,
            //end_bucket->id,
            //end_bucket->content);

        if (!check_legal(start_bucket, end_bucket, start_bucket_id)) {
            result.possible = false;
            return result;
        }
    } while (!(is_full(end_bucket) && is_empty(start_bucket)));

    return result;
}

bucket_result_t measure(bucket_liters_t bucket_1_size,
                        bucket_liters_t bucket_2_size,
                        bucket_liters_t goal_volume, 
                        bucket_id_t start_bucket_id) {

    bucket_t bucket1 = {
        .id = BUCKET_ID_1,
        .size = bucket_1_size,
        .content = 0
    };

    bucket_t bucket2 = {
        .id = BUCKET_ID_2,
        .size = bucket_2_size,
        .content = 0
    };

    bucket_t* start_bucket = &bucket2;
    bucket_t* end_bucket = &bucket1;
    if (start_bucket_id == BUCKET_ID_1) {
        start_bucket = &bucket1;
        end_bucket = &bucket2;
    }

    //printf("goal value: %d, start id: %d\n", goal_volume, start_bucket_id); 
    //printf("size %d-bucket: %d, size %d-bucket: %d\n", 
        //start_bucket->id,
        //start_bucket->size,
        //end_bucket->id,
        //end_bucket->size);


    start_bucket->content = start_bucket->size;
    end_bucket->content = 0;
    //printf("------------------\n");
    //printf("move: 1, %d-bucket: %d, %d-bucket: %d\n", 
        //start_bucket->id,
        //start_bucket->content,
        //end_bucket->id,
        //end_bucket->content);
    bucket_result_t start_to_end = bounce(
        start_bucket,
        end_bucket,
        goal_volume,
        start_bucket_id);

    start_bucket->content = start_bucket->size;
    end_bucket->content = 0;
    //printf("------------------\n");
    //printf("move: 1, %d-bucket: %d, %d-bucket: %d\n", 
        //start_bucket->id,
        //start_bucket->content,
        //end_bucket->id,
        //end_bucket->content);
    bucket_result_t end_to_start = bounce(
        end_bucket,
        start_bucket,
        goal_volume,
        start_bucket_id);

    if (start_to_end.possible && end_to_start.possible) {
        return start_to_end.move_count < end_to_start.move_count ?
            start_to_end : end_to_start;
    }
    if (start_to_end.possible) {
        return start_to_end;
    }
    return end_to_start;
}
