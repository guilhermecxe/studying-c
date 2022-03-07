typedef struct lista Lista;
typedef struct item Item;

// Funções dos exercícios
Lista* concatenar_listas(Lista l1, Lista l2); // Questão 1
int remover_primeiros_elementos(Lista *l, int n); // Questão 2
int maior_elemento(Lista *l, Item *i, int *posicao); // Questão 3
int pares_quantidade(Lista l); // Questão 4
int media(Lista l); // Questão 5

// Funções auxiliares
Lista* criar_lista();
int lista_tamanho(Lista l);
int lista_vazia(Lista l);
int adicionar_item_ao_final(Lista *l, Item i);
int remover_primeiro_elemento(Lista *l);
void exibir_lista(Lista l);