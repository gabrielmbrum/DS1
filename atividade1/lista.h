//TAD: lista seq.
#define MAX 100    //estimativa do tamanho máximo da lista
#define TRUE 1     //define tipo boleano – não existe em C
#define FALSE 0
#define boolean int

//------------------------------------------------------

/* Estruturas e tipos empregados (Obs: aqui não está usando 
encapsulamento... definido aqui apenas p/ facilitar a implementação */
//-------------------------------------------
//Tipo chave
typedef int tipo_chave; 

//Tipo registro
typedef struct
{
   char nome[30];
   int idade;
   float media_final;
   //... (caso tenha mais campos)
} tipo_dado;

//Tipo elemento (registro + chave)
typedef struct
{
   tipo_chave chave;
   tipo_dado info;
} tipo_elem;

//Tipo lista (seq. encadeada)
typedef struct
{
   int nelem; //nro de elementos
   tipo_elem A[MAX+1];
} lista;
//-------------------------------------------


//Operações
//-------------------------------------------
boolean Vazia(lista *L);
boolean Cheia(lista *L);
void Definir(lista *L);
void Apagar(lista *L);
boolean Inserir_posic(tipo_elem x, int p, lista *L);
boolean Inserir_ord(tipo_elem x, lista *L);
boolean Buscar(tipo_chave x, lista *L, int *p);
boolean Buscar_ord(tipo_chave x, lista *L, int *p);
boolean Busca_bin(tipo_chave x, lista *L, int *p);
void Remover_posic(int *p, lista *L);
boolean Remover_ch(tipo_chave x, lista *L);
void Impr_elem(tipo_elem t);
void Imprimir(lista *L);
int Tamanho(lista *L);
//-------------------------------------------

