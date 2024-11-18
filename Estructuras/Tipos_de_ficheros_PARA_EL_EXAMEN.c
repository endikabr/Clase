Tipos de Ficheros
Tipo 1: Fichero con Cabecera de Filas y Columnas, seguido de unsigned char
Descripción:
El primer elemento del fichero es una estructura que contiene las dimensiones de una matriz (filas y columnas). El resto de los elementos son datos de tipo unsigned char organizados por filas.

Formato del fichero:

Cabecera: Una estructura con:
filas (int): Número de filas.
columnas (int): Número de columnas.
Datos: Elementos de tipo unsigned char organizados fila por fila.
Código:
c
Copiar código
typedef struct {
    int filas;         // Número de filas
    int columnas;      // Número de columnas
} Cabecera;

void procesarFicheroConCabecera(const char *nomFich) {
    FILE *puntFich;
    Cabecera cabecera;
    unsigned char valor;

    if ((puntFich = fopen(nomFich, "rb")) != NULL) {
        // Leer la cabecera
        fread(&cabecera, sizeof(Cabecera), 1, puntFich);
        printf("Dimensiones de la matriz: %d filas x %d columnas\n", cabecera.filas, cabecera.columnas);

        // Leer y mostrar los datos
        for (int i = 0; i < cabecera.filas; i++) {
            for (int j = 0; j < cabecera.columnas; j++) {
                fread(&valor, sizeof(unsigned char), 1, puntFich);
                printf("%3u ", valor);  // Mostrar valor como entero sin signo
            }
            printf("\n");
        }

        fclose(puntFich);
    } else {
        printf("Error al abrir el fichero %s.\n", nomFich);
    }
}
Tipo 2: Fichero de Elementos de Tipo Estructura, Sin Cabecera
Descripción:
Contiene solo elementos de tipo estructura. No hay cabecera inicial que indique cuántos elementos hay en el fichero.
Código:
c
Copiar código
void procesarFicheroSinCabecera(const char *nomFich) {
    FILE *puntFich;
    Elemento elemento;

    if ((puntFich = fopen(nomFich, "rb")) != NULL) {
        printf("Fichero %s abierto correctamente.\n", nomFich);

        // Leer y procesar los elementos
        while (fread(&elemento, sizeof(Elemento), 1, puntFich) != 0) {
            visualizaFicha(elemento);  // Función para mostrar los datos
        }

        fclose(puntFich);
    } else {
        printf("Error al abrir el fichero %s.\n", nomFich);
    }
}
Tipo 3: Fichero con Cabecera numElem, seguido de Elementos de Tipo Estructura
Descripción:
El primer elemento del fichero es un entero que indica cuántos elementos hay. El resto son estructuras con los datos.
Código:
c
Copiar código
void procesarFicheroConNumElem(const char *nomFich) {
    FILE *puntFich;
    int numElem;
    Elemento elemento;

    if ((puntFich = fopen(nomFich, "rb")) != NULL) {
        // Leer la cabecera
        fread(&numElem, sizeof(int), 1, puntFich);
        printf("Número de elementos en el fichero: %d\n", numElem);

        // Leer y procesar los elementos
        for (int i = 0; i < numElem; i++) {
            fread(&elemento, sizeof(Elemento), 1, puntFich);
            visualizaFicha(elemento);
        }

        fclose(puntFich);
    } else {
        printf("Error al abrir el fichero %s.\n", nomFich);
    }
}
Tipo 4: Fichero con Dos Cabeceras (Filas y Columnas), seguido de unsigned char
Descripción:
Contiene dos enteros al inicio (número de filas y columnas) como cabecera. El resto de los datos son de tipo unsigned char, organizados por filas.
Código:
c
Copiar código
void procesarFicheroConDosCabeceras(const char *nomFich) {
    FILE *puntFich;
    int filas, columnas;
    unsigned char valor;

    if ((puntFich = fopen(nomFich, "rb")) != NULL) {
        // Leer las dos cabeceras
        fread(&filas, sizeof(int), 1, puntFich);
        fread(&columnas, sizeof(int), 1, puntFich);
        printf("Dimensiones de la matriz: %d filas x %d columnas\n", filas, columnas);

        // Leer y mostrar los datos
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                fread(&valor, sizeof(unsigned char), 1, puntFich);
                printf("%3u ", valor);
            }
            printf("\n");
        }

        fclose(puntFich);
    } else {
        printf("Error al abrir el fichero %s.\n", nomFich);
    }
}
Tabla Resumen
Tipo	Descripción	Cabecera	Datos
1	Cabecera con filas y columnas, seguido de datos unsigned char.	Estructura (filas y columnas)	unsigned char
2	Solo contiene elementos de tipo estructura, sin cabecera.	Ninguna	Estructura
3	Cabecera con número de elementos (numElem), seguido de elementos de tipo estructura.	Entero (numElem)	Estructura
4	Dos enteros iniciales (filas y columnas), seguido de datos unsigned char.	Dos enteros (filas, columnas)	unsigned char
Consejos para el Examen
Identificar el Tipo de Fichero:

Examina si tiene cabeceras y qué tipo de datos contiene.
Usar fread y sizeof:

Asegúrate de usar el tamaño correcto para leer cada dato (sizeof).
Control de Bucles:

Si hay cabeceras, usa su información para controlar los bucles (filas, columnas, o número de elementos).
Si no hay cabecera, lee hasta el final del fichero.
Tipos de Datos:

Para datos de tipo unsigned char, recuerda que se muestran como enteros sin signo (%u).
