#include "fila.c"

int main(){
    Fila f1, f2, f3;
    criar_fila(&f1);
    criar_fila(&f2);
    criar_fila(&f3);

    // Enfileirando apenas na fila 1
    enfileirar(&f1, 1);
    enfileirar(&f1, 3);
    enfileirar(&f1, 4);
    enfileirar(&f1, 9);

    // Demonstração da junção das filas 1 e 2 na fila 3,
    // estando a fila 2 vazia, em ordem crescente
    juntar_filas(&f1, &f2, &f3);
    exibir_fila(f3);

    // Enfileirando apenas na fila 2,
    // agora apenas a fila 2 e 3 contém elementos
    enfileirar(&f2, 0);
    enfileirar(&f2, 5);
    enfileirar(&f2, 10);

    // Demonstração juntando as filas 2 e 3 na fila 3 em ordem crescente
    juntar_filas(&f2, &f3, &f1);
    exibir_fila(f1);

    liberar_fila(&f1);
    liberar_fila(&f2);
    liberar_fila(&f3);
}