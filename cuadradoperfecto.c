#include <stdio.h>

void lectura(int[3][3]);
void proceso(int[3][3]);
/* int resultado();*/
int suma_filas();
int suma_columnas();
int suma_diagonales(); 

int main(){ 
    int matriz[3][3];
    lectura(matriz);
}

void lectura(int m[3][3]){
    int i, j;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf ("Posicion %d %d\n", i, j);
            scanf ("%d", &m[i][j]);  
        }
    }
}

void proceso(int m[3][3]){
    suma_filas(m);
    suma_columnas(m);
    suma_diagonales(m);
}

int suma_filas(int filas[3][]){

}