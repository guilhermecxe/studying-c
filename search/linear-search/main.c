#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXTAM 100000 // 100 mil

typedef struct Registro{
    int valor;
} Registro;

typedef struct Tabela{
    Registro registros[MAXTAM];
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
        printf("%02d - %02d\n", i, t.registros[i]);
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

    // Inserindo 100 mil valores aleatórios que vão de 0 a 1 milhão
    srand(time(NULL));
    int valor;
    for(int i=0; i<MAXTAM; i++){
        valor = (rand() % MAXTAM*10) + 1;
        inserir_valor(&tabela, valor);
    }

    // printf("Exibindo os valores criados (posicao, valor):\n");
    // exibir_tabela(tabela);

    // Buscando valores na lista criada e exibindo o tempo de busca
    int posicao;
    for(int i=0; i<10; i++){
        valor = (rand() % MAXTAM*10) + 1;

        clock_t begin = clock();
        posicao = busca_sequencial(tabela, valor);
        clock_t end = clock();
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

        if(posicao == -1)
            printf("O valor %08d nao foi encontrado\t\t\t", valor);
        else
            printf("O valor %08d foi encontrado na posicao: %06d\t", valor, posicao);
        printf("\t(Tempo de busca: %.3f)\n", time_spent);
    }

    return 0;
}