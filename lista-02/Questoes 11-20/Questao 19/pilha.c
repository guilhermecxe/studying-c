#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void criar_pilha(Pilha *p){
    p->topo = NULL;
}

int pilha_vazia(Pilha p){
    return p.topo == NULL;
}

void empilhar(Pilha *p, char caracter){
    Apontador celula = (Apontador) malloc(sizeof(Celula));
    celula->caracter = caracter;
    celula->prox = p->topo;
    p->topo = celula;
}

char desempilhar(Pilha *p){
    if(pilha_vazia(*p))
        return NULL;

    Apontador aux = p->topo;
    char caractere = aux->caracter;
    p->topo = p->topo->prox;
    free(aux);

    return caractere;
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

int pilha_tamanho(Pilha p){
    Apontador aux = p.topo;
    int contador=0;
    while(aux != NULL){
        contador++;
        aux = aux->prox;
    }
    return contador;
}

void exibir_pilha(Pilha p){
    Apontador aux = p.topo;
    while(aux != NULL){
        printf("%c\n", aux->caracter);
        aux = aux->prox;
    }
    printf("\n");
}

void inverter(Pilha *p){
    int tamanho = pilha_tamanho(*p);
    char valores[tamanho];

    for(int i=0; i<tamanho; i++)
        valores[i] = desempilhar(p);

    for(int i=0; i<tamanho; i++)
        empilhar(p, valores[i]);
}

Pilha* copiar_pilha(Pilha *p){
    Pilha *copia = (Pilha*) malloc(sizeof(Pilha));
    criar_pilha(copia);

    int tamanho = pilha_tamanho(*p);
    char valores[tamanho];

    for(int i=0; i<tamanho; i++)
        valores[i] = desempilhar(p);

    for(int i=tamanho; i>0; i--){
        empilhar(p, valores[i-1]);
        empilhar(copia, valores[i-1]);
    }

    return copia;
}

int pilhas_iguais(Pilha *p1, Pilha *p2){
    if(p1 == p2)
        return 1;

    int tamanho_p1 = pilha_tamanho(*p1), tamanho_p2 = pilha_tamanho(*p2);
    if(tamanho_p1 != tamanho_p2)
        return 0;
    char valores_p1[tamanho_p1], valores_p2[tamanho_p2];

    int i;
    int iguais = 1;
    for(i=0; i<tamanho_p1; i++){
        valores_p1[i] = desempilhar(p1);
        valores_p2[i] = desempilhar(p2);
        if(valores_p1[i] != valores_p2[i]){
            iguais = 0;
            break;
        }
    }

    for(int j=i; j>0; j--){
        empilhar(p1, valores_p1[j-1]);
        empilhar(p2, valores_p2[j-1]);
    }

    return iguais;
}

int palindromo(Pilha *p){
    Pilha *copia = copiar_pilha(p);
    inverter(copia);
    int e_palindromo = pilhas_iguais(p, copia);
    liberar_pilha(copia);
    return e_palindromo;
}
