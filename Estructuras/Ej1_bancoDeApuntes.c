/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   main.c
 * Author: xabie
 *
 * Created on 4 de enero de 2023, 23:24
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#define MAXTAM 20
#define MAXPAB 5
//
/*
 * 
 */
typedef struct controlAlquiler
{
    char nombreEmpresa[MAXTAM];
    int numeroPabellon, diasAlquiler;
    float metros, precioTotal;
    
}STAND;

typedef struct controlFeria
{
    float tarifa, metrosAlquilados;
    
}PABELLON;

void pideMaximoStands(int *numStand);
STAND *reservaMemoriaStands(int numElem);
PABELLON *reservaMemoriaPabellones(int numElem);
void pideTarifaPabellones(PABELLON *pabellones, int numPabellon);

int visualizaOpciones();

void addStand(STAND *stands, PABELLON *pabellones, int *numElem, int numStand);
STAND pideElemento(PABELLON *pabellones);
void actualizaMetros(STAND elemento, PABELLON *pabellones);
void insertaElemento(STAND *array, int numElem, int indice, STAND elemento);

void eliminaStand(STAND *stands, PABELLON *pabellones, int *numElem);
STAND pideNombreEmpresa();

void modificaTarifa(STAND *stands, PABELLON *pabellones, int numElem);

void visualizaInformacion(STAND *stands, PABELLON *pabellones, int numElem, int numPabellon);

void leeCadena(char *mensaje, char *cadena, int tam);
void limpiaBuffer();
void eliminaEnter(char *cadena);

int busquedaBinaria(STAND *array, STAND elemento, int numElem);

int main(int argc, char** argv) 
{
    STAND *stands;
    PABELLON *pabellones;
    int opcion, numElem = 0, numStand, numPabellon = MAXPAB;
    
    pideMaximoStands(&numStand);
    stands = reservaMemoriaStands(numStand);
    pabellones = reservaMemoriaPabellones(numPabellon);
    pideTarifaPabellones(pabellones, numPabellon);
    
    do
    {
        opcion = visualizaOpciones();
        
        switch(opcion)
        {
            case 1:
                addStand(stands, pabellones, &numElem, numStand);
                break;
                
            case 2:
                eliminaStand(stands, pabellones, &numElem);
                break;
                
            case 3:
                modificaTarifa(stands, pabellones, numElem);
                break;
                
            case 4:
                visualizaInformacion(stands, pabellones, numElem, numPabellon);
                break;
            
            case 5:
                printf("\nFin del programa.");
                break;
        }
        
    }while(opcion != 5);

    return (EXIT_SUCCESS);
}

void pideMaximoStands(int *numStand)
{
    do
    {
        printf("\nIntroduce el número máximo de stands: ");
        limpiaBuffer();
        scanf("%d", numStand);
        
    }while(*numStand <= 0);
}

STAND *reservaMemoriaStands(int numElem) 
{
    STAND *array;

    array = (STAND*)malloc(numElem * sizeof(STAND));

    return array;
}

PABELLON *reservaMemoriaPabellones(int numElem) 
{
    PABELLON *array;

    array = (PABELLON*)malloc(numElem * sizeof(PABELLON));

    return array;
}

void pideTarifaPabellones(PABELLON *pabellones, int numPabellon)
{
    int i;

    printf("\n");
    
    for(i = 0; i < numPabellon; i++) 
    {
        printf("Introduce la tarifa para el pabellón %d: ", i);
        limpiaBuffer();
        scanf("%f", &pabellones[i].tarifa);
    }
}

int visualizaOpciones() 
{
    int opcion;

    do 
    {
        printf("\nMENÚ");
        printf("\n1.-Añadir un stand");
        printf("\n2.-Eliminar un stand");
        printf("\n3.-Modificar la tarifa de un pabellón");
        printf("\n4.-Visualizar la información de los stands y de los pabellones");
        printf("\n5.-Salir del programa");
        
        printf("\n\nIntroduce el número de la opción: ");
        limpiaBuffer();
        scanf("%d", &opcion);
        
    }while((opcion < 1) || (opcion > 5));

    return opcion;
}

void addStand(STAND *stands, PABELLON *pabellones, int *numElem, int numStand)
{
    STAND elemento;
    int indice;
    
    if(*numElem < numStand)
    {
        elemento = pideElemento(pabellones);
        
        if(*numElem == 0)
        {
            stands[0] = elemento;
            (*numElem)++;
            actualizaMetros(elemento, pabellones);
            
        }else 
        {
            indice = busquedaBinaria(stands, elemento, *numElem);
            
            if(strcmp(stands[indice].nombreEmpresa, elemento.nombreEmpresa) == 0)
            {
                printf("\nEl stand ya está asignado.\n");
                
            }else if(strcmp(stands[indice].nombreEmpresa, elemento.nombreEmpresa) > 0)
            {
                insertaElemento(stands, *numElem, indice, elemento);
                (*numElem)++;
                actualizaMetros(elemento, pabellones);
                
            }else if(strcmp(stands[indice].nombreEmpresa, elemento.nombreEmpresa) < 0)
            {
                indice++;
                insertaElemento(stands, *numElem, indice, elemento);
                (*numElem)++;
                actualizaMetros(elemento, pabellones);
            }
        }
        
    }else
    {
        printf("\n¡Ya se ha alquilado el número máximo de stands!\n");
    }
}

STAND pideElemento(PABELLON *pabellones)
{
    STAND elemento;
    
    leeCadena("\nIntroduce el nombre de la empresa: ", elemento.nombreEmpresa, MAXTAM);
    
    printf("Introduce el número de pabellón: ");
    limpiaBuffer();
    scanf("%d", &elemento.numeroPabellon);
    
    printf("Introduce los días de alquiler: ");
    limpiaBuffer();
    scanf("%d", &elemento.diasAlquiler);
    
    printf("Introduce los metros cuadrados del stand: ");
    limpiaBuffer();
    scanf("%f", &elemento.metros);
    
    elemento.precioTotal = pabellones[elemento.numeroPabellon].tarifa * elemento.metros * elemento.diasAlquiler;
    printf("\nEl precio total del alquiler es: %.2f \n", elemento.precioTotal);
    
    return elemento;
}

void actualizaMetros(STAND elemento, PABELLON *pabellones)
{
    pabellones[elemento.numeroPabellon].metrosAlquilados = pabellones[elemento.numeroPabellon].metrosAlquilados + elemento.metros;    
}

void insertaElemento(STAND *array, int numElem, int indice, STAND elemento)
{
    int i;
    
    for(i = numElem - 1; i >= indice; i--)
    {
        array[i + 1] = array[i];
    }
    
    array[indice] = elemento;
}

void eliminaStand(STAND *stands, PABELLON *pabellones, int *numElem)
{
    STAND elemento;
    int indice;
    
    if(*numElem == 0)
    {
        printf("\n¡No hay ningún stand alquilado!\n");
        
    }else 
    {
        elemento = pideNombreEmpresa();
        indice = busquedaBinaria(stands, elemento, *numElem);
        
        if(strcmp(stands[indice].nombreEmpresa, elemento.nombreEmpresa) == 0) 
        {
            pabellones[stands[indice].numeroPabellon].metrosAlquilados = pabellones[stands[indice].numeroPabellon].metrosAlquilados - stands[indice].metros;
            
            while(indice < *numElem) 
            {
                stands[indice] = stands[indice + 1];
                indice++;
            }
            
            printf("\nStand eliminado.\n");
            (*numElem)--;
            
        }else 
        {
            printf("\nNo se han encontrado stands de esa empresa.\n");
        }
    }
}

STAND pideNombreEmpresa()
{
    STAND elemento;

    leeCadena("\nIntroduce el nombre de la empresa del stand a eliminar: ", elemento.nombreEmpresa, MAXTAM);

    return elemento;
}

void modificaTarifa(STAND *stands, PABELLON *pabellones, int numElem)
{
    int i, numeroPabellon;
    
    printf("\nIntroduce el número de pabellón a modificar la tarifa: ");
    limpiaBuffer();
    scanf("%d", &numeroPabellon);
    
    printf("Introduce la nueva tarifa: ");
    limpiaBuffer();
    scanf("%f", &pabellones[numeroPabellon].tarifa);
    
    for(i = 0; i < numElem; i++)
    {
        stands[i].precioTotal = pabellones[numeroPabellon].tarifa * stands[i].metros * stands[i].diasAlquiler;
    }
}

void visualizaInformacion(STAND *stands, PABELLON *pabellones, int numElem, int numPabellon)
{
    int i;
    
    if(numElem == 0)
    {
        printf("\nNo hay ningún stand alquilado.\n");
        
    }else
    {
        for(i = 0; i < numElem; i++) 
        {
            printf("\nSTAND %d", i);
            printf("\nNombre: %s \nPabellón: %d, Días de alquiler: %d, Metros cuadrados: %.2f, Precio total: %.2f \n", stands[i].nombreEmpresa, stands[i].numeroPabellon, stands[i].diasAlquiler, stands[i].metros, stands[i].precioTotal);
        }
    
        printf("\n");
    }
    
    for(i = 0; i < numPabellon; i++) 
    {
        printf("\nPABELLÓN %d", i);
        printf("\nTarifa: %.2f, Metros alquilados: %.2f \n", pabellones[i].tarifa, pabellones[i].metrosAlquilados);
    }
    
    printf("\n");
}

void leeCadena(char *mensaje, char *cadena, int tam)
{
    printf("%s", mensaje);
    limpiaBuffer();
    fgets(cadena, tam, stdin);
    eliminaEnter(cadena);
}

void limpiaBuffer()
{
    __fpurge(stdin);
}

void eliminaEnter(char *cadena)
{
    if(cadena[strlen(cadena) - 1] == '\n')
    {
        cadena[strlen(cadena) - 1] = '\0';
    }
}

int busquedaBinaria(STAND *array, STAND elemento, int numElem)
{
    int izquierda = 0, medio, derecha = numElem - 1, encontrado = 0;
    
    medio = (izquierda + derecha) / 2;
    
    while((izquierda < derecha) && (!encontrado))
    {
        if(strcmp(array[medio].nombreEmpresa, elemento.nombreEmpresa) == 0)
        {
            encontrado = 1;
            
        }else 
        {
            if(strcmp(array[medio].nombreEmpresa, elemento.nombreEmpresa) < 0)
            {
                izquierda = medio + 1;
                
            }else 
            {
                derecha = medio - 1;
            }
        
            medio = (izquierda + derecha) / 2;
        }
    }
    
    return medio;
}
