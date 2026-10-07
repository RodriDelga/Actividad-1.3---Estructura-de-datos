/*
 * Description: Implementation of FileHandler to parse logs from files and save ordered logs.
 * Author(s): A01648834, A01648281, A01645656, A01648448
 * Date: 3 de septiembre de 2026
 */

#include "FileHandler.h"
#include "Months.h"
#include <fstream>

// Purpose: Reads log entries from a given text file and loads them into memory.
// Parameters: 
//   bitacora: Reference to the vector storing Registro pointers.
//   fileName: Name of the log file to read.
// Return value: None.
void FileHandler::readLogs(std::vector<Registro *> &bitacora, const std::string fileName) {
	std::ifstream file(fileName);
	std::string lineaActual = "";

	if (file.is_open()) {
		while (std::getline(file, lineaActual)) {
			std::vector<std::string> partes = OOPUtils::split(lineaActual, " ");
			std::vector<std::string> horario = OOPUtils::split(partes[2], ":");
			std::string mensaje = "";

			for (int i = 4; i < partes.size(); i++) {
				mensaje += partes[i] + ((i == partes.size() - 1) ? "" : " ");
			}
			
			std::vector<std::string> ipKeys = OOPUtils::split(partes[3], ".");
			std::vector<std::string> noPort = OOPUtils::split(ipKeys[3], ":");
			
			ipKeys.pop_back();
			ipKeys.push_back(noPort[0]);

			Registro *nuevoRegistro = new Registro(MonthRegistry::getInstance().getMonthAbr(partes[0]),
												   std::stoi(partes[1]), std::stoi(horario[0]),
												   std::stoi(horario[1]), std::stoi(horario[2]),
												   partes[3], mensaje, ipKeys);

			bitacora.push_back(nuevoRegistro);
		}

		file.close();
	} else {
		std::cout << "ERROR FATAL AL LEER EL ARCHIVO! PANICO!" << std::endl;
	}
}

// Purpose: Writes the current list of logs to a file and cleans up allocated memory.
// Parameters: 
//   bitacora: Reference to the vector storing Registro pointers.
//   fileName: Name of the file to save the output.
// Return value: None.
void FileHandler::storeLogs(std::vector<Registro *> &bitacora, const std::string fileName) {
	std::ofstream archivo(fileName);

	if (archivo.is_open()) {
		for (const auto &linea : bitacora) {
			archivo << linea->getRegistro() << std::endl;
		}
		archivo.close();
	} else {
		std::cout << "ERROR: no se pudo abrir el archivo para escritura." << std::endl;
	}

	for (Registro *registroPtr : bitacora) {
		delete registroPtr;
	}
	
	bitacora.clear();
}