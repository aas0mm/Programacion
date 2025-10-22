//Numero primo

#include <stdio.h>

void es_primo(int, int *);

int main() {
    int n, esPrimo = 1;
    printf("Numero: ");
    scanf("%d", &n);
    es_primo(n, &esPrimo);

    if (esPrimo){
        printf("%d es un numero primo\n", n);
    }
    else {
        printf("%d NO es un numero primo\n", n);
    }

    return 0;
}

void es_primo(int numero, int *esPrimo){
    int i;
    if (numero <= 1){
        *esPrimo = 0;
    }
    else {
        for (i = 2; i < numero / 2; i++){
            if(numero % i == 0){
                *esPrimo = 0;
                break;
            }
        }
    }
}    