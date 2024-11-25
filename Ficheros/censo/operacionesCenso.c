#include <stdio.h>
#include <string.h>
#define TAMANOCENSO 100
#define MAXTAM 50

typedef struct {
    char nombre[MAXTAM];
    char apellidos[MAXTAM];
    int ano; // Año de nacimiento
    char ciudad[MAXTAM];
} CENS;

void mayoresXanos(const char *nomFich);
void insertaFicha(const char *nomFich);
int averiguaNumElem(const char *nomFich);

int main(){

int numElem = averiguaNumElem("censo.dat");
    return 0;
}

void mayoresXanos(const char *nomFich){

int anoActual = 2024;
int edad, j; 
CENS censo[TAMANOCENSO];

    FILE *f = fopen(nomFich, "rb");
    if(f == NULL){
        printf("\nError al abrir el fichero");
    }

    printf("\nIntroduce la edad: ");
scanf("%d", &edad);
int anoNacimiento = anoActual - edad;
    fread(censo, sizeof(CENS), TAMANOCENSO, f);
printf("Estas son las perosnas mayores de %d años.", edad);
for(int i = 0; i < TAMANOCENSO; i++){
if (censo[i].ano < anoNacimiento && censo[i].ano >1800)
{
    printf("%s %s %d\n", censo[i].nombre, censo[i].apellidos, censo[i].ano);
    j++;
}
}

fclose(f);
}


int averiguaNumElem(const char *nomFich){

int numElem, j;
CENS censo[TAMANOCENSO];
    FILE *f = fopen(nomFich, "rb");
    if(f == NULL){
        printf("Error al leer el archivo");
    }

fread(censo, sizeof(CENS), TAMANOCENSO, f);

for(int i = 0; i < TAMANOCENSO; i ++){
    if(censo[i].ano > 1){
        j++;
    }
}
numElem = j;

printf("El fichero tiene %d elementos", numElem);

    return numElem;
}


void insertaFicha(const char *nomFich){
    int numElem = averiguaNumElem(nomFich);

    FILE *f = fopen(nomfich, "wb");
    if(f == NULL){
        printf("Error al abrir el archivo");
    }
CENS censo[TAMANOCENSO] = vuelcaFicheroAArray(nomFich, numElem);

printf("Nombre: ");

printf("Apellidos: ");

printf("Año de nacimiento: ");
scanf("%d", censo[numElem+1].ano);

printf("Residente en: ");
fgets
    fwrite()
fclose(f);
}

CENS vuelcaFicheroAArray(const char nomFich, int numElem){
    CENS censo[TAMANOCENSO];
    FILE *f = fopen(nomFich, "rb");
    if(f == NULL){
        printf("Error al abrir el fichero");
    }

    fclose(f);
    return(censo);
}