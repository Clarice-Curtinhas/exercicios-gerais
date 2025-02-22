#include "tabuleiro.h"

#include <stdio.h>
#include <stdlib.h>

#define ID_JOGADOR_1 1
#define ID_JOGADOR_2 2


typedef struct{
    int id;
} tJogador;


/**
 * Cria um jogador com o id passado como parâmetro e retorna o jogador criado.
 * 
 * @param idJogador o id do jogador (1 ou 2).
 * 
 * @return tJogador o jogador criado.
 */
tJogador CriaJogador(int idJogador){
    tJogador pessoa;

    pessoa.id = idJogador;

    return pessoa;
}


/**
 * Recebe um jogador e um tabuleiro e retorna o tabuleiro com a jogada do jogador.
 * 
 * @param jogador o jogador que fará a jogada.
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return o tabuleiro atualizado com a jogada do jogador.
 */
tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro){
    int continua = 1;
    tJogada jogada;

    while(continua == 1){
        printf("Jogador %d\n", jogador.id);
        printf("Digite uma posicao (x e y):\n");

        jogada = LeJogada();

        if(FoiJogadaBemSucedida(jogada) == 1){
            if(EhPosicaoValidaTabuleiro(ObtemJogadaX(jogada), ObtemJogadaY(jogada)) == 1){

                if(EstaLivrePosicaoTabuleiro(tabuleiro, ObtemJogadaX(jogada), ObtemJogadaY(jogada)) == 1){

                    printf("Jogada [%d,%d]!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));

                    tabuleiro = MarcaPosicaoTabuleiro(tabuleiro, jogador.id, ObtemJogadaX(jogada), ObtemJogadaY(jogada));

                    ImprimeTabuleiro(tabuleiro);
                    continua = 0;
                }

                else{
                    printf("Posicao invalida (OCUPADA - [%d,%d])!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
                }
            }

            else{
                printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d])!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
            }
        }
    }

    return tabuleiro;
}

/**
 * Recebe um jogador e um tabuleiro e retorna 1 se o jogador venceu e 0 caso contrário.
 * 
 * @param jogador o jogador a ser verificado.
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return 1 se o jogador venceu, 0 caso contrário.
 */
int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro){
    int test1, test2;
    int horiz = 0, vert = 0, diag = 0;

    for(test1 = 0; test1 < 3; test1++){
        horiz = 0;
        vert = 0;
        diag = 0;

        for(test2 = 0; test2 < 3; test2++){
            horiz += EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, test2, test1, jogador.id);
            vert += EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, test1, test2, jogador.id);

            if(test1 == 0) diag += EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, test2, test2, jogador.id);
            else if(test1 == 1) diag += EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, (2 - test2), test2, jogador.id);
        }

        if(horiz == 3 || vert == 3){
            return 1;
        }
    }

    return 0;
}