#include "binary_search.h"

const int* binary_search(int value, const int* arr, size_t length) {
    int left = 0, right = length - 1;
    int index = -1;
    while (left <= right) {
        int mid = left + ((right - left) / 2);

        if (arr[mid] == value) {
            index = mid;
            break;
        }
        else if (arr[mid] > value) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return index != -1 ? &arr[index] : NULL;
}