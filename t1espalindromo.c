//Antonia Orellana Molina
//Seccion 2 programación

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void string_invertido(char texto[]);
int contar_vocales(char texto[]);
int es_palindromo(char texto[]);

int main(){
    char texto[31];
    printf("Ingrese una frase (no más de 30 caracteres)");
    fgets(texto, sizeof(texto), stdin);
    texto[strcspn(texto, "\n")] = '\n';

    printf("String invertido:\n");
    string_invertido(texto);

    printf("Cantidad de vocales: \n");
    printf("%d\n", contar_vocales(texto));

    printf("¿Es palíndromo?\n");
    if (es_palindromo(texto)){
        printf("Si");
    }
    else{
        printf("No");
    }
    return 0;
}

void string_invertido(char texto[]){
    int longitud = strlen(texto);
    int i;
    for (i = longitud - 1; i >= 0; i--){
        putchar(texto[i]);
    }
    putchar('\n');
}

int contar_vocales(char texto[]){
    int contador = 0, i;
    for (i = 0; texto[i] != '\0'; i++){
        char c = texto[i];
        if (c >= 'A' && c <= 'Z'){
            c = c + ('a' - 'A');
        }
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            contador++;
        }
    }
    return contador;
}

int es_palindromo(char texto[]){
    char limpio[31];
    int j = 0, i;
    for (i = 0; texto[i] != '\0'; i++){
        char c = texto[i];
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')){
            if (c >= 'A' && c <= 'Z'){
                c = c + ('a' - 'A');
            }
            limpio[j++] = c;
        }
    }
    limpio[j] = '\0';

    int izq = 0, der = j - 1;
    while (izq < der){
        if (limpio[izq] != limpio[der]){
            return 0;
        }
        izq++;
        der--;
    }
    return 1;
}