#include <stdio.h>
#include <stdlib.h>

typedef struct impr{
    char *msg;
} tImpr;

/**
 * @brief Cria uma tarefa do tipo impressão em tela
 * 
 * @param msg - A mensagem que deve ser impressa em tela
 *
 * @return Um ponteiro para a tarefa criada
 */
tImpr* CriaTarefaImprimir(char *msg){
    tImpr *imp;
    int i = 0;

    imp = (tImpr*) calloc(1, sizeof(tImpr));
    imp->msg = (char*) calloc(1, sizeof(char));

    while(msg[i] != '\0'){
        imp->msg[i] = msg[i];
        i++;

        imp->msg = (char*) realloc(imp->msg, (i+2 * sizeof(char)));
    }

    imp->msg[i] = '\0';

    return imp;
}

/**
 * @brief Função que executa uma tarefa de impressão em tela
 *
 * @param imp - Ponteiro para a tarefa a ser executada
 *
 */
void ExecutaTarefaImprimir(void *imp){
    printf("\n%s", ((tImpr*)imp)->msg);
}

/**
 * @brief Função que destrói (libera a memória) uma tarefa de impressão em tela
 *
 * @param imp - Ponteiro para a tarefa a ser destruída
 *
 */
void DestroiTarefaImprimir(void *imp){
    free(((tImpr*)imp)->msg);
    free((tImpr*)imp);
}
