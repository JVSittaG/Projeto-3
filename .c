#include "projeto.h"
#include <stdlib.h>

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int compararPrioridade(const void *a, const void *b) {
    return ((Tarefa *)b)->prioridade - ((Tarefa *)a)->prioridade;
}


int compararTarefas(const void *a, const void *b) {

    int comparacaoCategoria =
            strcmp(((Tarefa *)a)->categoria, ((Tarefa *)b)->categoria);

    if (comparacaoCategoria == 0) {
        return ((Tarefa *)b)->prioridade - ((Tarefa *)a)->prioridade;
    }

    return comparacaoCategoria;
}

void cadastrarTarefa(Tarefa tarefas[], int *numTarefas) {
    if (*numTarefas >= 100) {
        printf("Limite de tarefas atingido.\n");
        return;
    }

    printf("Digite a Prioridade o da tarefa: ");
    scanf(" %d", &tarefas[*numTarefas].prioridade);
    limparBuffer();

    printf("Digite a categoria da tarefa: ");
    scanf(" %s", tarefas[*numTarefas].categoria);
    limparBuffer();

    printf("Digite o Estado da tarefa: ");
    scanf("%s", tarefas[*numTarefas].status);
    limparBuffer();

    printf("Digite a Descricao da tarefa: ");
    scanf("%s", tarefas[*numTarefas].descricao);
    limparBuffer();

    (*numTarefas)++;
}

void listarTarefa(Tarefa tarefas[], int numTarefas) {
    if (numTarefas == 0) {
        printf("Nenhuma tarefa cadastrada.\n");
        return;
    }

    printf("Lista de Tarefas \n");
    for (int i = 0; i < numTarefas; i++) {
        printf("Tarefa %d:\n", i + 1);
        printf("Prioridade: %d\n", tarefas[i].prioridade);
        printf("Categoria: %s\n", tarefas[i].categoria);
        printf("Estado: %s\n", tarefas[i].status);
        printf("Descricao: %s\n", tarefas[i].descricao);
        printf("\n");
    }
}

void deletarTarefa(Tarefa tarefas[], int *numTarefas) {
    if (*numTarefas == 0) {
        printf("Nenhuma tarefa para deletar.\n");
        return;
    }

    int indiceTarefa;
    printf("Digite o índice da tarefa para deletar: ");
    scanf("%d", &indiceTarefa);

    if (indiceTarefa >= 1 && indiceTarefa <= *numTarefas) {
        for (int i = indiceTarefa - 1; i < *numTarefas - 1; i++) {
            tarefas[i] = tarefas[i + 1];
        }
        (*numTarefas)--;
        printf("Tarefa deletada com sucesso.\n");
    } else {
        printf("Índice inválido.\n");
    }
}

void salvarTarefa(Tarefa tarefas[], int numeroTarefas) {
    FILE *file = fopen("tarefas.txt", "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fwrite(&numeroTarefas, sizeof(int), 1, file);
    fwrite(tarefas, sizeof(Tarefa), numeroTarefas, file);

    fclose(file);
}

void alterarTarefa(Tarefa tarefas[], int numTarefas) {
    int indice;
    printf("Digite o índice da tarefa para alterar: ");
    scanf("%d", &indice);

    if (indice >= 1 && indice <= numTarefas) {
        printf("Escolha o campo a ser alterado:\n");
        printf("1. Prioridade\n");
        printf("2. Categoria\n");
        printf("3. Estado\n");
        printf("4. Descricao\n");
        printf("Digite sua escolha: ");

        int opcao;
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite a Prioridade: \n");
                scanf("%d", &tarefas[indice - 1].prioridade);
                break;
            case 2:
                printf("Digite a Categoria: \n");
                scanf(" %s", tarefas[indice - 1].categoria);
                break;
            case 3:
                printf("Digite o Estado: \n");
                scanf("%s", tarefas[indice - 1].status);
                break;
            case 4:
                printf("Digite a nova Descricao: \n");
                scanf("%s", tarefas[indice - 1].descricao);
                break;
            default:
                printf("Opção inválida.\n");
        }
    } else {
        printf("\nÍndice inválido.\n");
    }
}

void carregarTarefa(Tarefa tarefas[], int *numeroTarefas) {
    FILE *file = fopen("tarefas.txt", "r");
    if (file == NULL) {
        printf("Arquivo não encontrado.\n");
        return;
    }

    fread(numeroTarefas, sizeof(int), 1, file);
    fread(tarefas, sizeof(Tarefa), *numeroTarefas, file);

    fclose(file);
}

void filtrar_Prioridade(Tarefa tarefas[], int numeroTarefas) {
    int prioridadeFiltrar;
    printf("Digite a prioridade para filtrar: \n");
    scanf("%d", &prioridadeFiltrar);
    limparBuffer();

    printf("\n Tarefas com Prioridade %d \n", prioridadeFiltrar);
    for (int i = 0; i < numeroTarefas; i++) {
        if (tarefas[i].prioridade == prioridadeFiltrar) {
            exibirTarefa(tarefas[i]);
        }
    }
}

void filtrar_Estado(Tarefa *tarefas, int numeroTarefas) {
    char statusFiltrar[20];
    printf("Digite o estado para filtrar ");
    scanf("%s", statusFiltrar);
    printf("Tarefas com o estado %s:\n", statusFiltrar);
    for (int i = 0; i < numeroTarefas; i++) {
        if (strcmp(tarefas[i].status, statusFiltrar) == 0) {
            printf("Prioridade: %d\n", tarefas[i].prioridade);
            printf("Categoria: %s\n", tarefas[i].categoria);
            printf("Descricao: %s\n", tarefas[i].descricao);
        }
    }
}

void filtrar_Categoria(Tarefa tarefas[], int numeroTarefas) {
    char categoriaFiltrar[300];
    printf("Digite a categoria para filtrar: ");
    scanf(" %s", categoriaFiltrar);
    limparBuffer();

    Tarefa copiaTarefas[100];
    memcpy(copiaTarefas, tarefas, numeroTarefas * sizeof(Tarefa));

    int numFiltradas = 0;
    Tarefa filtradas[100];
    for (int i = 0; i < numeroTarefas; i++) {
        if (strcmp(copiaTarefas[i].categoria, categoriaFiltrar) == 0) {
            filtradas[numFiltradas++] = copiaTarefas[i];
        }
    }

    qsort(filtradas, numFiltradas, sizeof(Tarefa), compararPrioridade);

    printf("Tarefas filtradas por categoria (%s) e ordenadas por prioridade\n ",
           categoriaFiltrar);

    for (int i = 0; i < numFiltradas; i++) {
        printf("Tarefa %d:\n", i + 1);
        printf("Prioridade: %d\n", filtradas[i].prioridade);
        printf("Categoria: %s\n", filtradas[i].categoria);
        printf("Estado: %s\n", filtradas[i].status);
        printf("Descricao: %s\n", filtradas[i].descricao);
        printf("\n");
    }
}

void filtrar_Prioridade_Categoria(Tarefa tarefas[], int numeroTarefas) {
    int prioridadeFiltrar2;
    char categoriaFiltrar2;
    printf("Digite a prioridade desejada: ");
    scanf("%d", &prioridadeFiltrar2);
    printf("Digite a categoria desejada: ");
    scanf(" %[^\n]s", &categoriaFiltrar2);

    printf("=== Tarefas com Prioridade %d e Categoria %s ===\n",
           prioridadeFiltrar2, &categoriaFiltrar2);
    for (int i = 0; i < numeroTarefas; i++) {
        if (tarefas[i].prioridade == prioridadeFiltrar2 &&
            strcmp(tarefas[i].categoria, &categoriaFiltrar2) == 0) {
            exibirTarefa(tarefas[i]);
        }
    }
}

void exportar_Prioridade(Tarefa tarefas[], int numeroTarefas) {
    FILE *file = fopen("Prioridade.txt", "w");
    if (file == NULL) {
        printf("Erro ao criar o arquivo para exportação.\n");
        return;
    }

    int prioridadeExportar;
    printf("Digite a prioridade desejada para exportação: ");
    scanf("%d", &prioridadeExportar);

    for (int i = 0; i < numeroTarefas; i++) {
        if (tarefas[i].prioridade == prioridadeExportar) {
            fprintf(file, "%d, %s, %s, %s\n", tarefas[i].prioridade,
                    tarefas[i].categoria, tarefas[i].descricao, tarefas[i].status);
        }
    }

    fclose(file);
}

void exportar_Categoria(Tarefa tarefas[], int numeroTarefas) {

    FILE *arquivo = fopen("Categoria.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char categoriaExportar[300];
    printf("Digite a categoria para exportação: ");
    scanf(" %s", categoriaExportar);
    limparBuffer();

    int numFiltradas = 0;
    Tarefa filtradas[100];
    for (int i = 0; i < numeroTarefas; i++) {
        if (strcmp(tarefas[i].categoria, categoriaExportar) == 0) {
            filtradas[numFiltradas++] = tarefas[i];
        }
    }

    if (numFiltradas == 0) {
        printf("Nenhuma tarefa encontrada com categoria %s.\n", categoriaExportar);
        return;
    }

    qsort(filtradas, numFiltradas, sizeof(Tarefa), compararTarefas);

    fprintf(arquivo, " Tarefas da categoria %s ordenadas por prioridade \n",
            categoriaExportar);
    for (int i = 0; i < numFiltradas; i++) {
        fprintf(arquivo, "Prioridade: %d\n", filtradas[i].prioridade);
        fprintf(arquivo, "Categoria: %s\n", filtradas[i].categoria);
        fprintf(arquivo, "Estado: %s\n", filtradas[i].status);
        fprintf(arquivo, "Descricao: %s\n", filtradas[i].descricao);
        fprintf(arquivo, "\n");
    }

    fclose(arquivo);
}

void exportar_Prioridade_Categoria(Tarefa tarefas[], int numeroTarefas) {
    FILE *file = fopen("Proridade_e_Categoria.txt", "w");
    if (file == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return;
    }

    int prioridadeExportar2;
    char categoriaExportar2[300];
    printf("Digite a prioridade para exportação: ");
    scanf("%d", &prioridadeExportar2);
    printf("Digite a categoria para exportação: ");
    scanf(" %[^\n]s", categoriaExportar2);

    for (int i = 0; i < numeroTarefas; i++) {
        if (tarefas[i].prioridade == prioridadeExportar2 &&
            strcmp(tarefas[i].categoria, categoriaExportar2) == 0) {
            fprintf(file, "%d, %s, %s, %s\n", tarefas[i].prioridade,
                    tarefas[i].categoria, tarefas[i].status, tarefas[i].categoria);
        }
    }

    fclose(file);
}

void exibirTarefa(Tarefa tarefa) {
    printf("Prioridade: %d\n", tarefa.prioridade);
    printf("Categoria: %s\n", tarefa.categoria);
    printf("Estado: %s\n", tarefa.status);
    printf("Descricao: %s\n", tarefa.descricao);
    printf("\n");
}
