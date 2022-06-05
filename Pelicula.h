#ifndef PELICULA_H

#define PELICULA_H

#define TAM 5

class Pelicula {

	private:

		int idPelicula[TAM];
		std::string titulo[TAM];
		int duracion[TAM];
		bool estreno[TAM];
		std::string hora[TAM];

	public: 
		
		Pelicula();
		Pelicula(int [], std::string [], int [], bool[], std::string[]);
		int buscarPelicula(int );
		void mostrarPelicula(int );
		void mostrarPeliculas();
		std::string getTitulo(int);
		std::string getHora(int);
};


#endif // PELICULA_H
