#include "ConsoleUI.h"
#include "IpKey.h"
#include "Registro.h"
#include "Date.h"
#include "FileHandler.h"
#include <binarySearch.h>
#include <mergeSort.h>
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

void printMonths(const MonthRegistry &);

int getValidInteger(const std::string &prompt, int minVal, int maxVal);

// Punto de entrada del programa: lee la bitácora, la ordena cronológicamente,
// permite consultar registros por rango de fechas y guarda el resultado
// ordenado. Retorna: 0 si el programa terminó correctamente.
int main() {
  MonthRegistry months;
  std::vector<Registro *> bitacora;
  FileHandler fileHandler;

  fileHandler.readLogs(bitacora, "bitacora.txt");

  std::string opcString = "";
  int opc = 0;

  std::string startMonthString = "";
  std::string startDayString = "";
  std::string endMonthString = "";
  std::string endDayString = "";

  
mergeSort(bitacora, 0, static_cast<int>(bitacora.size()) - 1, [](const auto &item) {return item->getDate();});
  do {
    try {
      std::cout << "Selecciona una opción: " << std::endl;
      std::cout << "1 - Ver información en un rango de fechas: " << std::endl;
      std::cout << "2 - Ver información en un rango de IP Keys: " << std::endl;
      std::cout << "3 - Salir" << std::endl;
      std::getline(std::cin, opcString);
      opc = std::stoi(opcString);

      Date dateStart, dateEnd;
      IpKey ipKeyStart, ipKeyEnd;
      int start,end;

      switch (opc) {
      case 1:
        
        mergeSort(bitacora, 0, static_cast<int>(bitacora.size()) - 1, [](const auto &item) {return item->getDate();});

        dateStart = ConsoleUI::promptForDate("inicio", months);

        dateEnd = ConsoleUI::promptForDate("final", months);

        start = lowerBound(bitacora, dateStart, [](const auto &item) {return item->getDate();});

        end = upperBound(bitacora, dateStart, [](const auto &item) {return item->getDate();})-1;
        
        if (start > end)
          std::cout << "No hay registros para ese periodo." << std::endl;
        for (int i = start; i <= end; i++) {
          std::cout << bitacora[i]->getRegistro() << std::endl;
        }

        break;
      case 2:
        mergeSort(bitacora, 0, bitacora.size() - 1, [](const auto &item) {return item->getIpKey();});
        ipKeyStart = ConsoleUI::promptForIpKey("inicio");
        ipKeyEnd = ConsoleUI::promptForIpKey("final");
        start = lowerBound(bitacora, ipKeyStart, [](const auto &item) {return item->getIpKey();});
        end = upperBound(bitacora, ipKeyEnd, [](const auto &item) {return item->getIpKey();}) - 1;
        if (start > end)
          std::cout << "No hay registros para ese periodo." << std::endl;
        for (int i = start; i <= end; i++) {
          std::cout << bitacora[i]->getRegistro() << std::endl;
        }
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
  } while (opc != 3);

  fileHandler.storeLogs(bitacora, "bitacoraOrdenada.txt");
}