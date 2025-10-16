// Ejercicio de Struct
// 16/10/2025

#include <stdio.h>
#include <string.h>

typedef struct {
    char nombre[50];
    int edad;
    float promedio;
} Estudiante;

int main() {
    Estudiante alumno;
    strcpy(alumno.nombre, "Antonia");
    alumno.edad = 18;
    alumno.promedio = 7.0;
    
    printf("Nombre: %s\n", alumno.nombre);
    printf("Edad: %d\n", alumno.edad);
    printf("Promedio: %f\n", alumno.promedio);
    return 0;
}