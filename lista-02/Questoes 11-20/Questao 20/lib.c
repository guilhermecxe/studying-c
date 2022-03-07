#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

void criar_pilha(Pilha *p){
    p->topo = NULL;
}

void criar_fila(Fila *f){
    f->primeiro = f->ultimo = NULL;
}

int fila_vazia(Fila f){
    return f.primeiro == NULL & f.ultimo == NULL;
}

int pilha_vazia(Pilha p){
    return p.topo == NULL;
}

void empilhar(Pilha *p, int valor){
    Apontador nova_celula = (Apontador) malloc(sizeof(Celula));
    nova_celula->valor = valor;
    nova_celula->prox = p->topo;
    p->topo = nova_celula;
}

void enfileirar(Fila *f, int valor){
    Apontador nova_celula = (Apontador) malloc(sizeof(Celula));
    nova_celula->valor = valor;
    nova_celula->prox = NULL;
    if(fila_vazia(*f))
        f->primeiro = f->ultimo = nova_celula;
    else {
        f->ultimo->prox = nova_celula;
        f->ultimo = f->ultimo->prox;
    }
}

int desempilhar(Pilha *p){
    if(pilha_vazia(*p))
        return 0;
    Apontador aux = p->topo;
    int valor = aux->valor;
    p->topo = aux->prox;
    free(aux);
    return valor;
}

int fila_tamanho(Fila f){
    Apontador aux = f.primeiro;
    int contador = 0;
    while(aux != NULL){
        contador++;
        aux = aux->prox;
    }
    return contador;
}

int desenfileirar(Fila *f){
    if(fila_vazia(*f))
        return 0;
    Apontador aux = f->primeiro;
    int valor = aux->valor;
    if(fila_tamanho(*f) == 1)
        f->primeiro = f->ultimo = NULL;
    else
        f->primeiro = aux->prox;
    free(aux);
    return valor;
}

void exibir_pilha(Pilha p){
    Apontador aux = p.topo;
    while(aux != NULL){
        printf("%d\n", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
}

void exibir_fila(Fila *f){
    Apontador aux = f->primeiro;
    while(aux != NULL){
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
}

int par(int valor){
    return valor % 2 == 0;
}

void remover_valores(Fila *pares, Fila *impares){
    Pilha positivos;
    int valor;

    criar_pilha(&positivos);

    while(!fila_vazia(*pares) || !fila_vazia(*impares)){
        if(!fila_vazia(*impares)){
            valor = desenfileirar(impares);
            if(valor > 0)
                empilhar(&positivos, valor);
        }
        if(!fila_vazia(*pares)){
            valor = desenfileirar(pares);
            if(valor > 0)
                empilhar(&positivos, valor);
        }
    }

    printf("Pilha resultante:\n");
    exibir_pilha(positivos);
}

void ler_valores(){
    Fila *pares = (Fila*) malloc(sizeof(Fila));
    Fila *impares = (Fila*) malloc(sizeof(Fila));;
    int valor = -1;

    criar_fila(pares);
    criar_fila(impares);

    while(valor != 0){
        scanf("%d", &valor);
        if(valor == 0)
            break;
        else if(par(valor))
            enfileirar(pares, valor);
        else
            enfileirar(impares, valor);
    }

    remover_valores(pares, impares);
}