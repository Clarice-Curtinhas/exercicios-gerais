#include "jogada.h"
#include "jogador.h"
#include "jogo.h"
#include "tabuleiro.h"

#include <stdio.h>
#include <stdlib.h>

int main(){
    tJogo jogo;
    int vez, venceu1 = 0, venceu2 = 0, count = 0;
    int continua = 1;

    while(continua == 1){
        jogo = CriaJogo();
        ComecaJogo(jogo);

        while(AcabouJogo(jogo) == 0 && venceu1 == 0 && venceu2 == 0){

            for(vez = 1; vez <= 2; vez++){

                if(vez == 1){
                    jogo.tabuleiro = JogaJogador(jogo.jogador1, jogo.tabuleiro);
                }

                else{
                    jogo.tabuleiro = JogaJogador(jogo.jogador2, jogo.tabuleiro);
                }
            }

            count++;

            if(count > 5){
                venceu1 = VenceuJogador(jogo.jogador1, jogo.tabuleiro);
                venceu2 = VenceuJogador(jogo.jogador2, jogo.tabuleiro);
            }
        }

        if(venceu1 == 1) printf("JOGADOR 1 Venceu!\n");
        else if(venceu2 == 1) printf("JOGADOR 2 Venceu!\n");
        else printf("EMPATE\n");

        continua = ContinuaJogo();
    }

    return 0;
}