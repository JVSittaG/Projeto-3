#include "projeto.h"
#include <stdio.h>
#include <string.h>
// João Vitor Sitta Giopatto RA: 22.123.054-3

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
    printf("5) Sair\n");
    printf("6) Alterar por prioridade \n");
    printf("7) Filtrar por prioridade\n");
    printf("8) Filtrar por status\n");
    printf("9) Filtrar por categoria\n");
    printf("10) Filtrar por prioridade e categoria\n");
    printf("11) Exportar por prioridade\n");
    printf("12) Exportar por categoria\n");
    printf("13) Exportar por prioridade e categoria\n");
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
    case 6:
      printf(
          "Digite a prioridade da tarefa que deseja alterar: "); // TEM Q MUDAR
      int prioridadeAlteracao;
      scanf("%d", &prioridadeAlteracao);
      alterarTarefa(prioridadeAlteracao);
      break;
    case 7:
      filtrar_prioridade(tarefas);
      break;
    case 8:
      printf("Digite a status para filtrar as tarefas: ");
      char statusFiltro;
      scanf("%s", statusFiltro);
      filtrar_status(&statusFiltro);
      break;
