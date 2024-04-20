#include "AVL.h"

no *cria_no(int data)
{
  no *new = (no *)malloc(sizeof(no));
  new->dado = data;
  new->fb = 0;
  new->esq = new->dir = NULL;

  return new;
}

no *insere(no *raiz, int val)
{
  if (raiz == NULL)
  {
    // printf("\nraiz recebendo: %d\n", new->dado);
    raiz = cria_no(val);
    // printf("\nraiz recebeu: %d\n", raiz->dado);
  }
  else if (val > raiz->dado)
  {
    raiz->dir = insere(raiz->dir, val);
  }
  else if (val < raiz->dado)
  {
    raiz->esq = insere(raiz->esq, val);
  }
  else
  {
    printf("\n\tNÓ JÁ EXISTENTE!!!\n");
    return raiz;
  }

  // atualizar fb
  raiz->fb = altura(raiz->dir) - altura(raiz->esq);

  raiz = balancear(raiz);
  
  if (raiz->dado == val) // imprime a mensagem de inserido com sucesso, se for o número novo inserido
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

no *remover(no *raiz, int chave)
{
  if (raiz == NULL)
  {
    printf("NÓ NÃO ENCONTRADO!!!\n");
    return NULL;
  }
  else
  { // procura nó a remover
    if (raiz->dado == chave)
    {
      if (raiz->esq == NULL && raiz->dir == NULL)
      { // é nó folha
        free(raiz);
        printf("elemento folha removido: %d\n", chave);
        return NULL;
      }
      else if (raiz->esq != NULL && raiz->dir != NULL)
      {
        no *aux = raiz->esq;
        while (aux->dir)
          aux = aux->dir;

        raiz->dado = aux->dado;
        aux->dado = chave;
        printf("elemento trocado: %d\n", chave);
        raiz->esq = remover(raiz->esq, chave);
        return raiz;
      }
      else
      {
        no *aux;
        if (raiz->esq != NULL)
          aux = raiz->esq;
        else
          aux = raiz->dir;
        free(raiz);
        printf("elemento com 1 filho removido: %d\n", chave);
        return aux;
      }
    }
    else if (chave < raiz->dado)
      raiz->esq = remover(raiz->esq, chave);
    else
      raiz->dir = remover(raiz->dir, chave);
  }

  raiz->fb = altura(raiz->dir) - altura(raiz->esq);

  raiz = balancear(raiz);
}

no *busca_ancestral(no *raiz, int elem)
{
  if (raiz == NULL)
    return NULL;
  if (raiz->dado == elem)
    return raiz;
  if (elem > raiz->dado)
    return busca_ancestral(raiz->dir, elem);
  else
    return busca_ancestral(raiz->esq, elem);
}

no *maior_dir(no *raiz)
{
  no *aux = raiz->esq;

  while (aux->dir)
    aux = aux->dir;

  return aux;
}

no* balancear (no *raiz) {
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

  return raiz;
}