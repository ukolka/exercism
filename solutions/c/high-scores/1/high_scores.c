#include <stdlib.h>
#include "high_scores.h"

/// Return the latest score.
int32_t latest(const int32_t *scores, size_t scores_len) {
    return scores[scores_len - 1];
}

/// Return the highest score.
int32_t personal_best(const int32_t *scores, size_t scores_len) {
    if (scores_len == 0) {
        return 0;
    }
    int32_t max = scores[0]; 

    for (size_t i = 1; i < scores_len; i++) {
        if (scores[i] > max) {
            max = scores[i];
        }
    }
    return max;
}

static int compare_scores(const void* a, const void* b) {
    const int32_t* intA = (const int32_t*) a; 
    const int32_t* intB = (const int32_t*) b; 
    return *intB - *intA;
}
/// Write the highest scores to `output` (in non-ascending order).
/// Return the number of scores written.
size_t personal_top_three(const int32_t *scores, size_t scores_len,
                          int32_t *output) {
    int32_t* scoresCopy = malloc(sizeof(int32_t) * scores_len);
    for (size_t i = 0; i < scores_len; i++) {
        scoresCopy[i] = scores[i];
    }
    int (*cmp) (const void*, const void*) = compare_scores; 
    qsort(scoresCopy, scores_len, sizeof(const int32_t), cmp);

    size_t scores_written = 0;
    for (size_t i = 0; i < scores_len && scores_written < 3; i++) {
        output[scores_written++] = scoresCopy[i];
    }

    free(scoresCopy);
    scoresCopy = NULL;

    return scores_written;
}
