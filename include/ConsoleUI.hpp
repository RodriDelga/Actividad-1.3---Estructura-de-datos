#pragma once
#include <Date.hpp>
#include <iomanip>
#include <iostream>
#include <months.hpp>

namespace ConsoleUI {
int getValidInteger(const std::string &prompt, int minVal, int maxVal);
void printMonths(const MonthRegistry &reg);

Date promptForDate(const std::string &dateType, const MonthRegistry &months) {
  Date date;
  std::cout << "\n--- Fecha de " << dateType << " ---\n";
  printMonths(months);
  date.month = getValidInteger("Escoge un mes (1-12): ", 1, 12);
  std::string promptDay = "Ingresa el día (1-" +
                          std::to_string(months.get(date.month).days) + "): ";
  date.day = getValidInteger(promptDay, 1, months.get(date.month).days);

  return date;
}

int getValidInteger(const std::string &prompt, int minVal, int maxVal) {
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

void printMonths(const MonthRegistry &reg) {
  for (const auto &month : reg.all()) {
    std::cout << std::setw(3) << std::right << month.index << " - "
              << month.name << std::endl;
  }
}

} // namespace ConsoleUI