#include "AVL.h"

int main () {
    no *raiz = cria_no(5);

    raiz = insere(raiz, 7);
    raiz = insere(raiz, 4);
    raiz = insere(raiz, 6);
    raiz = insere(raiz, 3);
    printf("\nimprimindo árvore:\n");
    preOrd(raiz);

    raiz = remover(raiz, 3);

    printf("\nimprimindo árvore pós remoção:\n");
    preOrd(raiz);
}
