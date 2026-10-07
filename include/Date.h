/*
 * Description: Represents a date with time (month, day, hour, minute, second).
 * Author(s): A01648834, A01648281, A01645656, A01648448
 * Date: 3 de septiembre de 2026
 */

#pragma once
#include <iostream>

struct Date {
	int month;
	int day;
	int hour;
	int minute;
	int second;

	Date(int month = 1, int day = 1, int hour = 0, int minute = 0, int second = 0)
		: month(month), day(day), hour(hour), minute(minute), second(second) {
	}

	// Purpose: Compares chronologically if this date occurs before another.
	// Parameters: other - the date being compared against.
	// Return value: True if this date is earlier than the other.
	bool operator<(const Date &other) const {
		if (month != other.month) {
			return month < other.month;
		} else if (day != other.day) {
			return day < other.day;
		} else if (hour != other.hour) {
			return hour < other.hour;
		} else if (minute != other.minute) {
			return minute < other.minute;
		}
		
		return second < other.second;
	}

	// Purpose: Compares chronologically if this date occurs before or equal to another.
	// Parameters: other - the date being compared against.
	// Return value: True if this date is earlier than or equal to the other.
	bool operator<=(const Date &other) const {
		if (month != other.month) {
			return month <= other.month;
		} else if (day != other.day) {
			return day <= other.day;
		} else if (hour != other.hour) {
			return hour <= other.hour;
		} else if (minute != other.minute) {
			return minute <= other.minute;
		}
		
		return second <= other.second;
	}

	// Purpose: Prints the date to the console.
	// Parameters: None.
	// Return value: None.
	void getDate() {
		std::cout << month << " " << day << " " << hour << " " << minute << " " << second;
	}
};