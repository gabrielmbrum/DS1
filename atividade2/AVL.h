#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado, fb;
    struct no *esq, *dir;
} no;

// cria no com o dado passado de parâmetro
no* cria_no (int data);

// insere na AVL e no final balanceia a árvore
no* insere (no* raiz, int val);

// checa se a arvore esta desbalanceada
int desbalanceada (no * raiz);

// balanceia pelas rotações
no* balancear (no* raiz);

// retorna a altura da árvore
int altura (no *raiz);

// imprime em pré-ordem
void preOrd (no *raiz);

// rotação simples esquerda
no* rotEsqSimples (no* raiz);

// rotação simples direita
no* rotDirSimples (no *raiz);

// rotação dupla esquerda
no* rotEsqDupla (no *raiz);

// rotação dupla direita
no* rotDirDupla (no *raiz);

// remove o nó com o dado e balanceia a árvore
no* remover (no *raiz, int elem);

// retorna o maior nó á esquerda
no* maior_esq (no* raiz);
