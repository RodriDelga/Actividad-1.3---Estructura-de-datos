#include <fstream>

#include "OOPUtils.h"
#include "Registro.h"

/*
 * Programa: Ordenamiento y consulta por rango de fechas de una bitácora.
 * Lee un archivo de bitácora, lo ordena cronológicamente con merge sort,
 * permite consultar entradas dentro de un rango de fechas mediante
 * búsqueda binaria (lower bound / upper bound), y guarda el resultado
 * ordenado en un nuevo archivo.
 * Matrícula: A01648834
 * Matrícula: A01648281
 * Matrícula: A01645656
 * Matrícula: A01648448
 * Fecha: 3 de septiembre de 2026
 */

// Convierte el nombre abreviado de un mes a su número correspondiente.
// m: cadena con el nombre del mes (por ejemplo "Jun", "Jul").
// Retorna: el número del mes (6-10), o 0 si no coincide con ninguno reconocido
int month(std::string m) {
    if(m == "Jun") return 6;
    else if (m == "Jul") return 7;
    else if (m == "Aug") return 8;
    else if (m == "Sep") return 9;
    else if (m == "Oct") return 10;
    else return 0;
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
int upperBound(const std::vector<T> &array, int &endMonth, int &endDay) {
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

// Punto de entrada del programa: lee la bitácora, la ordena cronológicamente,
// permite consultar registros por rango de fechas y guarda el resultado ordenado.
// Retorna: 0 si el programa terminó correctamente.
int main() {

    std::vector<Registro*> bitacora;

    std::ifstream file("bitacora.txt");

    std::string lineaActual;

    // ahora si leemos archivo
    if(file.is_open()){

        // leamos el archivo linea por linea
        while (std::getline(file, lineaActual))
        {
            std::vector<std::string> partes = OOPUtils::split(lineaActual, " ");
            std::vector<std::string> horario = OOPUtils::split(partes[2], ":");
            std::string mensaje;

            for(int i = 4; i < partes.size(); i++){
                mensaje += partes[i] + " ";
            }

            Registro* r = new Registro(month(partes[0]), std::stoi(partes[1]), horario[0], horario[1], horario[2], partes[3], mensaje);
            bitacora.push_back(r);

        } 

        file.close();
    } else {
            std::cout << "ERROR FATAL AL LEER EL ARCHIVO! PANICO!" << std::endl;
    }

    mergeSort(bitacora, 0, static_cast<int>(bitacora.size()) - 1);

    std::string opcString = "";
    int opc = 0;
    std::string startMonthString = "";
    std::string startDayString = "";
    std::string endMonthString = "";
    std::string endDayString = "";
    int startMonth = 0;
    int startDay = 0;
    int endMonth = 0;
    int endDay = 0;
    int start = 0;
    int end = 0;

    do{
        try {
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
                    std::getline(std::cin, startDayString);
                    startDay = std::stoi(startDayString);
                    
                    std::cout << "Escoge un mes para la fecha final: " << std::endl;
                    std::cout << "6- Jun" << std::endl;
                    std::cout << "7- Jul" << std::endl;
                    std::cout << "8- Aug" << std::endl;
                    std::cout << "9- Sep" << std::endl;
                    std::cout << "10- Oct" << std::endl;
                    std::getline(std::cin, endMonthString);
                    endMonth = std::stoi(endMonthString);
                    std::cout << "Ingresa el dia de la fecha final: " << std::endl;
                    std::getline(std::cin, endDayString);
                    endDay = std::stoi(endDayString);

                    start = lowerBound(bitacora, startMonth, startDay);
                    end = upperBound(bitacora, endMonth, endDay) - 1;

                    for(int i = start; i <= end; i++){
                        std::cout << bitacora[i]->getRegistro() << std::endl;
                    }
                
                break;
            case 2:
                std::cout << "Gracias por usar este programa" << std::endl;
                break;
            default:
                std::cout << "Ingresa un numero valido " << std::endl;
                break;
        }
        } catch (const std::invalid_argument &error) {
                std::cout << "Ingresa un valor valido... FF" << std::endl;
                std::cout << std::endl;
        }
    }while(opc != 2);    

    std::ofstream archivo("bitacoraOrdenada.txt");

    if (archivo.is_open()) {
        for (const auto &linea : bitacora) {
            archivo << linea->getRegistro() << std::endl;
        }
        archivo.close();
    } else {
        std::cout << "ERROR: no se pudo abrir el archivo para escritura." << std::endl;
    }

    for (Registro* reg : bitacora) {
        delete reg;
    }
    bitacora.clear();
}