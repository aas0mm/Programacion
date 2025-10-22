//Programa para registrar datos de estudiantes y mostrar los que tienen promedio mayor que 4.0

#include <stdio.h>
#include <string.h>

#define MAX 100 //Maxima cantidad de estudiantes
#define Nota_minima 4.0 //Nota de aprobacion

typedef struct {
    char nombre[50];
    int edad;
    float promedio;
} Estudiante;

void ingresarEstudiantes(Estudiante *, int);
void mostrarAprobados(Estudiante *, int);

int main() {
    Estudiante lista[MAX];
    int cantidad;

    printf("Cantidad de estudiantes a ingresar: \n");
    scanf("%d", &cantidad);

    if (cantidad > MAX) {
        printf("Error: puedes ingresar maximo %d estudiantes. \n", MAX);
        return 1;
    }

    ingresarEstudiantes(lista, cantidad);
    mostrarAprobados(lista, cantidad);

    return 0;
}

void ingresarEstudiantes(Estudiante *lista, int cant){
    int i;
    for (i = 0; i < cant; i++){
        printf("\nEstudiante #%d\n", i + 1);
        printf("Nombre: ");
        scanf(" %[^\n]", lista[i].nombre);
        printf("Edad: ");
        scanf("%d", &lista[i].edad);
        printf("Promedio: ");
        scanf("%f", &lista[i].promedio);
    }
}

void mostrarAprobados(Estudiante *lista, int cant){
    int i;
    for (i = 0; i < cant; i++){
        if (lista[i].promedio > Nota_minima){
            printf("- %s (Edad: %d, Promedio: %.2f)\n", lista[i].nombre, lista[i].edad, lista[i].promedio);
        }
    }
}