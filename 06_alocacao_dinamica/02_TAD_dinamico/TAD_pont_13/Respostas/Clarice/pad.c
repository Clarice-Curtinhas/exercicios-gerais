/**
 * @file pad.h
 * @brief Este arquivo contém a declaração da estrutura de dados e funções relacionadas a ela.
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "lesao.h"
#include "paciente.h"
#include "data.h"

#define DIA_PAD 15 /**< Dia de preenchimento do PAD. */
#define MES_PAD 10 /**< Mês de preenchimento do PAD. */
#define ANO_PAD 2023 /**< Ano de preenchimento do PAD. */

/**
 * @brief Uma estrutura que representa um PAD.
 */
typedef struct pad{ 
    int qtdpacientes; /**< A quantidade de pacientes no PAD. */
    tPaciente* listapacientes[100]; /**< A lista de pacientes do PAD. */
} tPad;

/**
 * @brief Cria um novo PAD.
 * 
 * @return Retorna um ponteiro para a estrutura de dados tPad contendo o novo PAD criado.
 */
tPad* CriaPad(){
    tPad *p;

    p = (tPad*) calloc(1, sizeof(tPad));
    p->qtdpacientes = 0;

    return p;
}

/**
 * @brief Roda o PAD, permitindo que o usuário adicione pacientes e lesões.
 * 
 * @param p Ponteiro para a estrutura de dados tPad contendo o PAD a ser rodado.
 */
void RodaPad(tPad *p){
    char cartao[TAM_CSUS];
    char opcao;
    int lesaoExiste = 0;


    while((scanf("%c\n", &opcao)) == 1 && opcao != 'F'){

        if(opcao == 'P'){
            tPaciente *pac = CriaPaciente();
            LePaciente(pac);
            
            if(p->qtdpacientes < 100){
                p->listapacientes[p->qtdpacientes] = pac;
                p->qtdpacientes++;
            }
        }

        else if(opcao == 'L'){
            lesaoExiste = 0;
            scanf("%[^\n]\n", cartao);
            tLesao *l = CriaLesao();
            LeLesao(l);
            
            for(int i = 0; i < p->qtdpacientes; i++){
                if(strcmp(cartao, GetCartaoSusPaciente(p->listapacientes[i])) == 0){
                    AdicionaLesaoPaciente(p->listapacientes[i], l);
                    lesaoExiste = 1;
                    break;
                }
            }

            if(lesaoExiste == 0){
                LiberaLesao(l);
            }
        }

        else break;
    }
}

/**
 * @brief Imprime um relatório com as informações dos pacientes e lesões do PAD.
 * 
 * @param p Ponteiro para a estrutura de dados tPad contendo o PAD a ser impresso.
 */
void ImprimeRelatorioPad(tPad *p){
    int media = 0, totalLes = 0, totalCir = 0, soma = 0;

    if(p != NULL){
        printf("TOTAL PACIENTES: %d\n", p->qtdpacientes);

        if(p->qtdpacientes != 0){
            for(int i = 0; i < p->qtdpacientes; i++){
                tData *dataHj;
                dataHj = CriaData(DIA_PAD, MES_PAD, ANO_PAD);

                soma += CalculaIdadeData(GetNascimentoPaciente(p->listapacientes[i]), dataHj);
                totalLes += GetQtdLesoesPaciente(p->listapacientes[i]);
                totalCir += GetQtdCirurgiasPaciente(p->listapacientes[i]);

                LiberaData(dataHj);
            }
        }
        
        if(p->qtdpacientes != 0){
            media = soma/p->qtdpacientes;
        }

        printf("MEDIA IDADE (ANOS): %d\n", media);
        printf("TOTAL LESOES: %d\n", totalLes);
        printf("TOTAL CIRURGIAS: %d\n", totalCir);
        printf("LISTA DE PACIENTES:\n");

        if(p->qtdpacientes != 0){
            for(int i = 0; i < p->qtdpacientes; i++){
                ImprimePaciente(p->listapacientes[i]);
            }
        }
    }
}

/**
 * @brief Libera a memória alocada para uma estrutura de dados tPad.
 * 
 * @param p Ponteiro para a estrutura de dados tPad a ser liberada.
 */
void LiberaPad(tPad *p){
    if(p != NULL){
        for(int i = 0; i < p->qtdpacientes; i++){ 
            LiberaPaciente(p->listapacientes[i]);
        }

        free(p);
    }
}
