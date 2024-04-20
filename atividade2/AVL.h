#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado, fb;
    struct no *esq, *dir;
} no;

no* cria_no(int data);

no* insere(no* raiz, int val);

int desbalanceada(no * raiz);

int altura(no *raiz);

void preOrd (no *raiz);

no* rotEsqSimples (no* raiz);

no* rotDirSimples (no *raiz);

no* rotEsqDupla (no *raiz);

no* rotDirDupla (no *raiz);

no* remover(no *raiz, int elem);

no* busca_ancestral(no *raiz, int elem);

no* maior_dir (no* raiz);

no* balancear (no* raiz);