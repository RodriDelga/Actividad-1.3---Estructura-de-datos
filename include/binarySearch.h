/*
 * Description: Binary search implementation to find upper and lower bounds in ordered arrays.
 * Author(s): A01648834, A01648281, A01645656, A01648448
 * Date: 3 de septiembre de 2026
 */

#pragma once
#include <vector>
#include "Date.h"

// Purpose: Finds the index of the first element whose date is not prior to the target.
// Parameters: 
//   array: the sorted vector where the search takes place.
//   target: the reference date/key to compare.
//   func: extraction function to get the comparable attribute.
// Return value: Index of the first element >= target.
template <typename T, typename V, typename Func>
int lowerBound(const std::vector<T> &array, const V &target, Func func) {
	int low = 0;
	int high = static_cast<int>(array.size());

	while (low < high) {
		int middle = low + (high - low) / 2;

		if (func(array[middle]) < target) {
			low = middle + 1;
		} else {
			high = middle;
		}
	}

	return low;
}

// Purpose: Finds the index of the first element whose date/value is strictly after the target.
// Parameters: 
//   array: the sorted vector where the search takes place.
//   target: the reference date/key to compare.
//   func: extraction function to get the comparable attribute.
// Return value: Index of the first element > target.
template <typename T, typename V, typename Func>
int upperBound(const std::vector<T> &array, const V &target, Func func) {
	int low = 0;
	int high = static_cast<int>(array.size());

	while (low < high) {
		int middle = low + (high - low) / 2;

		if (!(target < func(array[middle]))) {
			low = middle + 1;
		} else {
			high = middle;
		}
	}

	return low;
}