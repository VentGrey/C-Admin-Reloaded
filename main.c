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
        unsigned int calif;
}Pelicula;

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
        Pelicula peli;
        fp = fp("Clientes.res");

        // Datos del cliente
        printf("Ingrese el ID del cliente: ");
        scanf("%i",&client.ID);

        if(client.ID == NULL) {
                printf("No se permiten campos nulos");
                return 0;
        }

        // Ingreso de correo
        printf("\nIngrese el correo del cliente: ");
        scanf("%s",&client.correo);
        if(strlen(client.correo) == 0) {
                printf("No se permiten campos nulos");
                return 0;
        } else if(strlen(client.correo) > 50) {
                printf("Se excedió el número de caracteres aceptados");
                return 0;
        }

        // Ingreso de Username
        printf("\nIngrese el nombre de usuario: ");
        scanf("%s",&client.nombre);
        if(strlen(client.nombre) == 0) {
                printf("No se permiten campos nulos");
                return 0;
        } else if(strlen(client.nombre) > 15) {
                printf("Se excedió el número de caracteres aceptados");
                return 0;
        }

        // Ingreso de Apellido Paterno
        printf("\nIngrese el apellido paterno del usuario: ");
        scanf("%s",&client.apaterno);
        if(strlen(client.apaterno) == 0) {
                printf("No se permiten campos nulos");
                return 0;
        }else if(strlen(client.apaterno) > 15) {
                printf("Se excedió el número de caracteres aceptados");
                return 0;
        }

        // Ingreso de apellido materno
        printf("\nIngrese el apellido materno del usuario");
        scanf("%s",&client.amaterno);
        if(strlen(client.amaterno) == 0) {
                printf("No se permiten campos nulos");
                return 0;
        }else if(strlen(client.amaterno) > 15) {
                printf("Se excedió el número de caracteres aceptados");
                return 0;
        }

        // Ingreso de la edad del usuario
        printf("\nIngrese la edad del usuario: ");
        scanf("%s",&client.edad);
        if(client.edad== 0) {
                printf("No se permiten campos nulos");
                return 0;
        }

       // Ingreso de nombre de la película
       printf("\nIngrese el nombre de la película: ");
       scanf("%s", &peli.nombre);
       if(strlen(peli.nombre) == 0) {
               printf("\nNo se permiten campos nulos");
                return 0;
       } else if(strlen(peli.nombre) > 20) {
               printf("\nSe excedieron los carácteres aceptados");
               return 0;
       }

        // Ingreso del día de la película
        printf("\nIngrese el día de renta: ");
        scanf("%u", &peli.dia);
        if(peli.dia == NULL || peli.dia == 0) {
                printf("\nEntrada errónea")
               return 0; 
        }

        // Ingreso del mes

        printf("\nIngrese el mes de renta: ");
        scanf("%u", &peli.mes);
        if(peli.dia == NULL || peli.mes <= 0 || peli.mes > 12) {
                printf("\nEntrada Errónea");
                return 0;
        }

        // Ingreso del año
        printf("\nIngrese el año de renta: ");
        scanf("%u", &peli.anio);
        if(peli.anio == 0 || peli.anio <= 0) {
                printf("\nEntrada Errónea")
                return 0;
        }

        // Ingreso de clasificación
        printf("\nIngrese la clasificación de la película (A, AA, AB, etc");
        scanf("%u", &peli.clasificacion);
        if(strlen(peli.clasificacion) <= 0 || strlen(peli.clasificacion) > 2) {
                printf("\nEntrada errónea");
                return 0;
        }

        // Ingreso de calificacion
        printf("\nIngrese la calificación de la película <1-5>");
        scanf("%u", &peli.calif);
        if(peli.calif < 1 || peli.calif > 5 || peli.calif == NULL) {
                printf("Entrada errónea");
                return 0;
        }
        fseek(fp, 0L, SEEK_END);
        fwrite(&client,sizeof(Cliente),1,fp);
        fwrite(&peli,sizeof(Pelicula),1,fp);
        fclose(fp);
        printf("\n\n\n\n\n\n\n\n\n");
        menu();
}

