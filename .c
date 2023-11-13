#include "projeto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

  printf("Status Da Tarefa: ");
  scanf(" %s", tarefas[*qtd].status);
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
    printf("Status: %s\n", tarefas[i].status);
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

// Projeto 3

// Função para alterar campos de uma tarefa

// DAR UMA OLHADA COM O PROFESSOR PRA SABER COM QUE PARTE DA STRUCT VC VAI USAR
// PARA COMPARAR NO ARQUIVO PARA ALTERAR
void alterarTarefa(int prioridade) {
  FILE *arquivo;
  arquivo = fopen("tarefas.txt", "r+"); // Abre o arquivo para leitura e escrita

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

      // Mova o cursor de arquivo para o início da linha da tarefa
      fseek(arquivo, -1 * (long)sizeof(tarefa), SEEK_CUR);

      // Sobrescreva a tarefa com as informações atualizadas
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

// Função para comparar prioridades (usada na ordenação)
int compararPrioridade(const void *a, const void *b) {
  return ((Tarefa *)b)->prioridade - ((Tarefa *)a)->prioridade;
}

// Função para filtrar e ordenar tarefas
void filtrar_categoria(Tarefa *tarefas, int numeroTarefas,
                       const char *categoria) {
  printf("Tarefas na categoria \"%s\", ordenadas por prioridade:\n", categoria);

  // Filtrar tarefas pela categoria
  for (int i = 0; i < numeroTarefas; i++) {
    if (strcmp(tarefas[i].categoria, categoria) == 0) {
      printf("Prioridade: %d, Status: %s ,Descrição: %s\n",
             tarefas[i].prioridade, tarefas[i].status, tarefas[i].descricao);
    }
  }

  // Ordenar tarefas por prioridade (da maior para a menor)
  qsort(tarefas, numeroTarefas, sizeof(Tarefa), compararPrioridades);
}

void filtrar_categoria_prioriade(Tarefa *tarefas, int numeroTarefas,
                                 const char *categoriaFiltro,
                                 int prioridadeFiltro) {
  printf("Tarefas na categoria \"%s\" com prioridade %d:\n", categoriaFiltro,
         prioridadeFiltro);

  // Filtrar tarefas pela categoria e prioridade
  for (int i = 0; i < numeroTarefas; i++) {
    if (strcmp(tarefas[i].categoria, categoriaFiltro) == 0 &&
        tarefas[i].prioridade >= prioridadeFiltro) {
      printf("Status: %s ,Descrição: %s\n", tarefas[i].status,
             tarefas[i].descricao);
    }
  }
  // Ordenar tarefas por prioridade (da maior para a menor)
  qsort(tarefas, numeroTarefas, sizeof(Tarefa), compararPrioridades);
}

void exportar_prioridade(Tarefa *tarefas, int numTarefas,
                         int prioridadeEscolhida) {
  FILE *arquivo = fopen("tarefas.txt", "w");
  if (arquivo == NULL) {
    printf("Não foi possível abrir o arquivo.\n");
    return;
  }

  // Escrever as tarefas da prioridade escolhida no arquivo
  for (int i = 0; i < numTarefas; i++) {
    if (tarefas[i].prioridade == prioridadeEscolhida) {
      fprintf(arquivo, "%s, %s, %s\n", tarefas[i].categoria, tarefas[i].status,
              tarefas[i].descricao);
    }
  }

  fclose(arquivo);
  printf("Tarefas exportadas com sucesso.\n");
}

void exportar_categoria(Tarefa *tarefas, int numeroTarefas, char *categoria) {
  // Abrir arquivo para escrita
  FILE *fp = fopen("tarefas.txt", "w");
  if (fp == NULL) {
    printf("Não foi possível abrir o arquivo para escrita\n");
    return;
  }
  // Filtrar tarefas pela categoria
  for (int i = 0; i < numeroTarefas; i++) {
    if (strcmp(tarefas[i].categoria, categoria) == 0) {
      // Escrever tarefa no arquivo
      fprintf(fp, "Prioridade: %d, Status: %s ,Descrição: %s\n",
              tarefas[i].prioridade, tarefas[i].status, tarefas[i].descricao);
    }
  }

  // Fechar o arquivo
  fclose(fp);

  // Ordenar tarefas por prioridade (da maior para a menor)
  qsort(tarefas, numeroTarefas, sizeof(Tarefa), compararPrioridades);
}

void exportar_categoria_prioridade(Tarefa *tarefas, int numeroTarefas,
                                   const char *categoria, int prioridade) {

  // Abrir arquivo para escrita
  FILE *fp = fopen("tarefas.txt", "w");
  if (fp == NULL) {
    printf("Não foi possível abrir o arquivo para escrita\n");
    return;
  }

  // Filtrar tarefas pela categoria e prioridade
  for (int i = 0; i < numeroTarefas; i++) {
    if (strcmp(tarefas[i].categoria, categoria) == 0 &&
        tarefas[i].prioridade == prioridade) {
      // Escrever tarefa no arquivo
      fprintf(fp, "Prioridade: %d, Status: %s ,Descrição: %s\n",
              tarefas[i].prioridade, tarefas[i].status, tarefas[i].descricao);
    }
  }
  // Fechar o arquivo
  fclose(fp);

  // Ordenar tarefas por prioridade (da maior para a menor)
  qsort(tarefas, numeroTarefas, sizeof(Tarefa), compararPrioridades);
}
