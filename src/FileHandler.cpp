#include "FileHandler.h"
#include <fstream>

void FileHandler::readLogs(std::vector<Registro *> &bitacora,
                           const std::string fileName) {
  std::ifstream file(fileName);

  std::string lineaActual;

  // ahora si leemos archivo
  if (file.is_open()) {

    // leamos el archivo linea por linea
    while (std::getline(file, lineaActual)) {
      std::vector<std::string> partes = OOPUtils::split(lineaActual, " ");
      std::vector<std::string> horario = OOPUtils::split(partes[2], ":");
      std::string mensaje;

      for (int i = 4; i < partes.size(); i++) {
        mensaje += partes[i] + ((i == partes.size() - 1) ? "" : " ");
      }
      std::vector<std::string> ipKeys = OOPUtils::split(partes[3], ".");
      std::vector<std::string> noPort = OOPUtils::split(ipKeys[3], ":");
      ipKeys.pop_back();
      ipKeys.push_back(noPort[0]);

      Registro *r = new Registro(months.getMonthAbr(partes[0]),
                                 std::stoi(partes[1]), std::stoi(horario[0]),
                                 std::stoi(horario[1]), std::stoi(horario[2]),
                                 partes[3], mensaje, months, ipKeys);

      bitacora.push_back(r);
    }

    file.close();
  } else {
    std::cout << "ERROR FATAL AL LEER EL ARCHIVO! PANICO!" << std::endl;
  }
}

void FileHandler::storeLogs(std::vector<Registro *> &bitacora,
                            const std::string fileName) {
  std::ofstream archivo(fileName);

  if (archivo.is_open()) {
    for (const auto &linea : bitacora) {
      archivo << linea->getRegistro() << std::endl;
    }
    archivo.close();
  } else {
    std::cout << "ERROR: no se pudo abrir el archivo para escritura."
              << std::endl;
  }

  for (Registro *reg : bitacora) {
    delete reg;
  }
  bitacora.clear();
}