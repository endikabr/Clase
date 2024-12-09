#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Para usar strlen
#define _GNU_SOURCE
#include <stdio_ext.h> // Incluye el encabezado necesario para __fpurge

#define MAXCHAR 30
#define MAXELEM 40
#define RELOJ 7

typedef struct {
    int numero_vuelo;
    char destino[MAXCHAR];
    char horario_salida[RELOJ];
    int numero_plazas_libres;
} DATOS;

void limpiarBuffer();
int pideOpcion();
void visualizaMenu();
int averiguaNumElem(const char* nomFich);
void vuelcaFichArray(const char* nomFich, DATOS *array, int numElem);
void vuelcaArrayFich(const char* nomFich, DATOS *array, int numElem);

void insertaFicha(const char* nomFich);
void insertaElem(const char* nomFich, DATOS *array, int *numElem);

void visualizaFichero(const char* nomFich);
void visualizaFicha(DATOS ficha);

int main(int argc, char** argv) {
    int opcion;

    do {
        visualizaMenu(); // Llamada a la función para mostrar el menú
        opcion = pideOpcion(); // Obtener la opción del usuario
        switch (opcion) {
            case 1:
                visualizaFichero("InfoVuelos.dat");
                break;
            case 2:
                insertaFicha("InfoVuelos.dat");
                break;
            case 3:
                printf("Has Elegido la opcion 3\n");
                break;
            case 0:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Por favor inserta una opción válida\n");
        }
    } while (opcion != 0);

    return EXIT_SUCCESS;
}

void limpiarBuffer() {
    __fpurge(stdin);
}

int pideOpcion() {
    int opcion;
    limpiarBuffer();
    scanf("%d", &opcion);
    return opcion;
}

void visualizaMenu() {
    printf("\nMenu:\n"
           "1.- Informacion de vuelos\n"
           "2.- Añadir un nuevo vuelo\n"
           "3.- Cancelar un vuelo\n"
           "4.- Modificar el horario de salida de un vuelo\n"
           "5.- Actualizar el número de plazas libres de un vuelo\n"
           "0.- EXIT\n");
}

int averiguaNumElem(const char* nomFich) {
    FILE *f = fopen(nomFich, "rb");
    int numElem = 0;

    if (f != NULL) {
        fseek(f, 0, SEEK_END);
        long tam = ftell(f);
        numElem = tam / sizeof(DATOS);
        printf("Se encontraron %d elementos\n", numElem);
        fclose(f);
    } else {
        printf("No se pudo abrir el archivo correctamente\n");
    }
    return numElem;
}

void vuelcaFichArray(const char* nomFich, DATOS *array, int numElem) {
    FILE *f = fopen(nomFich, "rb");
    if (f == NULL) {
        printf("Error al leer el fichero\n");
        return;
    }
    fread(array, sizeof(DATOS), numElem, f);
    fclose(f);
}

void vuelcaArrayFich(const char* nomFich, DATOS *array, int numElem) {
    FILE *f = fopen(nomFich, "wb");
    if (f == NULL) {
        printf("Error al escribir en el fichero\n");
        return;
    }
    fwrite(array, sizeof(DATOS), numElem, f);
    fclose(f);
}

void insertaElem(const char* nomFich, DATOS *array, int *numElem) {
    if (*numElem >= MAXELEM) {
        printf("\nError: No se pueden insertar más vuelos, el array está lleno.\n");
        return;
    }

    DATOS nuevo;
    nuevo.numero_vuelo = *numElem + 1; // Asignar número de vuelo basado en la posición
    printf("\nIntroduce el destino del vuelo: ");
    limpiarBuffer();
    fgets(nuevo.destino, MAXCHAR, stdin);
    nuevo.destino[strcspn(nuevo.destino, "\n")] = '\0';

    printf("\nIntroduce la hora de salida (HH:MM): ");
    limpiarBuffer();
    fgets(nuevo.horario_salida, RELOJ, stdin);
    nuevo.horario_salida[strcspn(nuevo.horario_salida, "\n")] = '\0';

    printf("\nIntroduce la cantidad de plazas libres del avión: ");
    limpiarBuffer();
    scanf("%d", &nuevo.numero_plazas_libres);

    // Insertar el nuevo elemento en el array de manera ordenada
    int i = *numElem - 1;
    while (i >= 0 && strcmp(array[i].horario_salida, nuevo.horario_salida) > 0) {
        array[i + 1] = array[i]; // Desplazar elementos hacia adelante
        i--;
    }
    array[i + 1] = nuevo;
    (*numElem)++;
}

void insertaFicha(const char* nomFich) {
    DATOS array[MAXELEM];
    int numElem = averiguaNumElem(nomFich);
    vuelcaFichArray(nomFich, array, numElem);
    insertaElem(nomFich, array, &numElem);
    vuelcaArrayFich(nomFich, array, numElem);
}

void visualizaFichero(const char* nomFich) {
    DATOS ficha;
    FILE *f = fopen(nomFich, "rb");

    if (f != NULL) {
        while (fread(&ficha, sizeof(DATOS), 1, f) == 1) {
            visualizaFicha(ficha);
        }
        fclose(f);
    } else {
        printf("\nError al abrir el fichero\n");
    }
}

void visualizaFicha(DATOS ficha) {
    printf("Vuelo %d: Destino: %s, Salida: %s, Plazas libres: %d\n",
           ficha.numero_vuelo, ficha.destino, ficha.horario_salida, ficha.numero_plazas_libres);
}
