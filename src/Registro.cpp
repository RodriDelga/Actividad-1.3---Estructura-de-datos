/*
 * Description: Implementation of the Registro class including its constructor, chronological comparison, and getters.
 * Author(s): A01648834, A01648281, A01645656, A01648448
 * Date: 3 de septiembre de 2026
 */

#include "Registro.h"
#include "IpKey.h"
#include "Months.h"
#include <vector>

// Purpose: Creates a new log registry with the provided date, time, IP, and message.
// Parameters:
//   mes: month of the registry.
//   dia: day of the month.
//   hora, minuto, segundo: time components.
//   ip: IP address associated with the log.
//   mensaje: content of the log message.
//   reg: reference to the MonthRegistry.
//   ipKeys: vector containing the IP octets.
// Return value: None (Constructor).
Registro::Registro(int mes, int dia, int hora, int minuto, int segundo, std::string ip, std::string mensaje, std::vector<std::string>& ipKeys) 
	: mes(mes), dia(dia), hora(hora), minuto(minuto), segundo(segundo), ip(ip), mensaje(mensaje),  ipKey(ipKeys) {
}

// Purpose: Compares this registry with another to determine chronological order.
// Parameters: registro - the registry being compared against.
// Return value: True if this registry is chronologically prior to the provided one, false otherwise.
bool Registro::operator<(const Registro &registro) const {
	if (mes != registro.getMes()) {
		return mes < registro.getMes();
	} else if (dia != registro.getDia()) {
		return dia < registro.getDia();
	} else if (hora != registro.getHora()) {
		return hora < registro.getHora();
	} else if (minuto != registro.getMinuto()) {
		return minuto < registro.getMinuto();
	} else if (segundo < registro.getSegundo()) {
		return true;
	} 
	
	return false;
}

// Purpose: Builds the string representation of this registry, with the abbreviated month.
// Parameters: None.
// Return value: A formatted string "Mes dia hora:minuto:segundo ip mensaje".
std::string Registro::getRegistro() {
	std::string mesString = MonthRegistry::getInstance().get(mes).shortName;

	return mesString + " " + std::to_string(dia) + " " + (hora >= 10 ? "" : "0") + std::to_string(hora) + ":" + 
		(minuto >= 10 ? "" : "0") + std::to_string(minuto) + ":" + (segundo >= 10 ? "" : "0") + std::to_string(segundo) + 
		" " + ip + " " + mensaje;
}

// Purpose: Generates a Date struct from the registry's time components.
// Parameters: None.
// Return value: A Date object.
Date Registro::getDate() const {
	return Date(mes, dia, hora, minuto, segundo);
}

// Purpose: Retrieves the registry's month.
// Parameters: None.
// Return value: Integer representing the month (1-12).
int Registro::getMes() const { 
	return mes; 
}

// Purpose: Retrieves the registry's day.
// Parameters: None.
// Return value: Integer representing the day.
int Registro::getDia() const { 
	return dia; 
}

// Purpose: Retrieves the registry's hour.
// Parameters: None.
// Return value: Integer representing the hour.
int Registro::getHora() const { 
	return hora; 
}

// Purpose: Retrieves the registry's minute.
// Parameters: None.
// Return value: Integer representing the minute.
int Registro::getMinuto() const { 
	return minuto; 
}

// Purpose: Retrieves the registry's second.
// Parameters: None.
// Return value: Integer representing the second.
int Registro::getSegundo() const { 
	return segundo; 
}

// Purpose: Retrieves the registry's IP address.
// Parameters: None.
// Return value: String representing the IP.
std::string Registro::getIp() { 
	return ip; 
}

// Purpose: Retrieves the registry's message content.
// Parameters: None.
// Return value: String representing the message.
std::string Registro::getMensaje() { 
	return mensaje; 
}