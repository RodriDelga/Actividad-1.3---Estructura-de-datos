#pragma once

/*
 * Clase OOPUtils: agrupa funciones utilitarias de propósito general
 * usadas por el programa, como el procesamiento de cadenas de texto.
 * Matrícula: A01648834
 * Matrícula: A01648281
 * Matrícula: A01645656
 * Matrícula: A01648448
 * Fecha: 3 de septiembre de 2026
 */

#include <string>
#include <vector>
#include <iostream>

class OOPUtils
{
	public:
        // STATIC - miembro de la clase que pertenece directamente a la clase 
        // osea no hay copia por instancia

        // no es necesario hacer una instancia para poder utilizarlo / invocarlo
        // para después en su vida - si necesitan muchas cosas estáticas investigar singleton

        // Divide una cadena en subcadenas usando un delimitador dado.
        // source: la cadena a dividir.
        // delimiter: la secuencia de caracteres que separa cada subcadena.
        // Retorna: un vector con las subcadenas resultantes, en el orden en que aparecen.
		static std::vector<std::string> split(const std::string& source, const std::string& delimiter);

};