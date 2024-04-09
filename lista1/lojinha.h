//TAD: lista seq.
#define MAX 100    //estimativa do tamanho m�ximo da lista
#define TRUE 1     //define tipo boleano � n�o existe em C
#define FALSE 0
#define boolean int

//------------------------------------------------------

/* Estruturas e tipos empregados (Obs: aqui n�o est� usando 
encapsulamento... definido aqui apenas p/ facilitar a implementa��o */
//-------------------------------------------
//Tipo chave
//typedef int tipo_chave; 

//Tipo registro
typedef struct
{
   int quantidade;
   float valor;

} descricao;

//Tipo elemento (registro + chave)
typedef struct
{
   int chave;
   descricao info;
   
} produto;

//Tipo lista (seq. encadeada)
typedef struct
{
   int nelem; //nro de elementos
   produto A[MAX+1];

}lista;
//-------------------------------------------


//Opera��es
//-------------------------------------------
boolean Vazia(lista *L);
boolean Cheia(lista *L);
void Definir(lista *L);
void Apagar(lista *L);
boolean Inserir_posic(produto x, int p, lista *L);
boolean Inserir_ord(produto x, lista *L);
boolean Buscar(int x, lista *L, int *p);
boolean Buscar_ord(int x, lista *L, int *p);
boolean Busca_bin(int x, lista *L, int *p);
void Remover_posic(int p, lista *L);
boolean Remover_ch(int x, lista *L);
void Impr_prod(produto t);
void Imprimir(lista *L);
int Tamanho(lista *L);
//-------------------------------------------

