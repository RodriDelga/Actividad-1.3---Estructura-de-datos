/*
 * Description: Implementation of the recursive merge sort algorithm.
 * Author(s): A01648834, A01648281, A01645656, A01648448
 * Date: 3 de septiembre de 2026
 */

#pragma once
#include <vector>

// Purpose: Combines two contiguous sorted subarrays into a single ordered array.
// Parameters: 
//   array: the vector containing both subarrays, modified in place.
//   first: initial index of the first subarray.
//   middle: final index of the first subarray.
//   last: final index of the second subarray.
//   func: function to extract the comparable attribute.
// Return value: None.
template<typename T, typename Func>
void merge(std::vector<T> &array, int first, int middle, int last, Func func) {
	int leftSize = middle - first + 1;
	int rightSize = last - middle;
	std::vector<T> left = std::vector<T>();
	std::vector<T> right = std::vector<T>();
		
	for (int i = 0; i < leftSize; i++) {
		left.push_back(array[first + i]);
	}
		
	for (int i = 0; i < rightSize; i++) {
		right.push_back(array[middle + i + 1]);
	}
		
	int i = 0;
	int j = 0;
	int k = first;
		
	while (i < leftSize && j < rightSize) {
		if (func(left[i]) <= func(right[j])) {
			array[k] = left[i];
			i++;
		} else {
			array[k] = right[j];
			j++;
		}
		k++;
	}
		
	while (i < leftSize) {
		array[k] = left[i];
		i++;
		k++;
	}
	
	while (j < rightSize) {
		array[k] = right[j];
		j++;
		k++;
	}
}

// Purpose: Sorts an array in ascending order using recursive merge sort.
// Parameters: 
//   array: the vector to sort, modified in place.
//   first: initial index of the sorting range.
//   last: final index of the sorting range.
//   func: function to extract the comparable attribute.
// Return value: None.
template<typename T, typename Func>
void mergeSort(std::vector<T> &array, int first, int last, Func func) {
	if (first >= last) {
		return;
	}
	
	int middle = (first + last) / 2;
	mergeSort(array, first, middle, func);
	mergeSort(array, middle + 1, last, func);
	
	merge(array, first, middle, last, func);
}