/*  Autor: Antonia Orellana Molina
    Programa para resolver un laberinto con recursividad
    06/10/2025*/

#include <stdio.h>

#define FILAS 10
#define COLUMNAS 10

char laberinto[FILAS][COLUMNAS] = {
    {'A', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' '},
    {'#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' '},
    {' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' '},
    {' ', '#', '#', ' ', '#', '#', '#', ' ', '#', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' '},
    {'#', '#', '#', '#', '#', ' ', '#', ' ', '#', ' '},
    {' ', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', ' '},
    {' ', '#', '#', '#', '#', ' ', '#', '#', '#', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' '},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', 'B'},
};

void mostrarLaberinto();
void tipoMovimientoVF(int fila, int columna);
int calcularRutas(int fila, int columna);
void jugar();

int main() {
    printf("----- BUSCANDO EL CAMINO DEL LABERINTO RECURSIVO ---\n");
    printf("Buscando el camino desde A hasta B \n");
    mostrarLaberinto();
    jugar();
    return 0;
}

void mostrarLaberinto(){
    int i, j;
    for (i = 0; i < FILAS; i++){
        for(j = 0; j < COLUMNAS; j++){
            printf("%c ", laberinto[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int tipomovimientoVF(int fila, int columna) {
    return (fila >= 0 && fila < FILAS &&
            columna >= 0 && columna < COLUMNAS &&
            (laberinto[fila][columna] == ' ' || laberinto[fila][columna] == 'M'));
}

int calcularRutas(int fila, int columna) {
    if (fila < 0 || fila >= FILAS || columna < 0 || columna >= COLUMNAS) {
        return 0;
    }

    // Si se llega al Destino B.
    if (laberinto[fila][columna] == 'B') {
        return 1;
    }

    // Si se llega a un obstaculo.
    if (laberinto[fila][columna] == '#' || laberinto[fila][columna] == '.') {
        return 0;
    }

    // Si se llega al camino solución y se marca este mismo.
    if (laberinto[fila][columna] != 'A') {
        laberinto[fila][columna] = '.';
    }

    //El intento de movimiento en 4 posiciones y recursividad
    if (calcularRutas(fila + 1, columna)) {
        return 1;
    } else if (calcularRutas(fila - 1, columna)) {
        return 1;
    } else if (calcularRutas(fila, columna + 1)) {
        return 1;
    } else if (calcularRutas(fila, columna - 1)) {
        return 1;
    } else {
       
    // El uso de Backtracking.
    }if (laberinto[fila][columna] != 'A') {
        laberinto[fila][columna] = ' ';
    }
    return 0;
    }


void jugar() {
    // Buscar la posicion A.
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (laberinto[i][j] == 'A') {
                printf("Laberinto inicial:\n");
                mostrarLaberinto();

                if (calcularRutas(i, j)) {
                    printf("¡Camino encontrado!\n");
                } else {
                    printf("No hay camino disponible.\n");
                }

                printf("Laberinto con solucion:\n");
                mostrarLaberinto();
                return;
            }
        }
    }
}