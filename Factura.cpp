#include <iostream>
#include <string>
#include "Factura.h"

Factura::Factura(std::string cedula, std::string telefono, std::string	direccion, std::string correoElectronico) {

	this->cedula = cedula;
	this->telefono = telefono;
	this->direccion = direccion;
	this->correoElectronico = correoElectronico;

}

void Factura::calcularTotal(float precioCombo) {

	float subTotal = precioCombo;
	float iva = subTotal * 0.12f;
	float total = subTotal + iva;

	std::cout << "Sub total: $" << subTotal << std::endl;
	std::cout << "IVA: $" << iva << std::endl;
	std::cout << "Total: $" << total << std::endl;

}

void Factura::calcularTotal(float precioProducto, int totalPiezas) {

	float subTotal = precioProducto * totalPiezas;
	float iva = subTotal * 0.12f;
	float total = subTotal + iva;

	std::cout << "Sub total: $" << subTotal << std::endl;
	std::cout << "IVA: $" << iva << std::endl;
	std::cout << "Total: $" << total << std::endl;

}

void Factura::calcularTotal(float costoBoleto, int totalBoletos, float sumaDescuento) {

	float subTotal = (costoBoleto * totalBoletos) - ((costoBoleto * totalBoletos) * sumaDescuento);
	float iva = subTotal * 0.12f;
	float total = subTotal + iva;

	std::cout << "Sub total: $" << subTotal<< std::endl;
	std::cout << "IVA: $" << iva << std::endl;
	std::cout << "Total: $" << total << std::endl;

}

void Factura::mostrarFactura(float costoBoleto, int totalBoletos, float sumaDescuento) {

	std::cout << "\nDATOS DE LA FACTURA DEL CLIENTE: " << std::endl;

	std::cout << "Cedula: " << cedula << std::endl;
	std::cout << "Telefono: " << telefono << std::endl;
	std::cout << "Direccion: " << direccion << std::endl;
	std::cout << "Correo Electronico: " << correoElectronico << std::endl;

	calcularTotal(costoBoleto, totalBoletos, sumaDescuento);

}

void Factura::mostrarFactura(float precioCombo) {

	std::cout << "\nDATOS DE LA FACTURA DEL CLIENTE: " << std::endl;

	std::cout << "Cedula: " << cedula << std::endl;
	std::cout << "Telefono: " << telefono << std::endl;
	std::cout << "Direccion: " << direccion << std::endl;
	std::cout << "Correo Electronico: " << correoElectronico << std::endl;

	calcularTotal(precioCombo);

}

void Factura::mostrarFactura(float precioProducto, int totalPiezas) {

	std::cout << "\nDATOS DE LA FACTURA DEL CLIENTE: " << std::endl;

	std::cout << "Cedula: " << cedula << std::endl;
	std::cout << "Telefono: " << telefono << std::endl;
	std::cout << "Direccion: " << direccion << std::endl;
	std::cout << "Correo Electronico: " << correoElectronico << std::endl;

	calcularTotal(precioProducto, totalPiezas);

}