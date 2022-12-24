#include "list.c"
#include <stdlib.h>

int errors_count = 0;

void test(int condition){
    if(!condition)
        errors_count++;
    printf("%s\n", condition ? "Success" : "Error");
}

void test_inicializar_lista(){
    printf("test_inicializar_lista\n");

    Lista lista;
    inicializar_lista(&lista);

    test(lista.primeiro == NULL);
    test(lista.ultimo == NULL);
    test(lista.tamanho == 0);
    
    printf("\n");
}

void test_inicializar_lista_alocada(){
    printf("test_inicializar_lista_alocada\n");

    Lista *lista = malloc(sizeof(Lista));
    inicializar_lista(lista);

    test(lista->primeiro == NULL);
    test(lista->ultimo == NULL);
    test(lista->tamanho == 0);

    free(lista);
    printf("\n");
}

void test_lista_vazia(){
    printf("test_inicializar_lista\n");

    Lista lista;
    inicializar_lista(&lista);

    Valor v = {1};
    Elemento e;
    e.valor = v;

    // Teste após inserir um elemento
    inserir_no_inicio(&lista, &e);
    test(lista_vazia(lista) == 0);

    // Teste após remover um elemento
    remover_do_final(&lista);
    test(lista_vazia(lista) == 1);

    printf("\n");
}

void test_inserir_no_inicio(){
    printf("test_inserir_no_inicio\n");

    Lista lista;
    inicializar_lista(&lista);
    
    Valor v1 = {1}, v2 = {2};
    Elemento e1, e2;
    e1.valor = v1;
    e2.valor = v2;

    // Teste inserindo em uma lista vazia
    inserir_no_inicio(&lista, &e1);
    test(lista.primeiro->valor.numero == v1.numero);
    test(lista.ultimo->valor.numero == v1.numero);
    test(lista.primeiro->proximo == NULL);
    test(lista.ultimo->proximo == NULL);
    test(lista.tamanho == 1);

    // Teste inserindo em uma lista com elementos
    inserir_no_inicio(&lista, &e2);;
    test(lista.primeiro->valor.numero == v2.numero);
    test(lista.ultimo->valor.numero == v1.numero);
    test(lista.primeiro->proximo == &e1);
    test(lista.ultimo->proximo == NULL);
    test(lista.tamanho == 2);

    printf("\n");
}

void test_inserir_no_final(){
    printf("test_inserir_no_final\n");

    Lista lista;
    inicializar_lista(&lista);
    
    Valor v1 = {1}, v2 = {2};
    Elemento e1, e2;
    e1.valor = v1;
    e2.valor = v2;

    // Teste inserindo em uma lista vazia
    inserir_no_final(&lista, &e1);
    test(lista.primeiro->valor.numero == v1.numero);
    test(lista.ultimo->valor.numero == v1.numero);
    test(lista.primeiro->proximo == NULL);
    test(lista.ultimo->proximo == NULL);
    test(lista.tamanho == 1);

    // Teste inserindo em uma lista com elementos
    inserir_no_final(&lista, &e2);
    test(lista.primeiro == &e1);
    test(lista.ultimo == &e2);
    test(lista.primeiro->proximo == &e2);
    test(lista.ultimo->proximo == NULL);
    test(lista.tamanho == 2);

    printf("\n");
}

void test_inserir(){
    printf("test_inserir\n");

    Lista lista;
    inicializar_lista(&lista);
    
    Valor v1 = {1}, v2 = {2}, v3 = {3};
    Elemento e1, e2, e3;
    e1.valor = v1;
    e2.valor = v2;
    e3.valor = v3;

    // Teste inserindo em uma lista vazia (no início)
    inserir(&lista, &e1, 0);
    test(lista.primeiro == &e1);
    test(lista.ultimo == &e1);
    test(lista.primeiro->proximo == NULL);
    test(lista.ultimo->proximo == NULL);
    test(lista.tamanho == 1);

    // Teste inserindo em uma lista com elementos (no final)
    inserir(&lista, &e2, 1);
    test(lista.primeiro == &e1);
    test(lista.ultimo == &e2);
    test(lista.primeiro->proximo == &e2);
    test(lista.ultimo->proximo == NULL);
    test(lista.tamanho == 2);

    // Teste inserindo em uma lista com elementos (no meio)
    inserir(&lista, &e3, 1);
    test(lista.primeiro == &e1);
    test(lista.ultimo == &e2);
    test(lista.primeiro->proximo == &e3);
    test(lista.primeiro->proximo->proximo == &e2);
    test(lista.ultimo->proximo == NULL);
    test(lista.tamanho == 3);

    printf("\n");
}

void test_remover_do_inicio(){
    printf("test_remover_do_inicio\n");

    Lista lista;
    inicializar_lista(&lista);
    
    Valor v1 = {1}, v2 = {2};
    Elemento e1, e2;
    e1.valor = v1;
    e2.valor = v2;

    // Teste removendo de uma lista com mais de 1 elemento
    inserir_no_final(&lista, &e1);
    inserir_no_final(&lista, &e2);
    remover_do_inicio(&lista);
    test(lista.primeiro == &e2);
    test(lista.ultimo == &e2);
    test(lista.primeiro->proximo == NULL);
    test(lista.ultimo->proximo == NULL);
    test(lista.tamanho == 1);

    // Removendo de uma lista com 1 elemento
    remover_do_inicio(&lista);
    test(lista_vazia(lista));

    printf("\n");
}

void test_remover_do_final(){
    printf("test_remover_do_final\n");

    Lista lista;
    inicializar_lista(&lista);
    
    Valor v1 = {1}, v2 = {2};
    Elemento e1, e2;
    e1.valor = v1;
    e2.valor = v2;

    // Teste removendo de uma lista com mais de 1 elemento
    inserir_no_final(&lista, &e1);
    inserir_no_final(&lista, &e2);
    remover_do_final(&lista);
    test(lista.primeiro == &e1);
    test(lista.ultimo == &e1);
    test(lista.primeiro->proximo == NULL);
    test(lista.ultimo->proximo == NULL);
    test(lista.tamanho == 1);

    // Removendo de uma lista com 1 elemento
    remover_do_final(&lista);
    test(lista.primeiro == NULL);
    test(lista.ultimo == NULL);
    test(lista.tamanho == 0);

    printf("\n");
}

void test_remover(){
    printf("test_remover\n");

    Lista lista;
    inicializar_lista(&lista);
    
    Valor v1 = {1}, v2 = {2}, v3 = {3};
    Elemento e1, e2, e3;
    e1.valor = v1;
    e2.valor = v2;
    e3.valor = v3;

    // Teste removendo de uma lista com mais de 1 elemento (no meio)
    inserir_no_final(&lista, &e1);
    inserir_no_final(&lista, &e2);
    inserir_no_final(&lista, &e3);
    remover(&lista, 1);
    test(lista.primeiro == &e1);
    test(lista.ultimo == &e3);
    test(lista.primeiro->proximo == &e3);
    test(lista.ultimo->proximo == NULL);
    test(lista.tamanho == 2);

    // Teste removendo de uma lista com mais de 1 elemento (no final)
    remover(&lista, 1);
    test(lista.primeiro == &e1);
    test(lista.ultimo == &e1);
    test(lista.primeiro->proximo == NULL);
    test(lista.ultimo->proximo == NULL);
    test(lista.tamanho == 1);

    // Teste removendo de uma lista com mais de 1 elemento (no inicio)
    remover(&lista, 0);
    test(lista.primeiro == NULL);
    test(lista.ultimo == NULL);
    test(lista.tamanho == 0);

    printf("\n");
}

void main(){
    test_inicializar_lista();
    test_inicializar_lista_alocada();
    test_lista_vazia();
    test_inserir_no_inicio();
    test_inserir_no_final();
    test_inserir();
    test_remover_do_inicio();
    test_remover_do_final();
    test_remover();

    printf("Errors count: %d\n", errors_count);
}