#include "candidato.h"
#include "eleitor.h"

#include <stdio.h>
#include <stdlib.h>


#define MAX_CANDIDATOS_POR_CARGO 3
#define MAX_ELEITORES 10

typedef struct {
    tCandidato presidentes[MAX_CANDIDATOS_POR_CARGO];
    int totalPresidentes;

    tCandidato governadores[MAX_CANDIDATOS_POR_CARGO];
    int totalGovernadores;

    int votosBrancosPresidente;
    int votosNulosPresidente;

    int votosBrancosGovernador;
    int votosNulosGovernador;

    tEleitor eleitores[MAX_ELEITORES];
    int totalEleitores;
    
} tEleicao;

/**
 * @brief Inicializa uma eleição com valores padrão (zerando os votos invalidos).
 * Ainda nessa função, é lido a quantidade de candidatos e os candidatos são lidos e armazenados.
 * @return Eleição inicializada.
 */
tEleicao InicializaEleicao(){
    int candidatosTotal;
    tCandidato cand;
    tEleicao eleicao;

    eleicao.votosBrancosGovernador = 0;
    eleicao.votosBrancosPresidente = 0;

    eleicao.votosNulosGovernador = 0;
    eleicao.votosNulosPresidente = 0;

    eleicao.totalPresidentes = 0;
    eleicao.totalGovernadores = 0;

    scanf("%d\n", &candidatosTotal);

    for(int qnt = 0; qnt < candidatosTotal; qnt++){
        cand = LeCandidato();

        if(ObtemCargo(cand) == 'P' && eleicao.totalPresidentes < MAX_CANDIDATOS_POR_CARGO){
            eleicao.presidentes[eleicao.totalPresidentes] = cand;
            eleicao.totalPresidentes++;
        }

        else if(ObtemCargo(cand) == 'G' && eleicao.totalGovernadores < MAX_CANDIDATOS_POR_CARGO){
            eleicao.governadores[eleicao.totalGovernadores] = cand;
            eleicao.totalGovernadores++;
        }
    }

    return eleicao;
}

/**
 * @brief Realiza uma eleição.
 * Nessa função, é lido a quantidade de eleitores e os eleitores são lidos e armazenados.
 * @param eleicao Eleição a ser realizada.
 * @return Eleição com os resultados da votação.
 */
tEleicao RealizaEleicao(tEleicao eleicao){
    int votaram = 0, votoAnuladoP = 0, votoAnuladoG = 0;
    tEleitor eleitor;

    scanf("%d", &eleicao.totalEleitores);

    if(eleicao.totalEleitores <= MAX_ELEITORES){

        for(int qnt = 0; qnt < eleicao.totalEleitores; qnt++){
            eleitor = LeEleitor();

            if(votaram == 0){
                eleicao.eleitores[votaram] = CriaEleitor(eleitor.id, eleitor.votoP, eleitor.votoG);
                    
                if(eleitor.votoP == 0) eleicao.votosBrancosPresidente++;

                else{
                    for(int presi = 0; presi < eleicao.totalPresidentes; presi++){

                        if(ObtemVotoPresidente(eleicao.eleitores[votaram]) == eleicao.presidentes[presi].id){
                            eleicao.presidentes[presi] = IncrementaVotoCandidato(eleicao.presidentes[presi]);
                            votoAnuladoP = 0;
                            break;
                        }

                        else votoAnuladoP = 1;
                    }

                    if(votoAnuladoP == 1) eleicao.votosNulosPresidente++;
                }

                if(eleitor.votoG == 0) eleicao.votosBrancosGovernador++;

                else{
                    for(int gov = 0; gov < eleicao.totalGovernadores; gov++){
                        if(ObtemVotoGovernador(eleicao.eleitores[votaram]) == eleicao.governadores[gov].id){
                            eleicao.governadores[gov] = IncrementaVotoCandidato(eleicao.governadores[gov]);
                            votoAnuladoG = 0;
                            break;
                        }

                        else votoAnuladoG = 1;
                    }

                    if(votoAnuladoG == 1) eleicao.votosNulosGovernador++;
                }

                votaram++;
            }

            else{
                for(int count = 0; count < votaram; count++){
                    if(EhMesmoEleitor(eleitor, eleicao.eleitores[count])){
                        printf("ELEICAO ANULADA");
                        eleicao.totalEleitores = 0;
                        break;
                    }

                    else{
                        eleicao.eleitores[votaram] = CriaEleitor(eleitor.id, eleitor.votoP, eleitor.votoG);
                        
                        if(eleitor.votoP == 0) eleicao.votosBrancosPresidente++;

                        else{
                            for(int presi = 0; presi < eleicao.totalPresidentes; presi++){

                                if(ObtemVotoPresidente(eleicao.eleitores[votaram]) == eleicao.presidentes[presi].id){
                                    eleicao.presidentes[presi] = IncrementaVotoCandidato(eleicao.presidentes[presi]);
                                    votoAnuladoP = 0;
                                    break;
                                }

                                else votoAnuladoP = 1;
                            }

                            if(votoAnuladoP == 1) eleicao.votosNulosPresidente++;
                        }

                        if(eleitor.votoG == 0) eleicao.votosBrancosGovernador++;

                        else{
                            for(int gov = 0; gov < eleicao.totalGovernadores; gov++){
                                if(ObtemVotoGovernador(eleicao.eleitores[votaram]) == eleicao.governadores[gov].id){
                                    eleicao.governadores[gov] = IncrementaVotoCandidato(eleicao.governadores[gov]);
                                    votoAnuladoG = 0;
                                    break;
                                }

                                else votoAnuladoG = 1;
                            }

                            if(votoAnuladoG == 1) eleicao.votosNulosGovernador++;
                        }

                        votaram++;
                        break;
                    }
                }
            }

            if(eleicao.totalEleitores == 0) break;
        }
    }

    else{
        printf("ELEICAO ANULADA");
        eleicao.totalEleitores = 0;
    }

    return eleicao;
}

/**
 * @brief Imprime o resultado da eleição na tela a partir da aparucao dos votos.
 * @param eleicao Eleição a ser impressa.
 */
void ImprimeResultadoEleicao(tEleicao eleicao){
    int vencendoP, votosVencedorP = 0, votosViceP = 0, viceP;
    int vencendoG, votosVencedorG = 0, votosViceG = 0, viceG;

    if(eleicao.totalEleitores != 0){
        for(int qnt = 0; qnt < eleicao.totalPresidentes; qnt++){
            if(ObtemVotos(eleicao.presidentes[qnt]) > votosVencedorP){
                vencendoP = qnt;
                votosVencedorP = ObtemVotos(eleicao.presidentes[qnt]);
            }

            else if(ObtemVotos(eleicao.presidentes[qnt]) == votosVencedorP){
                votosViceP = ObtemVotos(eleicao.presidentes[qnt]);
                viceP = qnt;
            }
        }

        printf("- PRESIDENTE ELEITO: ");

        if(votosVencedorP >= (eleicao.votosBrancosPresidente + eleicao.votosNulosPresidente)){
            if(votosVencedorP == votosViceP && EhMesmoCandidato(eleicao.presidentes[vencendoP], eleicao.presidentes[viceP]) == 0){
                printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
            }

            else ImprimeCandidato(eleicao.presidentes[vencendoP], CalculaPercentualVotos(eleicao.presidentes[vencendoP], eleicao.totalEleitores));
        }

        else if((votosVencedorP == votosViceP) && (EhMesmoCandidato(eleicao.presidentes[vencendoP], eleicao.presidentes[viceP]) == 0)){
            printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
        }

        else{
            printf("SEM DECISAO\n");
        }


        for(int qnt = 0; qnt < eleicao.totalGovernadores; qnt++){
            if(ObtemVotos(eleicao.governadores[qnt]) > votosVencedorG){
                vencendoG = qnt;
                votosVencedorG = ObtemVotos(eleicao.governadores[qnt]);
            }

            else if(ObtemVotos(eleicao.governadores[qnt]) == votosVencedorG){
                votosViceG = ObtemVotos(eleicao.governadores[qnt]);
                viceG = qnt;
            }
        }

        printf("- GOVERNADOR ELEITO: ");

        if(votosVencedorG >= (eleicao.votosBrancosGovernador + eleicao.votosNulosGovernador)){
            if((votosVencedorG == votosViceG) && EhMesmoCandidato(eleicao.governadores[vencendoG], eleicao.governadores[viceG]) == 0){
                printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
            }

            else ImprimeCandidato(eleicao.governadores[vencendoG], CalculaPercentualVotos(eleicao.governadores[vencendoG], eleicao.totalEleitores));
        }

        else if((votosVencedorG == votosViceG) && (EhMesmoCandidato(eleicao.governadores[vencendoG], eleicao.governadores[viceG]) == 0)){
            printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
        }

        else{
            printf("SEM DECISAO\n");
        }

        printf("- NULOS E BRANCOS: %d, %d", (eleicao.votosNulosGovernador+eleicao.votosNulosPresidente),(eleicao.votosBrancosGovernador+eleicao.votosBrancosPresidente));
    }
}