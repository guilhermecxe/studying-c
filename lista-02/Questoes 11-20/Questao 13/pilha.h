typedef struct Celula* Apontador;

typedef struct Processo{
    int id;
    int espera;
} Processo;

typedef struct Celula{
    Processo processo;
    Apontador prox;
} Celula;

typedef struct Fila{
    Apontador topo;
} Fila;


void criar_fila(Fila *f);
void liberar_fila(Fila *f);
int fila_vazia(Fila f);
int fila_tamanho(Fila f);
void empilhar_processo(Fila *f, Processo p);
void exibir_processos(Fila *f);
Processo desempilhar(Fila *f);
Processo remover_maior_espera(Fila *f);