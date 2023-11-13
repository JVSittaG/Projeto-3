#ifndef PJ_H
#define PJ_H

#include <stdio.h>
#include <string.h>


typedef struct {
    int prioridade;
    char descricao[300];
    char categoria[100];
    char status[13];
} Tarefa;

void cadastrarTarefa(Tarefa tarefas[], int *numeroTarefas);
void listarTarefa(Tarefa tarefas[], int numeroTarefas);
void alterarTarefa(Tarefa tarefas[], int numeroTarefas);
void filtrar_Prioridade(Tarefa tarefas[], int numeroTarefas);
void filtrar_Estado(Tarefa tarefas[], int numeroTarefas);
void filtrar_Categoria(Tarefa tarefas[], int numeroTarefas);
void filtrar_Prioridade_Categoria(Tarefa tarefas[], int numeroTarefas);
void exportar_Prioridade(Tarefa tarefas[], int numeroTarefas);
void exportar_Categoria(Tarefa tarefas[], int numeroTarefas);
void exportar_Prioridade_Categoria(Tarefa tarefas[], int numeroTarefas);
void deletarTarefa(Tarefa tarefas[], int *numeroTarefas);
void salvarTarefa(Tarefa tarefas[], int numeroTarefas);
void carregarTarefa(Tarefa tarefas[], int *numeroTarefas);
void exibirTarefa(Tarefa tarefas);

#endif
