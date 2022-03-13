#include <stdio.h>
#include <time.h>

#define MAXTAM 100

typedef struct Registro{
    int valor;
} Registro;

typedef struct Tabela{
    Registro registros[MAXTAM + 1];
    int n;
} Tabela;

int criar_tabela(Tabela *t){
    t->n = 0;
}

void inserir_valor(Tabela *t, int valor){
    Registro r = {valor};
    t->registros[t->n] = r;
    t->n++;
}

void exibir_tabela(Tabela t){
    for(int i=0; i<t.n; i++)
        printf("%d\t-\t%d\n", i, t.registros[i]);
}

int busca_sequencial(Tabela t, int valor){
    // Começando a busca pelo final da tabela
    int i = t.n;
    
    do {
        i--;
    } while ((t.registros[i].valor != valor) & (i >= 0));
    
    return i;
}

int main(){
    Tabela tabela;
    criar_tabela(&tabela);

    srand(time(NULL));

    int valor;
    for(int i=0; i<5; i++){
        valor = (rand() % (10 - 1)) + 1;
        inserir_valor(&tabela, valor);
    }

    printf("Exibindo os valores criados (posicao, valor):\n");
    exibir_tabela(tabela);

    int posicao;
    for(int i=0; i<5; i++){
        valor = (rand() % (10 - 1)) + 1;
        posicao = busca_sequencial(tabela, valor);
        if(posicao == -1)
            printf("O valor %d nao foi encontrado\n", valor);
        else
            printf("O valor %d foi encontrado na posicao: %d\n", valor, posicao);
    }

    return 0;
}