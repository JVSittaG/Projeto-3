#ifndef PROJETO3FINAL_PROJETO_H
#define PROJETO3FINAL_PROJETO_H

typedef struct {
  int prioridade;
  char descricao[300];
  char categoria[100];
  char status[13];
} Tarefa;

// projeto 1
void cadastrarTarefa(Tarefa tarefas[], int *qtd);
void listarTarefas(Tarefa tarefas[], int qtd);
void deletarTarefa(Tarefa tarefas[], int *qtd);
void salvarTarefas(Tarefa tarefas[], int qtd);
void carregarTarefas(Tarefa tarefas[], int *qtd);

// projeto 3
void alterarTarefa(int prioridade);
void filtrar_prioridade(Tarefa tarefas[]);
void filtrar_status(char *status);
int compararPrioridades(const void *a, const void *b);
void filtrar_categoria(Tarefa *tarefas, int numTarefas, const char *categoria);
void filtrar_categoria_prioriade(Tarefa *tarefas, int numeroTarefas,
                                 const char *categoriaFiltro,
                                 int prioridadeFiltro);
void exportar_prioridade(Tarefa *tarefas, int numeroTarefas,
                         int prioridadeExportar);
void exportar_categoria_prioridade(Tarefa *tarefas, int numeroTarefas,
                                   const char *categoria, int prioridade);
void exportar_categoria(Tarefa *tarefas, int numeroTarefas,
                        char categoriaExportar);

#endif // PROJETO3FINAL_PROJETO_H
