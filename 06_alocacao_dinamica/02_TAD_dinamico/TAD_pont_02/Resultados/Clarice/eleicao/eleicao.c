#include <stdio.h>
#include <stdlib.h>

#include "candidato.h"
#include "eleitor.h"


// #define MAX_CANDIDATOS_POR_CARGO 3
// #define MAX_ELEITORES 10

typedef struct {
    tCandidato** presidentes;
    int totalPresidentes;

    tCandidato** governadores;
    int totalGovernadores;

    int votosBrancosPresidente;
    int votosNulosPresidente;

    int votosBrancosGovernador;
    int votosNulosGovernador;

    tEleitor** eleitores;
    int totalEleitores;
    
} tEleicao;

/**
 * @brief Inicializa uma eleição com valores padrão (zerando as variáveis que armazenam votos).
 * Ainda nessa função, é lido a quantidade de candidatos e os candidatos são lidos e armazenados
 * A memória necessária para os vetores "presidentes", "governadores" deve ser alocada aqui.
 * Demais ponteiros devem ser inicializado com NULL.
 * @return Eleição inicializada.
 */
tEleicao* InicializaEleicao(){
    int totalCand;
    tEleicao *eleicao;

    eleicao = (tEleicao*) calloc(1, sizeof(tEleicao));

    eleicao->presidentes = (tCandidato**) calloc(1, sizeof(tCandidato*));
    eleicao->governadores = (tCandidato**) calloc(1, sizeof(tCandidato*));

    eleicao->totalPresidentes = 0;
    eleicao->totalGovernadores = 0;

    scanf("%d\n", &totalCand);

    for(int i = 0; i < totalCand; i++){
        tCandidato *cand;
        cand = CriaCandidato();
        LeCandidato(cand);

        if(ObtemCargo(cand) == 'P'){
            eleicao->presidentes[eleicao->totalPresidentes] = cand;
            eleicao->totalPresidentes++;
            eleicao->presidentes = (tCandidato**) realloc(eleicao->presidentes, (eleicao->totalPresidentes+1)*sizeof(tCandidato*));
        }

        else if(ObtemCargo(cand) == 'G'){
            eleicao->governadores[eleicao->totalGovernadores] = cand;
            eleicao->totalGovernadores++;
            eleicao->governadores = (tCandidato**) realloc(eleicao->governadores, (eleicao->totalGovernadores+1)*sizeof(tCandidato*));
        }
    }

    eleicao->eleitores = (tEleitor**) calloc(1, sizeof(tEleitor*));
    eleicao->eleitores[0] = NULL;

    eleicao->votosBrancosPresidente = 0;
    eleicao->votosNulosPresidente = 0;

    eleicao->votosBrancosGovernador = 0;
    eleicao->votosNulosGovernador = 0;

    eleicao->totalEleitores = 0;

    return eleicao;
}


void ApagaEleicao(tEleicao* eleicao){
    for(int i = 0; i < eleicao->totalPresidentes; i++){
        ApagaCandidato(eleicao->presidentes[i]);
    }
    
    for(int i = 0; i < eleicao->totalGovernadores; i++){
        ApagaCandidato(eleicao->governadores[i]);
    }

    for(int i = 0; i < eleicao->totalEleitores; i++){
        ApagaEleitor(eleicao->eleitores[i]);
    }

    free(eleicao->presidentes);
    free(eleicao->governadores);
    free(eleicao->eleitores);

    free(eleicao);
}

/**
 * @brief Realiza uma eleição.
 * Nessa função, é lido a quantidade de eleitores e os eleitores são lidos e armazenados.
 * @param eleicao Eleição a ser realizada. 
 */
void RealizaEleicao(tEleicao* eleicao){
    int votouP = 0, votouG = 0;

    scanf("%d\n", &eleicao->totalEleitores);

    eleicao->eleitores = (tEleitor**) realloc(eleicao->eleitores, (eleicao->totalEleitores) * sizeof(tEleitor*));

    for(int i = 0; i < eleicao->totalEleitores; i++){
        eleicao->eleitores[i] = CriaEleitor();
        LeEleitor(eleicao->eleitores[i]);

        if(ObtemVotoPresidente(eleicao->eleitores[i]) != 0){
            for(int j = 0; j < eleicao->totalPresidentes; j++){
                if(VerificaIdCandidato(eleicao->presidentes[j], ObtemVotoPresidente(eleicao->eleitores[i])) == 1){
                    IncrementaVotoCandidato(eleicao->presidentes[j]);
                    votouP = 1;
                    break;
                }
            }

            if(votouP == 0) eleicao->votosNulosPresidente++;
        }

        else eleicao->votosBrancosPresidente++;

        if(ObtemVotoGovernador(eleicao->eleitores[i]) != 0){
            for(int j = 0; j < eleicao->totalGovernadores; j++){
                if(VerificaIdCandidato(eleicao->governadores[j], ObtemVotoGovernador(eleicao->eleitores[i])) == 1){
                    IncrementaVotoCandidato(eleicao->governadores[j]);
                    votouG = 1;
                    break;
                }
            }

            if(votouG == 0) eleicao->votosNulosGovernador++;
        }

        else eleicao->votosBrancosGovernador++;

        votouP = 0;
        votouG = 0;
    }
}

/**
 * @brief Imprime o resultado da eleição na tela a partir da aparucao dos votos.
 * @param eleicao Eleição a ser impressa.
 */
void ImprimeResultadoEleicao(tEleicao* eleicao){
    int totalBrancos = 0, totalNulos = 0, iguaisG = 0, iguaisP = 0;
    int ganhandoP = 0, ganhandoG = 0, iGanhandoP = -1, iGanhandoG = -1;
    int jaVotou = 0;

    for(int i = 0; i < eleicao->totalEleitores; i++){
        for(int j = i+1; j < eleicao->totalEleitores; j++){
            if(EhMesmoEleitor(eleicao->eleitores[i], eleicao->eleitores[j]) == 1){
                printf("ELEICAO ANULADA\n");
                jaVotou = 1;
                break;
            }
        }

        if(jaVotou == 1) break;
    }

    if(jaVotou == 0){
        printf("- PRESIDENTE ELEITO: ");

        for(int i = 0; i < eleicao->totalPresidentes; i++){
            if(ganhandoP < ObtemVotos(eleicao->presidentes[i])){
                ganhandoP = ObtemVotos(eleicao->presidentes[i]);
                iGanhandoP = i;
                iguaisP = 0;
            }

            else if(ganhandoP == ObtemVotos(eleicao->presidentes[i])) iguaisP = 1;
        }

        if(iguaisP == 1){
            printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
        }

        else if(ganhandoP < (eleicao->votosBrancosPresidente + eleicao->votosNulosPresidente)){
            printf("SEM DECISAO\n");
        }

        else{
            ImprimeCandidato(eleicao->presidentes[iGanhandoP], CalculaPercentualVotos(eleicao->presidentes[iGanhandoP], eleicao->totalEleitores));
        }

        printf("- GOVERNADOR ELEITO: ");

        for(int i = 0; i < eleicao->totalGovernadores; i++){
            if(ganhandoG < ObtemVotos(eleicao->governadores[i])){
                ganhandoG = ObtemVotos(eleicao->governadores[i]);
                iGanhandoG = i;
                iguaisG = 0;
            }

            else if(ganhandoG == ObtemVotos(eleicao->governadores[i])) iguaisG = 1;
        }

        if(iguaisG == 1){
            printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
        }

        else if(ganhandoG < (eleicao->votosBrancosGovernador + eleicao->votosNulosGovernador)){
            printf("SEM DECISAO\n");
        }

        else{
            ImprimeCandidato(eleicao->governadores[iGanhandoG], CalculaPercentualVotos(eleicao->governadores[iGanhandoG], eleicao->totalEleitores));
        }

        totalBrancos = eleicao->votosBrancosGovernador + eleicao->votosBrancosPresidente;
        totalNulos = eleicao->votosNulosGovernador + eleicao->votosNulosPresidente;

        printf("- NULOS E BRANCOS: %d, %d", totalNulos, totalBrancos);
    }
}
