// Programa para recorrer un arreglo y sumar sus elementos
//Fecha: 26/09/2025

#include <stdio.h>

#define N 5

void mostrar_arreglo(int *);
int suma(int *);

int main(){
    int arreglo[N] = {1, 2, 3, 4, 5};
    mostrar_arreglo(arreglo);
    printf("\n El resultado de la suma de los elementos es: %d", suma(arreglo));
    return 0;
}

void mostrar_arreglo(int arr[]){
    int i;
    printf("\n Elementos del arreglo: \n");
    for(i = 0; i < N; i++){
        printf(" %d ", arr[i]);
    }
}

int suma(int arr[]){
    int total = 0, i;
    for(i = 0; i < N; i++){
        total += arr[i];
    }
    return total;
}
