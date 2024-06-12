#include "ex3.h"

int main()
{

  no *raiz = cria_no(10, NULL, NULL);
  int bigger = raiz->dado;

  insere_esq(raiz, 9);
  insere_dir(raiz, 11);
  insere_esq(raiz->esq, 8);
  // imprimir(raiz);

  maior(raiz, &bigger);

  print_menores_que(raiz, 10);

  // posOrdem(raiz);
}

int vazia(no *raiz)
{
  if (raiz->esq == NULL && raiz->dir == NULL)
    return 1;
  return 0;
}

no *cria_no(int info, no *esq, no *dir)
{
  no *raiz = (no *)malloc(sizeof(no));
  if (raiz == NULL)
  {
    printf("ERROR AO ALOCAR MEMÓRIA!!!\n");
    return NULL;
  }

  raiz->esq = esq;
  raiz->dir = dir;
  raiz->dado = info;

  return raiz;
}

void imprimir(no *raiz)
{
  if (raiz != NULL)
  {
    printf("%d\n", raiz->dado);
    imprimir(raiz->esq);
    imprimir(raiz->dir);
  }
}

int insere_esq(no *pai, int info)
{
  no *filho = cria_no(info, NULL, NULL);
  if (filho == NULL)
  {
    printf("ERROR AO ALOCAR MEMÓRIA!!!\n");
    return 0;
  }

  pai->esq = filho;
  return 1;
}

int insere_dir(no *pai, int info)
{
  no *filho = cria_no(info, NULL, NULL);
  if (filho == NULL)
  {
    printf("ERROR AO ALOCAR MEMÓRIA!!!\n");
    return 0;
  }

  pai->dir = filho;
  return 1;
}

void maior(no *raiz, int *m)
{
  if (raiz != NULL)
  {
    if (raiz->dado > *m)
      *m = raiz->dado;
    maior(raiz->esq, &(*m));
    maior(raiz->dir, &(*m));
  }
}

int qtd_no_folha(no *raiz)
{
  if (raiz == NULL)
    return 0;
  if (raiz->esq == NULL && raiz->dir == NULL)
    return 1;

  int folhas_esq = qtd_no_folha(raiz->esq);
  int folhas_dir = qtd_no_folha(raiz->dir);

  return (folhas_esq + folhas_dir);
}

int cheia(no *raiz)
{
  if (raiz == NULL)
    return 0;
  if (raiz->esq == NULL && raiz->dir == NULL)
    return 1;
  if ((raiz->esq == NULL && raiz->dir != NULL) || (raiz->esq != NULL && raiz->dir == NULL))
    return 0;
  return (cheia(raiz->esq) && cheia(raiz->dir));
}

void print_menores_que(no *raiz, int N)
{
  if (raiz == NULL)
    return;
  if (N > raiz->dado)
  {
    printf("%d\n", raiz->dado);
    print_menores_que(raiz->esq, N);
    print_menores_que(raiz->dir, N);
  }
  else
    print_menores_que(raiz->esq, N);
}

no *maior_esq(no *raiz)
{
  no *aux = raiz->esq;

  while (aux && aux->dir) // while exist aux and exit the next right node
    aux = aux->dir;

  return aux;
}

no *busca_remove(no *raiz, int info)
{
  if (raiz == NULL)
    return NULL;

  if (raiz->dado == info)
    raiz = remove_no(raiz);
  else if (info < raiz->dado)
    raiz->esq = busca_remove(raiz->esq, info);
  else 
    raiz->dir = busca_remove(raiz->dir, info);
  
  return raiz;
}

no* remove_no(no* raiz) {
  no* aux;

  if (raiz->esq == NULL) {
    // leaf node or rigth is the only son
    aux = raiz; raiz = raiz->dir; free(aux);
  } else if (raiz->dir == NULL) {
    // only son in the left
    aux = raiz; raiz = raiz->esq; free(aux);
  } else {
    // there are two sons
    aux = maior_esq(raiz); raiz->dado = aux->dado; busca_remove(raiz, aux->dado);
  }

  return raiz;
}

int balanceada(no* raiz) {
  if (raiz == NULL) return 1;
  else if (raiz->esq == NULL && raiz->dir == NULL) return 1;
  else if (raiz->esq != NULL && raiz->dir != NULL) return (balanceada(raiz->esq) && balanceada(raiz->dir));
  else if (raiz->esq != NULL) return (Altura(raiz->esq) == 1);
  else return (Altura(raiz->dir) == 1);
}

int Altura (no* raiz) {
  if (raiz == NULL) return 0;

  int altE = Altura(raiz->esq);
  int altD = Altura(raiz->dir);
  return (altE > altD ? (altE + 1) : (altD + 1));
}

int qtdNos (no* raiz) {
  if (raiz == NULL) return 0;

  int nosE = qtdNos(raiz->esq);
  int nosD = qtdNos(raiz->dir);

  return (nosE + nosD + 1);
}

int perfBalanceada (no *raiz) {
  if (raiz == NULL) return 1;
  else if (raiz->esq == NULL && raiz->dir == NULL) return 1;
  else if (raiz->esq != NULL && raiz->dir != NULL) return (perfBalanceada(raiz->esq) && perfBalanceada(raiz->dir));
  else if (raiz->esq != NULL) return (qtdNos(raiz->esq) == 1);
  else return (qtdNos(raiz->dir) == 1);
}