#pragma once
#include <array>
#include <iostream>
#include "Months.h"
#include "Date.h"
#include <string>
#include <vector>
#include <IpKey.h>

/*
 * Clase Registro: representa una entrada de la bitácora con fecha, hora,
 * dirección IP y mensaje asociado. Permite comparar registros para
 * ordenarlos cronológicamente y obtener su representación en texto.
 * Matrícula: A01648834
 * Matrícula: A01648281
 * Matrícula: A01645656
 * Matrícula: A01648448
 * Fecha: 3 de septiembre de 2026
 */

class Registro {
private:
  int mes;
  int dia;
  int hora;
  int minuto;
  int segundo;
  std::string ip;
  std::string mensaje;
  const MonthRegistry &monthRegistry_;
  IpKey ipKey;

public:
  explicit Registro(int mes, int dia, int hora, int minuto, int segundo,
                    std::string ip, std::string mensaje,
                    const MonthRegistry &reg, std::vector<std::string>& IpKeys);
  bool operator<(const Registro &registro) const;
  std::string getRegistro();
  int getMes() const;
  int getDia() const;
  int getHora() const;
  int getMinuto() const;
  int getSegundo() const;
  std::string getIp();
  std::string getMensaje();
  //bool compareIpKeyLT(const Registro &otherRegistro) const;
  IpKey getIpKey() const {return ipKey;};
  Date getDate() const;
};