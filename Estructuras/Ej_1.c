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
typedef struct controlAlquiler{
    
    char nomEmpresa[MAXTAM];
    int numPabellon;
    int dias;
    float metros;
    float precio;

} STAND;

typedef struct controlFeria{
    
    float tarifa, metrosAlquilados;
    
}PABE;

STAND *reservaMemoriaStands(int numElem);
PABE *reservaMemoriaPabe(int numElem);
void pideDatos(int *numStands);
void rellenaStands(STAND *stands, int numElem);
void limpiaBuffer();
void eliminaEnter(char *cadena);

int main(int argc, char** argv) {

    int numeroDeStands;
    STAND *stands;
    
    pideDatos(&numeroDeStands);
    stands = reservaMemoriaStands(numeroDeStands);
    rellenaStands(stands, numeroDeStands);
    
    free(stands);
    
    return (EXIT_SUCCESS);
}

STAND *reservaMemoriaStands(int numElem) {

    STAND *array = (STAND*)malloc(sizeof(STAND) * numElem);
    return array;
}

PABE *reservaMemoriaPabe(int numElem){
PABE *    
}
void pideDatos(int *numStands){
    printf("Introduce El numero de stands:\n");
    scanf("%d", numStands);
}
/////CODIGO SIN TERMINAR Y MAL
void limpiaBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);  // Vacía el buffer hasta el siguiente salto de línea
}

void eliminaEnter(char *cadena) {
    if (cadena[strlen(cadena) - 1] == '\n') {
        cadena[strlen(cadena) - 1] = '\0';
    }
}

void rellenaStands(STAND *stands, int numElem){
    ////    numPabellon, dias, metros, precio;

    
    for(int i = 0; i < numElem; i++){
        
    printf("Introduce el nombre de la empresa:\n");
    limpiaBuffer();
    fgets(stands[i].nomEmpresa, MAXTAM, stdin);
    eliminaEnter(stands[i].nomEmpresa);

    printf("Introduce el numero de pabellon:\n");
    scanf("%d",&stands[i].numPabellon);
    
    printf("Introduce el numero de dias de alquiler:\n");
    scanf("%d",&stands[i].dias);
    
    printf("Introduce el numero de metros cuadrados del stand:\n");
    scanf("%f",&stands[i].metros);
    
    printf("Introduce el precio total del aquiler:\n");
    scanf("%f",&stands[i].precio);
}
}
