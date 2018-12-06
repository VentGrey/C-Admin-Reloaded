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
}Cliente;

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
        } while (opcion != 4);

}

void alta_clientes() {
        FILE *fp;

        Cliente client;
        fp = fp("Clientes.res");

        // Datos del cliente
        printf("Ingrese el ID del cliente: ");
        scanf("%i",&client.ID);

        if(client.ID == 0) {
                client.ID = NULL;
                printf("No se permiten campos nulos");
                alta_clientes();
        }

        // Ingreso de correo
        printf("\nIngrese el correo del cliente: ");
        scanf("%s",&client.correo);
        if(strlen(client.correo) == 0) {
                client.correo = NULL;
                printf("No se permiten campos nulos");
                alta_clientes();
        } else if(strlen(client.correo) > 50) {
                printf("Se excedió el número de caracteres aceptados");
        }

        // Ingreso de Username
        printf("\nIngrese el nombre de usuario: ");
        scanf("%s",&client.nombre);
        if(strlen(client.nombre) == 0) {
                client.nombre = NULL;
                printf("No se permiten campos nulos");
                alta_clientes();
        } else if(strlen(client.correo) > 15) {
                printf("Se excedió el número de caracteres aceptados");
        }

        // Ingreso de Apellido Paterno
        printf("\nIngrese el apellido paterno del usuario: ");
        scanf("%s",&client.apaterno);
        if(strlen(client.apaterno) == 0) {
                client.apaterno = NULL;
                printf("No se permiten campos nulos");
                alta_clientes();
        }else if(strlen(client.correo) > 15) {
                printf("Se excedió el número de caracteres aceptados");
        }

        // Ingreso de apellido materno
        printf("\nIngrese el apellido materno del usuario");
        scanf("%s",&client.amaterno);
        if(strlen(client.amaterno) == 0) {
                client.amaterno = NULL;
                printf("No se permiten campos nulos");
                alta_clientes();
        }else if(strlen(client.correo) > 15) {
                printf("Se excedió el número de caracteres aceptados");
        }

        // Ingreso de la edad del usuario
        printf("\nIngrese la edad del usuario: ");
        scanf("%s",&client.edad);
        if(client.edad== 0) {
                client.edad = NULL;
                printf("No se permiten campos nulos");
                alta_clientes();
        }


        //Datos de las películas
}