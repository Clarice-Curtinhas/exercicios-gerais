/**
 * @file pad.h
 * @brief Este arquivo contém a declaração da estrutura de dados e funções relacionadas a ela.
 */


#include "lesao.h"
#include "paciente.h"

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
    char opcao;

    scanf("%c\n", &opcao);

    while(opcao != 'F'){
        if(opcao == 'P'){
            tPaciente *pac = CriaPaciente();
            LePaciente(pac);
            
            if(p->qtdpacientes < 100){
                p->listapacientes[p->qtdpacientes] = pac;
                p->qtdpacientes++;
            }
        }
        scanf("%c\n", &opcao);
    }
}

/**
 * @brief Imprime um relatório com as informações dos pacientes e lesões do PAD.
 * 
 * @param p Ponteiro para a estrutura de dados tPad contendo o PAD a ser impresso.
 */
void ImprimeRelatorioPad(tPad *p);

/**
 * @brief Libera a memória alocada para uma estrutura de dados tPad.
 * 
 * @param p Ponteiro para a estrutura de dados tPad a ser liberada.
 */
void LiberaPad(tPad *p){
    free(p->listapacientes);
    free(p);
}
