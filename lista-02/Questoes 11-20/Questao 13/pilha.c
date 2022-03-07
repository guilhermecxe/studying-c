#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void criar_fila(Fila *f){
    f->topo = NULL;
}

void liberar_fila(Fila *f){
    Apontador aux1 = f->topo, aux2;
    while(aux1 != NULL){
        aux2 = aux1->prox;
        free(aux1);
        aux1 = aux2;
    }
}

int fila_vazia(Fila f){
    return f.topo == NULL;
}

int fila_tamanho(Fila f){
    int contador = 0;
    Apontador aux = f.topo;
    while(aux != NULL){
        contador++;
        aux = aux->prox;
    }
    return contador;
}

void empilhar_processo(Fila *f, Processo p){
    Apontador nova_celula = (Apontador) malloc(sizeof(Celula));
    nova_celula->processo = p;
    nova_celula->prox = f->topo;
    f->topo = nova_celula;
}

void exibir_processos(Fila *f){
    Apontador aux = f->topo;
    while(aux != NULL){
        printf("Processo %d (Tempo de espera: %d)\n", aux->processo.id, aux->processo.espera);
        aux = aux->prox;
    }
}

Processo desempilhar(Fila *f){
    if(fila_vazia(*f))
        return;
    Apontador aux = f->topo;
    Processo processo = aux->processo;
    f->topo = f->topo->prox;
    free(aux);
    return processo;
}

Processo remover_maior_espera(Fila *f){
    if(fila_vazia(*f))
        return;
    int tamanho = fila_tamanho(*f);
    int maior_espera, maior_espera_indice;
    Processo valores[tamanho];

    valores[0] = desempilhar(f);
    maior_espera = valores[0].espera;
    maior_espera_indice = 0;

    for(int i=1; i<tamanho; i++){
        valores[i] = desempilhar(f);
        if(valores[i].espera > maior_espera){
            maior_espera = valores[i].espera;
            maior_espera_indice = i;
        }
    }

    for(int i=tamanho-1; i>=0; i--){
        if(i != maior_espera_indice)
            empilhar_processo(f, valores[i]);
    }

    return valores[maior_espera_indice];
}