#include <stdio.h>
#include "projeto.h"
//João Vitor Sitta Giopatto RA: 22.123.054-3



int main() {
    Tarefa tarefas[100];
    int qtd = 0;

    carregarTarefas(tarefas, &qtd);
    // Função que carrega as tarefas que estão no arquivo.


    int opcao;
    do {
        printf("\n Menu\n");
        printf("1) Cadastrar tarefa\n");
        printf("2) Listar tarefas\n");
        printf("3) Deletar tarefa\n");
        printf("4) Salvar tarefas\n");
        printf("5) Sair\n")
        printf("Digite a acao que quer realizar : ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarTarefa(tarefas, &qtd);
                break;
            case 2:
                listarTarefas(tarefas, qtd);
                break;
            case 3:
                deletarTarefa(tarefas, &qtd);
                break;
            case 4:
                salvarTarefas(tarefas, qtd);
                break;
            case 5:
                printf("Fechando programa.\n");
                break;
            default:
              printf("Tente outra acao.\n");
        }
    } while (opcao != 5);

    return 0;
}
