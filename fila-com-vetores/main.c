#include "fila.c"
#include <stdio.h>

int main(void) {
  // Criando uma fila
  TipoFila f;
  criar_fila(&f);

  // Criando items
  TipoItem i1 = {1};
  TipoItem i2 = {2};
  TipoItem i3 = {10};
  TipoItem i4 = {4};

  // Adicionando os items à fila
  enfileirar(&f, i1);
  enfileirar(&f, i2);
  enfileirar(&f, i3);
  enfileirar(&f, i4);
  exibir_fila(f);

  // Desinfileirando um item da fila
  desinfileirar(&f, &i2);
  exibir_fila(f);
  
  return 0;
}