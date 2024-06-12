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

// faz o inteiro 'm' receber o maior elemento da árvore
void maior (no *raiz, int *m);

// retorna a quantidade de nó folhas da árvore
int qtd_no_folha (no *raiz);

int cheia(no* raiz);

void print_menores_que (no *raiz, int N);

// retorna o maior nó a esquerda 
no* maior_esq (no* raiz);

no *busca_remove(no *raiz, int info);

no* remove_no(no* raiz);

int balanceada(no* raiz); //retorna 1 (true) ou 0 (false)

int Altura(no* raiz);

int qtdNos (no* raiz);