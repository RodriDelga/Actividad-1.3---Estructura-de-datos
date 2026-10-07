/*
 * Description: Represents a log entry with chronological and network data.
 * Author(s): A01648834, A01648281, A01645656, A01648448
 * Date: 3 de septiembre de 2026
 */

#pragma once
#include <array>
#include <iostream>
#include "Months.h"
#include "Date.h"
#include <string>
#include <vector>
#include "IpKey.h"

class Registro {
private:
	int mes;
	int dia;
	int hora;
	int minuto;
	int segundo;
	std::string ip;
	std::string mensaje;
	IpKey ipKey;

public:
	explicit Registro(int mes, int dia, int hora, int minuto, int segundo,
					  std::string ip, std::string mensaje
					  , std::vector<std::string>& ipKeys);
	bool operator<(const Registro &registro) const;
	
	// Purpose: Gets the string representation of the registry log.
	// Parameters: None.
	// Return value: String containing the log data.
	std::string getRegistro();
	
	// Purpose: Retrieves the month associated with the registry.
	// Parameters: None.
	// Return value: Integer representing the month.
	int getMes() const;
	
	// Purpose: Retrieves the day associated with the registry.
	// Parameters: None.
	// Return value: Integer representing the day.
	int getDia() const;
	
	// Purpose: Retrieves the hour associated with the registry.
	// Parameters: None.
	// Return value: Integer representing the hour.
	int getHora() const;
	
	// Purpose: Retrieves the minute associated with the registry.
	// Parameters: None.
	// Return value: Integer representing the minute.
	int getMinuto() const;
	
	// Purpose: Retrieves the second associated with the registry.
	// Parameters: None.
	// Return value: Integer representing the second.
	int getSegundo() const;
	
	// Purpose: Retrieves the IP address associated with the registry.
	// Parameters: None.
	// Return value: String representation of the IP address.
	std::string getIp();
	
	// Purpose: Retrieves the error or log message.
	// Parameters: None.
	// Return value: String containing the message.
	std::string getMensaje();
	
	// Purpose: Retrieves the structured IpKey object of the registry.
	// Parameters: None.
	// Return value: The internal IpKey structure.
	IpKey getIpKey() const { return ipKey; };
	
	// Purpose: Generates and retrieves the Date object for chronological sorting.
	// Parameters: None.
	// Return value: A Date object reflecting the registry's timestamp.
	Date getDate() const;
};