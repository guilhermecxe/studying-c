#include <stdio.h>
#include <stdlib.h>
#include "list.h"

Lista* inicializar_lista(){
    Lista *lista = (Lista*) malloc(sizeof(Lista));
    lista->tamanho = 0;
    return lista;
}

int lista_vazia(Lista lista){
  return lista.tamanho == 0;
}

void exibir_lista(Lista *lista){
    for(int i=0; i<lista->tamanho; i++)
        printf("%d ", lista->elementos[i]);
}

void inserir(Lista *lista, Elemento elemento, int posicao){
    if(lista->tamanho >= MAXTAM)
        return;

    int i;
    for(i=lista->tamanho; i>posicao; i--)
        lista->elementos[i] = lista->elementos[i-1];

    lista->elementos[i] = elemento;
    lista->tamanho++;
}

void remover(Lista *lista, int posicao){
    if(lista_vazia(*lista))
        return;

    for(int i=posicao; i<lista->tamanho; i++)
        lista->elementos[i] = lista->elementos[i+1];
    
    lista->tamanho--;
}