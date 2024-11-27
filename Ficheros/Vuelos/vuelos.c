#include <stdio.h>
#include <string.h>
#define MAXCHAR 30
#define MAXELEM 40
#define RELOJ 7

typedef struct {

int numero_vuelo;
char destino[MAXCHAR];
char horario_salida[RELOJ];
int numero_plazas_libres;

} DATOS;

int averiguaNumeElem(const char* nomFich);
void insertaElementoEnFichero(const char* nomFich);
void vuelcaFicheroAArray(const char* nomFich, DATOS vuelos[MAXELEM]);
void vuelcaArrayAFichero(const char *nomFich, DATOS *array, int numElemFichero);
int anadeFicha(DATOS *array, int numElemFichero);

int main(){

insertaElemetosEnElFichero("vuelos.dat");
    return(0);
}
int averiguaNumeElem(const char* nomFich){
FILE *f = fopen(nomFich, "rb");
if (f == NULL)
{
    printf("No se pudo abrir el fichero correctamente");
}

int numElem = sizeof(nomFich)/sizeof(DATOS);

fclose(f);
    return(numElem);
}

void insertaElementoEnFichero(const char* nomFich){

DATOS vuelos[MAXELEM];

int numElemFichero = averiguaNumElem(nomFich);
vuelcaFicheroAArray(nomFich, &vuelos, numElemFichero);
numElemFichero = anadeFicha(vuelos[], numElemFichero);
vuelcaArrayAFichero(nomFich, &vuelos, numElemFichero);

}
void vuelcaArrayAFichero(const char *nomFich, DATOS *array, int numElemFichero){

FILE *f = fopen(nomFich, "wb");
if(f == NULL){
printf("No se pudo abrir el fichero correctamente");
}

fwrite(nomFich, sizeof(DATOS), numElemFichero, f);

fclose(f);
}

int anadeFicha(DATOS *array, int numElemFichero){
printf("Introduce El destino del vuelo: ");
printf("Introduce El horario del vuelo: ");
printf("Introduce El numero de plazas libres de ese vuelo");
scanf("%d", array[numElemFichero+1]);
numElemFichero++;

    return(numElemFichero);
}

void vuelcaFicheroAArray(const char* nomFich, DATOS *vuelos, int numElemFichero){

    FILE *f = fopen(nomFich, "rb");
if(f == NULL){
printf("No se pudo abrir el fichero correctamente");
}

fread(vuelos[0], sizeof(DATOS), numElemFichero, f);
fclose(f);
}