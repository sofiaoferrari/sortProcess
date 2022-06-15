#ifndef _COMMON_HH_
#define _COMMON_HH_

#define N 1000

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <limits.h>
#include <time.h>

// == arrayNew ==
// Crear un arreglo de enteros de tama;o size.
int* arrayNew(int size);

// == arrayPrint ==
// Imprime un arreglo de tama;o size.
void arrayPrint(int* array, int size);

// == arraySortCheck ==
// Chequea que un arreglo este ordenado correctamente
int arraySortCheck(int* array, int size);

// == bubbleSort ==
// Ordena un arreglo de tama;o size
void bubbleSort(int* array, int size);

// == merge ==
// Mezcla de forma ordenada la parte alta de un arreglo
// con la parte baja del mismo arreglo. El resultado lo
// guarda en un nuevo arreglo (copy).
void merge(int* arr, int* copy, int size);

// == mergeLimit ==
// Mezcla de forma ordenada la parte alta de un arreglo
// con la parte baja del mismo arreglo. Limitando el
// resultado a la mitad mas grande del arreglo.
// El resultado se guarda en copy.
void mergeLimit(int* arr, int* copy, int size);

// == mergeLimitReverse ==
// Mezcla de forma ordenada la parte alta de un arreglo
// con la parte baja del mismo arreglo. Limitando el
// resultado a la mitad mas chica del arreglo.
// El resultado se guarda en copy.
void mergeLimitReverse(int* arr, int* copy, int size);

#endif
