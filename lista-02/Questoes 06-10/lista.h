#ifndef _LISTA_H_INCLUDED
#define _LISTA_H_INCLUDED
#endif

typedef int TipoChave;
typedef struct{
    TipoChave chave;
} TipoItem;
typedef struct TipoCelula *TipoApontador;
typedef struct TipoCelula{
    TipoItem item;
    TipoApontador proximo;
} TipoCelula;
typedef struct TipoLista{
  TipoApontador primeiro, ultimo;
  int tamanho;
} TipoLista;

// Função referente à questão 06:
void criar_lista(TipoLista *lista, int vetor[], int n);
// Função referente à questão 07:
void concatenar(TipoLista lista1, TipoLista lista2, TipoLista *lista3);
// Função referente à questão 08:
void remover_repetidos(TipoLista *lista);
// Função referente à questão 09:
void intercalar(TipoLista *lista1, TipoLista *lista2, TipoLista *lista3);
// Função referente à questão 10:
int somar(TipoLista lista);

// Funções auxiliares:
void criar_lista_vazia(TipoLista *lista);
void inserir(TipoItem x, TipoLista *Lista);
void exibir_items(TipoLista lista);
void remover(TipoLista *lista, int posicao);