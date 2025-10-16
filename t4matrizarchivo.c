/*  Autor: Antonia Orellana Molina
    Fecha: 08/09/2025
    Tema: Uso de vectores con archivo
*/

#include <stdio.h>
#include <string.h>

#define FILAS 5
#define COLUMNAS 5

void lee_archivo(char [FILAS][COLUMNAS]);
void muestra_matriz(char[FILAS][COLUMNAS]);
void muestra_array(char[], int);
int busca_palabra(char[FILAS][COLUMNAS], int, int, int, int, char[]);
void mostrar_coordenadas(char[FILAS][COLUMNAS], char[]);

int main(){
    char sopadeletras[FILAS][COLUMNAS];
    lee_archivo(sopadeletras);

    char word1[] = "CASA";
    char word2[] = "RATOS";
    char word3[] = "CALAS";
    char word4[] = "LOSA";
    char word5[] = "RATON";
    char word6[] = "SOLO";
    char word7[] = "SALA";

    muestra_matriz(sopadeletras);

    printf("\n");
    
    muestra_array(word1, 1);
    muestra_array(word2, 2);
    muestra_array(word3, 3);
    muestra_array(word4, 4);
    muestra_array(word5, 5);
    muestra_array(word6, 6);
    muestra_array(word7, 7);

    printf("\n");
    
    mostrar_coordenadas(sopadeletras, word1);
    mostrar_coordenadas(sopadeletras, word2);
    mostrar_coordenadas(sopadeletras, word3);
    mostrar_coordenadas(sopadeletras, word4);
    mostrar_coordenadas(sopadeletras, word5);
    mostrar_coordenadas(sopadeletras, word6);
    mostrar_coordenadas(sopadeletras, word7);
}

void lee_archivo(char sopa[FILAS][COLUMNAS]){
    FILE *sopadeletras;
    int filas = 0;
    
    sopadeletras = fopen("matriz.txt", "r"); 

    if (sopadeletras == NULL) {
        printf("Error: No se pudo abrir el archivo matriz.txt\n");
        return;
    }

    while (filas < FILAS) {
        char linea[100];  // buffer temporal
        if (fgets(linea, sizeof(linea), sopadeletras) == NULL) break;

        int col = 0;
        for (int i = 0; linea[i] != '\0' && col < COLUMNAS; i++) {
            if (linea[i] != ' ' && linea[i] != '\n') {
                sopa[filas][col++] = linea[i];
            }
        }
        filas++;
    }
    fclose(sopadeletras);
}

void muestra_matriz(char sopa[FILAS][COLUMNAS]){
    printf("Sopa de letras: \n");
    for (int i = 0; i < FILAS; i++){
        for (int j = 0; j < COLUMNAS; j++){
            printf("%2c ", sopa[i][j]);
        }
        printf("\n");
    }
}

void muestra_array(char palabra[], int indice){
    printf("Palabra %d: %2s\n", indice, palabra);
}

int busca_palabra(char sopa[FILAS][COLUMNAS], int fila, int col, int df, int dc, char palabra[]) {
    int len = strlen(palabra);
    for (int k = 0; k < len; k++) {
        int nf = fila + k * df;
        int nc = col + k * dc;
        if (nf < 0 || nf >= FILAS || nc < 0 || nc >= COLUMNAS || sopa[nf][nc] != palabra[k]) {
            return 0;
        }
    }
    return 1;
}

void mostrar_coordenadas(char sopa[FILAS][COLUMNAS], char palabra[]) {
    int direcciones[8][2] = {
        {-1, -1}, {-1, 0}, {-1, 1},
        { 0, -1},          { 0, 1},
        { 1, -1}, { 1, 0}, { 1, 1}
    };

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            for (int d = 0; d < 8; d++) {
                int df = direcciones[d][0];
                int dc = direcciones[d][1];
                if (busca_palabra(sopa, i, j, df, dc, palabra)) {
                    printf("Palabra '%s' encontrada en (%d, %d) dirección (%d, %d)\n", palabra, i, j, df, dc);
                    return;
                }
            }
        }
    }
    printf("Palabra '%s' no encontrada\n", palabra);
}