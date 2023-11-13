#include <stdio.h>

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
      alterarTarefa(tarefas);
      break;
    case 7:
      filtrar_prioridade(tarefas);
      break;
    case 8:
      filtrar_status(tarefas);
      break;
    case 9:
      filtrar_categoria(tarefas, qtd);
      break;
    case 10:
      filtrar_categoria_prioriade(tarefas, qtd);
      break;
    case 11:
      exportar_prioridade(tarefas, qtd);
      break;
    case 12:
      exportar_categoria(tarefas, qtd);
      break;
    case 13:
      exportar_categoria_prioridade(tarefas, qtd);
      break;
    default:
      printf("Tente outra acao.\n");
    }
  } while (opcao != 13);

  return 0;
}
