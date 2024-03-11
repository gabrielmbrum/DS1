#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#define boolean int

int main()
{
  // Preencher aqui um exemplo pr�tico que utilizar parte das opera��es da lista sequencial

  // Declaração
  lista *L = (lista *)malloc(sizeof(lista));
  tipo_elem x, y, z;

  // Inserção
  x.chave = 10;
  strcpy(x.info.nome, "joão");
  x.info.idade = 18;
  x.info.media_final = 9;

  y.chave = 3;
  strcpy(y.info.nome, "carlos");
  y.info.idade = 11;
  y.info.media_final = 5;

  z.chave = 7;
  strcpy(z.info.nome, "carlos");
  z.info.idade = 11;
  z.info.media_final = 5;

  Definir(L);

  if (Inserir_posic(y, 1, L))
    printf("\nelemento 3 inserido com sucesso!!\n");
  else
    puts("\nERROR!!\n");

  Imprimir(L);

  if (Inserir_ord(x, L))
    printf("\nelemento 10 inserido com sucesso!!\n");
  else
    printf("\nERRO\n");

  if (Inserir_ord(z, L))
    printf("\nelemento 7 inserido com sucesso!!\n");
  else
    printf("\nERRO kk\n");

  Imprimir(L);

  return 0;
}
