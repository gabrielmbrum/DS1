#include "AVL.h"

no* cria_no (int data) {
    no* new = (no*) malloc(sizeof(no));
    new->dado = data;
    new->fb = 0;
    new->esq = new->dir = NULL;

    return new;     
}

no* insere(no* raiz, no* new) {
    if (raiz == NULL) { 
        //printf("\nraiz recebendo: %d\n", new->dado); 
        raiz = cria_no(new->dado); 
        //printf("\nraiz recebeu: %d\n", raiz->dado);
    } 
    else if (new->dado > raiz->dado) { raiz->dir = insere(raiz->dir, new); }
    else if (new->dado < raiz->dado) { raiz->esq = insere(raiz->esq, new); }
    else { printf("\n\tNÓ JÁ EXISTENTE!!!\n"); return raiz;}

    // atualizar fb
    raiz->fb = altura(raiz->dir) - altura(raiz->esq);

    //verificar se a raiz desbalanceou
    if (desbalanceada(raiz))
        printf("\ndesbalanceou!!\n");
    else if (raiz->dado == new->dado) //imprime a mensagem de inserido com sucesso, se e somente se, for o número novo inserido
        printf("\n%d inserido com sucesso!!\n", raiz->dado);

    return raiz;
}

int desbalanceada(no * raiz) {
    if (raiz == NULL) return 0;
    if (raiz->fb > 1 || raiz->fb < -1) return 1;
    else return(desbalanceada(raiz->esq) || desbalanceada(raiz->dir));
}

int altura(no *raiz) {
    if (raiz == NULL) return 0;

    int altE = altura(raiz->esq);
    int altD = altura(raiz->dir);

    return (altE + altD + 1);
}

void preOrd (no *raiz) {
    if (raiz != NULL) {
        printf("%d\n", raiz->dado);
        preOrd(raiz->esq);
        preOrd(raiz->dir);
    }
}
