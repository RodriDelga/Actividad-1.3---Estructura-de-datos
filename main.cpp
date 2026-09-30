#include <fstream>
#include <iomanip>
#include <iostream>
#include <months.hpp>
#include "OOPUtils.h"
#include "Registro.h"
#include <binarySearchByDate.hpp>
#include <mergeSortByDate.hpp>

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


void printMonths(const MonthRegistry&);


// Punto de entrada del programa: lee la bitácora, la ordena cronológicamente,
// permite consultar registros por rango de fechas y guarda el resultado ordenado.
// Retorna: 0 si el programa terminó correctamente.
int main() {
    MonthRegistry months;
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
                mensaje += partes[i] + ((i==partes.size()-1) ? "":" ");
            }

            Registro* r = new Registro(months.getMonthAbr(partes[0]), std::stoi(partes[1]), std::stoi(horario[0]), std::stoi(horario[1]), 
                                       std::stoi(horario[2]), partes[3], mensaje, months);
            bitacora.push_back(r);

        } 

        file.close();
    } else {
            std::cout << "ERROR FATAL AL LEER EL ARCHIVO! PANICO!" << std::endl;
    }

    mergeSortByDate(bitacora, 0, static_cast<int>(bitacora.size()) - 1);

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

                    printMonths(months);

                    std::getline(std::cin, startMonthString);

                    startMonth = std::stoi(startMonthString);

                    std::cout << "Ingresa el dia de la fecha de inicio: " << std::endl;

                    std::getline(std::cin, startDayString);

                    startDay = std::stoi(startDayString);
                    
                    std::cout << "Escoge un mes para la fecha final: " << std::endl;

                    printMonths(months);

                    std::getline(std::cin, endMonthString);

                    endMonth = std::stoi(endMonthString);
                    
                    std::cout << "Ingresa el dia de la fecha final: " << std::endl;

                    std::getline(std::cin, endDayString);

                    endDay = std::stoi(endDayString);

                    start = lowerBoundDate(bitacora, startMonth, startDay);

                    end = upperBoundDate(bitacora, endMonth, endDay) - 1;
                    if (start > end) std::cout << "No hay registros para ese periodo." << std::endl;
                    for(int i = start; i <= end; i++){
                        std::cout << bitacora[i]->getRegistro() << std::endl;
                    }
                
                break;
            case 2:
                
                break;
            case 3:
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

void printMonths(const MonthRegistry& reg) {
    for (const auto& month : reg.all()) {
        std::cout << std::setw(3) << std::right << month.index <<  " - " << month.name 
                  << std::endl;
    }
}