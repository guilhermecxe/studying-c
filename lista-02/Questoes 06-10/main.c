#include "lista.c"

int main(){
  // Criando listas e um vetor para as demonstrações
  TipoLista lista;
  TipoLista lista2;
  TipoLista lista3;
  int vetor[] = {1, 2, 5, 6, 2};

  criar_lista(&lista, vetor, 5);
  printf("Lista criada a partir de um vetor: "); exibir_items(lista);

  concatenar(lista, lista, &lista2);
  printf("Concatenacao da lista 1 duas vezes: "); exibir_items(lista2);

  remover_repetidos(&lista2);
  printf("A lista 2 depois de remover elementos repetidos: "); exibir_items(lista2);

  intercalar(&lista, &lista, &lista3);
  printf("A intercalacao da lista 1 duas vezes: "); exibir_items(lista3);

  printf("A soma da lista 3: %d\n", somar(lista3));

  return 0;
}