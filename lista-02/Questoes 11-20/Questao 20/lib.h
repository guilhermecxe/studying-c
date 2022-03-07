typedef struct Celula* Apontador;

typedef struct Celula{
    int valor;
    Apontador prox;
} Celula;

typedef struct Fila{
    Apontador primeiro, ultimo;
} Fila;

typedef struct Pilha{
    Apontador topo;
} Pilha;

void criar_pilha(Pilha *p);
void criar_fila(Fila *f);
int fila_vazia(Fila f);
int pilha_vazia(Pilha p);
void empilhar(Pilha *p, int valor);
void enfileirar(Fila *f, int valor);
int desempilhar(Pilha *p);
int fila_tamanho(Fila f);
int desenfileirar(Fila *f);
void exibir_pilha(Pilha p);
void exibir_fila(Fila *f);
int par(int valor);
void remover_valores(Fila *pares, Fila *impares);
void ler_valores();