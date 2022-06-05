#include <iostream>
#include <cctype>
#include <iomanip>
#include "Sala.h"

Sala::Sala() {

	for (int i = 0; i < TAM; i++) {

		for (int j = 0; j < TAM; j++) {

			sala[i][j] = 'O';

		}

	}

}

void Sala::mostrarSala() {
    std::cout << "X";
	for (int i = 1; i <= TAM; i++) {

		std::cout << std::setw(4) << i;

	}


    std::cout << std::endl << std::endl;

	for (int i = 0; i < TAM; i++) {

		std::cout << ((char)(65 + i));

		for (int j = 0; j < TAM; j++) {
			
            std::cout <<std::setw(4) << sala[i][j];

		}

		std::cout << std:: endl;

	}

}

int Sala::obtenerFila(char fila) {

	int filaPos;

	switch (fila) {

		
		case 'A': filaPos = 0; break;

		case 'B': filaPos = 1; break;

		case 'C': filaPos = 2; break;

		case 'D': filaPos = 3; break;

		case 'E': filaPos = 4; break;

	}

	return filaPos;

}

void Sala::modificarSalar() {

	int filaPos;
	
	do{

		do {
			
			std::cout << "Ingrese el asiento: ";
			std::cin >> fila >> columna;

			fila = toupper(fila);

			if (fila < 'A' or fila > 'E' or columna < 1 or columna > 5) {

				std::cout << "El lugar que esta eligiendo no existe" << std::endl;

			}

		} while (fila < 'A' or fila > 'E' or columna < 1 or columna > 5);

		columna -= 1;

		filaPos = obtenerFila(fila);

		if (sala[filaPos][columna] == 'X') {

			std::cout << "El asiento ya esta ocupado" << std::endl;

		}

	} while (sala[filaPos][columna] == 'X');

	sala[filaPos][columna] = 'X';

}

int Sala::getColumna() {

	return columna + 1;

}

char Sala::getFila() {

	return fila;

}
