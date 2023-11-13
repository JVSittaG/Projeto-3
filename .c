#include "projeto.h"
#include <stdio.h>

void cadastrarTarefa(Tarefa tarefas[], int *qtd) {
  if (*qtd >= 100) {
    printf(
        "O limite máximo de tarefas foi atingido .\n"); // Verifica se a
                                                        // quantidade limite de
                                                        // tarefas foi atingida.
    return;
  }

  // Se o limite máximo não foi atingido, cadastra a tarefa de acordo com o que
  // o usuário digitar.
  printf("Descricao Da Tarefa: ");
  scanf(" %s", tarefas[*qtd].descricao);

  printf("Categoria Da Tarefa: ");
  scanf("%s", tarefas[*qtd].categoria);

  printf("Prioridade Da Tarefa: ");
  scanf("%d", &tarefas[*qtd].prioridade);

  (*qtd)++;
}
// Função que adiciona a tarefa que o usuário desejar.

void listarTarefas(Tarefa tarefas[], int qtd) {
  if (qtd == 0) {
    printf("Sem tarefas cadastradas.\n"); // Verifica se há tarefas na lista.
    return;
  }

  // Caso tenha, o laço for percorre a lista de tarefas printando as tarefas
  // digitadas pelo usuário em ordem.
  printf(" Lista de Tarefas:\n");
  for (int i = 0; i < qtd; i++) {
    printf("Tarefa %d:\n", i + 1);
    printf("Descricao: %s\n", tarefas[i].descricao);
    printf("Categoria: %s\n", tarefas[i].categoria);
    printf("Prioridade: %d\n", tarefas[i].prioridade);
    printf("\n");
  }
}
// Função que lista todas as tarefas adicionadas pelo usuário.

void deletarTarefa(Tarefa tarefas[], int *qtd) {
  if (*qtd == 0) {
    printf("Não há tarefas para deletar.\n"); // Verifica se há tarefas na lista
                                              // tarefas para deletar.
    return;
  }
  (*qtd)--; // Se houverem tarefas, o programa deleta a última tarefa cadastrada
            // pelo usuário
  printf("Voce apagou a ultima tarefa cadastrada.\n");
}
// Função que deleta a última tarefa adicionada pelo usuário.

void salvarTarefas(Tarefa tarefas[], int qtd) {
  FILE *openfile = fopen("tarefas.txt", "wb");
  if (openfile == NULL) {
    printf("Erro ao abrir.\n"); // Caso haja algum erro ao abrir o arquivo, uma
                                // mensagem de erro é printada.
    return;
  }

  fwrite(&qtd, sizeof(int), 1,
         openfile); // Escreve a quantidade de tarefas no arquivo.

  fwrite(tarefas, sizeof(Tarefa), qtd,
         openfile); // Escreve o conteúdo de cada tarefa.

  fclose(openfile);
}

// Função que salva as tarefas do programa no arquivo

void carregarTarefas(Tarefa tarefas[], int *qtd) {
  FILE *openfile = fopen("tarefas.txt", "rb");
  if (openfile == NULL) {
    printf("Arquivo nao encontrado.\n"); // Caso haja algum erro ao abrir o
                                         // arquivo, uma mensagem de erro é
                                         // printada
    return;
  }

  fread(qtd, sizeof(int), 1,
        openfile); // Lê a quantidade de tarefas no arquivo.

  fread(tarefas, sizeof(Tarefa), *qtd,
        openfile); // Lê o conteúdo de cada tarefa.

  fclose(openfile);
}

// Função que carrega as tarefas do arquivo para o programa, sendo possivel
// lista-las.

