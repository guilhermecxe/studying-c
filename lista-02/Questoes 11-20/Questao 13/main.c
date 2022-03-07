#include "pilha.c"

int main(){
    Fila fila;
    criar_fila(&fila);
    int escolha = 1;

    while(escolha != 0){
        printf("\nOpcoes:\n");
        printf("1. Incluir novo processo.\n");
        printf("2. Retirar processo com o maior tempo de espera\n");
        printf("3. Exibir fila de processos.\n");
        printf("0. Sair\n");
        printf("Escolha o que fazer: ");
        scanf("%d", &escolha);

        if(escolha == 0)
            break;
        else if(escolha == 1){
            Processo processo;
            printf("Numero identificador: "); scanf("%d", &processo.id);
            printf("Tempo de espera: "); scanf("%d", &processo.espera);
            empilhar_processo(&fila, processo);
            printf("Processo empilhado!!\n");
        }
        else if(escolha == 2){
            remover_maior_espera(&fila);
            printf("Processo removido!!\n");
        }
        else if(escolha == 3){
            printf("\nSua fila de processos:\n");
            exibir_processos(&fila);
            printf("\n");
        }
        
    }

    liberar_fila(&fila);

    return 0;
}