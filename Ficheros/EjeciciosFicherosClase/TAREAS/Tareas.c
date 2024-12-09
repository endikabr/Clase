/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   EjercicioTarea.c
 * Author: endik
 *
 * Created on 9 de diciembre de 2024, 18:19
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXTAM 500 
#define MAXTAMF 10

typedef struct {
    char fechaIni[MAXTAMF];
    char fechaFin[MAXTAMF];
    char descripcion[MAXTAM];

} TAREA;

int pideOpcion();
void muestraMenu();
int averiguaNumeElem(const char *nomFich);
TAREA *reservaMemoria(int numElem);
void limpiaBuffer();
/*
 * 
 */
int main(int argc, char** argv) {
    int opcion;

    do {

        muestraMenu();
        opcion = pideOpcion();

        switch (opcion) {
            case 1:
                insertaFicha("Tareas.dat");
                break;

            case 2:

                break;

            case 3:

                break;

            case 4:

                break;

            case 0:
                printf("Cerrando prograrma...");
                break;

            default:
                printf("Introduce una opcion valida.");
                break;
        }

    } while (opcion != 0);

    return (EXIT_SUCCESS);
}

int pideOpcion() {
    int num;
    scanf("%d", &num);
    return (num);
}

void muestraMenu() {

    printf("MENU:\n
            "1. - Insertar tarea.\n
            "2. - Eliminar una tarea.\n
            "3. - Actualizar fichero.\n
            "4. - Mostrar fichero\n
            "\n0.-SALIR\n");
}

int averiguaNumeElem(const char *nomFich) {
    unsigned short numElem = 0;

            FILE *f = fopen(nomFich, "rb");
    if (f != NULL) {
        fread(&numElem, sizeof (unsigned short), 1, f);
    } else {

        printf("Error al abrir el fichero");
    }

    return (numElem);
}

TAREA *reservaMemoria(int numElem) {
    TAREA *array = (TAREA) malloc(sizeof (TAREA) * numElem);

    return (array);
}

void insertaFicha(const char *nomFich) {

    int numElem;
            TAREA ficha;
            int posicion;

            numElem = averiguaNumeElem(nomFich);
            TAREA *array = reservaMemoria(numElem + 1);
            if(numElem != 0){
                volcarFicheroAArray(nomFich, array, numElem);
            }
            ficha = pideFicha();
            posicion = buscaPosicion(array, ficha);
            insertaElem(array, ficha, posicion); 
            volcarArrayAFichero(nomFich, array, numElem);
            
}

pideFicha() {
    TAREA ficha;

            printf("Introduce la fecha de inicio de la tarea con este formato XXXXYYZZ (x = año, y = mes, z = dia)");
            limpiaBuffer();
            fgets(ficha.fechaIni, stdin);
            eliminaEnter(ficha.fechaIni);

            printf("Introduce la fecha de fin de la tarea con este formato XXXXYYZZ (x = año, y = mes, z = dia)");
            limpiaBuffer();
            fgets(ficha.fechaFin, stdin);
            eliminaEnter(ficha.fechaFin);

            printf("Introduce la tarea");
            limpiaBuffer();
            fgets(ficha.descripcion, stdin);
            eliminaEnter(ficha.descripcion);

    return (ficha);
}

void limpiaBuffer() {
    __fpurge(stdin);
}

void eliminaEnter(char *cadena) {

}

void volcarFicheroAArray(const char *nomFich, TAREA *array, int *numElem){
    FILE *f = fopen(nomFich, "rb");
    if(f != NULL){
        fread(&numElem, sizeof(unsigned short), 1, f);
        fread(array, sizeof(TAREA), *numElem, f);
    fclose(f);
    }
    else{
        printf("\nError al abrir el fichero\n");
    }    
}

void volcarArrayAFichero(const char *nomFich, TAREA *array, unsigned short *numElem){
    FILE *f = fopen(nomFich, "wb");
    if(f != NULL){
        fwrite(numElem, sizeof(unsigned short), 1, f);
        fwrite(array, sizeof(TAREA), *numElem, f);
        fclose(f);
    }
    else{
        printf("\nError al abrir el fichero\n");
    }
}