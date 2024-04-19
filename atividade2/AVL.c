#include "AVL.h"

no *cria_no(int data)
{
    no *new = (no *)malloc(sizeof(no));
    new->dado = data;
    new->fb = 0;
    new->esq = new->dir = NULL;

    return new;
}

no *insere(no *raiz, no *new)
{
    if (raiz == NULL)
    {
        // printf("\nraiz recebendo: %d\n", new->dado);
        raiz = cria_no(new->dado);
        // printf("\nraiz recebeu: %d\n", raiz->dado);
    }
    else if (new->dado > raiz->dado)
    {
        raiz->dir = insere(raiz->dir, new);
    }
    else if (new->dado < raiz->dado)
    {
        raiz->esq = insere(raiz->esq, new);
    }
    else
    {
        printf("\n\tNÓ JÁ EXISTENTE!!!\n");
        return raiz;
    }

    // atualizar fb
    raiz->fb = altura(raiz->dir) - altura(raiz->esq);

    // verificar se a raiz desbalanceou
    if (desbalanceada(raiz))
    {

        printf("\ndesbalanceou!!\n");

        if (raiz->fb > 1)
        {
            if (raiz->dir->fb < 0)
                raiz = rotEsqDupla(raiz);
            else
                raiz = rotEsqSimples(raiz);
        }
        else
        {
            if (raiz->esq->fb > 0)
                raiz = rotDirDupla(raiz);
            else
                raiz = rotDirSimples(raiz);
        }
    }
    else if (raiz->dado == new->dado) // imprime a mensagem de inserido com sucesso, se e somente se, for o número novo inserido
        printf("\n%d inserido com sucesso!!\n", raiz->dado);

    return raiz;
}

int desbalanceada(no *raiz)
{
    if (raiz == NULL)
        return 0;
    if (raiz->fb > 1 || raiz->fb < -1)
        return 1;
    else
        return (desbalanceada(raiz->esq) || desbalanceada(raiz->dir));
}

int altura(no *raiz)
{
    if (raiz == NULL)
        return 0;

    int altE = altura(raiz->esq);
    int altD = altura(raiz->dir);

    return (altE + altD + 1);
}

void preOrd(no *raiz)
{
    if (raiz != NULL)
    {
        printf("%d\n", raiz->dado);
        preOrd(raiz->esq);
        preOrd(raiz->dir);
    }
}

no *rotEsqSimples(no *raiz)
{
    no *aux = (no *)malloc(sizeof(no));

    aux->dado = raiz->dir->dado;
    aux->esq = raiz;
    aux->dir = raiz->dir->dir;
    aux->esq->dir = raiz->dir->esq;

    // recalcula os FB's
    aux->fb = altura(aux->dir) - altura(aux->esq);
    raiz->fb = altura(raiz->dir) - altura(raiz->esq);

    return aux;
}

no *rotDirSimples(no *raiz)
{
    no *aux = (no *)malloc(sizeof(no)); // nova raiz

    aux->dado = raiz->esq->dado;
    aux->dir = raiz;
    aux->esq = raiz->esq->esq;
    aux->dir->esq = raiz->esq->dir;

    // refatorando os FBs
    aux->fb = altura(aux->dir) - altura(aux->esq);
    raiz->fb = altura(raiz->dir) - altura(raiz->esq);

    return aux;
}

no *rotEsqDupla(no *raiz)
{
    raiz->dir = rotDirSimples(raiz->dir);
    return rotEsqSimples(raiz);
}

no *rotDirDupla(no *raiz)
{
    raiz->esq = rotEsqSimples(raiz->esq);
    return rotDirSimples(raiz);
}

no* remover(no *raiz, int elem)
{
    no* alvo = NULL; 
    alvo = (no *) malloc(sizeof(no)); 
    alvo = busca(raiz, elem);
    if (alvo == NULL)
    {
        puts("\nNÓ NÃO ENCONTRADO!");
        return raiz;
    }

    // caso for nó folha
    if (alvo->dir == NULL && alvo->esq == NULL)
    {
        free(alvo);
    }
    // caso possuir filho a esquerda
    else if (alvo->dir == NULL)
    {
        alvo->dado = alvo->esq->dado;
        alvo->esq = NULL;
    }
    // caso possuir filho a direita
    else if (alvo->esq == NULL) {
        alvo->dado = alvo->dir->dado;
        alvo->dir = NULL;
    }
    // caso for pai de 2
    else {
        no* aux = maior_dir(alvo);
        alvo->dado = aux->dado;
        remover(aux, aux->dado);
    }
    
    puts("oi");
    return raiz;
}

no* busca(no *raiz, int elem)
{
    if (raiz == NULL)
        return NULL;
    if (raiz->dado == elem)
        return raiz;
    if (elem > raiz->dado)
        return busca(raiz->dir, elem);
    else
        return busca(raiz->esq, elem);
}

no* maior_dir (no* raiz) {
    no* aux = raiz->esq;
    
    while (aux->dir)
        aux = aux->dir;
    
    return aux;
}
