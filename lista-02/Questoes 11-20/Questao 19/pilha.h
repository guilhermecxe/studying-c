typedef struct Celula* Apontador;

typedef struct Celula{
    char caracter;
    Apontador prox;
} Celula;

typedef struct Pilha{
    Apontador topo;
} Pilha;

void criar_pilha(Pilha *p);
int pilha_vazia(Pilha p);
void empilhar(Pilha *p, char caracter);
char desempilhar(Pilha *p);
void liberar_pilha(Pilha *p);
int pilha_tamanho(Pilha p);
void exibir_pilha(Pilha p);
void inverter(Pilha *p);
Pilha* copiar_pilha(Pilha *p);
int pilhas_iguais(Pilha *p1, Pilha *p2);
int palindromo(Pilha *p);
