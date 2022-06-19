#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <limits.h>
#include <time.h>
#include <pthread.h>

#include "common.h"

static int* array;
static int size;
static int* newArray;

int main() {
    // Seteo la semilla del generador de numeros aleatorios
    srand(time(NULL));

    // Genero un arreglo de N elementos
    size = N;
    array = arrayNew(size);
    

    bubbleSort(array, size/2);
    bubbleSort(array+(size/2), size/2);

    newArray = (int*)malloc(sizeof(int)*size);

    mergeLimit(array, newArray, size);
    mergeLimitReverse(array, newArray, size);

    arrayPrint(newArray, size);
    
    // Verificar si el arreglo esta ordenado
    arraySortCheck(newArray, size);

    // Libero memoria
    free(array);
    free(newArray);

    return 0;
}
