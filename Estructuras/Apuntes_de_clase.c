///VISUALIZAR FICHERO
///VISUALIZA FICHA

void visualizarFichero(const char *nomFich) {
    FILE *puntFich;
    Elemento elemento;

    // Intentar abrir el fichero en modo lectura binaria
    if ((puntFich = fopen(nomFich, "rb")) != NULL) {
        printf("Fichero %s abierto correctamente para lectura.\n", nomFich);

        // Leer y visualizar cada elemento mientras haya datos en el fichero
        while (fread(&elemento, sizeof(Elemento), 1, puntFich) != 0) {
            visualizaFicha(elemento);
        }

        // Cerrar el fichero
        fclose(puntFich);
        printf("Fichero cerrado correctamente.\n");
    } else {
        printf("Error al abrir el fichero %s.\n", nomFich);
    }
}


//creaFichero
void creaFichero(const char *nomFich) {
    FILE *puntFich;
    Elemento elemento;
    char continuar;

    // Abrir el fichero para escritura binaria
    if ((puntFich = fopen(nomFich, "wb")) != NULL) {
        printf("Fichero %s abierto correctamente para escritura.\n", nomFich);

        // Sentencia repetitiva para agregar múltiples fichas
        do {
            // Crear una ficha
            elemento = creaFicha();

            // Escribir la ficha en el fichero
            fwrite(&elemento, sizeof(Elemento), 1, puntFich);

            // Preguntar si se desea añadir otra ficha
            printf("¿Deseas añadir otra ficha? (s/n): ");
            scanf(" %c", &continuar);
        } while (continuar == 's' || continuar == 'S');

        // Cerrar el fichero
        fclose(puntFich);
        printf("Fichero cerrado correctamente.\n");
    } else {
        printf("Error al abrir el fichero %s.\n", nomFich);
    }
}


int averiguaNumElem (){
//funcion averigua numElem, essta funcion abre el fichero, leee el primer dato, y cierra el fichero



vuelca fichero()
// nos saltamos el primer elemento del fichero por que este solo contiene la cantidad de elementos, para eso usaremos. para eso usaremos fsin o algo asi, y luego sentencia repetitiva while(fread =! 0)


///tipos de ficheros

Tipo 1: Primer elemento es una estructura (cabecera) con filas y columnas; el resto son elementos individuales
Descripción:
El primer elemento del fichero es una estructura que contiene las dimensiones de una matriz (número de filas y columnas). Los elementos de la matriz están almacenados de forma secuencial.

Código:
c
Copiar código
typedef struct {
    int filas;
    int columnas;
} Cabecera;

void procesarFicheroConCabecera(const char *nomFich) {
    FILE *puntFich;
    Cabecera cabecera;
    int valor;

    if ((puntFich = fopen(nomFich, "rb")) != NULL) {
        // Leer la cabecera
        fread(&cabecera, sizeof(Cabecera), 1, puntFich);
        printf("Dimensiones de la matriz: %d filas x %d columnas\n", cabecera.filas, cabecera.columnas);

        // Leer y mostrar los datos de la matriz
        for (int i = 0; i < cabecera.filas; i++) {
            for (int j = 0; j < cabecera.columnas; j++) {
                fread(&valor, sizeof(int), 1, puntFich);
                printf("%d ", valor);
            }
            printf("\n");
        }

        fclose(puntFich);
    } else {
        printf("Error al abrir el fichero %s.\n", nomFich);
    }
}
Tipo 2: Fichero de elementos de tipo estructura, sin cabecera
Descripción:
El fichero solo contiene elementos de tipo estructura. No hay información adicional al inicio.

Código:
c
Copiar código
void procesarFicheroSinCabecera(const char *nomFich) {
    FILE *puntFich;
    Elemento elemento;

    if ((puntFich = fopen(nomFich, "rb")) != NULL) {
        printf("Fichero %s abierto correctamente.\n", nomFich);

        // Leer y procesar los elementos hasta el final del fichero
        while (fread(&elemento, sizeof(Elemento), 1, puntFich) != 0) {
            visualizaFicha(elemento);
        }

        fclose(puntFich);
    } else {
        printf("Error al abrir el fichero %s.\n", nomFich);
    }
}
Notas:

No necesitas calcular la cantidad de elementos; simplemente lees hasta el final del fichero.
Usa fread dentro de un bucle.
Tipo 3: Fichero con una cabecera indicando numElem, seguido de elementos de tipo estructura
Descripción:
El primer elemento es un entero que indica cuántos elementos hay en el fichero. El resto son estructuras.

Código:
c
Copiar código
void procesarFicheroConNumElem(const char *nomFich) {
    FILE *puntFich;
    int numElem;
    Elemento elemento;

    if ((puntFich = fopen(nomFich, "rb")) != NULL) {
        // Leer la cabecera (número de elementos)
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
Tipo 4: Fichero con dos cabeceras (filas y columnas), seguido de elementos individuales
Descripción:
Los dos primeros elementos son enteros que indican las dimensiones de una matriz (número de filas y columnas). El resto son datos de la matriz almacenados secuencialmente.

Código:
c
Copiar código
void procesarFicheroConDosCabeceras(const char *nomFich) {
    FILE *puntFich;
    int filas, columnas;
    int valor;

    if ((puntFich = fopen(nomFich, "rb")) != NULL) {
        // Leer las dos cabeceras
        fread(&filas, sizeof(int), 1, puntFich);
        fread(&columnas, sizeof(int), 1, puntFich);
        printf("Dimensiones: %d filas x %d columnas\n", filas, columnas);

        // Leer y mostrar la matriz
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                fread(&valor, sizeof(int), 1, puntFich);
                printf("%d ", valor);
            }
            printf("\n");
        }

        fclose(puntFich);
    } else {
        printf("Error al abrir el fichero %s.\n", nomFich);
    }
}
Tabla Resumen
Tipo	Descripción	Cabecera
1. Cabecera (estructura)	Primera estructura contiene filas y columnas, seguido de elementos individuales.	Estructura con filas/columnas
2. Sin Cabecera	Solo contiene elementos de tipo estructura.	Ninguna
3. Num. Elem. (cabecera)	Primer entero indica el número de elementos, seguido de estructuras.	Entero (numElem)
4. Dos Cabeceras	Dos enteros iniciales (filas y columnas), seguido de elementos individuales.	Dos enteros (filas, columnas)
Consejos para el Examen
Identificar el Tipo de Fichero:

Revisa si tiene cabeceras y qué tipo de información contienen.
Diferencia entre elementos individuales y estructuras.
Usar fread y sizeof:

Siempre asegura que el tamaño de lectura coincide con el tamaño del dato (estructura o entero).
Bucle Correcto:

Si no hay cabecera, lee hasta el final del fichero.
Si hay cabecera, usa la información para controlar los bucles.
Practica Casos Similares:

Intenta crear un fichero con un editor binario o en otro programa y procesarlo con estas funciones.






Apuntes: Gestión de Ficheros
Estos son los apuntes organizados sobre la gestión de ficheros binarios que contienen información bidimensional de tipo unsigned char. El programa maneja dos tipos de ficheros y un menú interactivo.

Tipos de Ficheros
Tipo 1: Fichero de Listado (listado.dat)
Descripción:
Este fichero contiene el listado de los ficheros de tipo 2 que se desean gestionar.

Formato:

Cabecera:
Un entero (int) que almacena el número de elementos en el listado.
Datos:
Cada elemento contiene:
nomFich: Cadena de caracteres (máximo 20 caracteres) que contiene el nombre del fichero.
codigo: Cadena de caracteres (máximo 12 caracteres) que contiene el código de acceso asociado al fichero.
Tipo 2: Ficheros de Datos
Descripción:
Estos ficheros contienen información bidimensional de datos de tipo unsigned char.

Formato:

Cabecera:
Una estructura con:

filas: Número de filas (int).
columnas: Número de columnas (int).
codigo: Código de acceso (char[12]).
Datos:
Los datos son de tipo unsigned char y están almacenados fila por fila.

Menú del Programa
Salir del Programa

Finaliza la ejecución.
Insertar Fichero

Inserta el nombre y el código de acceso de un fichero de tipo 2 en listado.dat.
Eliminar Fichero

Elimina un elemento del fichero listado.dat.
Comprobar Listado

Verifica que todos los ficheros del listado existen y que sus códigos de acceso coinciden con los de las cabeceras de los ficheros de tipo 2.
Ejemplo de Ejercicio
Ejercicio 1: Gestión de Listado y Datos
Codifica un programa que permita la gestión de ficheros binarios con información bidimensional de tipo unsigned char. El programa manejará dos 
tipos de ficheros descritos anteriormente (tipo 1 y tipo 2) a través del menú interactivo.

Ejercicio 2: Filtrado de Censo
Dado un fichero que contiene el censo de la población bilbaína, escribe un programa que:

Cree un nuevo fichero con la información de las personas mayores de 60 años o que los cumplan en el año actual.
El fichero original no debe ser modificado.
    
Calcule el porcentaje de estas personas respecto al total de la población.
Formato del Fichero de Censo
Cada registro contiene:

nombre: Cadena de caracteres.
apellido1: Cadena de caracteres.
apellido2: Cadena de caracteres.
anioNacimiento: Año de nacimiento (int).
direccion: Cadena de caracteres.
Con esta estructura, los apuntes deberían ser más claros, organizados y fáciles de usar como referencia. Si aún hay algo que mejorar, avísame y ajusto lo necesario.





EJEMPLO DE EJERCICIO 1
Codificar un programa que permita la gestión de ficheros con información bidimensional de datos tipo unsigned char.

Para ello se dispone de dos tipos de ficheros binarios de datos:

Tipo 1
De este tipo hay un solo fichero.
El contenido de este fichero es el listado de ficheros de tipo 2 a gestionar.
Los de tipo 2 tienen el siguiente formato:
Primer elemento del fichero: Un dato de tipo int que almacena el número de elementos.
A partir del segundo elemento: Cada elemento del fichero contiene la siguiente información:
nomfich: Cadena de caracteres de máximo 20 elementos.
codigo: ?????
Tipo 2
De este tipo hay tantos ficheros como se deseen gestionar.
Cada fichero contiene información bidimensional de datos de tipo unsigned char.
Formato del fichero tipo 2:

a) El primer elemento del fichero es una estructura con la siguiente información:

filas: Dato de tipo int que indica el número de filas.
columnas: Dato de tipo int que indica el número de columnas.
codigo: Cadena de caracteres de máximo 12 elementos, que contiene el código de acceso al fichero.
b) A partir del segundo elemento, cada elemento del fichero almacena datos de tipo unsigned char.

Esta información está almacenada por filas.
El programa se ejecutará rápidamente en torno a un menú con las siguientes opciones:

Salir del programa.
Insertar fichero.
Eliminar fichero.
Comprobar listado.
EJEMPLO DE EJERCICIO 2
Opción 1: Insertar fichero
Se introduce el nombre y el código de acceso de un fichero de datos de tipo unsigned char en el fichero listado.dat.

Se pedirá por teclado el nombre del fichero a insertar en el listado.
Si el fichero existe, se solicitará la introducción por teclado del código de acceso al fichero.
Si el código de acceso es correcto y el fichero no está en el listado, su información será almacenada en el fichero listado.dat.
En caso de que no pueda ser insertado en el listado, se mostrará en pantalla la razón.
Nota del profesor: Para esto se debe realizar volcados, búsquedas binarias, y otros procesos adicionales.

Opción 2: Eliminar fichero
Elimina del fichero listado.dat el elemento que contiene el nombre y el código de acceso de un fichero de datos de tipo unsigned char.

Se pedirá por teclado el nombre del fichero a eliminar del listado.
Si el fichero está en el listado, se solicitará el código de acceso al fichero.
Si el código de acceso coincide con el que figura en el listado, el elemento correspondiente será eliminado.
En caso de que no pueda ser eliminado, se visualizará en pantalla la razón.
Opción 3: Comprobar listado
Comprueba que todos los ficheros del listado existen y que sus códigos de acceso coinciden con los que figuran en la cabecera de los ficheros de tipo 2.

Para todo fichero que no exista o cuyo código de acceso no sea el mismo que el registrado, el elemento correspondiente será eliminado del listado.
La razón de su eliminación se mostrará en pantalla.
EJEMPLO DE EJERCICIO 3
Dado un fichero que contiene el censo de la población bilbaína, se pide escribir un programa que cree un fichero que contenga la información referente a las personas con más de 60 años o que los cumplan dentro del año actual.

La información no deberá borrarse del fichero original.
El programa deberá calcular el porcentaje que representan estas personas respecto al total del censo.
Formato del fichero del censo:
Cada registro contiene los siguientes datos:

nombre: Nombre del ciudadano.
dos apellidos: Apellidos del ciudadano.
año de nacimiento: Año en que nació el ciudadano.
direccion: Dirección del ciudadano.
Funciones del programa:

programa cReaCenos60: Programa principal.
creaFichero2(nomFich1, nomFich2): Crea un nuevo fichero con los datos filtrados.
visualizaFichero(nomFich): Muestra el contenido de un fichero.
visualizaFicha(ficha): Muestra los datos de una ficha individual.






