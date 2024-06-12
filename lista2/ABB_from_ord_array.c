#include <stdio.h>
#include <stdlib.h>

typedef struct no {
  int dado;
  struct no *esq;
  struct no *dir;
} no;

no* ABB_from_ord_array (int arr[], int start, int end) {
  if (start > end)
    return NULL;

  int mid = (start + end) / 2;
  no* raiz = (no*) malloc(sizeof(no));
  raiz->dado = arr[mid];

  raiz->esq = ABB_from_ord_array(arr, start, mid - 1);
  raiz->dir = ABB_from_ord_array(arr, mid+1, end);

  return raiz;
}

void Pre_Ord (no *raiz) {
  if (raiz!= NULL) {
    printf("%d\n", raiz->dado);
    Pre_Ord(raiz->esq);
    Pre_Ord(raiz->dir);
  }
}

int main(void) {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  no* raiz = ABB_from_ord_array(arr, 0, (sizeof(arr)/sizeof(arr[0])) - 1);

  Pre_Ord(raiz);
  return 0;
}
