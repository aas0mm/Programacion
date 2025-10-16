//Autor: Antonia Orellana
//Programa con getchar

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void ordenar(char *);
void NuevoTexto(char *,  char *);

int main (){
    char texto[]= "FZJYQKOMWUXVCPRSTBHLADGNIE";
    char textonuevo[30];
    char copia_texto[30];

    strcpy(copia_texto, texto);

    ordenar(texto);
    NuevoTexto(texto, textonuevo);
    printf("Texto original: %s\n", copia_texto);
    printf("Texto ordenado: %s\n", textonuevo);
    return 0;
}

void ordenar(char sin_ordenar[]){
    int i, j, largo;
    largo = strlen(sin_ordenar);
    for (i = 0; i < largo - 1; i++){
        for (j = i + 1; j < largo; j++){
            if (sin_ordenar[i] > sin_ordenar[j]){
                char aux = sin_ordenar[i];
                sin_ordenar[i] = sin_ordenar[j];
                sin_ordenar[j] = aux;
            }
        }
    }
}

void NuevoTexto(char sin_ordenar[], char ordenado[]){
    strcpy(ordenado, sin_ordenar);
}