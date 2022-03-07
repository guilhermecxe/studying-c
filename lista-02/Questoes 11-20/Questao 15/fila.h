typedef struct Celula* Apontador;

typedef struct Celula{
    int valor;
    Apontador prox;
} Celula;

typedef struct Fila{
    Apontador primeiro, ultimo;
} Fila;

void criar_fila(Fila *f);
int fila_vazia(Fila f);
void enfileirar(Fila *f, int valor);
void desinfileirar(Fila *f, int *valor);
void liberar_fila(Fila *f);
void exibir_fila(Fila f);
void mover(Fila *f1, Fila *f2);
void juntar_filas(Fila *f1, Fila *f2, Fila *f3);