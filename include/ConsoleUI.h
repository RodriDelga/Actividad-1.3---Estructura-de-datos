/*
 * Description: UI utility functions to capture and validate user input from the console for Dates and IP Keys.
 * Author(s): A01648834, A01648281, A01645656, A01648448
 * Date: 3 de septiembre de 2026
 */

#pragma once
#include "Date.h"
#include <array>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include "IpKey.h"
#include "Months.h"

namespace ConsoleUI {
	int getValidInteger(const std::string &prompt, int minVal, int maxVal);
	void printMonths();

	// Purpose: Prompts the user to create a valid IPv4 key by capturing each of the 4 octets.
	// Parameters: dateType - string indicating if it is for start or end of a range.
	// Return value: An IpKey object validated and created from user input.
	inline IpKey promptForIpKey(const std::string &dateType) {
		std::array<int, 4> ipKey = {0, 0, 0, 0};
		std::cout << "\n--- Fecha de " << dateType << " ---\n";

		for (int i = 0; i < 4; i++) {
			std::string preview = "";
			for (int j = 0; j < 4; j++) {
				if (j < i) {
					preview += std::to_string(ipKey[j]);
				} else if (j == i) {
					preview += "___";
				} else {
					preview += "X";
				}
				
				if (j < 3) {
					preview += ".";
				}
			}

			ipKey[i] = getValidInteger("Clave IP (" + preview + "). Escoge un valor entre 0 y 255: ", 0, 255);
		}
		std::cout << "IP Key " << dateType << ": ";
		
		for (int i = 0; i < 4; i++) {
			std::cout << ipKey[i] << (i < 3 ? "." : "");
		}
		std::cout << std::endl;

		IpKey createdIpKey(ipKey);
		return createdIpKey;
	}

	// Purpose: Prompts the user for a full date (month, day, hour, minute, second).
	// Parameters: 
	//   dateType: text indicating if it's the start or end date.
	// Return value: A Date object with the captured and validated values.
	inline Date promptForDate(const std::string &dateType) {
		Date date = Date();
		std::cout << "\n--- Fecha de " << dateType << " ---\n";
		printMonths();
		
		date.month = getValidInteger("Escoge un mes (1-12): ", 1, 12);
		std::string promptDay = "Ingresa el dia (1-" + std::to_string(MonthRegistry::getInstance().get(date.month).days) + "): ";
		date.day = getValidInteger(promptDay, 1, MonthRegistry::getInstance().get(date.month).days);
		date.hour = getValidInteger("Ingresa la hora (0-23): ", 0, 23);
		date.minute = getValidInteger("Ingresa el minuto (0-59): ", 0, 59);
		date.second = getValidInteger("Ingresa el segundo (0-59): ", 0, 59);

		return date;
	}

	// Purpose: Requests an integer from the console until it is valid and within range.
	// Parameters: 
	//   prompt: message shown to the user.
	//   minVal: minimum allowed value.
	//   maxVal: maximum allowed value.
	// Return value: The validated integer.
	inline int getValidInteger(const std::string &prompt, int minVal, int maxVal) {
		std::string input = "";
		int value = 0;

		while (true) {
			std::cout << prompt;
			std::getline(std::cin, input);

			try {
				value = std::stoi(input);
				if (value >= minVal && value <= maxVal) {
					return value;
				}
				std::cout << "Error: Por favor ingresa un numero entre " << minVal << " y " << maxVal << ".\n";
			} catch (const std::invalid_argument &) {
				std::cout << "Error: Entrada invalida. Solo se permiten numeros.\n";
			} catch (const std::out_of_range &) {
				std::cout << "Error: El numero es demasiado grande.\n";
			}
		}
	}

	// Purpose: Prints the list of months along with their index.
	// Return value: None.
	inline void printMonths() {
		for (const auto &month : MonthRegistry::getInstance().all()) {
			std::cout << std::setw(3) << std::right << month.index << " - " << month.name << std::endl;
		}
	}
}