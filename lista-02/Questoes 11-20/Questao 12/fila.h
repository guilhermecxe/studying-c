typedef struct TipoItem TipoItem;
typedef struct TipoCelula TipoCelula;
typedef struct TipoCelula *TipoApontador;
typedef struct TipoFila TipoFila;

void criar_fila(TipoFila *fila);

int fila_vazia(TipoFila *fila);

void enfileirar(TipoFila *fila, TipoItem item);

void exibir_fila(TipoFila *fila);

void dividir_fila(TipoFila *f1, TipoFila *f2, TipoFila *f3, int p);