#include <stdio.h>
#include <stdlib.h>

#include "tabuleiro.h"
#include "jogada.h"


#define ID_JOGADOR_1 1
#define ID_JOGADOR_2 2

typedef struct{
    int id;
} tJogador;

/**
 * Aloca e retorna uma estrutura do tipo tJogador.
 * Se a alocação falhar, o programa é encerrado.
 *
 *  @param idJogador o ID do jogador (1 ou 2).
 * 
 * @return a estrutura do tipo tJogador alocada.
 */
tJogador* CriaJogador(int idJogador){
    tJogador *j;

    j = (tJogador*) calloc(1, sizeof(tJogador));

    j->id = idJogador;

    return j;
}


/**
 * Libera a memória de uma estrutura do tipo tJogador.
 * 
 * @param jogador a estrutura do tipo tJogador a ser liberada.
 */
void DestroiJogador(tJogador* jogador){
    free(jogador);
}


/**
 * Lê uma jogada e armazena em uma estrutura do tipo tJogada.
 * 
 * @param jogador o jogador atual.
 * @param tabuleiro o tabuleiro atual.
 */
void JogaJogador(tJogador* jogador, tTabuleiro* tabuleiro){
    int jogou = 0;
    tJogada *jogada;
    jogada = CriaJogada();

    while(jogou == 0){
        printf("Jogador %d\n", jogador->id);
        LeJogada(jogada);

        if(EhPosicaoValidaTabuleiro(ObtemJogadaX(jogada), ObtemJogadaY(jogada)) == 1){

            if(EstaLivrePosicaoTabuleiro(tabuleiro, ObtemJogadaX(jogada), ObtemJogadaY(jogada)) == 1){
                printf("Jogada [%d,%d]!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
                MarcaPosicaoTabuleiro(tabuleiro, jogador->id, ObtemJogadaX(jogada), ObtemJogadaY(jogada));
                jogou = 1;
            }

            else printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
        }

        else if(FoiJogadaBemSucedida(jogada) == 0) printf("Jogada invalida!\n");

        else printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
    }

    DestroiJogada(jogada);
}


/**
 * Verifica se o jogador venceu o jogo.
 * 
 * @param jogador o jogador atual.
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return 1 se o jogador venceu, 0 caso contrário.
 */
int VenceuJogador(tJogador* jogador, tTabuleiro* tabuleiro){
    int horiz, vert, diag1 = 0, diag2 = 0;

    for(int j = 0; j < TAM_TABULEIRO; j++){
        horiz = 0;
        vert = 0;

        for(int i = 0; i < TAM_TABULEIRO; i++){
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, i, j, jogador->id) == 1) horiz++;
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, j, i, jogador->id) == 1) vert++;
        }

        if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, j, j, jogador->id) == 1) diag1++;
        if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, TAM_TABULEIRO-j-1, j, jogador->id) == 1) diag2++;

        if(horiz == TAM_TABULEIRO || vert == TAM_TABULEIRO || diag1 == TAM_TABULEIRO || diag2 == TAM_TABULEIRO) return 1;
    }

    return 0;
}
