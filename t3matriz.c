/*  Autor: Antonia Orellana Molina
    Fecha: 25/08/2025
    Tema: Programa para ordenar los valores de una matriz en orden ascendente
*/

#include <stdio.h>

#define FILAS 10
#define COLUMNAS 10

void ordenar(int *);
void intercambio(int *, int *);
void mostrar_matriz(int matriz[FILAS][COLUMNAS]);

int main(){
    int matriz[FILAS][COLUMNAS] = {
        {64, 12, 95, 38, 71, 4, 27, 83, 56, 19},
        {23, 77, 9, 41, 88, 32, 60, 5, 94, 16},
        {45, 2, 67, 91, 10, 53, 78, 29, 86, 37},
        {18, 72, 6, 49, 85, 21, 63, 34, 97, 40},
        {31, 59, 13, 76, 24, 90, 47, 8, 82, 65},
        {54, 1, 79, 35, 92, 26, 68, 43, 15, 87},
        {7, 48, 84, 20, 73, 39, 96, 52, 30, 61},
        {42, 89, 17, 74, 3, 58, 25, 91, 66, 11},
        {80, 33, 69, 14, 55, 22, 75, 46, 98, 28},
        {36, 62, 93, 50, 81, 44, 19, 57, 0, 70}
    };
    
    printf("Matriz desordenada: \n");
    mostrar_matriz(matriz);

    for (int i = 0; i < FILAS; i++){
        ordenar(matriz[i]);
    }

    printf("Matriz ordenada: \n");
    mostrar_matriz(matriz);

    return 0;
}

void ordenar(int *fila){
    for (int i = 0; i < COLUMNAS - 1; i++){
        for (int j = 0; j < COLUMNAS - i - 1; j++){
            if (*(fila + j) > *(fila + j + 1)){
                intercambio(fila + j, fila + j + 1);
            }
        }
    }
}

void intercambio(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

void mostrar_matriz(int matriz[FILAS][COLUMNAS]){
    for (int i = 0; i < FILAS; i++){
        for (int j = 0; j < COLUMNAS; j++){
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }
}