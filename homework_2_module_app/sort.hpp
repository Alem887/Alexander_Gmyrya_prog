#ifndef SORT_HPP
#define SORT_HPP

namespace ag {
	namespace sortings {
		void merge_sort (int* const arr, int left, int right);
        void merge (int* const arr, int left, int mid, int right);
	}
}

#endif