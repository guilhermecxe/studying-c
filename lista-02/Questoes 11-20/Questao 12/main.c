#include "fila.c"

int main(){
    float valor;
    int prioridade, p;
    TipoFila f;
    criar_fila(&f);

    // Gerando valores aleatórios para alimentar a fila
    srand(time(NULL));
    for(int i=0; i<20; i++){
        valor = (rand() % (100 - 1)) + 1;
        prioridade = (rand() % (10 - 1)) + 1;
        TipoItem i = {valor, prioridade};
        enfileirar(&f, i);
    }

    printf("Esta eh sua fila inicial (valor, prioridade):\n");
    exibir_fila(&f);

    printf("Escolha um numero para ser o divisor da fila: ");
    scanf("%d", &p);

    TipoFila f2, f3;
    dividir_fila(&f, &f2, &f3, p);

    printf("\nEsta eh a primeira fila resultante:\n");
    exibir_fila(&f2);

    printf("Esta eh a segunda fila resultante:\n");
    exibir_fila(&f3);

    return 0;
}