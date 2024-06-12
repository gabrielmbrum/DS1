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
float Valor(int key, lista *L);
float ValorCarrinho (lista *Carrinho);
boolean Buscar(int x, lista *L, int *p);
void Remover_posic(int p, lista *L);
void Impr_prod(produto t);
void Imprimir(lista *L);
int Produto_existente (int key, produto *array);
boolean Inserir_produto (int key, int qtd, float valor, lista *L);
boolean Remover_produto (int key, int qtd, lista *L);
boolean AdicionarAoCarrinho (int key, lista *L, lista *Carrinho);
//-------------------------------------------

