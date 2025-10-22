//Probando la funcion switch - mi propia calculadora simple

#include <stdio.h>

int main() {
    float a, b;
    printf("Calculadora basica\n");
    printf("Valor 1: ");
    scanf("%f", &a);
    printf("Valor 2: ");
    scanf("%f", &b);

    char operador;
    printf("Operador (+,-,*,/): ");
    scanf(" %c", &operador);

    switch (operador) {
        case '+':
            printf("Resultado: %f\n", a + b);
            break;
        case '-':
            printf("Resultado: %f\n", a - b);
            break;
        case '*':
            printf("Resultado: %f\n", a * b);
            break;
        case '/':
            printf("Resultado: %f\n", a / b);
            break;
    }

    return 0;
}