#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la estructura Empleado
typedef struct {
    int id;            // Identificador único del empleado
    char nombre[50];   // Nombre del empleado
    float salario;     // Salario del empleado
} Empleado;

void crearFichero(const char *nombreFichero) {
    // Abrimos el fichero en modo binario para escritura
    FILE *fichero = fopen(nombreFichero, "wb");
    if (fichero == NULL) {
        perror("Error al abrir el fichero");
        exit(EXIT_FAILURE);
    }

    // Número de empleados
    int numElem = 6;

    // Datos de los empleados
    Empleado empleados[] = {
        {1, "Ana Pérez", 2500.50},
        {2, "Luis Gómez", 3200.00},
        {3, "Marta Sánchez", 4000.75},
        {4, "Carlos Ruiz", 2800.00},
        {5, "Lucía Fernández", 3100.25},
        {6, "Jorge Ramírez", 4500.00}
    };

    // Escribimos el número de elementos (cabecera)
    fwrite(&numElem, sizeof(int), 1, fichero);

    // Escribimos las estructuras de los empleados
    fwrite(empleados, sizeof(Empleado), numElem, fichero);

    // Cerramos el fichero
    fclose(fichero);
    printf("Fichero '%s' creado correctamente con %d empleados.\n", nombreFichero, numElem);
}

int main() {
    // Crear el fichero binario
    crearFichero("empleados.dat");
    return 0;
}
