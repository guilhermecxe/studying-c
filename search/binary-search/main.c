#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXTAM 100000 // 100 mil

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
        printf("%02d - %02d\n", i, t.registros[i]);
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
    int valor, ultimo_valor=0;

    criar_tabela(&tabela);
    
    srand(time(NULL));

    // Inserindo 100 mil valores aleatórios que são sempre maiores que o anterior,
    // então está sempre ordenado
    for(int i=0; tabela.n < MAXTAM; i++){
        valor = (rand() % 10) + ultimo_valor+1;
        if (valor > ultimo_valor){
            inserir_valor(&tabela, valor);
            ultimo_valor = valor;
        }
    }

    // printf("Exibindo os valores criados (posicao, valor):\n");
    // exibir_tabela(tabela);

    // Buscando valores na lista criada e exibindo o tempo de busca
    int posicao;
    for(int i=0; i<10; i++){
        valor = (rand() % (MAXTAM*10));
        
        clock_t begin = clock();
        posicao = busca_binaria(tabela, valor);
        clock_t end = clock();
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        
        if(posicao == -1)
            printf("O valor %07d nao foi encontrado\t\t\t", valor);
        else
            printf("O valor %07d foi encontrado na posicao: %06d\t", valor, posicao);
        printf("(Tempo de busca: %.3f)\n", time_spent);
    }

    return 0;
}