#include "common.h"

int* arrayNew(int size) {
    int* array = (int*)malloc(sizeof(int)*size);
    for(int i=0; i<size; i++) {
        array[i] = rand() % 1000;
    }
    return array;
}

void arrayPrint(int* array, int size) {
    for(int i=0; i<size; i++) {
        printf("%i\t",array[i]);
    }
    printf("\n");
}

int arraySortCheck(int* array, int size) {
    for(int i=0; i<size-1; i++) {
        if(array[i]>array[i+1]) {
            printf("INVALIDO\n");
            return 0;
        }
    }
    printf("VALIDO\n");
    return 1;
}

void bubbleSort(int* array, int size) {

    // COMPLETAR

}

void merge(int* arr, int* copy, int size) {
    int i=0;      // indice del arreglo copia
    int iLow=0;   // indice del arreglo parte baja
    int iHigh=0;  // indice del arreglo parte alta
    // (1) mezclo la parte alta del arreglo con la parte
    //     baja del arreglo
    while( i<size && iLow<size/2 && iHigh<size/2 ) {
        if( arr[iLow] < arr[iHigh+size/2] ) {
            copy[i] = arr[iLow];
            iLow++;
        } else {
            copy[i] = arr[iHigh+size/2];
            iHigh++;
        }
        i++;
    }
    // (2) Si me quedaron datos en la parte baja o alta
    //     del arreglo, entonces completo el resto
    if( i<size ) {
        if(iLow<size/2) {
            // (2.1) Completo con el arreglo de la parte baja
            while( i<size ) {
                copy[i] = arr[iLow];
                iLow++;
                i++;
            }
        } else {
            // (2.1) Completo con el arreglo de la parte alta
            while( i<size ) {
                copy[i] = arr[iHigh+size/2];
                iHigh++;
                i++;
            }
        }
    }
}

void mergeLimit(int* arr, int* copy, int size) {
    int i=0;      // indice del arreglo copia
    int iLow=0;   // indice del arreglo parte baja
    int iHigh=0;  // indice del arreglo parte alta
    // (1) mezclo la parte alta del arreglo con la parte
    //     baja del arreglo hasta llegar a la mitad del
    //     arreglo destino
    while( i<size/2 && iLow<size/2 && iHigh<size/2 ) {
        if( arr[iLow] < arr[iHigh+size/2] ) {
            copy[i] = arr[iLow];
            iLow++;
        } else {
            copy[i] = arr[iHigh+size/2];
            iHigh++;
        }
        i++;
    }
    // (2) Si me quedaron datos en la parte baja o alta
    //     del arreglo, entonces completo el resto
    if( i<size/2 ) {
        if(iLow<size/2) {
            // (2.1) Completo con el arreglo de la parte baja
            while( i<size/2 ) {
                copy[i] = arr[iLow];
                iLow++;
                i++;
            }
        } else {
            // (2.1) Completo con el arreglo de la parte alta
            while( i<size/2 ) {
                copy[i] = arr[iHigh+size/2];
                iHigh++;
                i++;
            }
        }
    }
}

void mergeLimitReverse(int* arr, int* copy, int size) {
    int i=size-1;         // indice del arreglo copia
    int iLow=size/2-1;  // indice del arreglo parte baja
    int iHigh=size/2-1; // indice del arreglo parte alta
    // (1) mezclo la parte alta del arreglo con la parte
    //     baja del arreglo comenzando desde el final
    //     hasta llegar a la mitad del arreglo destino
    while( size/2<=i && 0<=iLow && 0<=iHigh ) {
        if( arr[iLow] > arr[iHigh+size/2] ) {
            copy[i] = arr[iLow];
            iLow--;
        } else {
            copy[i] = arr[iHigh+size/2];
            iHigh--;
        }
        i--;
    }
    // (2) Si me quedaron datos en la parte baja o alta
    //     del arreglo, entonces completo el resto
    if( size/2<=i ) {
        if(0<=iLow) {
            // (2.1) Completo con el arreglo de la parte baja
            while( size/2<=i ) {
                copy[i] = arr[iLow];
                iLow--;
                i--;
            }
        } else {
            // (2.1) Completo con el arreglo de la parte alta
            while( size/2<=i ) {
                copy[i] = arr[iHigh+size/2];
                iHigh--;
                i--;
            }
        }
    }
}
