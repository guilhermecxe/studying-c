#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void criar_pilha(Pilha *p){
    p->topo = NULL;
}

int pilha_vazia(Pilha p){
    return p.topo == NULL;
}

void empilhar(Pilha *p, int valor){
    Apontador celula = (Apontador) malloc(sizeof(Celula));
    celula->prox = p->topo;
    celula->valor = valor;
    p->topo = celula;
}

int desempilhar(Pilha *p){
    if(pilha_vazia(*p)){
        printf("Pilha vazia\n\n");
        return NULL;
    }
    Apontador aux = p->topo;
    int valor = aux->valor;
    p->topo = p->topo->prox;
    free(aux);
    return valor;
}

void liberar_pilha(Pilha *p){
    Apontador aux1 = p->topo;
    Apontador aux2;
    while(aux1 != NULL){
        aux2 = aux1->prox;
        free(aux1);
        aux1 = aux2;
    }
}

void exibir_pilha(Pilha p){
    Apontador aux = p.topo;
    while(aux != NULL){
        printf("%d\n", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
}

int pilha_tamanho(Pilha p){
    Apontador aux = p.topo;
    int contador=0;
    while(aux != NULL){
        contador++;
        aux = aux->prox;
    }
    return contador;
}

void inverter(Pilha *p){
    int tamanho = pilha_tamanho(*p);
    int valores[tamanho];

    for(int i=0; i<tamanho; i++)
        valores[i] = desempilhar(p);

    for(int i=0; i<tamanho; i++)
        empilhar(p, valores[i]);
}

void descrever(Pilha *p, int *menor, int *maior, int *media){
    int tamanho = pilha_tamanho(*p);
    int valores[tamanho];

    *menor = *maior = *media = valores[0] = desempilhar(p);

    for(int i=1; i<tamanho; i++){
        valores[i] = desempilhar(p);
        if(valores[i] < *menor)
            *menor = valores[i];
        if(valores[i] > *maior)
            *maior = valores[i];
        *media += valores[i];
    }
    *media = *media / tamanho;

    for(int i=tamanho; i>0; i--)
        empilhar(p, valores[i-1]);
}