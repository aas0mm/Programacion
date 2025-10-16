/*  Programa de practica
    Antonia Orellana Molina*/

#include <stdio.h>
#include <string.h>

// Verifica si el carácter es una letra (sin usar ctype.h)
int esLetra(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

// Verifica si el carácter es mayúscula
int esMayuscula(char c) {
    return (c >= 'A' && c <= 'Z');
}

// Convierte una letra mayúscula a minúscula (solo para letras comunes y Ñ)
char aMinuscula(char c) {
    if (c >= 'A' && c <= 'Z') return c + 32;
    return c;
}

// Convierte una letra minúscula a mayúscula (solo para letras comunes y ñ)
char aMayuscula(char c) {
    if (c >= 'a' && c <= 'z') return c - 32;
    return c;
}

void convertirAPigLatin(char palabra[]) {
    int len = strlen(palabra);
    if (len < 2) {
        printf("%s ", palabra);
        return;
    }

    char primera = palabra[0];
    char segunda = palabra[1];
    char resultado[100];

    // Ajuste de mayúsculas
    if (esMayuscula(primera)) {
        segunda = aMayuscula(segunda);
        primera = aMinuscula(primera);
    }

    // Construir la nueva palabra
    int i = 0;
    resultado[i++] = segunda;
    for (int j = 2; j < len; j++) {
        resultado[i++] = palabra[j];
    }
    resultado[i++] = primera;
    resultado[i++] = 'a';
    resultado[i] = '\0';

    printf("%s ", resultado);
}

int main() {
    char texto[] = "Casa perro computador.";
    char palabra[100];
    int i = 0, j = 0;

    while (texto[i] != '\0') {
        if (esLetra(texto[i])) {
            palabra[j++] = texto[i];
        } else {
            if (j > 0) {
                palabra[j] = '\0';
                convertirAPigLatin(palabra);
                j = 0;
            }
            printf("%c", texto[i]); // Imprimir puntuación o espacio
        }
        i++;
    }

    // Última palabra si no termina en puntuación
    if (j > 0) {
        palabra[j] = '\0';
        convertirAPigLatin(palabra);
    }

    return 0;
}
