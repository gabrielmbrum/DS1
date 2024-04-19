#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado, fb;
    struct no *esq, *dir;
} no;

no* cria_no(int data);

no* insere(no* raiz, no* new);

int desbalanceada(no * raiz);

int altura(no *raiz);

void preOrd (no *raiz);

no* rotEsqSimples (no* raiz);