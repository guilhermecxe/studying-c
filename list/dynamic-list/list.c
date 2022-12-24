#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void inicializar_lista(Lista *lista){
    /* Cria uma lista vazia a partir de um apontador do tipo Lista. */
    lista->primeiro = NULL;
    lista->ultimo = NULL;
    lista->tamanho = 0;
}

int lista_vazia(Lista lista){
    /* A partir de uma instância de Lista, retorna 1 se ela estiver vazia e 0 se não. */
    return lista.tamanho == 0;
}

void inserir_no_inicio(Lista *lista, Elemento *elemento){
    /* A partir de uma referência para uma instância de Lista e de Elemento, adiciona o elemento ao início da lista. */
    elemento->proximo = lista->primeiro;
    lista->primeiro = elemento;
    if(lista_vazia(*lista))
        lista->ultimo = elemento;
    lista->tamanho++;
}

void exibir_lista(Lista lista){
    Apontador aux = lista.primeiro;
    for(int i=0; i<lista.tamanho; i++){
        printf("%d ", aux->valor);
        aux = aux->proximo;
    }
}

void inserir_no_final(Lista *lista, Elemento *elemento){
    if(lista_vazia(*lista))
        inserir_no_inicio(lista, elemento);
    else {
        elemento->proximo = NULL;
        lista->ultimo->proximo = elemento;
        lista->ultimo = elemento;
        lista->tamanho++;
    }
}

void inserir(Lista *lista, Elemento *elemento, int posicao){
    if(posicao < 0 || (posicao > lista->tamanho))
        return;
    if(posicao == 0)
        inserir_no_inicio(lista, elemento);
    else if(posicao == lista->tamanho)
        inserir_no_final(lista, elemento);
    else {
        Apontador aux = lista->primeiro;
        for(int i=0; (i<lista->tamanho & i<posicao-1); i++)
            aux = aux->proximo;
        elemento->proximo = aux->proximo;
        aux->proximo = elemento;
        lista->tamanho++;
    }
}

void remover_do_inicio(Lista *lista){
    if(lista_vazia(*lista))
        return;
    lista->primeiro = lista->primeiro->proximo;
    if(lista->tamanho == 1)
        lista->ultimo = NULL;
    lista->tamanho--;
}

void remover_do_final(Lista *lista){
    if(lista_vazia(*lista))
        return;

    if(lista->tamanho == 1)
        remover_do_inicio(lista);
    else {
        Apontador aux = lista->primeiro;
        for(int i=0; i<lista->tamanho-2; i++)
            aux = aux->proximo;
        aux->proximo = NULL;
        lista->ultimo = aux;
        lista->tamanho--;
    }
}

void remover(Lista *lista, int posicao){
    if(lista_vazia(*lista) | posicao < 0 | posicao > lista->tamanho-1)
        return;
    
    if(posicao == 0)
        remover_do_inicio(lista);
    else if(posicao == lista->tamanho-1)
        remover_do_final(lista);
    else {
        Apontador aux = lista->primeiro;
        for(int i=0; i<posicao-1; i++)
            aux = aux->proximo;
        aux->proximo = aux->proximo->proximo;
        lista->tamanho--;
    }
}