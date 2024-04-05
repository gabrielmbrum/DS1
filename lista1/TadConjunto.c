#include <stdio.h>
#include <stdlib.h>
#include "TadConjunto.h"

int main () {
    int *arr1, *arr2, *res, inp;

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

    printf("tam res: %d\n", (int)(sizeof(res)/sizeof(int)));
    
    printf("\nPrintando resultado!\n");
    for (int i = 0; i <= (sizeof(arr1) + sizeof(arr2))/sizeof(int); i++) {
        printf("res[%d]: %d\n", i, res[i]);
    }
}

int* Uniao (int *a, int *b) {
    int *arr, sizeA = sizeof(a)/sizeof(int), sizeB = sizeof(b)/sizeof(int);
    int len = sizeA + sizeB + 1, i;

    
    arr = malloc(sizeof(int) * len);

    for (i = 0; i <= len; i++) {
        printf("arr[%d]: %d\n", i, arr[i]);
    }
    printf("len: %d\n", len);
    printf("arr: %d\n", (int)(sizeof(arr)/sizeof(int)));
    for (i = 0; i <= sizeA; i++) {
        arr[i] = a[i];
    }

    for (i = 0; i <= sizeB; i++) {
        arr[sizeA+i] = b[i];
    }
    return arr;
}