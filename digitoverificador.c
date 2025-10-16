/*  Autor: Antonia Orellana Molina
    Programacion 2025
    Programa que calcula el digito verificador */

#include <stdio.h>
#include <string.h>

char calcular_dv(int rut) {
    int factores[] = {2, 3, 4, 5, 6, 7};
    int suma = 0, factor_id = 0;

    while (rut > 0) {
        int digito = rut % 10;
        suma = suma + (digito * factores[factor_id]);

        rut = rut / 10;
        factor_id = (factor_id + 1) % 6;
    }

    int resto = suma % 11;
    int dv = 11 - resto;

    if (dv == 11) return '0';
    if (dv == 10) return 'K';
    return dv + '0';
}

int main() {
    int rut;
    char dv_ingresado, dv_calculado;

    printf("Ingrese el número de RUT (sin dígito verificador): ");
    scanf("%d", &rut);

    dv_calculado = calcular_dv(rut);

    printf("El digito verificador es: %c\n", dv_calculado);

    return 0;
}