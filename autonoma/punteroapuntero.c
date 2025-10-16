// Programa para imprimir el valor de una variable a traves de un puntero que apunte al puntero de la variable
// Fecha: 26/09/2025

#include <stdio.h>

int main(){
    int x = 10;
    int *p = &x;
    int **pp = &p;
    printf ("El valor de la variable x es %d", **pp);
    return 0;
}