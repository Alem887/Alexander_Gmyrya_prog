#include "sort.hpp"

void ag::sortings::merge (int* const arr, int left, int mid, int right) {
    const int size = right - left + 1;
    int* temp = new int[size];
    int i = left;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= right) {
        if (arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    for (int n = 0; n < size; n++) {
        arr[left + n] = temp[n];
    }
    delete[] temp;
}

void ag::sortings::merge_sort (int* const arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
    ag::sortings::merge_sort (arr, left, mid);
    ag::sortings::merge_sort(arr, mid + 1, right);
    ag::sortings::merge(arr, left, mid, right);
    }
}