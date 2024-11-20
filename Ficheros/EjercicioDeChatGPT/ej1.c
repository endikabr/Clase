#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTAM 50

typedef struct {
    int id;
    char nombre[MAXTAM];
    float salario;
} EMPLEADO;

//esto es un programa de chat gpt

int averiguaNumElem(char *nomFich);
EMPLEADO *reservaMemoriaEmpleado(int numElem);
int vuelcaFicheroAArray(char *nomFich, EMPLEADO *array, int numElem);
void insertaFicha(char *nomFich);
int insertaElemento(EMPLEADO *array, int numElem);
int buscaPosicion(EMPLEADO *array, int numElem, int elemento);
void inserta(EMPLEADO *array, int numElem, int elemento, int posicion);

int main() {
    insertaFicha("empleados.dat");
    return 0;
}

int averiguaNumElem(char *nomFich) {
    int numElem;
    FILE *f = fopen(nomFich, "rb");

    if (f == NULL) {
        printf("\nNo se ha podido abrir el fichero.\n");
        return -1;
    }

    if (fread(&numElem, sizeof(int), 1, f) != 1) {
        printf("\n No se ha encontrado ningun elemento en el fichero.\n");
        fclose(f);
        return -1;
    }
    fclose(f);
    return numElem;
}

EMPLEADO *reservaMemoriaEmpleado(int numElem) {
    EMPLEADO *array = (EMPLEADO *)malloc(sizeof(EMPLEADO) * numElem);
    if (array == NULL) {
        printf("Error al reservar memoria.\n");
    }
    return array;
}

int vuelcaFicheroAArray(char *nomFich, EMPLEADO *array, int numElem) {
    FILE *f = fopen(nomFich, "rb");
    if (f == NULL) {
        printf("\nNo se pudo abrir el fichero\n");
        return -1;
    }
    fseek(f, sizeof(int), SEEK_SET);
    int elementosLeidos = fread(array, sizeof(EMPLEADO), numElem, f);

    if (elementosLeidos != numElem) {
        printf("\nAdvertencia, se esperaban %d empleados pero solo se leyeron %d\n", numElem, elementosLeidos);
    }

    fclose(f);
    return elementosLeidos;
}

int buscaPosicion(EMPLEADO *array, int numElem, int elemento) {
    for (int i = 0; i < numElem; i++) {
        if (elemento < array[i].id) {
            return i;
        }
    }
    return numElem; // Si no encontró una posición, insertar al final
}

int insertaElemento(EMPLEADO *array, int numElem) {
    int elemento;

    printf("\nIntroduce el ID del empleado que deseas añadir a la base de datos: ");
    scanf("%d", &elemento);

    int posicion = buscaPosicion(array, numElem, elemento);
    inserta(array, numElem, elemento, posicion);

    return numElem + 1;
}

void inserta(EMPLEADO *array, int numElem, int elemento, int posicion) {
    for (int i = numElem; i > posicion; i--) {
        array[i] = array[i - 1];
    }

    array[posicion].id = elemento;
    printf("\nIntroduce el nombre del empleado: ");
    scanf(" %[^\n]", array[posicion].nombre);

    printf("\nIntroduce su salario: ");
    scanf("%f", &array[posicion].salario);
}

void insertaFicha(char *nomFich) {
    EMPLEADO *arrayDeEmpleados;
    int numElem = averiguaNumElem(nomFich);
    if (numElem == -1) return;

    arrayDeEmpleados = reservaMemoriaEmpleado(numElem + 1);
    if (arrayDeEmpleados == NULL) return;

    int elementosEnElArray = vuelcaFicheroAArray(nomFich, arrayDeEmpleados, numElem);
    if (elementosEnElArray == -1) {
        free(arrayDeEmpleados);
        return;
    }

    numElem = insertaElemento(arrayDeEmpleados, elementosEnElArray);

for(int i = 0; i < numElem; i++){
    printf("%d", arrayDeEmpleados[i].id);
}

    free(arrayDeEmpleados);
}
