#include "sortings.hpp"
#include <algorithm>

void ar::sortings::bubble_sort(int* const arr, const int size) {
	for (int i=0; i < size; ++i) {
        for (int j=0; j < size - 1; ++j) {
            if (arr[j] > arr[j+1]) {
                std::swap (arr[j], arr[j+1]);
            }
        }
    }
}