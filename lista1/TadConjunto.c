#include <stdio.h>
#include <stdlib.h>
#include "TadConjunto.h"

int main () {
    // fields
    int *arr1, inp;

    // initializing and implementing arr1 and arr2
    printf("Digite o tamanho do array: ");
    scanf(" %d", &inp);
    arr1 = malloc(sizeof(int) * inp);

    for (int i = 0; i < inp; i++) {
        printf("arr1[%d]: ", i);
        scanf(" %d", &arr1[i]);
    }
    
    Insere(192, &arr1);
    
    printf("\nPrintando resultado!\n");
    //printf("res[0]: %d", res[0]);

    for (int i = 0; i < inp+1; i++) {
        printf("a[%d]: %d\n", i, arr1[i]);
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

int* Intersecsao (int *a, int *b) {
    // fields
    int *arr, *aux, sizeA, sizeB, count = 0;

    // initializing vars
    sizeA = sizeof(a)/sizeof(int);
    sizeB = sizeof(b)/sizeof(int);

    // creates aux array with the bigger length
    if (sizeA > sizeB) aux = malloc(sizeof(int) * sizeA);
    else aux = malloc(sizeof(int) * sizeB);

    // check the equals, if it is equal implement and goes to the next position, until the array is over
    for (int i = 0; i <= sizeA; i++) {
        for (int j = 0; j <= sizeB; j++) {
            if (a[i] == b[j]) {
                aux[count++] = a[i];
                break;
            }
        }
    }

    // creates the return arr with the necessary length, implements it and return it
    arr = malloc(sizeof(int) * count);

    for (int i = 0; i<count; i++)
        arr[i] = aux[i];

    return arr;
}

boolean Membro (int x, int *a) {
    // fields
    int sizeA = sizeof(a)/sizeof(int);

    // checking if the 'x' is on the array, if it is return TRUE, else return FALSE
    for (int i = 0; i<=sizeA; i++) {
        if (a[i] == x)
            return TRUE;
    }

    return FALSE;
}

void Insere (int x, int **a) {
    // checks if the element is already on the array
    if (Membro(x, *a))
        return;

    int sizeA = 0;
    while ((*a)[sizeA])
        sizeA++;
    // +2 is because the sizeA has the max index value, which is the sizeOfArray - 1, 
    // so to has a new position, it needs to be created as +2
    int *aux = malloc (sizeof(int) * (sizeA+1)); 
    

    for (int i = 0; i<sizeA; i++) {
        aux[i] = (*a)[i];
    }

    aux[sizeA] = x;

    *a = aux;
}

boolean Igual (int *a, int *b) {
    for (int i = 0; a[i]; i++) 
        if (!(Membro(a[i], b)))
            return FALSE;

    return TRUE;
}