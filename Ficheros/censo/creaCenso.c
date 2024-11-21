#include <stdio.h>
#include <string.h>
#define TAMANOCENSO 100
#define MAXTAM 50

typedef struct {
    char nombre[MAXTAM];
    char apellidos[MAXTAM];
    int ano; // Año de nacimiento
    char ciudad[MAXTAM];
} CENS;

void creaCenso(const char *nomFich);

int main() {
    // Llamamos a la función para crear el archivo del censo
    creaCenso("censo.dat");

    printf("Censo creado correctamente en 'censo.dat'.\n");
    return 0;
}

void creaCenso(const char *nomFich) {
    int elemenEnElCenso = 0; // Contador de elementos
    CENS censo[TAMANOCENSO] = {
        {"Antonio", "González", 1977, "Lugo"},
        {"Beatriz", "Hernández", 1989, "Girona"},
        {"Juan", "Álvarez", 1986, "Almería"},
        {"Patricia", "Martín", 1990, "Salamanca"},
        {"Luis", "Cordero", 1984, "Oviedo"},
        {"Esteban", "Bravo", 1992, "Soria"},
        {"Ramírez", "Santos", 1995, "Tarragona"},
        {"Pérez", "Gutiérrez", 1982, "Badajoz"},
        {"Silvia", "López", 1987, "Córdoba"},
        {"Eduardo", "Ruiz", 1990, "Madrid"},
        {"Ana", "García", 1993, "Sevilla"},
        {"Carlos", "Romero", 1988, "Valencia"},
        {"Isabel", "Fernández", 1991, "Bilbao"},
        {"Diego", "Navarro", 1985, "Alicante"},
        {"María", "Sánchez", 1994, "Zaragoza"},
        {"Andrés", "Jiménez", 1996, "Granada"},
        {"Lucía", "Molina", 1983, "Santander"},
        {"Pedro", "Vázquez", 1981, "Málaga"},
        {"Laura", "Domínguez", 1980, "Valladolid"},
        {"Jorge", "Gómez", 1979, "San Sebastián"}
    };

    // Calculamos el número de elementos válidos en el censo
    for (int i = 0; i < TAMANOCENSO && censo[i].ano > 0; i++) {
        elemenEnElCenso++;
    }

    // Intentamos abrir el archivo en modo binario
    FILE *f = fopen(nomFich, "wb");
    if (f == NULL) {
        printf("No se ha podido crear el fichero correctamente.\n");
        return;
    }

    // Escribimos los datos en el archivo
    fwrite(censo, sizeof(CENS), elemenEnElCenso, f);

    // Cerramos el archivo
    fclose(f);
    printf("Se escribieron %d elementos en el censo.\n", elemenEnElCenso);
}