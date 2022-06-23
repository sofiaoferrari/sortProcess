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
static int* newnewArray;

static void* sort1(void* arg) {
    bubbleSort(array, size/4);
    return 0;
}

static void* sort2(void* arg) {
    bubbleSort(array+(size/4), size/4);
    return 0;
}

static void* sort3(void* arg) {
    bubbleSort(array+(size/2), size/4);
    return 0;
}

static void* sort4(void* arg) {
    bubbleSort(array+((size*3)/4), size/4);
    return 0;
}

static void* merge1(void* arg) {
    mergeLimit(array, newArray, size/2);
    return 0;
}

static void* merge2(void* arg) {
    mergeLimitReverse(array, newArray, size/2);
    return 0;
}

static void* merge3(void* arg) {
    mergeLimit(array+(size/2), newArray+(size/2), size/2);
    return 0;
}

static void* merge4(void* arg) {
    mergeLimitReverse(array+(size/2), newArray+(size/2), size/2);
    return 0;
}

static void* merge5(void* arg) {
    mergeLimit(newArray, newnewArray, size);
    return 0;
}

static void* merge6(void* arg) {
    mergeLimitReverse(newArray, newnewArray, size);
    return 0;
}


int main() {

    pthread_t thread1, thread2;
    pthread_t thread3, thread4;

    // Seteo la semilla del generador de numeros aleatorios
    srand(time(NULL));

    // Genero un arreglo de N elementos
    size = N;
    array = arrayNew(size);

    // Ordeno el arreglo en dos procesos distintos
    pthread_create(&thread1, NULL, sort1, NULL);    
    pthread_create(&thread2, NULL, sort2, NULL);
    pthread_create(&thread3, NULL, sort3, NULL);
    pthread_create(&thread4, NULL, sort4, NULL);


    // Espero la terminacion de los dos procesos
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);

    newArray = (int*)malloc(sizeof(int)*size);

    // Mezclo el arreglo en dos procesos distintos
    pthread_create(&thread1, NULL, merge1, NULL);
    pthread_create(&thread2, NULL, merge2, NULL);
    pthread_create(&thread3, NULL, merge3, NULL);
    pthread_create(&thread4, NULL, merge4, NULL);

    // Espero la terminacion de los dos procesos
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);
   
    newnewArray = (int*)malloc(sizeof(int)*size);
       
    //
    pthread_create(&thread1, NULL, merge5, NULL);
    pthread_create(&thread2, NULL, merge6, NULL);
    
    // Espero la terminacion de los dos procesos
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    

    // Imprimo en pantalla el arreglo
    arrayPrint(newnewArray, size);
    
    // Verificar si el arreglo esta ordenado
    arraySortCheck(newnewArray, size);
    
    // Libero memoria
    free(array);
    free(newArray);

    return 0;
}
