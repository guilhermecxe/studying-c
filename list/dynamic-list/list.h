typedef struct Elemento* Apontador;

typedef struct Valor{
    int numero;
} Valor;

typedef struct Elemento{
    Valor valor;
    Apontador proximo;
} Elemento;

typedef struct Lista{
    Apontador primeiro, ultimo;
    int tamanho;
} Lista;

void inicializar_lista(Lista *lista);

int lista_vazia(Lista lista);

void inserir_no_inicio(Lista *lista, Elemento *elemento);