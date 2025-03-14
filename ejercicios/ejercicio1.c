#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, valores;
    int *arr;

    printf("Ingrese el tamano del arreglo: ");
    scanf("%i",&n);

    arr =(int*)malloc(sizeof(int)*n);

    if (arr == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        return 1;
    }

    printf("Ingrese %d valores:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%i",&valores);
        arr[i] = valores;

    }

    printf("El arreglo es: \n");
    for (int i = 0; i < n; i++) {
        printf("%i \n", arr[i]);
    }
    printf("\n");
    free(arr);
    
    return 0;
}
