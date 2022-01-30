//==============================================================================
// fila.h
//==============================================================================
#include <stdio.h>

#define MAXTAM 1000

typedef int TipoChave;
typedef int TipoApontador;
typedef struct tipoitem TipoItem;
typedef struct tipofila TipoFila;

void criar_fila(TipoFila *fila);

int fila_vazia(TipoFila fila);

int enfileirar(TipoFila *fila, TipoItem item);

int desinfileirar(TipoFila *fila, TipoItem *item);

void exibir_fila(TipoFila fila);

//==============================================================================
// fila.c
//==============================================================================

struct tipoitem{
  TipoChave chave;
};

struct tipofila{
  TipoItem Item[MAXTAM];
  TipoApontador frente;
  TipoApontador tras;
};

void criar_fila(TipoFila *fila){
  fila->frente = 0;
  fila->tras = 0;
}

int fila_vazia(TipoFila fila){
  return fila.tras == 0;
}

int enfileirar(TipoFila *fila, TipoItem item){
  if(fila->tras >= MAXTAM)
    return 0; // Lista cheia
  fila->Item[fila->tras] = item;
  fila->tras++;
  return 1;
}

int desinfileirar(TipoFila *fila, TipoItem *item){
  if(fila_vazia(*fila))
    return 0; // Lista cheia
  *item = fila->Item[fila->frente];
  fila->frente++;
  return 1;
}

void exibir_fila(TipoFila fila){
  for(int i=fila.frente; i<fila.tras; i++)
    printf("%d ", fila.Item[i]);
  printf("\n");
}