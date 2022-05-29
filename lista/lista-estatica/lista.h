#define MAXTAM 1000

typedef struct Valor{
    int numero;
} Valor;

typedef struct Elemento{
    Valor valor;
} Elemento;

typedef struct Lista{
    Elemento elementos[MAXTAM];
    int tamanho;
} Lista;