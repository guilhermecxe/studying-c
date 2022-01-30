#ifndef _FILA_H_INCLUDED
#define _FILA_H_INCLUDED
#endif

typedef int TipoChave;
typedef int TipoApontador;
typedef struct tipoitem TipoItem;
typedef struct tipofila TipoFila;

void criar_fila(TipoFila *fila);

int fila_vazia(TipoFila fila);

int enfileirar(TipoFila *fila, TipoItem item);

int desinfileirar(TipoFila *fila, TipoItem *item);

void exibir_fila(TipoFila fila);