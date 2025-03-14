#include <stdio.h>
#include <stdlib.h>

int main() {
    int size=5 ; // Asigna un número pequeño
    int *arr ; // reserva memoria con malloc
    arr = (int*)malloc(sizeof(int)*size);

    if (arr == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        return 1;
    }

    int count = 0;
    int num;
    printf("Ingrese los numeros (ingrese -1 para terminar):\n");
    while (1) {
        scanf("%d",&num);

        if (num == -1){
            break;
        }//rompe el ciclo

        if (count >= size) {
            size *= 2;
            arr = (int*)realloc(arr,size*sizeof(int)); //utiliza realloc para cambiar el tamaño del arreglo
            if (arr == NULL) {
                printf("Error: No se pudo reasignar memoria.\n");
                return 1;
            }
        }

        arr[count++] = num;
    }

    printf("La lista ingresada es: \n");
    for (int i = 0; i < count; i++) {
        printf("%i ",arr[i]);
        //Imprime la lista
    }
    printf("\n");

    //libera la memoria
    free(arr);
    return 0;
}
