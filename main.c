//---Macros
//--Colores
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

//---Bibliotecas
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//---Estructuras
typedef struct {
        int ID;
        char correo[50];
        char nom[15];
        char apater[15];
        char amater[15];
        unsigned int edad;
}Cliente;

typedef struct {
        char nom[20];
        unsigned int dia;
        unsigned int mes;
        unsigned int anio;
        char clas[2];
        unsigned int cal;
}Pelicula;

int opcion;

//---Prototipos de funciones
//--Clientes
void alta_clientes(), baja_clientes(), modif_clientes(), list_clientes();
//--Películas
void alta_pelis(), baja_pelis(), modificar_pelis(), list_pelis();
//--Core Functions
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
                printf("---------- FLIXNET ----------\n");
                printf("-----Clientes------------------\n");
                printf("1- Dar de alta un cliente\n");
                printf("2- Dar de baja un cliente\n");
                printf("3- Modificar un cliente\n");
                printf("4- Listar los clientes\n");
                printf("-----Películas-------------------");
                printf("5- Dar de alta una película\n");
                printf("6- Dar de baja una película\n");
                printf("7- Modificar una película\n");
                printf("8- Listar las películas\n");
                printf("9- Salir\n");
                scanf("%d",&op);

                switch(opcion) {
                        case 1: alta_clientes();
                        break;

                        case 2: baja_clientes();
                        break;

                        case 3: modif_clientes();
                        break;

                        case 4: list_clientes();
                        break;

                        case 5: alta_pelis();
                        break;

                        case 6: baja_pelis();
                        break;

                        case 7: modificar_pelis();
                        break;

                        case 8: list_pelis();
                        break;

                        case 9: break;
                }
        } while (opcion != 9);

}

void alta_clientes() {
        FILE *fp;

        Cliente client;
        fp = fopen("Clientes.cow", "ab");

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
        printf("\nIngrese el nom de usuario: ");
        scanf("%s",&client.nom);
        if(strlen(client.nom) == 0) {
                printf("No se permiten campos nulos");
                return 0;
        } else if(strlen(client.nom) > 15) {
                printf("Se excedió el número de caracteres aceptados");
                return 0;
        }

        // Ingreso de Apellido Paterno
        printf("\nIngrese el apellido paterno del usuario: ");
        scanf("%s",&client.apater);
        if(strlen(client.apater) == 0) {
                printf("No se permiten campos nulos");
                return 0;
        }else if(strlen(client.apater) > 15) {
                printf("Se excedió el número de caracteres aceptados");
                return 0;
        }

        // Ingreso de apellido materno
        printf("\nIngrese el apellido materno del usuario");
        scanf("%s",&client.amater);
        if(strlen(client.amater) == 0) {
                printf("No se permiten campos nulos");
                return 0;
        }else if(strlen(client.amater) > 15) {
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

        fseek(fp, 0L, SEEK_END);
        fwrite(&client,sizeof(Cliente),1,fp);
        fclose(fp);
        printf("\n\n\n\n\n\n\n\n\n");
        menu();
}

void list_clientes() {
        FILE *fp;

        Cliente client;

        fp = fopen("Clientes.cow","rb");
        fread(&client,sizeof(Cliente),1,fp);
        while(!feof(fp)) {
                printf("| %i | %s | %s | %s | %s | %u |\n"
                ,client.ID, client.nom, client.apater, client.edad);
                fread(&client,sizeof(Cliente),1,fp);
        }
        fclose(fp);
}

void alta_pelis() {
        FILE *fp;
        Pelicula peli;
        Cliente client;

        fp = fopen("Pelis.ntlx", "ab");

        // Ingreso de nom de la película
       printf("\nIngrese el nom de la película: ");
       scanf("%s", &peli.nom);
       if(strlen(peli.nom) == 0) {
               printf("\nNo se permiten campos nulos");
                return 0;
       } else if(strlen(peli.nom) > 20) {
               printf("\nSe excedieron los carácteres aceptados");
               return 0;
       }

        // Ingreso del día de la película
        printf("\nIngrese el día de renta: ");
        scanf("%u", &peli.dia);
        if(peli.dia == NULL || peli.dia == 0) {
                printf("\nEntrada errónea");
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
                printf("\nEntrada Errónea");
                return 0;
        }

        // Ingreso de clasificación
        printf("\nIngrese la clasificación de la película (A, AA, AB, etc");
        scanf("%u", &peli.clas);
        if(strlen(peli.clas) <= 0 || strlen(peli.clas) > 2) {
                printf("\nEntrada errónea");
                return 0;
        }

        // Ingreso de calificacion
        printf("\nIngrese la calificación de la película <1-5>");
        scanf("%u", &peli.cal);
        if(peli.cal < 1 || peli.cal > 5 || peli.cal == NULL) {
                printf("Entrada errónea");
                return 0;
        }
        
        fseek(fp, 0L, SEEK_END);
        fwrite(&peli,sizeof(Pelicula),1,fp);
        fclose(fp);
        printf("\n\n\n\n\n\n\n\n\n");
        menu();
}

void list_pelis() {
        FILE *fp;

        Pelicula peli;

        fp = fopen("Pelis.ntlx", "rb");
        fread(&peli,sizeof(Pelicula),1,fp);
        while(!feof(fp)) {
                printf("| %s | %u | %u | %u | %s | %u |"
                , peli.nom, peli.dia, peli.mes, peli.anio, peli.clas, peli.cal);
                fread(&peli,sizeof(Pelicula),1,fp);
        }
        fclose(fp);
}
