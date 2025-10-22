//Programa para registrar datos de un archivo de estudiantes y crear un archivo con los que tienen promedio mayor que 4.0
//Archivo: estudiantes.txt

#include <stdio.h>
#include <string.h>

#define MAX 100 //Maxima cantidad de estudiantes
#define Nota_minima 4.0 //Nota de aprobacion

typedef struct {
    char nombre[50];
    int edad;
    float promedio;
} Estudiante;

int cargarEstudiantes(const char *archivoEntrada, Estudiante *lista);
void guardarAprobados(const char *archivoSalida, Estudiante *lista, int cantidad);

int main() {
    Estudiante lista[MAX];
    int cantidad;

    cantidad = cargarEstudiantes("estudiantes.txt", lista);
    if (cantidad == -1) {
        printf("Error al abrir el archibo de entrada. \n");
        return 1;
    }

    guardarAprobados("aprobados.txt", lista, cantidad);
    printf("Proceso completado. Estudiantes aprobado guardados en 'aprobados.txt'.\n");

    return 0;
}

int cargarEstudiantes(const char *archivoEntrada, Estudiante *lista) {
    FILE *archivo = fopen(archivoEntrada, "r");
    if (!archivo) return -1;

    int i = 0;
    while(fscanf(archivo, "%s %d %f", lista[i].nombre, &lista[i].edad, &lista[i].promedio) == 3) {
        i++;
        if (i >= MAX) break;
    }

    fclose(archivo);
    return i;
}

void guardarAprobados(const char *archivoSalida, Estudiante *lista, int cantidad) {
    FILE *archivo = fopen(archivoSalida, "w");

    int i;
    for(i = 0; i < cantidad; i++) {
        if (lista[i].promedio > Nota_minima) {
            fprintf(archivo, "%s %d %.2f\n", lista[i].nombre, lista[i].edad, lista[i].promedio);
        }
    }

    fclose(archivo);
}