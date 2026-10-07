/*
 * Description: Log sorting and querying program by chronological range and IP keys.
 * Author(s): A01648834, A01648281, A01645656, A01648448
 * Date: 11 October  2026
 */

#include "ConsoleUI.h"
#include "IpKey.h"
#include "Registro.h"
#include "Date.h"
#include "FileHandler.h"
#include "binarySearch.h"
#include "mergeSort.h"

// Purpose: Main entry point of the program. Reads logs, processes queries via terminal, and sorts/exports.
// Parameters: None.
// Return value: 0 on successful termination.
int main() {
	std::vector<Registro *> bitacora = std::vector<Registro *>();
	FileHandler fileHandler = FileHandler();

	fileHandler.readLogs(bitacora, "bitacora.txt");

	std::string opcString = "";
	int opc = 0;

	std::string startMonthString = "";
	std::string startDayString = "";
	std::string endMonthString = "";
	std::string endDayString = "";

	mergeSort(bitacora, 0, static_cast<int>(bitacora.size()) - 1, [](const auto &item) { return item->getDate(); });
	
	do {
		try {
			std::cout << "Selecciona una opcion: " << std::endl;
			std::cout << "1 - Ver informacion en un rango de fechas: " << std::endl;
			std::cout << "2 - Ver informacion en un rango de IP Keys: " << std::endl;
			std::cout << "3 - Salir" << std::endl;
			std::getline(std::cin, opcString);
			opc = std::stoi(opcString);

			Date dateStart = Date();
			Date dateEnd = Date();
			IpKey ipKeyStart = IpKey();
			IpKey ipKeyEnd = IpKey();
			int start = 0;
			int end = 0;

			switch (opc) {
				case 1:
					mergeSort(bitacora, 0, static_cast<int>(bitacora.size()) - 1, [](const auto &item) { return item->getDate(); });
					dateStart = ConsoleUI::promptForDate("inicio");
					dateEnd = ConsoleUI::promptForDate("final");
					start = lowerBound(bitacora, dateStart, [](const auto &item) { return item->getDate(); });
					end = upperBound(bitacora, dateStart, [](const auto &item) { return item->getDate(); }) - 1;
					
					if (start > end) {
						std::cout << "No hay registros para ese periodo." << std::endl;
					}
					
					for (int i = start; i <= end; i++) {
						std::cout << bitacora[i]->getRegistro() << std::endl;
					}
					break;
					
				case 2:
					mergeSort(bitacora, 0, static_cast<int>(bitacora.size()) - 1, [](const auto &item) { return item->getIpKey(); });
					ipKeyStart = ConsoleUI::promptForIpKey("inicio");
					ipKeyEnd = ConsoleUI::promptForIpKey("final");
					start = lowerBound(bitacora, ipKeyStart, [](const auto &item) { return item->getIpKey(); });
					end = upperBound(bitacora, ipKeyEnd, [](const auto &item) { return item->getIpKey(); }) - 1;
					
					if (start > end) {
						std::cout << "No hay registros para ese periodo." << std::endl;
					}
					
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
	return 0;
}