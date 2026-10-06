#pragma once
#include <Registro.h>

void merge2(std::vector<Registro *> &array, int first, int middle, int last) {
    int nL = middle - first + 1;
    int nR = last - middle;
    std::vector<Registro*> left;
    std::vector<Registro*> right;
        
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
        // Equivalent to left[i] <= right[j]
        // Preserves date order for equal IPs (Stable)
        if (!right[j]->compareIpKeyLT(*left[i])) {
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
    while (j < nR) {
        array[k] = right[j];
        j++;
        k++;
    }
}
void mergeSortByIpKey(std::vector<Registro *> &array, int first, int last) {
  if (first >= last)
    return;
  int middle = (first + last) / 2;
  mergeSortByIpKey(array, first, middle);
  mergeSortByIpKey(array, middle + 1, last);
  merge2(array, first, middle, last);
}