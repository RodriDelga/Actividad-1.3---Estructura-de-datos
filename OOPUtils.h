#pragma once

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
		static std::vector<std::string> split(const std::string& source, const std::string& delimiter);

};