#include <stdlib.h> //Para usar malloc, free, exit ...
#include <stdio.h>  //Para usar printf ,... 
#include "lojinha.h"  //Carrega o arquivo .h criado

#define MAX 100    //estimativa do tamanho m�ximo da lista
#define TRUE 1     //define tipo boleano � n�o existe em C
#define FALSE 0
#define boolean int

//Implementa��o: lista seq.

//Opera��es
//-------------------------------------------
boolean Vazia(lista *L)
{
   //Retorna true (1): se vazia, false (0): caso contr�rio
   return (L->nelem == 0);
}

boolean Cheia(lista *L)
{
   //Retorna true (1): se cheia, false (0): caso contr�rio
   return (L->nelem == MAX);
}

void Definir(lista *L)
{
   /*Cria uma lista vazia. Este procedimento deve ser chamado
   para cada nova lista antes de qualquer outra opera��o.*/
   L->nelem = 0;
   L->A[0].chave = 0;
}

void Apagar(lista *L){
   //Apaga "logicamente" uma lista
   L->nelem = 0;
}

float Valor(int key, lista *L) {
   for (int i = 0; i < L->nelem; i++) {
      if (L->A[i].chave == key)
         return (L->A[i].info.valor);
   }
}

float ValorCarrinho (lista *Carrinho) {
   float value = 0;
   
   for (int i = 0; i < Carrinho->nelem; i++) {
      value += Carrinho->A[i].info.valor * Carrinho->A[i].info.quantidade;
   }

   return value;
}

boolean Buscar(int x, lista *L, int *p)
{   
   /*Retorna true, se x ocorre na posi��o p. Se x ocorre mais de
   uma vez, retorna a posi��o da primeira ocorr�ncia. Se x n�o
   ocorre, retorna false. Para listas N�O-ORDENADAS*/

   if (!Vazia(L))
   {
      int i = 1;
      while (i <= L->nelem)
         if (L->A[i].chave == x)
		   {
            *p = i;
            return TRUE;
         } 
		 else
         i++;
   }
   return FALSE; //Retorna false se n�o encontrou
}

void Remover_posic(int p, lista *L)
{
   /*S� � ativada ap�s a busca ter retornado a posi��o p
   do elemento a ser removido - Nro de Mov = (nelem � p)*/
   
   int i;
   
   for (i = p+1; i <= L->nelem; i++)
      L->A[i-1] = L->A[i];
   
   L->nelem--;
}

void Impr_prod(produto t)
{
   printf("chave: %d\n", t.chave);
   printf("quantidade: %d\n", t.info.quantidade);
   printf("valor: %4.2f\n", t.info.valor);
}

void Imprimir(lista *L)
{
   //Imprime os elementos na sua ordem de preced�ncia
   
   if (!Vazia(L))
      for (int i = 1; i <= L->nelem; i++)
         Impr_prod(L->A[i]);
}

int Produto_existente (int key, produto *array) {
   
   for (int i = 0; array[i].chave; i++)
      if (array[i].chave == key)
         return i+1;

   return 0;
}

boolean Inserir_produto (int key, int qtd, float valor, lista *L) {

   int aux = Produto_existente(key, L->A); 
   
   if (aux != 0) {
      // produto já existe, então adiciona somente a quantidade
      (*L).A[aux-1].info.quantidade += qtd;
      return TRUE;
   } 
   
   if (Cheia(L)) {
      printf("Lista de produtos já esá cheia!!");
      return FALSE;
   }

   (*L).A[L->nelem].chave = key;
   (*L).A[L->nelem].info.quantidade = qtd;
   (*L).A[L->nelem++].info.valor = valor;

   return TRUE;
}

boolean Remover_produto (int key, int qtd, lista *L) {

   
   int aux = Produto_existente(key, L->A);

   if (!aux) return FALSE; //produto não existe

   if (L->A[aux-1].info.quantidade < qtd) return FALSE;

   if (L->A[aux-1].info.quantidade == qtd) {
      Remover_posic(aux-1,L);
      return TRUE;   
   }  

   printf("Quantidade que deseja remove é maior do que a existente!!\n");
   return FALSE;
}

boolean AdicionarAoCarrinho (int key, lista *L, lista *Carrinho) {
   
   int aux = Produto_existente(key, L->A), qtd;

   // checa se existe estoque disponível
   if (L->A[aux-1].info.quantidade < 1) {
      printf("Produto indisponível!!");
      return FALSE;
   }
   
   if (aux) { //produto existe

      printf("Digite a quantidade desejada: ");
      scanf(" %d", &qtd);

      while (aux > L->A[aux-1].info.quantidade || aux == 0) {
         printf("Quantidade indisponível, digite a quantidade novamente: ");
         scanf(" %d", &qtd);
      }
      
      if (Remover_produto(key, qtd, L) && Inserir_produto(key, qtd, Valor(key, L), Carrinho))
         return TRUE;
   }  
   printf("ERRO!!\n");
   return FALSE;
}