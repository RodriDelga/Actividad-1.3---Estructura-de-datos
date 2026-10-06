#pragma once
#include <vector>
#include <Date.hpp>
// Busca el índice del primer elemento cuya fecha no es anterior a target.
// array: el vector ordenado donde se busca (no se modifica).
// target: la fecha de referencia a comparar.
// Retorna: el índice del primer elemento con fecha >= target.
// Complejidad: O(log n)
template<typename T>
int lowerBoundDate(const std::vector<T> &array, Date& dateStart) {
    int startMonth = dateStart.month;
    int startDay = dateStart.day;
    int low = 0;
    int high = static_cast<int>(array.size());

    while(low < high) {
        int middle = low + (high - low)/2;

        if (array[middle]->getMes() < startMonth || (array[middle]->getMes() == startMonth && array[middle]->getDia() < startDay)) {
            low = middle + 1;
        } else {
            high = middle;
        }
    }

    return low;
}

// Busca el índice del primer elemento cuya fecha es posterior a target.
// array: el vector ordenado donde se busca (no se modifica).
// target: la fecha de referencia a comparar.
// Retorna: el índice del primer elemento con fecha > target.
// Complejidad: O(log n)
template<typename T>
int upperBoundDate(const std::vector<T> &array, Date& dateEnd ) {
    int endMonth = dateEnd.month;
    int endDay = dateEnd.day;
    int low = 0;
    int high = static_cast<int>(array.size());

    while(low < high) {
        int middle = low + (high - low)/2;

        if (array[middle]->getMes() < endMonth || (array[middle]->getMes() == endMonth && array[middle]->getDia() < endDay + 1)) {
            low = middle + 1;
        } else {
            high = middle;
        }
    }

    return low;
}