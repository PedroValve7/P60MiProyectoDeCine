#pragma once
#ifndef FACTURA_H

#define FACTURA_H

#include <string>

class Factura{

	private:

		std::string cedula;
		std::string telefono;
		std::string direccion;
		std::string correoElectronico;

	public:


		Factura(std::string, std::string, std::string, std::string );
		void calcularTotal(float);
		void calcularTotal(float, int);
		void calcularTotal(float, int, float );
		void mostrarFactura(float);
		void mostrarFactura(float, int);
		void mostrarFactura(float, int, float );

};

#endif // FACTURA_H
