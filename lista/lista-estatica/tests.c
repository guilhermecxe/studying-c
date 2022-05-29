#include "lista.c"
#include <stdlib.h>

int errors_count = 0;

void test(int condition){
    if(!condition)
        errors_count++;
    printf("%s\n", condition ? "Success" : "Error");
}

void test_inicializar_lista(){
    printf("test_inicializar_lista\n");

    Lista *lista = inicializar_lista();

    test(lista->tamanho == 0);
    
    printf("\n");
}

void test_lista_vazia(){
    printf("test_lista_vazia\n");

    Lista *lista = inicializar_lista();

    Valor v = {2};
    Elemento e;
    e.valor = v;

    // Teste após inserir um elemento
    inserir(lista, e, 0);
    test(lista_vazia(*lista) == 0);

    // Teste após remover um elemento
    remover(lista, 1);
    test(lista_vazia(*lista) == 1);

    printf("\n");
}

void test_inserir(){
    printf("test_inserir\n");

    Lista *lista = inicializar_lista();
    
    Valor v1 = {1}, v2 = {2}, v3 = {3};
    Elemento e1, e2, e3;
    e1.valor = v1;
    e2.valor = v2;
    e3.valor = v3;

    // Teste inserindo em uma lista vazia (no início)
    inserir(lista, e1, 0);
    test(lista->elementos[0].valor.numero == e1.valor.numero);
    test(lista->tamanho == 1);

    // Teste inserindo em uma lista com elementos (no final)
    inserir(lista, e2, 1);
    test(lista->elementos[0].valor.numero == e1.valor.numero);
    test(lista->elementos[1].valor.numero == e2.valor.numero);
    test(lista->tamanho == 2);

    // Teste inserindo em uma lista com elementos (no meio)
    inserir(lista, e3, 1);
    test(lista->elementos[0].valor.numero == e1.valor.numero);
    test(lista->elementos[1].valor.numero == e3.valor.numero);
    test(lista->elementos[2].valor.numero == e2.valor.numero);
    test(lista->tamanho == 3);

    printf("\n");
}

void test_remover(){
    printf("test_remover\n");

    Lista *lista = inicializar_lista();
    
    Valor v1 = {1}, v2 = {2}, v3 = {3};
    Elemento e1, e2, e3;
    e1.valor = v1;
    e2.valor = v2;
    e3.valor = v3;

    // Teste removendo de uma lista com mais de 1 elemento (no meio)
    inserir(lista, e3, 0);
    inserir(lista, e2, 0);
    inserir(lista, e1, 0);
    remover(lista, 1);
    test(lista->elementos[0].valor.numero == e1.valor.numero);
    test(lista->elementos[1].valor.numero == e3.valor.numero);
    test(lista->tamanho == 2);

    // Teste removendo de uma lista com mais de 1 elemento (no final)
    remover(lista, 1);
    test(lista->elementos[0].valor.numero == e1.valor.numero);
    test(lista->tamanho == 1);

    // Teste removendo de uma lista com mais de 1 elemento (no inicio)
    remover(lista, 0);
    test(lista->tamanho == 0);

    printf("\n");
}

void main(){
    test_inicializar_lista();
    test_lista_vazia();
    test_inserir();
    test_remover();

    printf("Errors count: %d\n", errors_count);
}