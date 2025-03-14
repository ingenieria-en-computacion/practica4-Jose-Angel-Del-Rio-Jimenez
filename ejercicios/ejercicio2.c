#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n; 
    printf("Ingrese el número de filas: ");
    scanf("%i",&m);
    printf("Ingrese el número de columnas: ");
    scanf("%i",&n);

    int *matrix = (int *)calloc(m * n, sizeof(int));
    if (matrix == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        return 1;
    }

    printf("Matriz inicializada con ceros:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%i ",matrix[i*n + j]);
        }
        printf("\n");
    }

    printf("Ingrese las coordenadas (fila, columna) y el valor para modificar (ej. 1 2 5):\n");
    int row, col, value; //row es fila
    //lee los varlores solicitados
    printf("ingresa el numero de fila del elemento que desees modificar \n");
    scanf("%i",&row);
    printf("ingresa el numero de columna del elemento que desees modificar \n");
    scanf("%i",&col);
    printf("ingresa el valor que desees sustituir \n");
    scanf("%i",&value);

    matrix[(row-1) * n + (col-1)] = value;

    printf("Matriz actualizada:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%i ",matrix[i * n + j]);
        }
        printf("\n");
    }

    free(matrix);
    return 0;
}
