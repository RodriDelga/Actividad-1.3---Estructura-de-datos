/*
 * Description: Manages month mappings and properties such as indexing and days per month. Implements the Singleton pattern to provide a single global instance.
 * Author(s): A01648834, A01648281, A01645656, A01648448
 * Date: 3 de septiembre de 2026
 */

#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <stdexcept>
#include <algorithm>
#include <cctype>

struct Month {
	int index = 0;
	std::string name = "";
	std::string shortName = "";
	int days = 0;

	// Purpose: Initializes a Month struct with default or provided values.
	// Parameters: 
	//   initIndex: chronological index.
	//   initName: full month name.
	//   initShortName: abbreviated month name.
	//   initDays: number of days in the month.
	// Return value: None (Constructor).
	Month(int initIndex = 0, std::string initName = "", std::string initShortName = "", int initDays = 0)
		: index(initIndex), name(initName), shortName(initShortName), days(initDays) {
	}

	// Purpose: Retrieves the number of days in the month, accounting for leap years.
	// Parameters: isLeapYear - boolean flag specifying if it is a leap year.
	// Return value: Integer representing the number of days.
	int getDays(bool isLeapYear = false) const {
		if (index == 2 && isLeapYear) {
			return 29;
		}
		
		return days;
	}
	
	// Purpose: Gets the full name of the month.
	// Parameters: None.
	// Return value: String representing the month name.
	std::string getMonth() const {
		return name;
	}
};

class MonthRegistry {
public:
	// Purpose: Provides global access to the single instance of MonthRegistry.
	// Parameters: None.
	// Return value: A constant reference to the static MonthRegistry instance.
	static const MonthRegistry& getInstance() {
		static MonthRegistry instance = MonthRegistry();
		return instance;
	}

	// Purpose: Deleted copy constructor to enforce Singleton.
	// Parameters: None.
	// Return value: None.
	MonthRegistry(const MonthRegistry&) = delete;

	// Purpose: Deleted assignment operator to enforce Singleton.
	// Parameters: None.
	// Return value: None.
	void operator=(const MonthRegistry&) = delete;

	// Purpose: Gets month details based on an integer index.
	// Parameters: index - the chronological index of the month (1-12).
	// Return value: A constant reference to the corresponding Month struct.
	const Month& get(int index) const {
		if (index < 1 || index > 12) {
			throw std::out_of_range("Invalid index.");
		}
		
		return monthsList[index - 1];
	}

	// Purpose: Gets month details based on a string name.
	// Parameters: name - the full or abbreviated name of the month.
	// Return value: A constant reference to the corresponding Month struct.
	const Month& get(std::string name) const {
		std::transform(name.begin(), name.end(), name.begin(), [](unsigned char c) { return std::tolower(c); });
		auto iterator = nameMap.find(name);
		
		if (iterator == nameMap.end()) {
			throw std::invalid_argument("Invalid name: " + name);
		}
		
		return *iterator->second;
	}

	// Purpose: Returns all stored month mappings.
	// Parameters: None.
	// Return value: A constant vector reference of all Month structs.
	const std::vector<Month>& all() const { 
		return monthsList; 
	}

	// Purpose: Retrieves the chronological index for a given month name.
	// Parameters: name - the name or abbreviation of the month.
	// Return value: Integer representing the month's index.
	const int getMonthAbr(std::string name) const {
		return get(name).index;
	}
	
private:
	std::vector<Month> monthsList;
	std::unordered_map<std::string, const Month*> nameMap;

	// Purpose: Private constructor to initialize the month data and prevent external instantiation.
	// Parameters: None.
	// Return value: None (Constructor).
	MonthRegistry() {
		monthsList = {
			Month(1, "January", "Jan", 31), Month(2, "February", "Feb", 28), Month(3, "March", "Mar", 31),
			Month(4, "April", "Apr", 30), Month(5, "May", "May", 31), Month(6, "June", "Jun", 30),
			Month(7, "July", "Jul", 31), Month(8, "August", "Aug", 31), Month(9, "September", "Sep", 30),
			Month(10, "October", "Oct", 31), Month(11, "November", "Nov", 30), Month(12, "December", "Dec", 31)
		};

		for (const auto& currentMonth : monthsList) {
			std::string lowerName = currentMonth.name;
			std::transform(lowerName.begin(), lowerName.end(), lowerName.begin(), [](unsigned char c) { return std::tolower(c); });
			nameMap[lowerName] = &currentMonth;

			std::string lowerAbbrev = currentMonth.shortName;
			std::transform(lowerAbbrev.begin(), lowerAbbrev.end(), lowerAbbrev.begin(), [](unsigned char c) { return std::tolower(c); });
			nameMap[lowerAbbrev] = &currentMonth;
		}
	}
};