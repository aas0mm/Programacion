//Programa o funcion para transformar un numero en base 10 a base 2
//Fecha: 06/10/2025

#include <stdio.h>

void EnteroABinario(int, char [], int *, int *);

int main(){
    int n, *contador, *indice;
    char binario[100];
    printf("\nIngrese el numero que desea transformar\n");
    scanf("%d", &n);
    EnteroABinario(n, binario, contador, indice);
    int i;
    printf("Numero %d en base 2 (binario): \n", n);
    for(i = 0; i < *contador; i++){
        printf("%c", binario[i]);
    }
    return 0;
}

void EnteroABinario(int n, char b_inverso[], int *cont, int *i){
    *i = 0;
    *cont = 0;
    char b_final[100];
    while(n/2 != 1){
        n = n % 2;
        b_inverso[*i] = n;
        (*cont)++;
        (*i)++;
        EnteroABinario(n/2, b_inverso, cont, i);
    }
}