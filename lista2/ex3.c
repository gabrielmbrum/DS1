#include "ex3.h"

int main () {
    no *raiz = cria_no(10, NULL, NULL);
    insere_esq(raiz, 9);
    insere_dir(raiz, 11);
    imprimir(raiz);
}

int vazia (no *raiz) {
    if (raiz->esq == NULL && raiz->dir == NULL) 
        return 1;
    return 0;
}

no *cria_no (int info, no *esq, no *dir) {
    no *raiz = (no*) malloc(sizeof(no));
    if (raiz == NULL) {
        printf("ERROR AO ALOCAR MEMÓRIA!!!\n");
        return NULL;
    }

    raiz->esq = esq;
    raiz->dir = dir;
    raiz->dado = info;

    return raiz;
}

void imprimir (no *raiz) {
    if (raiz != NULL) {
        printf("%d\n", raiz->dado);
        imprimir(raiz->esq);
        imprimir(raiz->dir);
    }
}

int insere_esq (no *pai, int info) {
    no *filho = cria_no(info, NULL, NULL);
    if (filho == NULL) {
        printf("ERROR AO ALOCAR MEMÓRIA!!!\n");
        return 0;
    }

    pai->esq = filho;
    return 1;
}

int insere_dir (no *pai, int info) {
    no *filho = cria_no(info, NULL, NULL);
    if (filho == NULL) {
        printf("ERROR AO ALOCAR MEMÓRIA!!!\n");
        return 0;
    }

    pai->dir = filho;
    return 1;
}