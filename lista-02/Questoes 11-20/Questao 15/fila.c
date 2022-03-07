#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void criar_fila(Fila *f){
    f->primeiro = NULL;
    f->ultimo = f->primeiro;
}

int fila_vazia(Fila f){
    return f.primeiro == NULL;
}

void enfileirar(Fila *f, int valor){
    if(fila_vazia(*f)){
        f->ultimo = (Apontador) malloc(sizeof(Celula));
        f->ultimo->valor = valor;
        f->ultimo->prox = NULL;
        f->primeiro = f->ultimo;
    }
    else{
        f->ultimo->prox = (Apontador) malloc(sizeof(Celula));
        f->ultimo->prox->valor = valor;
        f->ultimo->prox->prox = NULL;
        f->ultimo = f->ultimo->prox;
    }
}

void desinfileirar(Fila *f, int *valor){
    if(fila_vazia(*f))
        return;
    else {
        *valor = f->primeiro->valor;
        Apontador aux = f->primeiro;
        f->primeiro = f->primeiro->prox;
        free(aux);
        if(fila_vazia(*f))
            f->ultimo = NULL;
    }
}

void liberar_fila(Fila *f){
    Apontador aux1 = f->primeiro, aux2;
    while(aux1 != NULL){
        aux2 = aux1->prox;
        free(aux1);
        aux1 = aux2;
    }
}

void exibir_fila(Fila f){
    Apontador aux = f.primeiro;
    while(aux != NULL){
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
}

void mover(Fila *f1, Fila *f2){
    // Função que move um elemento da primeira fila para a segunda fila
    int aux;
    desinfileirar(f1, &aux);
    enfileirar(f2, aux);
}

void juntar_filas(Fila *f1, Fila *f2, Fila *f3){
    int aux;

    while(!fila_vazia(*f1) | !fila_vazia(*f2)){
        if(fila_vazia(*f1) & !fila_vazia(*f2))
            mover(f2, f3);
        else if(!fila_vazia(*f1) & fila_vazia(*f2))
            mover(f1, f3);
        else if(f1->primeiro->valor < f2->primeiro->valor)
            mover(f1, f3);
        else
            mover(f2, f3);
    }
}