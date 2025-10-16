#include <stdio.h>

int main(){
    int numero = 9;
    int *p = &numero;
    printf("%d %d", (void *)p, numero);
    printf("%d", *p);
    return 0;
}