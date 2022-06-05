#include <iostream>
#include "Sala.h"
#include "Pelicula.h"
#include "Boleto.h"
#include "Factura.h"
#include "Tienda.h"

#define SALA1 3.15f
#define SALA2 6.15f
#define SALA3 9.15f
#define SALA4 12.15f
#define SALA5 15.15f

using namespace std;

int main(){

    int opcion, numeroSala, posicion, totalBoletos, idBuscar, columna;
    char fila;

    bool continuar = true;

    int idPelicula[] = { 1, 2, 3, 4, 5 };

    std::string hora[] = { "14:30", "16:00", "18:20", "16:15", "11:30" };

    std::string titulo[] = { "El Rey Leon", "Spiderma: Lejos de Casa", "Annabelle 3: Vuelve a Casa", "Avengers: End Game", "Toy Story 4" };

    int duracion[] = { 117, 130, 106, 188, 104 };

    bool estreno[] = { true, true, false, false, false};

    Sala sala[5];

    Pelicula pelicula(idPelicula, titulo, duracion, estreno, hora);
    
    Boleto boletos[25];
    
    float costoBoleto;

    std::string cedula, telefono, direccion, correoElectronico;

    int idProductos[] = { 2, 4, 6, 12, 3, 234, 1, 7, 78, 8};
    std::string productos[] = { "Papas", "Doritos", "Lucas", "Palomitas", "Coca-Cola", "Snicker", "Rufles", "Paleta Caramelo", "Cacahuates", "Galletas" };
    float precioProducto[] = { 23.45f, 23.45f, 12.34f, 34.56f, 19.76f, 6.56f, 23.45f, 12.34, 16.78f, 18.23f};
    

    int idCombo[] = { 5, 13, 14, 9, 10, 21, 23, 34, 55, 123};
    std::string combo[] = { "Papas Coca-Cola Snicker", "Rufles Coca-Cola", "Coca-Cola Palomitas", "Palomitas Snicker", "Snicker Paleta", "Rufles Coca-Cola", "Paleta Palomitas", "Cacahuates Coca-Cola", "Galletas Snicker", "Doritos Coca-Cola"};
    float precioCombo[] = { 33.45f, 21.23f, 23.45f, 12.34f, 31.24f, 23.45f, 24.56f, 35.66f, 12.34f, 23.45};

    Tienda tienda(idProductos, idCombo, productos, combo,  precioProducto, precioCombo);

    int id, totalPiezas, edad;
    float sumaDescuento = 0.0f;
    int factura;

    while (continuar) {

        cout << "- - M I C I N E - -" << endl<<endl;

        cout << "+ + MENU PRINCIPAL ++" << endl;
        cout << "1. Mostrar Cartelera\n2. Mostrar Sala\n3. Comprar Boletos\n4. Tienda de Snack\n5. Salir" << endl;
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch (opcion) {

            case 1:

                std::cout << "\n\n- - C A R T E L E R A - -" << std::endl << std::endl;

                 pelicula.mostrarPeliculas();

                break;

            case 2:

                std::cout << "Ingrese el numero de sala: ";
                std::cin >> numeroSala;
                
                posicion = pelicula.buscarPelicula(numeroSala);

                if (posicion != -1) {

                    pelicula.mostrarPelicula(posicion);

                    std::cout << "\n- - A S I E N T O S - -" << std::endl;

                    sala[posicion].mostrarSala();

                }else {

                    std::cout << "No se encontro la sala del cine" << std::endl;

                }

                break;

            case 3:

                std::cout << "Ingrese el ID de la pelicula: ";
                std::cin >> idBuscar;

                posicion = pelicula.buscarPelicula(idBuscar);

                if (posicion != -1) {
                    
                    do {

                        std::cout << "Ingrese el numero de boletos: ";
                        std::cin >> totalBoletos;

                        if (totalBoletos < 1) {

                            std::cout << "El numero de boletos no pueden ser negativos" << std::endl;

                        }

                    } while (totalBoletos < 1);

                    switch (idBuscar) {

                        case 1: costoBoleto = SALA1; break;
                        case 2: costoBoleto = SALA2; break;
                        case 3: costoBoleto = SALA3; break;
                        case 4: costoBoleto = SALA4; break;
                        case 5: costoBoleto = SALA5; break;
                    
                    }

                    std::cout << "\nSeleccione los asientos" << std::endl;

                    for (int i = 0; i < totalBoletos; i++) {

                        sala[posicion].modificarSalar();

                        fila = sala[posicion].getFila();

                        columna = sala[posicion].getColumna();

                        boletos[i] = Boleto(idBuscar, pelicula, fila, columna);

                    }

                    std::cout << "\n\nRESUMEN DE LA COMMPRA: " << std::endl;

                    for (int i = 0; i < totalBoletos; i++) {

                        std::cout << "\n\nBoleto #" << i + 1 << std::endl;

                        do {

                            std::cout << "1. Ninio\n2. Adulto\n3. Adulto Mayor" << std::endl;
                            std::cout << "Elija su edad, para comprar el boleto: ";
                            std::cin >> edad;

                            if (edad < 1 or edad > 3) {

                                std::cout << "Ingrese correctamente su edad" << std::endl;

                            }

                        } while (edad < 1 or edad > 3);

                        switch (edad) {

                        case 1: sumaDescuento += 0.50f;  break;

                        case 2: sumaDescuento += 0.0f;  break;

                        case 3: sumaDescuento += 0.50f;  break;
 
                        }

                        std::cout << "\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << std::endl;

                        
                        boletos[i].mostrarBoleto();

                        std::cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << std::endl;

                    }
                    
                    std::cout << "\nTOTAL: " << ((float)(totalBoletos * costoBoleto) - ((totalBoletos * costoBoleto) * (sumaDescuento)));

                    do {
                     
                        std::cout << "\nDesea tener factura [Si = 1][No = 0]: ";
                        std::cin >> factura;

                        if (factura != 0 and factura != 1) {

                            std::cout << "Ingrese 0 si no requiere factura o ingresae 1 si la requiere" << std::endl;

                        }

                    } while (factura != 0 and factura != 1);

                    if (factura) {


                        std::cout << "Cedula: ";
                        cin.ignore();
                        getline(std::cin, cedula);

                        std::cout << "Telefono: ";
                        getline(std::cin, telefono);

                        std::cout << "Direccion: ";
                        getline(std::cin, direccion);

                        std::cout << "Correo Electronico: ";
                        getline(std::cin, correoElectronico);

                        Factura factura(cedula, telefono, direccion, correoElectronico);

                        factura.mostrarFactura(costoBoleto, totalBoletos, sumaDescuento);

                    }

                }else {

                    std::cout << "No se encontro la sala del cine" << std::endl;

                }

                break;

            case 4:

                do {
                    
                    std::cout << "- - T I E N D A - S N A C K - -" << endl << endl;
                    std::cout << "\n1. Catalogos de productos\n2. Combos\n3. Compra (por separado)\n4. Regresar al menu\n";
                    std::cout << "Elija una opcion: ";
                    std::cin >> opcion;

                    switch (opcion) {

                        case 1:

                            tienda.mostrarCatalogo();

                            break;

                        case 2:

                            tienda.mostrarCombo();

                            std::cout << "Ingrese el id del combo a comprar: ";
                            std::cin >> id;

                            posicion = tienda.buscarCombo(id);

                            if (posicion != -1) {

                                std::cout << "Total a pagar: $" << precioCombo[posicion];

                                do {

                                    std::cout << "\nDesea tener factura [Si = 1][No = 0]: ";
                                    std::cin >> factura;

                                    if (factura != 0 and factura != 1) {

                                        std::cout << "Ingrese 0 si no requiere factura o ingresae 1 si la requiere" << std::endl;

                                    }

                                } while (factura != 0 and factura != 1);

                                if (factura) {


                                    std::cout << "Cedula: ";
                                    cin.ignore();
                                    getline(std::cin, cedula);

                                    std::cout << "Telefono: ";
                                    getline(std::cin, telefono);

                                    std::cout << "Direccion: ";
                                    getline(std::cin, direccion);

                                    std::cout << "Correo Electronico: ";
                                    getline(std::cin, correoElectronico);

                                    Factura factura(cedula, telefono, direccion, correoElectronico);

                                    factura.mostrarFactura(precioCombo[posicion]);

                                }


                            }else {

                                std::cout << "No se encontro el id del combo a comprar" << std::endl;

                            }

                            break;

                        case 3:

                            tienda.mostrarProducto();

                            std::cout << "Ingrese el id del combo a comprar: ";
                            std::cin >> id;

                            posicion = tienda.buscarProducto(id);

                            if (posicion != -1) {

                                std::cout << "Ingrese el total de piezas a comprar: ";
                                std::cin >> totalPiezas;

                                std::cout << "Total a pagar: $" << totalPiezas * precioProducto[posicion];

                                do {

                                    std::cout << "\nDesea tener factura [Si = 1][No = 0]: ";
                                    std::cin >> factura;

                                    if (factura != 0 and factura != 1) {

                                        std::cout << "Ingrese 0 si no requiere factura o ingresae 1 si la requiere" << std::endl;

                                    }

                                } while (factura != 0 and factura != 1);

                                if (factura) {


                                    std::cout << "Cedula: ";
                                    cin.ignore();
                                    getline(std::cin, cedula);

                                    std::cout << "Telefono: ";
                                    getline(std::cin, telefono);

                                    std::cout << "Direccion: ";
                                    getline(std::cin, direccion);

                                    std::cout << "Correo Electronico: ";
                                    getline(std::cin, correoElectronico);

                                    Factura factura(cedula, telefono, direccion, correoElectronico);

                                    factura.mostrarFactura(precioProducto[posicion], totalPiezas);

                                }

                            }
                            else {

                                std::cout << "No se encontro el id del producto a comprar" << std::endl;

                            }

                            break;

                        case 4:

                            std::cout << "Regresando al menu principal" << std :: endl;

                            break;

                        default: 

                            std::cout << "Opcion invalida";

                    }
                    
                    if (opcion != 4) {

                        std::cout << endl;
                        system("pause");
                        system("cls");

                    }

                } while (opcion != 4);

                break;

            case 5:

                continuar = false;

                std::cout << "Saliendo del programa" << std::endl;

                break;

            default: cout << "Opcion invalida" << endl;

        }

        if (opcion != 5) {

            cout << endl;
            system("pause");
            system("cls");

        }

    }

}