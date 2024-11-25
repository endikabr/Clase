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

int anoActual = 2024;
int edad, j; 
int anoNacimiento = anoActual - edad;
CENS censo;

    FILE *f = fopen(nomFich, "rb");
    if(f == NULL){
        printf("\nError al abrir el fichero");
    }

    printf("\nIntroduce la edad: ");
scanf("%d", &edad);
    fread(censo, sizeof(CENS), TAMANOCENSO, f);
printf("Estas son las perosnas mayores de %d años.", edad);
for(int i = 0; i < TAMANOCENSO; i++){
if (censo[i].ano < anoNacimiento )
{
    printf("%s %s %d", censo[i].nombre cenos[i].apellidos censo[i].edad);
    j++;
}
}
fclose(f);
}