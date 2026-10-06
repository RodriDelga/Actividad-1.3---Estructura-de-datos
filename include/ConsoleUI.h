#pragma once
#include "Date.h"
#include <iomanip>
#include <iostream>
#include <string>
#include "Months.h"

namespace ConsoleUI {
int getValidInteger(const std::string &prompt, int minVal, int maxVal);
void printMonths(const MonthRegistry &reg);

// Pide al usuario una fecha completa con hora, minuto y segundo.
// dateType: texto que indica si es la fecha de inicio o final.
// months: registro de meses para validar el rango de dias.
// Retorna: un Date con los valores capturados y validados.
inline Date promptForDate(const std::string &dateType, const MonthRegistry &months) {
  Date date;
  std::cout << "\n--- Fecha de " << dateType << " ---\n";
  printMonths(months);
  date.month = getValidInteger("Escoge un mes (1-12): ", 1, 12);
  std::string promptDay = "Ingresa el día (1-" +
                          std::to_string(months.get(date.month).days) + "): ";
  date.day = getValidInteger(promptDay, 1, months.get(date.month).days);
  date.hour = getValidInteger("Ingresa la hora (0-23): ", 0, 23);
  date.minute = getValidInteger("Ingresa el minuto (0-59): ", 0, 59);
  date.second = getValidInteger("Ingresa el segundo (0-59): ", 0, 59);

  return date;
}

// Pide un entero por consola hasta que sea valido y este dentro del rango.
// prompt: mensaje que se muestra al usuario.
// minVal: valor minimo permitido.
// maxVal: valor maximo permitido.
// Retorna: el entero validado.
inline int getValidInteger(const std::string &prompt, int minVal, int maxVal) {
  std::string input;
  int value;

  while (true) {
    std::cout << prompt;
    std::getline(std::cin, input);

    try {
      value = std::stoi(input);
      if (value >= minVal && value <= maxVal) {
        return value;
      }
      std::cout << "Error: Por favor ingresa un numero entre " << minVal
                << " y " << maxVal << ".\n";
    } catch (const std::invalid_argument &) {
      std::cout << "Error: Entrada invalida. Solo se permiten numeros.\n";
    } catch (const std::out_of_range &) {
      std::cout << "Error: El numero es demasiado grande.\n";
    }
  }
}

// Imprime la lista de meses con su indice.
// reg: registro de meses a mostrar.
inline void printMonths(const MonthRegistry &reg) {
  for (const auto &month : reg.all()) {
    std::cout << std::setw(3) << std::right << month.index << " - "
              << month.name << std::endl;
  }
}

} // namespace ConsoleUI