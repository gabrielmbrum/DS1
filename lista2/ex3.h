#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *esq;
    struct no *dir;
} no;

// retorna 1 caso a árvore esteja vazia
int vazia (no *raiz);

// cria no com as informações passadas e retorna-o
no *cria_no (int info, no *esq, no *dir);

// imprimi toda a árvore em pré-ordem
void imprimir (no *raiz);

// insere nó a esquerda do nó pai
int insere_esq (no *pai, int info);

// insere nó a direita do nó pai
int insere_dir (no *pai, int info);