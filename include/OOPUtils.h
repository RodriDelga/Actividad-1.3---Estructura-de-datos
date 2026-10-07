/*
 * Description: Grouping of general-purpose utility functions used across the application.
 * Author(s): A01648834, A01648281, A01645656, A01648448
 * Date: 3 de septiembre de 2026
 */

#pragma once

#include <array>
#include <string>
#include <vector>
#include <iostream>

class OOPUtils {
	public:
		// Purpose: Divides a given string into substrings using a specified delimiter.
		// Parameters: 
		//   source: The string to be divided.
		//   delimiter: The sequence of characters separating each substring.
		// Return value: A vector containing the resulting substrings in order.
		static std::vector<std::string> split(const std::string& source, const std::string& delimiter);
};