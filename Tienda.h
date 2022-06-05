#pragma once

#ifndef TIENDA_H
#define TIENDA_H

#include <string>

#define TAM 10

class Tienda {

	private:

		int idProducto[TAM];
		int idCombo[TAM];
		std::string productos[TAM];
		std::string combos[TAM];
		float precioProducto[TAM];
		float precioCombo[TAM];

	public:

		Tienda();
		Tienda(int [], int [], std::string[], std::string[], float[], float[]);
		void mostrarCatalogo();
		void mostrarCombo();
		void mostrarProducto();
		void comprarSeparado(int);
		int buscarProducto(int);
		int buscarCombo(int);
};

#endif // !TIENDA_H