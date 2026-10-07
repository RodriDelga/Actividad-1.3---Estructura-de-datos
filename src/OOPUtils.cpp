/*
 * Description: Implementation of OOPUtils containing general-purpose utility functions.
 * Author(s): A01648834, A01648281, A01645656, A01648448
 * Date: 3 de septiembre de 2026
 */

#include "OOPUtils.h"

// Purpose: Divides a string into substrings using a specified delimiter.
// Parameters: 
//   source: the string to divide.
//   delimiter: the character sequence separating each substring.
// Return value: A vector with the resulting substrings in order.
std::vector<std::string> OOPUtils::split(const std::string &source, const std::string &delimiter) {
	std::vector<std::string> result = std::vector<std::string>();
	int start = 0;
	int end = 0;

	end = source.find(delimiter);

	while (end != std::string::npos) {
		std::string part = source.substr(start, end - start);
		result.push_back(part);
		start = end + delimiter.length();
		end = source.find(delimiter, start);
	}

	result.push_back(source.substr(start));
	return result;
}