// conjunto.h
// Implementação da struct

typedef struct conjunto {
  
  int *elementos;
  int tamanho;

} Conjunto;

// Função Criar: cria uma struct do tipo Conjunto e retorna ela
Conjunto *criar(int tamanho);

// Função União: junta os elementos do conjunto A e B e retorna o conjunto união
Conjunto *uniao(Conjunto *A, Conjunto *B);


// Função Interseçõa: junta os elementos iguais do conjunto A e B no conjunto C
Conjunto *interseccao (Conjunto *A, Conjunto *B);

// Imprime os elementos do conjunto
void imprimir(Conjunto *A);

// Quicksort functions
int mediana3 (int *arr, int a,int b, int c);
int partition(int arr[], int left, int right);
void quicksort(int arr[], int left, int right);

// Verifica se são iguais os conjuntos e retorna trues or false
int igual (Conjunto *A, Conjunto *B);
