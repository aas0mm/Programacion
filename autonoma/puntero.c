// Programa para intercambiar el valor de dos variables
// Fecha: 26/09/2025

#include <stdio.h>

void intercambiar(int *, int *);

int main(){
    int primero, segundo;
    
    printf("\nIngrese el valor para la primera variable\n");
    scanf("%d", &primero);
    printf("\nIngrese el valor para la segunda variable\n");
    scanf("%d", &segundo);

    printf("\nValores en el orden ingresado: \n");
    printf("\nPrimero: %d \n", primero);
    printf("\nSegundo: %d \n", segundo);

    intercambiar(&primero, &segundo);
    printf("\nValores intercambiados: \n");
    printf("\nPrimero: %d \n", primero);
    printf("\nSegundo: %d \n", segundo);
    return 0;
}

void intercambiar(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}