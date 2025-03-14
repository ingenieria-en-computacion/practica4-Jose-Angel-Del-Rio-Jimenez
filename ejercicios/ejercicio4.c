#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Crea un tipo de dato estudiante que guarde el nombre del estudiante max. 40 caracteres y su edad
typedef struct estudiante{
    int edad;
    char nombre[40];
} Estudiante;

int main() {
    Estudiante *arredim;
    int size = 2;
    // Crea un arreglo dinámico usando malloc de tamaño size
    arredim = (Estudiante*)malloc(size* sizeof(Estudiante)); 

    //Si el arreglo es nulo imprime el mensaje
    if (arredim == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        return 1;
    }

    int count = 0;
    char nombre[50];
    int edad;
    printf("Ingrese estudiantes (nombre y edad, ingrese 'fin' para terminar):\n");
    while (1) {
        printf("Nombre: ");
        scanf("%s", nombre);
        if (strcmp(nombre, "fin") == 0) break;

        printf("Edad: ");
        scanf("%d", &edad);

        if (count >= size) {
            size *= 2;
            //Cambia el tamaño del arreglo
            //Verifica nuevamente que si apunta a nulo se imprima el error
            arredim = (Estudiante*)realloc(arredim, size * sizeof(Estudiante));
            if (arredim == NULL) {
                printf("Error: No se pudo reasignar memoria.\n");
                return 1;
            }
        }
        //copia el nombre leido en el nuevo estudiante y su edad
        strcpy(arredim[count].nombre, nombre);
        arredim[count].edad = edad;
        
        count++;
    }

    printf("Lista de estudiantes:\n");
    for (int i = 0; i < count; i++) {
        printf("Nombre: %s, Edad: %d\n", arredim[i].nombre, arredim[i].edad);
    }

    //libera la memoria
    free(arredim);
    return 0;
}
