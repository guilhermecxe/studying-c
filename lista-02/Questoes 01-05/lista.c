#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

#define MAXTAM 1000

struct item{
  int valor;
};

struct lista{
  Item items[MAXTAM];
  int primeiro, ultimo;
};

Lista* criar_lista(){
  Lista *l = (Lista*) malloc(sizeof(Lista));
  l->primeiro = l->ultimo = 0;
  return l;
}

int lista_tamanho(Lista l){
  return l.ultimo - l.primeiro;
}

int lista_vazia(Lista l){
  return l.primeiro == l.ultimo;
}

int adicionar_item_ao_final(Lista *l, Item i){
  if(lista_tamanho(*l) >= MAXTAM)
    return 0;
  l->items[l->ultimo] = i;
  l->ultimo++;
  return 1;
}

Lista* concatenar_listas(Lista l1, Lista l2){
  int l1_tamanho = lista_tamanho(l1);
  int l2_tamanho = lista_tamanho(l2);
  if(l1_tamanho + l2_tamanho >= MAXTAM)
    return NULL;

  Lista *l3 = criar_lista();
  for(int i=0; i<l1_tamanho; i++)
    adicionar_item_ao_final(l3, l1.items[i]);
  for(int i=0; i<l2_tamanho; i++)
    adicionar_item_ao_final(l3, l2.items[i]);
  return l3;
}

int remover_primeiro_elemento(Lista *l){
  if(lista_vazia(*l))
    return 0;
  l->primeiro++;
  return 1;
}

int remover_primeiros_elementos(Lista *l, int n){
  int l_tamanho = lista_tamanho(*l);
  if(l_tamanho < n){
    printf("Não foi possível remover os %d primeiros elementos pois a lista contém %d elementos.\n", n, l_tamanho);
    return 0;
  }
  for(int i=0; i<n; i++)
    remover_primeiro_elemento(l);
  printf("%d primeiros elementos removidos.\n", n);
  return 1;
}

int maior_elemento(Lista *l, Item *i, int *posicao){
  if(lista_vazia(*l))
    return 0; // Não foi possível
  Item maior_elemento = l->items[l->primeiro];
  int maior_posicao = l->primeiro;

  for(int i=l->primeiro+1; i<l->ultimo; i++){
    if(l->items[i].valor > maior_elemento.valor){
      maior_elemento = l->items[i];
      maior_posicao = i;
    }
  }
  *i = maior_elemento;
  *posicao = maior_posicao;
  return 1; // Foi possível
}

int pares_quantidade(Lista l){
  int contagem = 0;
  for(int i=l.primeiro; i<l.ultimo; i++){
    if(l.items[i].valor % 2 == 0)
      contagem++;
  }
  return contagem;
}

int media(Lista l){
  if(lista_vazia(l))
    return 0;
  int soma = 0;
  for(int i=l.primeiro; i<l.ultimo; i++){
    soma += l.items[i].valor;
  }
  return soma/lista_tamanho(l);
}

void exibir_lista(Lista l){
    for(int i=l.primeiro; i<l.ultimo; i++)
        printf("%d ", l.items[i]);
}