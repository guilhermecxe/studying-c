#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fila.h"

typedef struct TipoItem{
    float valor;
    int prioridade;
};

typedef struct TipoCelula{
    TipoItem item;
    TipoApontador proximo;
} TipoCelula;

typedef struct TipoFila{
    TipoApontador primeiro, ultimo;
} TipoFila;

void criar_fila(TipoFila *fila){
    fila -> primeiro = (TipoApontador) malloc(sizeof(TipoCelula));
    fila -> ultimo = fila -> primeiro;
    fila -> primeiro -> proximo = NULL;
}

int fila_vazia(TipoFila *fila){
    return fila->primeiro == fila->ultimo;
}

void enfileirar(TipoFila *fila, TipoItem item){
    fila->ultimo->proximo = (TipoApontador) malloc(sizeof(TipoCelula));
    fila->ultimo = fila->ultimo->proximo;
    fila->ultimo->item = item;
    fila->ultimo->proximo = NULL;
}

void exibir_fila(TipoFila *fila){
    if(fila_vazia(fila))
        return;
    TipoApontador celula = fila->primeiro->proximo;
    while(celula != NULL){
        printf("%.2f %d\n", celula->item.valor, celula->item.prioridade);
        celula = celula->proximo;
    }
    printf("\n");
}

void dividir_fila(TipoFila *f1, TipoFila *f2, TipoFila *f3, int p){
    if(fila_vazia(f1))
        return;

    criar_fila(f2);
    criar_fila(f3);
    TipoApontador celula = f1->primeiro->proximo;
    while(celula != NULL){
        if(celula->item.prioridade <= p)
            enfileirar(f2, celula->item);
        else
            enfileirar(f3, celula->item);
        celula = celula->proximo;
    }
}