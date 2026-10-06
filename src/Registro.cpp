#include "Registro.hpp"
#include <months.hpp>
#include <vector>
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
Registro::Registro(int mes, int dia, int hora, int  minuto, int segundo, std::string ip, std::string mensaje, const MonthRegistry& reg, std::vector<std::string>& ipKeys) 
: mes(mes), dia(dia), hora(hora), minuto(minuto), segundo(segundo), ip(ip), mensaje(mensaje), monthRegistry_(reg)
{
    for (int i = 0; i < 4; i++) {
        ipKey[i] = std::stoi(ipKeys[i]);
    }
}

int Registro::getIpKey(int i) const {
    return ipKey[i];
}

// Compara este registro con otro para determinar orden cronológico.
// registro: el registro con el que se compara.
// Retorna: true si este registro es cronológicamente anterior al dado, false en caso contrario.
bool Registro::operator<(const Registro &registro) const {
    if(mes != registro.getMes()) return mes < registro.getMes();
    else if(dia != registro.getDia()) return dia < registro.getDia();
    else if(hora != registro.getHora()) return hora < registro.getHora();
    else if(minuto !=(registro.getMinuto())) return minuto < registro.getMinuto();
    else if(segundo < registro.getSegundo()) return true;
    else return false;
}

bool Registro::compareIpKeyLT(const Registro &otherRegistro) const  {
    if(ipKey[0] != otherRegistro.getIpKey(0)) {
        return ipKey[0] < otherRegistro.getIpKey(0);
    }
    else if(ipKey[1] != otherRegistro.getIpKey(1)) {
        return ipKey[1] < otherRegistro.getIpKey(1);
    }
    else if(ipKey[2] != otherRegistro.getIpKey(2)) {
        return ipKey[2] < otherRegistro.getIpKey(2);
    }
    else if(ipKey[3] != otherRegistro.getIpKey(3)) {
        return ipKey[3] < otherRegistro.getIpKey(3);
    }
    else return false;
}


// Construye la representación en texto de este registro, con el mes abreviado.
// Retorna: una cadena con el formato "Mes dia hora:minuto:segundo ip mensaje".
std::string Registro::getRegistro() {
    
    std::string mesString = monthRegistry_.get(mes).shortName;

    return mesString + " " + std::to_string(dia) + " " + (hora>= 10 ? "" : "0" ) + std::to_string(hora) + ":" + (minuto>= 10 ? "" : "0" ) +
     std::to_string(minuto) + ":" +(segundo>= 10 ? "" : "0" ) + std::to_string(segundo) + " " + ip + " " + mensaje;
}

// Retorna: el mes del registro (6-10).
int Registro::getMes() const { return mes; }
// Retorna: el día del mes del registro.
int Registro::getDia() const { return dia;}
// Retorna: la hora del registro, como texto.
int Registro::getHora() const { return hora; }
// Retorna: el minuto del registro, como texto.
int Registro::getMinuto() const { return minuto; }
// Retorna: el segundo del registro, como texto.
int Registro::getSegundo() const { return segundo; }
// Retorna: la dirección IP asociada al registro.
std::string Registro::getIp() { return ip; }
// Retorna: el mensaje contenido en el registro.
std::string Registro::getMensaje() { return mensaje; }

