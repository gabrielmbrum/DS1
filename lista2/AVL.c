#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado, altura;
    struct no *esq, *dir;
} no;

no* cria_no (int info) {
    no* newNode = (no*) malloc(sizeof(no));

    newNode->esq = newNode->dir = NULL;

    newNode->dado = info;

    return newNode;
}

void insere_esq () {

}

int main () {

}