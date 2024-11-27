#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Para usar strlen
#define MAXCHAR 30
#define MAXELEM 40
#define RELOJ 7

typedef struct {
    int numero_vuelo;
    char destino[MAXCHAR];
    char horario_salida[RELOJ];
    int numero_plazas_libres;
} DATOS;

// Prototipos de funciones
int averiguaNumeElem(const char* nomFich);
void insertaElementoEnFichero(const char* nomFich);
void vuelcaFicheroAArray(const char* nomFich, DATOS *vuelos, int numElem);
void vuelcaArrayAFichero(const char *nomFich, DATOS *array, int numElem);
int anadeFicha(DATOS *array, int numElem);
void limpiarBuffer();
void eliminarEnter(char *cadena);

int main(int argc, char** argv) {
    insertaElementoEnFichero("vuelos.dat");
    return (EXIT_SUCCESS);
}

int averiguaNumeElem(const char* nomFich) {
    FILE *f = fopen(nomFich, "rb");
    if (f == NULL) {
        printf("No se pudo abrir el fichero correctamente\n");
        return 0;
    }

    fseek(f, 0, SEEK_END); // Mover al final del archivo
    long fileSize = ftell(f); // Obtener el tamaño del archivo
    fclose(f);

    return fileSize / sizeof(DATOS); // Número de elementos
}

void insertaElementoEnFichero(const char* nomFich) {
    DATOS vuelos[MAXELEM];

    int numElem = averiguaNumeElem(nomFich);
    vuelcaFicheroAArray(nomFich, vuelos, numElem);
    numElem = anadeFicha(vuelos, numElem);
    vuelcaArrayAFichero(nomFich, vuelos, numElem);
}

void vuelcaArrayAFichero(const char *nomFich, DATOS *array, int numElem) {
    FILE *f = fopen(nomFich, "wb");
    if (f == NULL) {
        printf("No se pudo abrir el fichero correctamente\n");
        return;
    }

    fwrite(array, sizeof(DATOS), numElem, f);
    fclose(f);
}

int anadeFicha(DATOS *array, int numElem) {
    printf("Introduce el número de vuelo: ");
    scanf("%d", &array[numElem].numero_vuelo);
    limpiarBuffer(); // Limpia el búfer después de leer un número

    printf("Introduce el destino del vuelo: ");
    fgets(array[numElem].destino, MAXCHAR, stdin);
    eliminarEnter(array[numElem].destino); // Elimina el salto de línea

    printf("Introduce el horario del vuelo (HH:MM): ");
    fgets(array[numElem].horario_salida, RELOJ, stdin);
    eliminarEnter(array[numElem].horario_salida); // Elimina el salto de línea

    printf("Introduce el número de plazas libres: ");
    scanf("%d", &array[numElem].numero_plazas_libres);
    limpiarBuffer(); // Limpia el búfer después de leer un número

    numElem++;
    return numElem;
}

void vuelcaFicheroAArray(const char* nomFich, DATOS *vuelos, int numElem) {
    FILE *f = fopen(nomFich, "rb");
    if (f == NULL) {
        printf("No se pudo abrir el fichero correctamente\n");
        return;
    }

    fread(vuelos, sizeof(DATOS), numElem, f);
    fclose(f);
}

// Función para limpiar el búfer de entrada
void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // Consume caracteres hasta vaciar el búfer
    }
}

// Función para eliminar el salto de línea de una cadena
void eliminarEnter(char *cadena) {
    size_t len = strlen(cadena);
    if (len > 0 && cadena[len - 1] == '\n') {
        cadena[len - 1] = '\0';
    }
}
