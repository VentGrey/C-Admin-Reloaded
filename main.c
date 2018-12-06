//---Bibliotecas
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//---Estructuras
typedef struct {
        int ID;
        char correo[50];
        char nombre[15];
        char apaterno[15];
        char amaterno[15];
        unsigned int edad;
}cliente;

typedef struct {
        char nombre[20];
        unsigned int dia;
        unsigned int mes;
        unsigned int anio;
        char clasificacion[2];
        unsigned int calificacion;
}pelicula;

int opcion;

//---Prototipos de funciones
void alta_clientes(), baja_clientes(), modif_clientes(); //Funciones de cliente
void menu();


//---Función main
int main() {
        menu();
        return 0;
}


//---Funciones externas
void menu() {
        int op;

        do {
                printf("---------- FLIXNET ----------");
                printf("1- Dar de alta un cliente");
                printf("2- Dar de baja un cliente");
                printf("3- Modificar un cliente");
                printf("4- Salir")
                scanf("%d",&op);

                switch(opcion) {
                        case 1: alta_clientes();
                        break;

                        case 2: baja_clientes();
                        break;

                        case 3: modif_clientes();
                        break;

                        case 4: break;
                }
        } while (opcion != 5);

}