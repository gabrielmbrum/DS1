#include <stdio.h>
#include <stdlib.h>
#include "justForFun.h"
/*
this code was the first one and it is a exercise "Just For Fun" (by Wallace's Words)

it's just a code to remember the concepts and the usability of pointers
*/

//-------------//-------------//-------------//-------------//-------------
// conjunto.c

Conjunto *criar(int tamanho) {
  //puts("oi");
  Conjunto *A;
  if (!((Conjunto*) malloc(sizeof(Conjunto))))
    puts("ERROR!!!");
  
  A->tamanho = tamanho;
  A->elementos = (int*) malloc(sizeof(int) * tamanho);

  for (int i = 0; i < tamanho; i++) {
    printf("Digite o elemento %d do conjunto: ", i + 1);
    scanf(" %d", &A->elementos[i]);
    //printf("i: %d | tamanho %d\n", i, tamanho);
  }

  return A;
}

Conjunto *uniao(Conjunto *A, Conjunto *B) {
  Conjunto *C = (Conjunto*) malloc(sizeof(Conjunto));
  int i;
  
  C->tamanho = A->tamanho + B->tamanho;
  
  C->elementos = (int *)malloc(sizeof(int) * C->tamanho);

  for (i = 0; i < A->tamanho; i++) {
    C->elementos[i] = A->elementos[i];
  }

  for (int j = 0; i < B->tamanho + A->tamanho; i++) {
    C->elementos[i] = B->elementos[j];
    j++;
  }

  return C;
}
Conjunto *interseccao (Conjunto *A, Conjunto *B) {
  int tamAux, *arrayAux, equalCount = 0;

  //checar qual é maior
  tamAux = (A->tamanho > B->tamanho) ? A->tamanho : B->tamanho;

  //criar array com as posições que serão inseridas
  arrayAux = (int*) malloc(sizeof(int)*tamAux);

  //criar conjunto com a quantidade de elementos que serão inseridos
  for (int i = 0; i < A->tamanho; i++)
  {
    for (int j = 0; j < B->tamanho; j++)
    {
      if (A->elementos[i] == B->elementos[j])
      {
        arrayAux[equalCount++] = A->elementos[i];
        break;
      }
    }
  }

  //criar o conjunto com os tamanhos indicados
  Conjunto *C = (Conjunto*) malloc(sizeof(Conjunto));
  C->tamanho = equalCount;
  C->elementos = (int*) malloc(sizeof(int)*equalCount);
  
  //preencher o array do conjunto criado
  for (int i = 0; i < equalCount; i++)
    C->elementos[i] = arrayAux[i];
  
  return C;
}
void criaConjuntoVazio (Conjunto **A) {
  *A = (Conjunto*) malloc(sizeof(Conjunto));
}
int membro (Conjunto *A, int val) {
  for (int i = 0; i < A->tamanho; i++)
    if (A->elementos[i] == val)
      return 1;
  
  return 0;
}
void imprimir(Conjunto *A) {
  for (int i = 0; i < A->tamanho; i++) {
    printf("%d ", A->elementos[i]);
  }
}

int igual (Conjunto *A, Conjunto *B)
{
  if (A->tamanho != B->tamanho)
    return 0;

  quicksort(A->elementos, 0, A->tamanho - 1);
  quicksort(B->elementos, 0, B->tamanho - 1);

  for (int i=0; i<A->tamanho; i++)
    if (A->elementos[i] != B->elementos[i])
      return 0;

  return 1;
}

int mediana3 (int *arr, int a,int b, int c) {
  if ((arr[a] >= arr[b] || arr[a] >= arr[c])&&( arr[a] <= arr[b] || arr[a] <= arr[c]))
    return a;
  if ((arr[b] >= arr[a] || arr[b] >= arr[c])&&( arr[b] <= arr[a] || arr[b] <= arr[c]))
    return b;
  else
    return c;
}

int partition(int arr[], int left, int right) {
  
  int pivot = mediana3(arr, left, right, (left+right)/2);

  int i = left - 1;

  for (int j = left; j <= right; j++) {
      if (arr[j] < arr[pivot]) {
          i++;
          int temp = arr[i];
          arr[i] = arr[j];
          arr[j] = temp;
      }
  }

  // The pivot comes to its correct position
  int temp = arr[i + 1];
  arr[i + 1] = arr[pivot];
  arr[pivot] = temp;
  return i + 1;
}

void quicksort(int arr[], int left, int right) {
  if (left < right) {
      // Find the position of pivot
      int pivotFinalRestingPosition = partition(arr, left, right);

      // Recursively call left and right subarray to the pivot
      quicksort(arr, left, pivotFinalRestingPosition - 1);
      quicksort(arr, pivotFinalRestingPosition + 1, right);
  }
}

//-------------//-------------//-------------//-------------//-------------
// main.c

int main() {
  
  printf("hello its working!! :)\n");
  Conjunto *A;// *B;// *C;

  printf("CONJUNTO A\n");
  A = criar(3);

  printf("\nCONJUNTO B\n"); 
  //B = criar(3);

  //C = interseccao(A, B);

  //printf("\nCONJUNTO C: ");
  //imprimir(C);

  return 0;
}