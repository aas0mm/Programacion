//Programa que busca los valores punto silla de una matriz de 5 x 5 extraida de un archivo de texto
//20/10/2025

#include <stdio.h>

void punto_silla(int [5][5], int[10], int [10][2]);

int main(){
    FILE *matriz;
    int mat[5][5];
    int i, j;

    matriz = fopen("matriz5x5.txt", "r");
    if (matriz == NULL){
        printf("No se pudo abrir el archivo. \n");
        return 1;
    }

    //Lectura matriz
    for (i = 0; i < 5; i++){
        for (j = 0; j < 5; j++){
            fscanf(matriz, "%d ", &mat[i][j]);
        }
    }
    fclose(matriz);

    /* for (i = 0; i < 5; i++){
        for (j = 0; j < 5; j++){
            printf("%d", mat[i][j]);
        }
    } para corroborar que leyo correctamente*/
    
    int valor[10];
    int coordenada[10][2];
    
    punto_silla(mat, valor, coordenada);

    printf("\nPuntos silla encontrados: \n");
    for (i = 0; i < 10 && valor[i] != -1; i++){
        printf("Valor: %d en posicion [%d][%d]\n", valor[i], coordenada[i][0], coordenada[i][1]);
    }

    return 0;
}

void punto_silla(int matriz[5][5], int valor[10], int coordenada[10][2]){
    int i, j, k = 0; //i, j para avanzar en los valores de la matriz y compararlos, k para avanzar en las posiciones del arreglo "valor"

    for (i = 0; i < 5; i++){ //busca el minimo de cada fila
        int min = matriz[i][0];
        int col = 0;
        for(j = 1; j < 5; j++){
            if (matriz[i][j] < min){
                min = matriz[i][j];
                col = j;
            }
        }

        int es_max_col = 1; //verificamos si el minimo encontrado es el maximo de su columna
        for (j = 0; j < 5; j++){
            if (matriz[j][col] > min){
                es_max_col = 0;
                break;
            }
        }

        if (es_max_col && k < 10){
            valor[k] = min;
            coordenada[k][0] = i;
            coordenada[k][1] = col;
            k++;
        }
    }

    while (k < 10){ //marco el fin de datos
        valor[k] = -1;
        k++;
    }
}