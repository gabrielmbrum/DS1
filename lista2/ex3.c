#include "ex3.h"

int main () {
    
    no *raiz = cria_no(10, NULL, NULL);
    int bigger = raiz->dado;

    insere_esq(raiz, 9);
    insere_dir(raiz, 11);
    insere_esq(raiz->esq, 8);
    imprimir(raiz);

    maior(raiz, &bigger);

    printf("\no maior elemento é: %d\n", bigger);

    printf("\nessa árvore possui %d nós folhas\n", qtd_no_folha(raiz));

    if (cheia(raiz))
        printf("\nárvore está cheia!\n");
    else   
        printf("\návore não está cheia!\n");
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

void maior (no *raiz, int *m) {
    if (raiz != NULL) {
        if (raiz->dado > *m) *m = raiz->dado;
        maior(raiz->esq, &(*m));
        maior(raiz->dir, &(*m));
    }
}

int qtd_no_folha (no *raiz) {
    if (raiz==NULL) return 0;
    if (raiz->esq == NULL && raiz->dir == NULL) return 1;

    int folhas_esq = qtd_no_folha(raiz->esq);
    int folhas_dir = qtd_no_folha(raiz->dir);

    return (folhas_esq + folhas_dir);
}

int cheia (no *raiz) {
    if (raiz == NULL) return 0;
    if (raiz->esq == NULL && raiz->dir == NULL)
        return 1;
    if ( ( raiz->esq == NULL && raiz->dir != NULL )|| ( raiz->esq != NULL && raiz->dir == NULL ) )
        return 0;
    return (cheia(raiz->esq) && cheia(raiz->dir));

}