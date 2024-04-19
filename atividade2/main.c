#include "AVL.h"

int main () {
    no *raiz = cria_no(5), *seis = cria_no(6), *sete = cria_no(7), *quatro = cria_no(4);

    raiz = insere(raiz, seis);
    //raiz = insere(raiz, quatro);
    raiz = insere(raiz, sete);
    printf("\nimprimindo árvore:\n");
    preOrd(raiz);
}