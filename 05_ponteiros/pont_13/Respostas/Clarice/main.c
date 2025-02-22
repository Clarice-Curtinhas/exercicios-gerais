#include <stdio.h>
#include <stdlib.h>

#include "rolagem.h"
#define TAM_DISPLAY 30

void Mensagem(char msg[NUM_MAX_MSGS][TAM_MAX_MSG], int * numMsgs);

int main(){
    int qntMensag, i;
    char mensagens[NUM_MAX_MSGS][TAM_MAX_MSG];
    int tempo = 30;

    RolaMsg(Mensagem, TAM_DISPLAY, tempo);

    return 0;
}

void Mensagem(char msg[NUM_MAX_MSGS][TAM_MAX_MSG], int * numMsgs){
    scanf("%d\n", numMsgs);

    for(int i = 0; i < *numMsgs; i++){
        scanf("%*c -");
        scanf("%[^\n]\n", msg[i]);
    }
}