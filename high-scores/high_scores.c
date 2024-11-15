#include "high_scores.h"

#include <stdlib.h>

/// Return the latest score.
int32_t latest(const int32_t* scores, size_t scores_len) {
    return scores[scores_len - 1];
}

static int compareFn(const void* x, const void* y) {
    int a = (int)(*(int*)x);
    int b = (int)(*(int*)y);

    if (a < b) return -1;
    else if (a == b) return 0;

    return 1;
}

/// Return the highest score.
int32_t personal_best(const int32_t* scores, size_t scores_len) {
    qsort((void*)scores, scores_len, sizeof(int32_t), compareFn);
    return scores[scores_len - 1];
}

/// Write the highest scores to `output` (in non-ascending order).
/// Return the number of scores written.
size_t personal_top_three(const int32_t* scores, size_t scores_len, int32_t* output) {
    qsort((void*)scores, scores_len, sizeof(int32_t), compareFn);

    int cursor = 0;

    for (int i = scores_len - 1; i >= 0; i--) {
        output[cursor++] = scores[i];
        if (cursor == 3) break;
    }

    return cursor;
}