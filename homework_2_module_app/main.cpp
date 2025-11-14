#include "print.hpp"
#include "sort.hpp"

int main() {
    int arr[] = {4, 65, 12, 7, 23, 11};
    const int arr_size = sizeof(arr)/sizeof(arr[0]);
	
	ag::print_array("Массив до сортировки:", arr, arr_size);
    
    ag::sortings::merge_sort(arr, 0, arr_size - 1);

    ag::print_array("Массив после сортировки:", arr, arr_size);

    return 0;
}