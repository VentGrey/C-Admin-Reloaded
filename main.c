//---Bibliotecas
#include <stdio.h>
#include <string.h>


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


//---Prototipos de funciones
int menu();


//--- Función principal
int main() {
        int opcion;

        opcion = menu();



}

//---Funciones
int menu() {
        char s[50];
        int c;

        printf("------ Menú principal ------");
        printf("*** Clientes ***");
        printf("1- Registrar un usuario");
        printf("2- Modificar todos los usuarios"); //Dentro hay mas menús para 
        printf("4- Guardar archivo de usuarios");
        printf("5- Cargar archivo de usuarios");

        do {
                printf("Ingrese la opción deseada: ");
                fgets(s, sizeof(s), stdin);
                c = atoi(s);
        } while (c < 0 || c > 9);

        return c;
}