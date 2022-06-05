#include <string>
#include "Pelicula.h"

#ifndef BOLETO_H

#define BOLETO_H

class Boleto {

	private:

		int sala;
		Pelicula pelicula;
		char fila;
		int columna;

	public:

		Boleto();
		Boleto(int, Pelicula , char, int);
		void mostrarBoleto();

};

#endif // !BOLETO_H
