#include "pilha.c"

int main(){
    // Aqui está a questão 16, 17 e 18
    Pilha pilha;
    criar_pilha(&pilha);

    // Demonstração de desempilhação com pilha vazia
    desempilhar(&pilha);

    // Empilhando valores
    empilhar(&pilha, 10);
    empilhar(&pilha, 20);
    empilhar(&pilha, 30);
    empilhar(&pilha, 40);
    empilhar(&pilha, 50);
    empilhar(&pilha, 60);
    exibir_pilha(pilha);

    // Demonstração de desempilhação retornado o valor removido
    int valor = desempilhar(&pilha);
    exibir_pilha(pilha);
    printf("Valor removido: %d\n", valor);

    // Demonstração invertendo a pilha
    printf("\nPilha antes de ser invertida:\n");
    exibir_pilha(pilha);
    inverter(&pilha);
    printf("\nPilha depois de ser invertida:\n");
    exibir_pilha(pilha);

    // Usando a função da questão 17 para obter o menor número,
    // o maior número e a média da pilha
    int menor, maior, media;
    descrever(&pilha, &menor, &maior, &media);
    printf("Menor valor da pilha: %d\n", menor);
    printf("Maior valor da pilha: %d\n", maior);
    printf("Media da pilha: %d\n", media);

    liberar_pilha(&pilha);
    return 0;
}