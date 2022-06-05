#include <iostream>
#include <string>
#include "Tienda.h"

Tienda::Tienda(){}

Tienda::Tienda(int idProducto[], int idCombo[], std::string productos[], std::string combos[], float precioProducto[], float precioCombo[]) {

	for (int i = 0; i < TAM; i++) {

		this->idProducto[i] = idProducto[i];
		this->idCombo[i] = idCombo[i];
		this->productos[i] = productos[i];
		this->combos[i] = combos[i];
		this->precioProducto[i] = precioProducto[i];
		this->precioCombo[i] = precioCombo[i];

	}

}

void Tienda::mostrarCatalogo() {

	std::cout << "Productos: " << std::endl << std::endl;

	for (int i = 0; i < TAM; i++) {

		std::cout << "Producto: " << i + 1 << std::endl;
		std::cout << idProducto[i] << ". "  << productos[i] << " $" << precioProducto[i] << std::endl;

	}

	std::cout << "\nCombos: " << std::endl << std::endl;

	for (int i = 0; i < TAM; i++) {

		std::cout << "Combo: " << i + 1 << std::endl;
		std::cout << idCombo[i] << ". "  << combos[i] << "$ " << precioCombo[i] << std::endl;

	}

}

void Tienda::mostrarProducto() {

	std::cout << "Productos: " << std::endl << std::endl;

	for (int i = 0; i < TAM; i++) {

		std::cout << idProducto[i] << ". "  << productos[i] << " $" << precioProducto[i] << std::endl;

	}

}

void Tienda::mostrarCombo() {

	std::cout << "\nCombos: " << std::endl << std::endl;

	for (int i = 0; i < TAM; i++) {

		std::cout << idCombo[i] << ". "  << combos[i] << "$ " << precioCombo[i] << std::endl;

	}

}

int Tienda::buscarProducto(int buscarProducto) {

	int i = 0;
	
	while (i < TAM and buscarProducto != idProducto[i]) {

		i++;

	}

	if (buscarProducto == idProducto[i]) {

		return i;

	}else {

		return -1;

	}
	
}

int Tienda::buscarCombo(int buscarCombo) {


	int i = 0;
	
	while (i < TAM and buscarCombo != idCombo[i]) {

		i++;

	}

	if (buscarCombo == idCombo[i]) {

		return i;

	}
	else {

		return -1;

	}
	
}