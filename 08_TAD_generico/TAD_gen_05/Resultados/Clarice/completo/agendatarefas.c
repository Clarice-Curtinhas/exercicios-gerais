#include <stdio.h>
#include <stdlib.h>

typedef void (*func_exec)(void*);
typedef void (*func_destroi)(void*);

typedef struct tarefa{
    int prioridade;
    void *tarefa;
    func_exec executa;
    func_destroi destroi;
} tTarefa;

typedef struct agendatarefas{
    int qntTarefas;
    tTarefa *agendaTarefas;
} tAgendaTarefas;

/**
 * @brief Cria uma variável para um tipo genérico que representa uma Agenda de Tarefas
 *
 * @param numElem A quantidade de tarefas que serão armazenadas no agendador
 *
 * @return Um ponteiro para a agenda de tarefas
 */
tAgendaTarefas* CriaAgendaDeTarefas(int numElem){
    /*tAgendaTarefas *agenda;

    agenda = (tAgendaTarefas*) calloc(1, sizeof(tAgendaTarefas));

    agenda->qntTarefas = numElem;
    agenda->agendaTarefas = (tTarefa*) calloc(numElem, sizeof(tTarefa));

    return agenda;*/
}

/**
 * @brief Destroi a agenda de tarefas (libera a memória)
 *
 * @param tar - A agenda que terá seu conteúdo liberado/destruído
 */
void DestroiAgendaDeTarefas(tAgendaTarefas* tar){
    /*free(tar->agendaTarefas);
    free(tar);*/
}

/**
 * @brief Cadastra uma tarefa em um agendador de tarefas
 *
 * @param tar - Pointeiro para a agenda de tarefas
 * @param prioridade - Prioridade de execução da nova tarefa
 * @param tarefa - Ponteiro para nova tarefa a ser executada
 * @param executa - Ponteiro para função (callback) que será chamada quando for a hora de executar a tarefa
 * @param destroi - Ponteiro para função (callback) que será chamada quando for a hora de destruir a tarefa (liberar a memória)
 *
 */
void CadastraTarefaNaAgenda(tAgendaTarefas* tar, int prioridade, void *tarefa, void (*executa)(void*), void (*destroi)(void*) ){
    /*tar->agendaTarefas[tar->qntTarefas].destroi = destroi;
    tar->agendaTarefas[tar->qntTarefas].executa = executa;
    tar->agendaTarefas[tar->qntTarefas].tarefa = tarefa;
    tar->agendaTarefas[tar->qntTarefas].prioridade = prioridade;*/
}

int ComparaTarefas(const void *a, const void *b){
    /*if(((tTarefa*)a)->prioridade > ((tTarefa*)b)->prioridade) return 1;
    if(((tTarefa*)a)->prioridade < ((tTarefa*)b)->prioridade) return -1;
    else return 0;*/
}

/**
 * @brief Executa as tarefas que estão salvas na agenda de tarefas passada como parâmetro.
 *
 * @param tar Agenda de tarefas
 *
 */
void ExecutarTarefasDaAgenda(tAgendaTarefas* tar){
    /*qsort(&tar->agendaTarefas, tar->qntTarefas, sizeof(tTarefa), ComparaTarefas);

    for(int i = 0; i < tar->qntTarefas; i++){
        tar->agendaTarefas[i].executa(tar->agendaTarefas[i].tarefa);
        tar->agendaTarefas[i].destroi(tar->agendaTarefas[i].tarefa);
    }*/
}