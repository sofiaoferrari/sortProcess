#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <limits.h>
#include <time.h>
#include <pthread.h>

#include "common.h"

int main() {

    // Seteo la semilla del generador de numeros aleatorios
    srand(time(NULL));

    // Genero un arreglo de N elementos
    int size = N;
    int* array = arrayNew(size);

    // COMPLETAR

    return 0;
}
