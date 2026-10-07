#include "OOPUtils.h"

/*
 * Implementación de OOPUtils: funciones utilitarias de propósito general,
 * incluyendo el procesamiento de cadenas de texto.
 * Matrícula: A01648834
 * Matrícula: A01648281
 * Matrícula: A01645656
 * Matrícula: A01648448
 * Fecha: 3 de septiembre de 2026
 */

// Divide una cadena en subcadenas usando un delimitador dado.
// source: la cadena a dividir.
// delimiter: la secuencia de caracteres que separa cada subcadena.
// Retorna: un vector con las subcadenas resultantes, en el orden en que
// aparecen.
std::vector<std::string> OOPUtils::split(const std::string &source,
                                         const std::string &delimiter) {
  std::vector<std::string> result;

  int start = 0;
  int end;

  end = source.find(delimiter);

  while (end != std::string::npos) {
    std::string part = source.substr(start, end - start);
    result.push_back(part);
    start = end + delimiter.length();
    end = source.find(delimiter, start);
  }

  result.push_back(source.substr(start));
  return result;
}