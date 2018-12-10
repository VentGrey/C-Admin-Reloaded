//---Macros
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

/* Estructura de tipo cliente, posee un ID el cual nos ayudará con el listado,
modificación u ordenamiento mas adelante. */
typedef struct {
        int ID;
        char correo[50];
        char nom[15];
        char apater[15];
        char amater[15];
        unsigned int edad;
}Cliente;


/* Estructura de tipo película, al igual que la estructura cliente esta posee
un Identificador que ayudará con su listado u ordenamiento */
typedef struct {
        int IDP;
        char nom[20];
        unsigned int dia;
        unsigned int mes;
        unsigned int anio;
        char clas[2];
        unsigned int cal;
}Pelicula;

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
                printf(ANSI_COLOR_RED "------ FLIXNET ----\n" ANSI_COLOR_RESET);
                printf(ANSI_COLOR_BLUE "-----Clientes-----\n" ANSI_COLOR_RESET);
                printf("1- Dar de alta un cliente\n");
                printf("2- Dar de baja un cliente\n");
                printf("3- Modificar un cliente\n");
                printf("4- Listar los clientes\n");
                printf(ANSI_COLOR_GREEN "---Películas-----\n" ANSI_COLOR_RESET);
                printf("5- Dar de alta una película\n");
                printf("6- Dar de baja una película\n");
                printf("7- Modificar una película\n");
                printf("8- Listar las películas\n");
                printf(ANSI_COLOR_RED "9- Salir\n" ANSI_COLOR_RESET);
                scanf("%d",&op);

                switch(op) {
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
        } while (op != 9);

}

//---Funciones pertenencientes a clientes
//--Funcion de alta de clientes
void alta_clientes() {
        FILE *fp;

        Cliente client;
        fp = fopen("Clientes.cow", "ab");

        // Datos del cliente
        printf(ANSI_COLOR_YELLOW "\nIngrese el ID del\
         cliente: " ANSI_COLOR_RESET);
        scanf("%i",&client.ID);

        if(client.ID == '\0') {
                printf(ANSI_COLOR_RED "Error de entrada" ANSI_COLOR_RESET);
                return;
        }

        // Ingreso de correo
        printf(ANSI_COLOR_YELLOW "\nIngrese el correo del\
         cliente: " ANSI_COLOR_RESET);
        scanf("%s",&client.correo);
        if(strlen(client.correo) == 0) {
                printf(ANSI_COLOR_RED "Error de entrada" ANSI_COLOR_RESET);
                return;
        } else if(strlen(client.correo) > 50) {
                printf(ANSI_COLOR_RED "Se excedió el número de\
                 caracteres aceptados" ANSI_COLOR_RESET);
                return;
        }

        // Ingreso de Username
        printf("\nIngrese el nom de usuario: ");
        scanf("%s",&client.nom);
        if(strlen(client.nom) == 0) {
                printf(ANSI_COLOR_RED "Error de entrada" ANSI_COLOR_RESET);
                return;
        } else if(strlen(client.nom) > 15) {
                printf(ANSI_COLOR_RED "Se excedió el número de\
                 caracteres aceptados" ANSI_COLOR_RESET);
                return;
        }

        // Ingreso de Apellido Paterno
        printf("\nIngrese el apellido paterno del usuario: ");
        scanf("%s",&client.apater);
        if(strlen(client.apater) == 0) {
                printf(ANSI_COLOR_RED "\nError de entrada" ANSI_COLOR_RESET);
                return;
        }else if(strlen(client.apater) > 15) {
                printf(ANSI_COLOR_RED "\nSe excedió el número de\
                 caracteres aceptados" ANSI_COLOR_RESET);
                return;
        }

        // Ingreso de apellido materno
        printf("\nIngrese el apellido materno del usuario");
        scanf("%s",&client.amater);
        if(strlen(client.amater) == 0) {
                printf(ANSI_COLOR_RED "\nNo se permiten\
                 campos nulos" ANSI_COLOR_RESET);
                return;
        }else if(strlen(client.amater) > 15) {
                printf(ANSI_COLOR_RED "\nSe excedió el número de\
                 caracteres aceptados" ANSI_COLOR_RESET);
                return;
        }

        // Ingreso de la edad del usuario
        printf("\nIngrese la edad del usuario: ");
        scanf("%s",&client.edad);
        if(client.edad == 0) {
                printf(ANSI_COLOR_RED "\nError de entrada" ANSI_COLOR_RESET);
                return; 
        }

        fseek(fp, 0L, SEEK_END);
        fwrite(&client,sizeof(Cliente),1,fp);
        fclose(fp);
        menu();
}

void list_clientes() {
        FILE *fp;

        Cliente client;

        fp = fopen("Clientes.cow","rb");
        fread(&client,sizeof(Cliente),1,fp);
        while(!feof(fp)) {
                printf("|ID: %i |Correo: %s |Nombre: %s \
                |Apellido Paterno: %s |Apellido Materno: %s |Edad: %u |\n"
                ,client.ID, client.nom, client.apater, client.amater, 
                client.edad);
                fread(&client,sizeof(Cliente),1,fp);
        }
        fclose(fp);
}

void modif_clientes() {
        FILE *fp, *fpa;
        Cliente client;
        int aux;

        fp = fopen("Clientes.cow","rb");
        fpa = fopen("Clientestemp.meow", "ab");

        printf("\nIngrese el ID del cliente: ");
        scanf("%i", &aux);

        while(!feof(fp)) {
                if(client.ID != aux) {
                        fseek(fpa, 0l,SEEK_END);
                        fwrite(&client,sizeof(Cliente),1,fpa);
                } else {
                        printf("\nIngrese el nombre: ");
                        scanf("%s", client.nom);

                        printf("\nIngrese el apellido paterno: ");
                        scanf("%s", client.apater);

                        printf("\nIngrese el apellido materno: ");
                        scanf("%s", client.amater);

                        printf("\nIngrese la edad del cliente: ");
                        scanf("%u", client.edad);
                }
                fread(&client,sizeof(Cliente),1,fp);
        }
        fclose(fp);
        fclose(fpa);
        remove("Clientes.cow");
        rename("Clientestemp.meow","Clientes.cow");

}

void baja_clientes() {
        FILE *fp, *fpa;
        Cliente client;
        int aux;

        fp = fopen("Clientes.cow","rb");
        fpa = fopen("Clientestemp.meow", "ab");

        printf("\nIngrese el ID del cliente a dar de baja: ");
        scanf("%i", &aux);

        fread(&client,sizeof(Cliente),1,fp);
        while(!feof(fp)) {
                if(client.ID != aux) {
                        fseek(fpa,0l,SEEK_END);
                        fwrite(&client,sizeof(Cliente),1,fpa);
                }
                fread(&client,sizeof(Cliente),1,fp);
        }
        fclose(fp);
        fclose(fpa);
        remove("Clientes.cow");
        rename("Clientestemp.meow","Clientes.cow");
}


//---Funciones pertenecientes a películas
void alta_pelis() {
        FILE *fp;
        Pelicula peli;
        Cliente client;

        fp = fopen("Pelis.ntlx", "ab");

        //Ingreso del ID de la película
        printf("\nIngrese el ID de la película: ");
        scanf("%i", &peli.IDP);
        if(peli.IDP = "\0") {
                printf("Error de entrada :(");
                return;
        }

        // Ingreso de nom de la película
       printf("\nIngrese el nombre de la película: ");
       scanf("%s", &peli.nom);
       if(strlen(peli.nom) == 0) {
               printf("\nNo se permiten campos nulos");
                return;
       } else if(strlen(peli.nom) > 20) {
               printf("\nSe excedieron los carácteres aceptados");
               return;
       }

        // Ingreso del día de la película
        printf("\nIngrese el día de renta: ");
        scanf("%u", &peli.dia);
        if(peli.dia == '\0' || peli.dia == 0) {
                printf("\nEntrada errónea");
               return; 
        }

        // Ingreso del mes

        printf("\nIngrese el mes de renta: ");
        scanf("%u", &peli.mes);
        if(peli.dia == '\0' || peli.mes <= 0 || peli.mes > 12) {
                printf("\nEntrada Errónea");
                return;
        }

        // Ingreso del año
        printf("\nIngrese el año de renta: ");
        scanf("%u", &peli.anio);
        if(peli.anio == 0 || peli.anio <= 0) {
                printf("\nEntrada Errónea");
                return;
        }

        // Ingreso de clasificación
        printf("\nIngrese la clasificación de la película (A, AA, AB, etc");
        scanf("%u", &peli.clas);
        if(strlen(peli.clas) <= 0 || strlen(peli.clas) > 2) {
                printf("\nEntrada errónea");
                return;
        }

        // Ingreso de calificacion
        printf("\nIngrese la calificación de la película <1-5>");
        scanf("%u", &peli.cal);
        if(peli.cal < 1 || peli.cal > 5 || peli.cal == '\0') {
                printf("Entrada errónea");
                return;
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
                printf("| %d | %s | %u | %u | %u | %s | %u |"
                ,peli.IDP, peli.nom, peli.dia, peli.mes, peli.anio, peli.clas, 
                peli.cal);
                fread(&peli,sizeof(Pelicula),1,fp);
        }
        fclose(fp);
}

void modificar_pelis() {
        FILE *fp, *fpa;
        Pelicula peli;
        int aux;

        fp = fopen("Pelis.ntlx","rb");
        fpa = fopen("Pelistemp.wow","rb");

        printf("\nIngrese el ID de la película: ");
        scanf("%i", &aux);

        while(!feof(fp)) {
                if(peli.IDP != aux) {
                        fseek(fpa, 0l, SEEK_END);
                        fwrite(&peli,sizeof(Pelicula),1,fpa);
                } else {
                        printf("\nIngrese el nombre de la película: ");
                        scanf("%s", &peli.nom);

                        printf("Ingrese el día de renta: ");
                        scanf("%u", &peli.dia);

                        printf("Ingrese el mes de renta: ");
                        scanf("%u", &peli.mes);

                        printf("Ingrese el año de renta: ");
                        scanf("%u", &peli.anio);

                        printf("Ingrese la clasificación: ");
                        scanf("%s", &peli.clas);

                        printf("Ingrese la calificación (1-5): ");
                        scanf("%u", &peli.cal);
                }
                fread(&peli,sizeof(Pelicula),1,fp);
        }
        fclose(fp);
        fclose(fpa);
        remove("Pelis.ntlx");
        rename("Pelistemp.wow","Pelis.ntlx");
}

void baja_pelis() {
        FILE *fp, *fpa;
        Pelicula peli;
        int aux;

        fp = fopen("Pelis.ntlx","rb");
        fpa = fopen("Pelistemp.wow", "ab");

        printf("\nIngrese el ID de la película a dar de baja: ");
        scanf("%i", &aux);

        fread(&peli,sizeof(Pelicula),1,fp);
        while(!feof(fp)) {
                if(peli.IDP != aux) {
                        fseek(fpa,0l,SEEK_END);
                        fwrite(&peli,sizeof(Pelicula),1,fpa);
                }
                fread(&peli,sizeof(Pelicula),1,fp);
        }
        fclose(fp);
        fclose(fpa);
        remove("Pelis.ntlx");
        rename("Pelistemp.wow","Pelis.ntlx");
}