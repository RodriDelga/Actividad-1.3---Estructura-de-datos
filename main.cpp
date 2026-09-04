#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "OOPUtils.h"

/*
 * Programa: Ordenamiento y consulta por rango de fechas de una bitácora.
 * Lee un archivo de bitácora, lo ordena cronológicamente con merge sort,
 * permite consultar entradas dentro de un rango de fechas mediante
 * búsqueda binaria (lower bound / upper bound), y guarda el resultado
 * ordenado en un nuevo archivo.
 * Matrícula: A01648448
 * Fecha: 3 de septiembre de 2026
 */

// Convierte el nombre abreviado de un mes a su número correspondiente.
// m: cadena con el nombre del mes (por ejemplo "Jun", "Jul").
// Retorna: el número del mes (6-10), o 0 si no coincide con ninguno reconocido.
template<typename T>
int month(T m) {
    if(m == "Jun") return 6;
    else if (m == "Jul") return 7;
    else if (m == "Aug") return 8;
    else if (m == "Sep") return 9;
    else if (m == "Oct") return 10;
    else return 0;
}

// Compara dos entradas de bitácora para determinar su orden cronológico.
// left: la entrada izquierda a comparar.
// right: la entrada derecha a comparar.
// Retorna: true si left es cronológicamente anterior a right, false en caso contrario.
template<typename T>
bool comparsion(T left, T right) {

    std::vector<T> partesL = OOPUtils::split(left, " ");
    std::vector<T> partesR = OOPUtils::split(right, " ");

    std::vector<T> partesLHours = OOPUtils::split(partesL[2], ":");
    std::vector<T> partesRHours = OOPUtils::split(partesR[2], ":");

    if(month(partesL[0]) != month(partesR[0])) return month(partesL[0]) < month(partesR[0]);
    else if(std::stoi(partesL[1]) != std::stoi(partesR[1])) return std::stoi(partesL[1]) < std::stoi(partesR[1]);
    else if(std::stoi(partesLHours[0]) != std::stoi(partesRHours[0])) return std::stoi(partesLHours[0]) < std::stoi(partesRHours[0]);
    else if(std::stoi(partesLHours[1]) != std::stoi(partesRHours[1])) return std::stoi(partesLHours[1]) < std::stoi(partesRHours[1]);
    else if(std::stoi(partesLHours[2]) < std::stoi(partesRHours[2])) return true;
    else return false;
}

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
		if(comparsion(left[i], right[j])) {
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
void mergeSort(std::vector<T> &array, int first, int last) {
		if(first >= last) return;
		int middle = (first + last)/2;
		mergeSort(array, first, middle);
		mergeSort(array, middle + 1, last);
		
		merge(array, first, middle, last);
}

// Busca el índice del primer elemento cuya fecha no es anterior a target.
// array: el vector ordenado donde se busca (no se modifica).
// target: la fecha de referencia a comparar.
// Retorna: el índice del primer elemento con fecha >= target.
// Complejidad: O(log n)
template<typename T>
int lowerBound(const std::vector<T> &array, int &startMonth, int &startDay) {
    // min, max, avg are indices
    int low = 0;
    int high = static_cast<int>(array.size());

    while(low < high) {
        int middle = low + (high - low)/2;

        std::vector<T> partesArray = OOPUtils::split(array[middle], " ");

        if (month(partesArray[0]) < startMonth || (month(partesArray[0]) == startMonth && std::stoi(partesArray[1]) < startDay)) {
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
int upperBound(const std::vector<T> &array, int &endMonth, int &endDay) {
    // min, max, avg are indices
    int low = 0;
    int high = static_cast<int>(array.size());

    while(low < high) {
        int middle = low + (high - low)/2;

        std::vector<T> partesArray = OOPUtils::split(array[middle], " ");

        if (month(partesArray[0]) < endMonth || (month(partesArray[0]) == endMonth && std::stoi(partesArray[1]) < endDay + 1)) {
            low = middle + 1;
        } else {
            high = middle;
        }
    }

    return low;
}

int main() {

    std::vector<std::string> bitacora;

    std::ifstream file("bitacora.txt");

    std::string lineaActual;

    // ahora si leemos archivo
    if(file.is_open()){

        // leamos el archivo linea por linea
        while (std::getline(file, lineaActual))
        {
            bitacora.push_back(lineaActual);
        } 

        file.close();
    } else {
            std::cout << "ERROR FATAL AL LEER EL ARCHIVO! PANICO!" << std::endl;
    }

    mergeSort(bitacora, 0, static_cast<int>(bitacora.size()) - 1);

    std::string opcString;
    int opc;
    std::string startMonthString;
    std::string startDayString;
    std::string endMonthString;
    std::string endDayString;
    std::string endDate;
    int startMonth;
    int startDay;
    int endMonth;
    int endDay;
    int start;
    int end;

    do{
        std::cout << "Selecciona una opción: " << std::endl;
        std::cout << "1- Ver información en un rango de fechas" << std::endl;
        std::cout << "2- Salir" << std::endl;
        std::getline(std::cin, opcString);
        opc = std::stoi(opcString);

        switch (opc)
        {
            case 1:
                std::cout << "Escoge un mes para la fecha de inicio: " << std::endl;
                std::cout << "6- Jun" << std::endl;
                std::cout << "7- Jul" << std::endl;
                std::cout << "8- Aug" << std::endl;
                std::cout << "9- Sep" << std::endl;
                std::cout << "10- Oct" << std::endl;
                std::getline(std::cin, startMonthString);
                startMonth = std::stoi(startMonthString);
                std::cout << "Ingresa el dia de la fecha de inicio: " << std::endl;
                std::getline(std::cin, startMonthString);
                startDay = std::stoi(startMonthString);
                
                std::cout << "Escoge un mes para la fecha final: " << std::endl;
                std::cout << "6- Jun" << std::endl;
                std::cout << "7- Jul" << std::endl;
                std::cout << "8- Aug" << std::endl;
                std::cout << "9- Sep" << std::endl;
                std::cout << "10- Oct" << std::endl;
                std::getline(std::cin, endMonthString);
                endMonth = std::stoi(endMonthString);
                std::cout << "Ingresa el dia de la fecha final: " << std::endl;
                std::getline(std::cin, endMonthString);
                endDay = std::stoi(endMonthString);

                start = lowerBound(bitacora, startMonth, startDay);
                end = upperBound(bitacora, endMonth, endDay) - 1;

                for(int i = start; i <= end; i++){
                    std::cout << bitacora[i] << std::endl;
                }
                break;
            case 2:
                    
                break;
            default:
                std::cout << "Ingresa un numero valido " << std::endl;
                break;
        }
    }while(opc != 2);    

    std::ofstream archivo("bitacoraOrdenada.txt");

    if (archivo.is_open()) {
        for (const auto &linea : bitacora) {
            archivo << linea << std::endl;
        }
        archivo.close();
    } else {
        std::cout << "ERROR: no se pudo abrir el archivo para escritura." << std::endl;
    }
}