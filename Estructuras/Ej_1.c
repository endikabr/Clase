/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   1ej_Estructuras.c
 * Author: 1009672
 *
 * Created on November 13, 2024, 6:13 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#define MAXTAM 50
#define MAXPAB 5

/*
 * 
 */


typedef struct controlAlquiler {
    char nomEmpresa[MAXTAM];
    int numPabellon;
    int dias;
    float metros;
    float precio;

} STAND;

typedef struct controlFeria {
    float tarifa, metrosAlquilados;

} PABE;

STAND *reservaMemoriaStands(int numElem);
PABE *reservaMemoriaPabe(int numElem);
void pideDatos(int *numStands);
void rellenaStands(STAND *stands, int numEstand, int pabellon, int metroscuadrados);
void limpiaBuffer();
void eliminaEnter(char *cadena);
void precioPabe(PABE *pabellones, int numPabellones);
void eliminarStand(STAND *stands, int numStands);
void visualizaStands(STAND *stands, int numStands);

int main(int argc, char** argv) {

    int numeroDeStands, opcion, pabellon, metroscuadrados;
    STAND *stands;
    PABE *pabellones;
    int numPabellones = 5;
    int numEstand = 0;

    pideDatos(&numeroDeStands);
    stands = reservaMemoriaStands(numeroDeStands);
    pabellones = reservaMemoriaPabe(numPabellones);
    precioPabe(pabellones, numPabellones);

    do {
        printf("MENU\n\n");
        printf("1.- Añadir un stand.\n");
        printf("2.- Eliminar un stand.\n");
        printf("3.- Modificar la tarifa de un pabellon.\n");
        printf("4.- Visualizar la informacion de los stands y de los pabellones.\n");
        printf("5.- Salir del programa\n");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                rellenaStands(stands, numEstand, pabellon, metroscuadrados);
                numEstand++;
                pabellones[pabellon].metrosAlquilados = pabellones[pabellon].metrosAlquilados + metroscuadrados;
                break;
            case 2:

                break;
            case 3:
                break;
            case 4:
                visualizaStands(stands, numeroDeStands);
                break;
            case 0:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion invalida, porfavor introduzca un numero valido: \n");

        }
    } while (opcion != 0);


    free(stands);

    return (EXIT_SUCCESS);
}

STAND *reservaMemoriaStands(int numElem) {

    STAND *array = (STAND*) malloc(sizeof (STAND) * numElem);
    return array;
}

PABE *reservaMemoriaPabe(int numElem) {
    PABE *array = (PABE*) malloc(sizeof (PABE) * numElem);
    return (array);
}

void pideDatos(int *numStands) {
    printf("Introduce El numero de stands:\n");
    scanf("%d", numStands);
}

void limpiaBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // Vacía el buffer hasta el siguiente salto de línea
}

void eliminaEnter(char *cadena) {
    if (cadena[strlen(cadena) - 1] == '\n') {
        cadena[strlen(cadena) - 1] = '\0';
    }
}

void precioPabe(PABE *pabellones, int numPabellones) {

    for (int i = 0; i < numPabellones; i++) {
        printf("Introduce el precio (€/m^2 dia) del pabellon(%d)", i + 1);
        scanf("%f", &pabellones[i].tarifa);
    }
}

void rellenaStands(STAND *stands, int numEstand, int pabellon, int metroscuadrados) {
    ////    numPabellon, dias, metros, precio;
    printf("Introduce el nombre de la empresa:\n");
    limpiaBuffer();
    fgets(stands[numEstand].nomEmpresa, MAXTAM, stdin);
    eliminaEnter(stands[numEstand].nomEmpresa);

    printf("Introduce el numero de pabellon:\n");
    scanf("%d", &stands[numEstand].numPabellon);

    printf("Introduce el numero de dias de alquiler:\n");
    scanf("%d", &stands[numEstand].dias);

    printf("Introduce el numero de metros cuadrados del stand:\n");
    scanf("%f", &stands[numEstand].metros);

    printf("Introduce el precio total del aquiler:\n");
    scanf("%f", &stands[numEstand].precio);
    pabellon = stands[numEstand].numPabellon;
    metroscuadrados = stands[numEstand].metros;
}

void eliminarStand(STAND *stands, int numStands) {
    char empresa[MAXTAM];
    int encontrado = 1;
    int posicion;

    printf("Introduce el nombre de la empresa del stand que deseas eliminar: \n");
    do {
        limpiaBuffer();
        fgets(empresa, MAXTAM, stdin);
        eliminaEnter(empresa);

        for (int i = 0; i < numStands; i++) {
            if (strcmp(empresa, stands[i].nomEmpresa) == 0) {
                posicion = i;
                encontrado = 0;
                break;
            }
        }
    } while (encontrado == 1);
    for (int j = posicion; posicion < numStands - 1; j++) {
        stands[j] = stands[j + 1];
    }
}

void visualizaStands(STAND *stands, int numStands){
    for(int i = 0; i < numStands; i++){
        if(stands[i].metros != 0){
            printf("Empresa: %s\n", stands[i].nomEmpresa);
            printf("Pabellon: %d Alquiler: %d Dias, m^2: %f, Precio: %f.", stands[i].numPabellon, stands[i].dias, stands[i].metros, stands[i].precio);
        }
    }
}
