#include <iostream>
#include <string>
#include "Pelicula.h"

Pelicula::Pelicula() {}

Pelicula::Pelicula(int idPelicula[], std::string titulo[], int duracion[], bool estreno[], std::string hora[]) {

	for (int i = 0; i < TAM; i++) {

		this->idPelicula[i] = idPelicula[i];
		this->titulo[i] = titulo[i];
		this->duracion[i] = duracion[i];
		this->estreno[i] = estreno[i];
		this->hora[i] = hora[i];

	}

}

int Pelicula::buscarPelicula(int buscarId) {

	int i = 0;

	while (i < TAM and buscarId != idPelicula[i]) {

		i++;

	}

	if (buscarId == idPelicula[i]) {

		return i;

	}else {

		return -1;

	}

}

void Pelicula::mostrarPelicula(int buscarId) {

	if (estreno[buscarId]) {

		std::cout << idPelicula[buscarId] << " - " << " [" << hora[buscarId] << "]" << " " << titulo[buscarId] << " " << duracion[buscarId] << " " << "* ESTRENO *" << std::endl;

	}else {

		std::cout << idPelicula[buscarId] << " - " << " [" << hora[buscarId] << "]" << " " << titulo[buscarId] << " " << duracion[buscarId] << " " << std::endl;

	}

}

void Pelicula::mostrarPeliculas() {

	for (int i = 0; i < TAM; i++) {

        mostrarPelicula(i);

	}

}

std::string Pelicula::getTitulo(int posicion) {

	std::string titu = titulo[posicion];

	return titu;
}

std::string Pelicula::getHora(int posicion) {

	std::string hor = hora[posicion];

	return hor;

}
