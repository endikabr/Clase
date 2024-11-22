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

int main(){

mayoresXanos("censo.dat");
    return 0;
}

void mayoresXanos(const char *nomFich){
int anoEdad = 2024 - 30;
    FILE *f = fopen(nomFich, "rb");
    if(f == NULL){
        printf("\nError al abrir el fichero");
    }
    
    fread()

fclose(f);
}