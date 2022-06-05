#include <iostream>
#include "Pelicula.h"
#include "Boleto.h"

Boleto::Boleto(){}

Boleto::Boleto(int sala, Pelicula pelicula, char fila, int columna) {

	this->sala = sala;
	this->pelicula = pelicula;
	this->fila = fila;
	this->columna = columna;

}


void Boleto::mostrarBoleto() {
    std::cout << "\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << std::endl;
	std::cout << ": Sala: " << sala << "\t\t\t\t\t\t    :" << std::endl;
	std::cout << ": Hora: " << pelicula.getHora(sala - 1) << "\t\t\t\t\t\t    :" << std::endl;
	std::cout << ": Asiento: " << fila << columna << "\t\t\t\t\t\t    :" << std::endl;
    std::cout << ": Pelicula: " << pelicula.getTitulo(sala - 1) << "\t\t\t\t\t    :" <<std::endl;
    std::cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << std::endl;

}
