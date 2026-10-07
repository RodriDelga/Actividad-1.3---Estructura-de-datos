/*
 * Description: Handles reading from and writing to log files.
 * Author(s): A01648834, A01648281, A01645656, A01648448
 * Date: 3 de septiembre de 2026
 */

#pragma once
#include "Registro.h"
#include "OOPUtils.h"
#include <string>
#include <vector>
#include "Months.h"

class FileHandler {
	private:
		
	public:
		// Purpose: Reads log entries from a file and appends them to a vector.
		// Parameters: 
		//   bitacora: Reference to the vector where pointers to Registro will be stored.
		//   fileName: String containing the name of the log file to read.
		// Return value: None.
		void readLogs(std::vector<Registro*> &bitacora, const std::string fileName);
		
		// Purpose: Stores the provided log entries into a specified file.
		// Parameters: 
		//   bitacora: Reference to the vector containing pointers to Registro.
		//   fileName: String containing the target file name to save the logs.
		// Return value: None.
		void storeLogs(std::vector<Registro*> &bitacora, const std::string fileName);
};