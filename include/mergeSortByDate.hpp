#pragma once
#include <vector>
// Combina dos sublistas contiguas y ordenadas de un vector en una sola lista ordenada.
// array: el vector que contiene ambas sublistas, se modifica in place.
// first: índice inicial de la primera sublista.
// middle: índice final de la primera sublista.
// last: índice final de la segunda sublista.
// Retorna: nada (el vector queda combinado y ordenado in place).
template<typename T>
void merge(std::vector<T> &array, int first, int middle, int last) {
	int nL = middle - first + 1;
	int nR = last - middle;
    std::vector<T> left;
    std::vector<T> right;
		
	for (int i = 0; i < nL; i++) {
		left.push_back(array[first + i]);
	}
		
	for (int i = 0; i < nR; i++) {
		right.push_back(array[middle + i + 1]);
	}
		
	int i = 0;
	int j = 0;
	int k = first;
		
	while (i < nL && j < nR) {
		if(*left[i] < *right[j]) {
			array[k] = left[i];
			i++;
		} else {
			array[k] = right[j];
			j++;
		}
		k++;
	}
		
	while (i < nL) {
		array[k] = left[i];
		i++;
		k++;
	}
	while(j < nR) {
		array[k] = right[j];
		j++;
		k++;
	}
}

// Ordena un vector de forma ascendente usando el algoritmo merge sort recursivo.
// array: el vector a ordenar, se modifica in place.
// first: índice inicial del rango a ordenar.
// last: índice final del rango a ordenar.
// Retorna: nada (el vector queda ordenado in place).
// Complejidad: O(n log n)
template<typename T>
void mergeSortByDate(std::vector<T> &array, int first, int last) {
		if(first >= last) return;
		int middle = (first + last)/2;
		mergeSortByDate(array, first, middle);
		mergeSortByDate(array, middle + 1, last);
		
		merge(array, first, middle, last);
}