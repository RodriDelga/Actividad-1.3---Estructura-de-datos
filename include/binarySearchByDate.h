#pragma once
#include <vector>
#include "Date.h"

// Busca el indice del primer elemento cuya fecha no es anterior a dateStart.
// array: el vector ordenado donde se busca (no se modifica).
// dateStart: la fecha de referencia a comparar.
// Retorna: el indice del primer elemento con fecha >= dateStart.
// Complejidad: O(log n)
template<typename T>
int lowerBoundDate(const std::vector<T> &array, const Date &dateStart) {
    int low = 0;
    int high = static_cast<int>(array.size());

    while (low < high) {
        int middle = low + (high - low) / 2;

        if (array[middle]->getFecha() < dateStart) {
            low = middle + 1;
        } else {
            high = middle;
        }
    }

    return low;
}

// Busca el indice del primer elemento cuya fecha es posterior a dateEnd.
// array: el vector ordenado donde se busca (no se modifica).
// dateEnd: la fecha de referencia a comparar.
// Retorna: el indice del primer elemento con fecha > dateEnd.
// Complejidad: O(log n)
template<typename T>
int upperBoundDate(const std::vector<T> &array, const Date &dateEnd) {
    int low = 0;
    int high = static_cast<int>(array.size());

    while (low < high) {
        int middle = low + (high - low) / 2;

        if (!(dateEnd < array[middle]->getFecha())) {
            low = middle + 1;
        } else {
            high = middle;
        }
    }

    return low;
}