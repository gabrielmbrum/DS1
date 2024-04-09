#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lojinha.h"
#define boolean int

int main()
{
  // Preencher aqui um exemplo pr�tico que utilizar parte das opera��es da lista sequencial
  lista *L, *Carrinho;

  L = malloc(sizeof(lista));
  
  Carrinho = malloc(sizeof(lista));

  free(L);
  free(Carrinho);

  return 0;
}
