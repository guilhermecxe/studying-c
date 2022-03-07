#include "pilha.c"

int main(){
    Pilha pilha1, pilha2, pilha3;
    criar_pilha(&pilha1);
    criar_pilha(&pilha2);
    criar_pilha(&pilha3);

    // Empilhando a palavra OSSO na pilha 1
    empilhar(&pilha1, 'O');
    empilhar(&pilha1, 'S');
    empilhar(&pilha1, 'S');
    empilhar(&pilha1, 'O');
    exibir_pilha(pilha1);

    // // Empilhando a palavra CEU na pilha 2
    empilhar(&pilha2, 'C');
    empilhar(&pilha2, 'E');
    empilhar(&pilha2, 'U');
    exibir_pilha(pilha2);

    // // Empilhando a palavra ARARA na pilha 2
    empilhar(&pilha3, 'A');
    empilhar(&pilha3, 'R');
    empilhar(&pilha3, 'A');
    empilhar(&pilha3, 'R');
    empilhar(&pilha3, 'A');
    exibir_pilha(pilha3);

    printf("OSSO eh palindromo? %d\n", palindromo(&pilha1));
    printf("CEU eh palindromo? %d\n", palindromo(&pilha2));
    printf("ARARA eh palindromo? %d\n", palindromo(&pilha3));

    liberar_pilha(&pilha1);
    liberar_pilha(&pilha2);
    liberar_pilha(&pilha3);

    return 0;
}