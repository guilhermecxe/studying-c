#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void criar_lista_vazia(TipoLista *lista) {
  lista->primeiro = (TipoApontador) malloc(sizeof(TipoCelula));
  lista->ultimo = lista->primeiro;
  lista->primeiro->proximo = NULL;
  lista->tamanho = 0;
}

void inserir(TipoItem x, TipoLista *lista){
  lista->ultimo->proximo = (TipoApontador) malloc(sizeof(TipoCelula));
  lista->ultimo = lista->ultimo->proximo;
  lista->ultimo->item = x;
  lista->ultimo->proximo = NULL;
  lista->tamanho++;
}

void criar_lista(TipoLista *lista, int vetor[], int n){
  criar_lista_vazia(lista);
  for(int i=0; i<n; i++){
    int valor = vetor[i];
    TipoItem item = {valor};
    inserir(item, lista);
  }
}

void exibir_items(TipoLista lista){
  TipoApontador celula = lista.primeiro->proximo;
  for(int i=0; i<lista.tamanho; i++){
    printf("%d ", celula->item.chave);
    celula = celula->proximo;
  }
  printf("\n");
}

void concatenar(TipoLista lista1, TipoLista lista2, TipoLista *lista3){
  criar_lista_vazia(lista3);

  TipoApontador celula = lista1.primeiro->proximo;
  for(int i=0; i<lista1.tamanho; i++){
    inserir(celula->item, lista3);
    celula = celula->proximo;
  }

  celula = lista2.primeiro->proximo;
  for(int i=0; i<lista2.tamanho; i++){
    inserir(celula->item, lista3);
    celula = celula->proximo;
  }
}

void remover(TipoLista *lista, int posicao){
  if(posicao >= lista->tamanho)
    return;
  
  TipoApontador celula = lista->primeiro;
  for(int i=0; i<posicao; i++)
    celula = celula->proximo;

  celula->proximo = celula->proximo->proximo;
  lista->tamanho--;
}

void remover_repetidos(TipoLista *lista){
  TipoApontador celula1 = lista->primeiro->proximo;
  for(int i=0; i<lista->tamanho; i++){
    TipoApontador celula2 = celula1->proximo;
    for(int j=i+1; j<lista->tamanho; j++){
      if(celula1->item.chave == celula2->item.chave){
        remover(lista, j);
        j--;
      }
      celula2 = celula2->proximo;
    }
    celula1 = celula1->proximo;
  }
}

void intercalar(TipoLista *lista1, TipoLista *lista2, TipoLista *lista3){
  // Assumindo que as listas a serem intercaladas devem ter o mesmo tamanho
  if(lista1->tamanho != lista2->tamanho)
    return;

  criar_lista_vazia(lista3);
  TipoApontador celula1 = lista1->primeiro->proximo;
  TipoApontador celula2 = lista2->primeiro->proximo;
  for(int i=0; i<lista1->tamanho; i++){
    inserir(celula1->item, lista3);
    inserir(celula2->item, lista3);
    celula1 = celula1->proximo;
    celula2 = celula2->proximo;
  }
}

int somar(TipoLista lista){
  int soma = 0;
  TipoApontador celula = lista.primeiro->proximo;
  for(int i=0; i<lista.tamanho; i++){
    soma += celula->item.chave;
    celula = celula->proximo;
  }
  return soma;
}