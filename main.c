#include "projeto.h"
#include <stdio.h>

//João Vitor Sitta Giopatto
//RA: 22.123.054-3

int main() {
    Tarefa tarefas[100];
    int qtd = 0;

    carregarTarefa(tarefas, &qtd);

    int opcao;
    do {
        printf("\n Menu \n");
        printf("1. Cadastrar tarefas\n");
        printf("2. Listar tarefas\n");
        printf("3. Deletar tarefa\n");
        printf("4. Salvar tarefa\n");
        printf("5. Sair\n");
        printf("6. Alterar tarefa\n");
        printf("7. Filtrar por Prioridade\n");
        printf("8. Filtrar por Estado\n");
        printf("9. Filtrar por Categoria\n");
        printf("10. Filtrar por Prioridade e Categoria\n");
        printf("11. Exportar por Prioridade\n");
        printf("12. Exportar por Categoria\n");
        printf("13. Exportar por Prioridade e Categoria\n");
        printf("Digite sua escolha: \n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarTarefa(tarefas, &qtd);
                break;
            case 2:
                listarTarefa(tarefas, qtd);
                break;
            case 3:
                deletarTarefa(tarefas, &qtd);
                break;
            case 4:
                salvarTarefa(tarefas, qtd);
                break;
            case 5:
                printf("Fechando o programa...");
                break;
            case 6:
                alterarTarefa(tarefas, qtd);
                break;
            case 7:
                filtrar_Prioridade(tarefas, qtd);
                break;
            case 8:
                filtrar_Estado(tarefas, qtd);
                break;
            case 9:
                filtrar_Categoria(tarefas, qtd);
                break;
            case 10:
                filtrar_Prioridade_Categoria(tarefas, qtd);
                break;
            case 11:
                exportar_Prioridade(tarefas, qtd);
                break;
            case 12:
                exportar_Categoria(tarefas, qtd);
                break;
            case 13:
                exportar_Prioridade_Categoria(tarefas, qtd);
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 5);

    return 0;
}
