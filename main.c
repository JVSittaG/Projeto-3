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
    case 9:
      printf("Digite a categoria para filtrar as tarefas: ");
      const char categoriaFiltro;
      scanf("%s", &categoriaFiltro);
      filtrar_categoria(tarefas, qtd, &categoriaFiltro);
      break;
    case 10:
      printf("Digite a categoria para filtrar as tarefas: ");
      const char categoriaFiltro2;
      scanf("%s", categoriaFiltro2);
      printf("Digite tambem a prioridade prioridade: ");
      const int prioridadeFiltro2;
      scanf("%d", prioridadeFiltro2);
      filtrar_categoria_prioriade(tarefas, qtd, &categoriaFiltro,
                                  prioridadeFiltro2);
      break;
    case 11:
      printf("Digite a prioridade para exportar as tarefas:");
      int prioridadeExportar;
      scanf("%d", prioridadeExportar);
      exportar_prioridade(tarefas, qtd, prioridadeExportar);
      break;
    case 12:
      printf("Digite a prioridade para exportar as tarefas:");
      char categoriaExportar;
      scanf("%s", categoriaExportar);
      exportar_categoria(tarefas, qtd, categoriaExportar);
      break;
    case 13:
      printf("Digite a prioridade para exportar as tarefas:");
      char categoriaExportar2;
      scanf("%s", categoriaExportar2);
      printf("Digite tambem a prioridade prioridade: ");
      const int prioridadeExportar2;
      scanf("%d", prioridadeExportar2);
      exportar_categoria_prioridade(tarefas, qtd, categoriaExportar2,
                                    prioridadeExportar2);
      break;
    default:
      printf("Tente outra acao.\n");
    }
  } while (opcao != 13);

  return 0;
}
