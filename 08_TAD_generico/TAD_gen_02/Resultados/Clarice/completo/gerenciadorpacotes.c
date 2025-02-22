#include <stdio.h>
#include <stdlib.h>

#include "pacote.h"

typedef struct gerenciadorpacotes{
    tPacote **pacs;
    int tamGeren;
    int tamAloc;
} tGerenciador;

/**
 * @brief Cria uma TAD que gerencia pacotes. O pacote é um TAD genérico.
 *
 *
 * @return O gerenciador de pacotes
 */
tGerenciador* CriaGerenciador(){
    tGerenciador *geren;

    geren = (tGerenciador*) calloc(1, sizeof(tGerenciador));

    geren->pacs = (tPacote**) calloc(5, sizeof(tPacote*));

    geren->tamAloc = 1;
    geren->tamGeren = 0;

    return geren;
}

/**
 * @brief Adiciona um pacote ao gerenciador de pacotes.
 *
 * @param geren O gerenciador de pacotes que armazenará o pacote 
 * @param pac O pacote que queremos adicionar no gerenciador.
 *
 */
void AdicionaPacoteNoGerenciador(tGerenciador* geren, tPacote* pac){
    geren->pacs[geren->tamGeren] = pac;
    geren->tamAloc++;
    geren->tamGeren++;

    geren->pacs = (tPacote**) realloc(geren->pacs, (geren->tamAloc)*sizeof(tPacote*));
}


/**
 * @brief Destrói um gerenciador de pacotes
 *
 * @param geren O gerenciador de pacotes que será destruído (memória liberada)
 *
 */
void DestroiGerenciador(tGerenciador* geren){
    for(int i = 0; i < geren->tamGeren; i++){
        DestroiPacote(geren->pacs[i]);
    }

    free(geren->pacs);
    free(geren);
}

/**
 * @brief Imprime um pacote específico do gerenciador de pacotes.
 *
 * @param geren - O gerenciador de pacotes que terá um pacote impresso
 * @param idx - O índice do pacote a ser impresso (começa em zero!)
 *
 */
void ImprimirPacoteNoIndice(tGerenciador* geren, int idx){
    ImprimePacote(geren->pacs[idx]);
}


/**
 * @brief Imprime todos os pacotes de um gerenciador de pacotes
 *
 * @param geren O gerenciador de pacotes que terá seus pacotes impressos
 *
 */
void ImprimirTodosPacotes(tGerenciador* geren){
    for(int i = 0; i < geren->tamGeren; i++){
        ImprimirPacoteNoIndice(geren, i);
    }
}
