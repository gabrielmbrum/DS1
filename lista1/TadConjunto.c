#include <stdio.h>
#include <stdlib.h>
#include "TadConjunto.h"

int main () {
    // fields
    int *arr1, *arr2, *res, inp;

    // initializing and implementing arr1 and arr2
    printf("Digite o tamanho do array 1: ");
    scanf(" %d", &inp);
    arr1 = malloc(sizeof(int) * inp);

    for (int i = 0; i < inp; i++) {
        printf("arr1[%d]: ", i);
        scanf(" %d", &arr1[i]);
    }
    
    printf("\nDigite o tamanho do array 2: ");
    scanf(" %d", &inp);
    arr2 = malloc(sizeof(int) * inp);

    for (int i = 0; i < inp; i++) {
        printf("arr2[%d]: ", i);
        scanf(" %d", &arr2[i]);
    }

    res = Uniao(arr1, arr2);
    
    printf("\nPrintando resultado!\n");

    for (int i = 0; res[i]; i++) {
        printf("res[%d]: %d\n", i, res[i]);
    }
}

int* Uniao (int *a, int *b) {
    // fields
    int *arr, sizeA, sizeB, len, i;

    // initializing vars
    sizeA = sizeof(a)/sizeof(int);
    sizeB = sizeof(b)/sizeof(int);
    len = sizeA + sizeB + 1;
    arr = malloc(sizeof(int) * len);

    //implementing returning array with a and b elements
    for (i = 0; i <= sizeA; i++) 
        arr[i] = a[i];

    for (i = 0; i <= sizeB; i++) 
        arr[sizeA+i] = b[i];

    return arr;
}