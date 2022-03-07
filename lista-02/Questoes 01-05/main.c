#include "lista.c"

int main(void) {
  // Criando listas e itens para as demonstrações
  Lista *l = criar_lista();
  Lista *l2 = criar_lista();
  Item i1={3}, i2={7}, i3={5}, i4={13};

  adicionar_item_ao_final(l, i1);
  adicionar_item_ao_final(l, i2);

  adicionar_item_ao_final(l2, i3);
  adicionar_item_ao_final(l2, i4);

  // Concatenando duas listas
  Lista *l3 = concatenar_listas(*l, *l2);
  printf("Lista concatenada: "); exibir_lista(*l3);
  printf("\n");

  // Removendo os primeiros 4 elementos
  remover_primeiros_elementos(l3, 4);
  printf("Tamanho da lista depois de remover 4 elementos: %d\n", lista_tamanho(*l3));

  // Obtendo o maior elemento
  int p;
  maior_elemento(l2, &i1, &p);
  printf("Valor do maior elemento da lista 2: %d\n", i1.valor);
  printf("Posicao do maior elemento da lista 2: %d\n", p);

  // Obtendo a quantidade de pares
  printf("Quantidade de pares na lista 1: %d\n", pares_quantidade(*l));

  // Obtendo a média da lista
  printf("Media dos valores da lista 1: %d\n", media(*l));
  return 0;
}