#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lojinha.h"
#define boolean int

int main()
{
  // Preencher aqui um exemplo pr�tico que utilizar parte das opera��es da lista sequencial
  lista L, Carrinho;

  Definir(&L);
  Definir(&Carrinho);

  Inserir_produto(1, 20, 31.5, &L);

  Imprimir(&L);

  return 0;
}
