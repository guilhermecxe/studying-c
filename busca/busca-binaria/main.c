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

int busca_binaria(Tabela t, int valor){
    int inicio, fim, meio;
    inicio = 0;
    fim = t.n-1;
    meio = (fim+inicio)/2;
    
    while(t.registros[meio].valor != valor){
        if((fim - inicio) == 1){
            meio = -1;
            break;
        }
        if(t.registros[meio].valor > valor)
            fim = meio;
        if(t.registros[meio].valor < valor)
            inicio = meio;
        meio = (fim+inicio)/2;
    }

    return meio;
}

int main(){
    Tabela tabela;
    criar_tabela(&tabela);

    srand(time(NULL));

    int valor, ultimo_valor;
    for(int i=0; tabela.n < 5 ; i++){
        valor = (rand() % (2+i - 1)) + 1;
        if (valor > ultimo_valor){
            inserir_valor(&tabela, valor);
            ultimo_valor = valor;
        }
    }

    printf("Exibindo os valores criados (posicao, valor):\n");
    exibir_tabela(tabela);

    int posicao;
    for(int i=0; i<5; i++){
        valor = (rand() % (3+i - 1)) + 1;
        
        clock_t begin = clock();
        posicao = busca_binaria(tabela, valor);
        clock_t end = clock();
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        
        if(posicao == -1)
            printf("O valor %d nao foi encontrado", valor);
        else
            printf("O valor %d foi encontrado na posicao: %d", valor, posicao);
        printf("\t(Tempo de busca: %f)\n", time_spent);
    }

    return 0;
}