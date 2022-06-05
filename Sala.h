#pragma once
#ifndef SALA_H

#define SALA_H

#define TAM 5

class Sala {

	private:

		char sala[TAM][TAM];
		int columna;
		char fila;

	public:

		Sala();
		void mostrarSala();
		void modificarSalar();
		int obtenerFila(char);
		char getFila();
		int getColumna();

};

#endif // !SALA_H
