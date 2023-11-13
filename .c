#include "projeto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cadastrarTarefa(Tarefa tarefas[], int *qtd) {
  if (*qtd >= 100) {
    printf(
        "O limite máximo de tarefas foi atingido .\n"); 
    return;
  }


  printf("Descricao Da Tarefa: ");
  scanf(" %s", tarefas[*qtd].descricao);

  printf("Categoria Da Tarefa: ");
  scanf("%s", tarefas[*qtd].categoria);

  printf("Prioridade Da Tarefa: ");
  scanf("%d", &tarefas[*qtd].prioridade);

  printf("Status Da Tarefa: ");
  scanf(" %s", tarefas[*qtd].status);
  (*qtd)++;
}


void listarTarefas(Tarefa tarefas[], int qtd) {
  if (qtd == 0) {
    printf("Sem tarefas cadastradas.\n"); 
    return;
  }

  
  printf(" Lista de Tarefas:\n");
  for (int i = 0; i < qtd; i++) {
    printf("Tarefa %d:\n", i + 1);
    printf("Descricao: %s\n", tarefas[i].descricao);
    printf("Categoria: %s\n", tarefas[i].categoria);
    printf("Prioridade: %d\n", tarefas[i].prioridade);
    printf("Status: %s\n", tarefas[i].status);
    printf("\n");
  }
}


void deletarTarefa(Tarefa tarefas[], int *qtd) {
  if (*qtd == 0) {
    printf("Não há tarefas para deletar.\n"); 
    return;
  }
  (*qtd)--; 
  printf("Voce apagou a ultima tarefa cadastrada.\n");
}


void salvarTarefas(Tarefa tarefas[], int qtd) {
  FILE *openfile = fopen("tarefas.txt", "wb");
  if (openfile == NULL) {
    printf("Erro ao abrir.\n"); 
    return;
  }

  fwrite(&qtd, sizeof(int), 1,
         openfile); 

  fwrite(tarefas, sizeof(Tarefa), qtd,
         openfile); 

  fclose(openfile);
}



void carregarTarefas(Tarefa tarefas[], int *qtd) {
  FILE *openfile = fopen("tarefas.txt", "rb");
  if (openfile == NULL) {
    printf("Arquivo nao encontrado.\n"); 
    return;
  }

  fread(qtd, sizeof(int), 1,
        openfile);

  fread(tarefas, sizeof(Tarefa), *qtd,
        openfile);

  fclose(openfile);
}



// Projeto 3

// Função para alterar campos de uma tarefa

// DAR UMA OLHADA COM O PROFESSOR PRA SABER COM QUE PARTE DA STRUCT VC VAI USAR
// PARA COMPARAR NO ARQUIVO PARA ALTERAR
void alterarTarefa(int prioridade) {
  FILE *arquivo;
  arquivo = fopen("tarefas.txt", "r+");a

  if (arquivo == NULL) {
    printf("Nenhuma tarefa salva.\n");
    return;
  }

  Tarefa tarefa;

  while (fscanf(arquivo, "%d;%[^;];%[^;];%[^;]\n", &tarefa.prioridade,
                tarefa.descricao, tarefa.categoria, tarefa.status) != EOF) {
    if (tarefa.prioridade == prioridade) {
      printf("Prioridade: %d\n", tarefa.prioridade);
      printf("Descrição: %s\n", tarefa.descricao);
      printf("Categoria: %s\n", tarefa.categoria);
      printf("Estado: %s\n\n", tarefa.status);

      int opcao;
      printf("Selecione o campo para alterar:\n");
      printf("1. Prioridade\n");
      printf("2. Descrição\n");
      printf("3. Categoria\n");
      printf("4. Estado\n");
      printf("Escolha uma opção: ");
      scanf("%d", &opcao);

      switch (opcao) {
      case 1:
        printf("Nova prioridade: ");
        scanf("%d", &tarefa.prioridade);
        break;
      case 2:
        printf("Nova descrição: ");
        scanf(" %[^\n]", tarefa.descricao);
        break;
      case 3:
        printf("Nova categoria: ");
        scanf(" %[^\n]", tarefa.categoria);
        break;
      case 4:
        printf("Novo estado: ");
        scanf(" %[^\n]", tarefa.status);
        break;
      default:
        printf("Opção inválida. Nenhum campo foi alterado.\n");
        break;
      }

     
      fseek(arquivo, -1 * (long)sizeof(tarefa), SEEK_CUR);

    
      fprintf(arquivo, "%d;%s;%s;%s\n", tarefa.prioridade, tarefa.descricao,
              tarefa.categoria, tarefa.status);
      printf("Tarefa atualizada com sucesso!\n");
      break;
    }
  }

  fclose(arquivo);
}

void filtrar_prioridade(Tarefa *tarefas) {
  FILE *arquivo;
  arquivo = fopen("tarefas.txt", "r");

  if (arquivo == NULL) {
    printf("Nenhuma tarefa salva.\n");
    return;
  }

  printf("Digite a prioridade para filtrar as tarefas: ");
  int prioridadeFiltro;
  scanf("%d", &prioridadeFiltro);
  printf("Tarefas com prioridade %d:\n", prioridadeFiltro);
  while (fscanf(arquivo, "%d;%[^;];%[^;];%[^;]\n", &tarefas->prioridade,
                tarefas->descricao, tarefas->categoria,
                tarefas->status) != EOF) {
    if (tarefas->prioridade == prioridadeFiltro) {
      printf("Prioridade: %d\n", tarefas->prioridade);
      printf("Descrição: %s\n", tarefas->descricao);
      printf("Categoria: %s\n", tarefas->categoria);
      printf("Status: %s\n\n", tarefas->status);
    }
  }
  fclose(arquivo);
}

void filtrar_status(char status[]) {
  FILE *arquivo;
  arquivo = fopen("tarefas.txt", "r");

  if (arquivo == NULL) {
    printf("Nenhuma tarefa salva.\n");
    return;
  }

  Tarefa outra_tarefa;

  printf("Tarefas com status %s:\n", outra_tarefa.status);
  while (fscanf(arquivo, "%d;%[^;];%[^;];%[^;]\n", &outra_tarefa.prioridade,
                outra_tarefa.descricao, outra_tarefa.categoria,
                outra_tarefa.status) != EOF) {
    if (outra_tarefa.status == status) {
      printf("Prioridade: %d\n", outra_tarefa.prioridade);
      printf("Descrição: %s\n", outra_tarefa.descricao);
      printf("Categoria: %s\n", outra_tarefa.categoria);
      printf("Status: %s\n\n", outra_tarefa.status);
    }
  }

  fclose(arquivo);
}


