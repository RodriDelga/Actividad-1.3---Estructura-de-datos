#pragma once

#include <iostream>
#include <string>

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

class Registro
{
private:
    int mes;
    int dia;
    std::string hora;
    std::string minuto;
    std::string segundo;
    std::string ip;
    std::string mensaje;
public:
    Registro(int mes, int dia, std::string hora, std::string minuto, std::string segundo, std::string ip, std::string mensaje);
    bool operator<(const Registro &registro) const;
    std::string getRegistro();
    int getMes() const;
    int getDia() const;
    std::string getHora() const;
    std::string getMinuto() const;
    std::string getSegundo() const;
    std::string getIp();
    std::string getMensaje();
};