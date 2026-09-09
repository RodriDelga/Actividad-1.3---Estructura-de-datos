#include "Registro.h"

/*
 * Implementación de la clase Registro: constructor, comparación
 * cronológica y getters para acceder a cada campo del registro.
 * Matrícula: A01648834
 * Matrícula: A01648281
 * Matrícula: A01645656
 * Matrícula: A01648448
 * Fecha: 3 de septiembre de 2026
 */

// Crea un nuevo registro de bitácora con la fecha, hora, IP y mensaje dados.
// mes: número de mes del registro. dia: día del mes del registro.
// hora, minuto, segundo: hora del registro, representada como texto.
// ip: dirección IP asociada al registro. mensaje: contenido del mensaje registrado.
Registro::Registro(int mes, int dia, std::string hora, std::string minuto, std::string segundo, std::string ip, std::string mensaje) : mes(mes), dia(dia), hora(hora), minuto(minuto), segundo(segundo), ip(ip), mensaje(mensaje) {}

// Compara este registro con otro para determinar orden cronológico.
// registro: el registro con el que se compara.
// Retorna: true si este registro es cronológicamente anterior al dado, false en caso contrario.
bool Registro::operator<(const Registro &registro) const {
    if(mes != registro.getMes()) return mes < registro.getMes();
    else if(dia != registro.getDia()) return dia < registro.getDia();
    else if(std::stoi(hora) != std::stoi(registro.getHora())) return std::stoi(hora) < std::stoi(registro.getHora());
    else if(std::stoi(minuto) != std::stoi(registro.getMinuto())) return std::stoi(minuto) < std::stoi(registro.getMinuto());
    else if(std::stoi(segundo) < std::stoi(registro.getSegundo())) return true;
    else return false;
}

// Construye la representación en texto de este registro, con el mes abreviado.
// Retorna: una cadena con el formato "Mes dia hora:minuto:segundo ip mensaje".
std::string Registro::getRegistro() {
    std::string mesString = "";
    if(mes == 6) mesString = "Jun";
    else if (mes == 7) mesString = "Jul";
    else if (mes == 8) mesString = "Aug";
    else if (mes == 9) mesString = "Sep";
    else if (mes == 10) mesString = "Oct";

    return mesString + " " + std::to_string(dia) + " " + hora + ":" + minuto + ":" + segundo + " " + ip + " " + mensaje;
}

// Retorna: el mes del registro (6-10).
int Registro::getMes() const { return mes; }
// Retorna: el día del mes del registro.
int Registro::getDia() const { return dia;}
// Retorna: la hora del registro, como texto.
std::string Registro::getHora() const { return hora; }
// Retorna: el minuto del registro, como texto.
std::string Registro::getMinuto() const { return minuto; }
// Retorna: el segundo del registro, como texto.
std::string Registro::getSegundo() const { return segundo; }
// Retorna: la dirección IP asociada al registro.
std::string Registro::getIp() { return ip; }
// Retorna: el mensaje contenido en el registro.
std::string Registro::getMensaje() { return mensaje; }