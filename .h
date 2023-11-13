#ifndef PROJETO1FINAL_PROJETO_H
#define PROJETO1FINAL_PROJETO_H

typedef struct {
  int prioridade;
  char descricao[300];
  char categoria[100];
  char status[20];
} Tarefa;

void cadastrarTarefa(Tarefa tarefas[], int *qtd);
void listarTarefas(Tarefa tarefas[], int qtd);
void deletarTarefa(Tarefa tarefas[], int *qtd);
void salvarTarefas(Tarefa tarefas[], int qtd);
void carregarTarefas(Tarefa tarefas[], int *qtd);


#endif // PROJETO1FINAL_PROJETO_H
