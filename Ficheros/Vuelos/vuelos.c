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

void limpiarBuffer();
int averiguaNumElem(const char* nomFich);
void vuelcaFichArray(const char* nomFich, DATOS *array, int *numElem);
void vuelcaArrayFich(const char* nomFich, DATOS *array, int *numElem);

void insertaFicha(const char* nomFich, DATOS *array, int *numElem);


int main(int argc, char** argv) {

    int opcion;
    do {
        printf("\nMenu:\n"
                "1.-\n"
                "2.-\n"
                "3.-\n"
                "0.-EXIT\n");
        limpiarBuffer();
        scanf("%d", &opcion);
        switch (opcion) {

            case 1:
                printf("Has Elegido la opcion 1");
                break;

            case 2:
                printf("Has Elegido la opcion 2");
                break;

            case 3:
                printf("Has Elegido la opcion 3");
                break;

            case 0:
                printf("Saliendo del programa...");
                break;

            default:
                printf("Porfavor inserta una opcion valida");
        }
    } while (opcion != 0);

    return (EXIT_SUCCESS);
}

void limpiarBuffer() {
    __fpurge(stdin);
}

void vuelcaFichArray(const char* nomFich, DATOS *array, int *numElem){
    FILE *f = fopen(nomFich, "rb");
    if(f == NULL){
        printf("Error al leer el fichero");
    }
    fread(array, sizeof(DATOS), numElem, f);
    fclose(f);
}

void vuelcaArrayFich(const char* nomFich, DATOS *array, int *numElem){
    FILE *f = fopen(nomFich, "wb");
    if(f == NULL){
        printf("Error al leer el fichero");
    }
    fwrite(array, sizeof(DATOS), numElem, f);
    fclose(f);    
}

void insertaElem(const char* nomFich, DATOS *array, int *numElem) {
    if (*numElem >= MAXELEM) { // Validar si el array está lleno
        printf("Error: No se pueden insertar más vuelos, el array está lleno.\n");
        return;
    }

    printf("Introduce el destino del vuelo: ");
    limpiarBuffer();
    fgets(array[*numElem].destino, MAXCHAR, stdin);
    array[*numElem].destino[strcspn(array[*numElem].destino, "\n")] = '\0'; // Eliminar salto de línea

    printf("Introduce la hora de salida (HH:MM): ");
    limpiarBuffer();
    fgets(array[*numElem].horario_salida, RELOJ, stdin);
    array[*numElem].horario_salida[strcspn(array[*numElem].horario_salida, "\n")] = '\0'; // Eliminar salto de línea

    printf("Introduce la cantidad de plazas libres del avión: ");
    limpiarBuffer();
    scanf("%d", &array[*numElem].numero_plazas_libres); // Usar '&' para scanf

    (*numElem)++; // Incrementar después de insertar los datos
}

void insertaFicha(cosnt char* nomFich, DATOS *array, int *numElem){
    DATOS array[MAXELEM];
    int numElem;
    vuelcaFichArray(nomFich, *array, *numElem);
    insertaElem(nomFich, *array, *numElem);
    vuelcaArrayFich(nomFich, *array, *numElem);
}
