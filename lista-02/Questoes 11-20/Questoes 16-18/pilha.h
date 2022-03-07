#include <stdio.h>
#include <stdlib.h>

typedef struct Celula* Apontador;

typedef struct Celula{
    int valor;
    Apontador prox;
} Celula;

typedef struct Pilha{
    Apontador topo;
} Pilha;

// Funções das questões
int desempilhar(Pilha *p); // Questão 16
void descrever(Pilha *p, int *menor, int *maior, int *media); // Questão 17
void inverter(Pilha *p); // Questão 18

// Funções auxiliares
void criar_pilha(Pilha *p);
int pilha_vazia(Pilha p);
void empilhar(Pilha *p, int valor);
void liberar_pilha(Pilha *p);
void exibir_pilha(Pilha p);
int pilha_tamanho(Pilha p);
