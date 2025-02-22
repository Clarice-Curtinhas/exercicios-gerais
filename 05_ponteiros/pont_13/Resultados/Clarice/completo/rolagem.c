#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_MAX_MSG 1000
#define NUM_MAX_MSGS 10

/**
 * @brief Ponteiro para função que recebe um array de mensagens e o número de mensagens para rolagem.
 * 
 * @param msg Array de mensagens.
 * @param numMsgs Número de mensagens.
 */
typedef void (*FptrMsg)(char msg[NUM_MAX_MSGS][TAM_MAX_MSG], int * numMsgs);

/**
 * @brief Dispara a função de rolagem de mensagens.
 * 
 * @param FuncMsg Ponteiro para a função que recebe um array de mensagens e o número de mensagens.
 * @param tamanhoDisplay Tamanho do display.
 * @param tempoFim Tempo de duração da rolagem, que diz respeito a quantidade de deslocamento no painel.
 */
void RolaMsg(FptrMsg FuncMsg, int tamanhoDisplay, int tempoFim){
    int tempo = 0, *qntMensag, rolar = 0;
    int i, tam = 0;
    char m[TAM_MAX_MSG * TAM_MAX_MSG], mensagem[NUM_MAX_MSGS][TAM_MAX_MSG];

    FuncMsg(mensagem, qntMensag);

    scanf("%d\n", &tempoFim);

    for(i = 0; i < *qntMensag; i++){
        printf("%s\n", mensagem[i]);
        strcat(m, mensagem[i]);
    }

    /*while(tempoFim > tempo){
        for( i = 0; i < tamanhoDisplay; i++){
            if(m[i+rolar] == '\0') rolar = 0;

            printf("%c", m[i+rolar]);
        }

        printf("\033[H\033[J");
        tempo++;
        rolar++;
    }*/
}
