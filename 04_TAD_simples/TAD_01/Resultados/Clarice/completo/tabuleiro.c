#define TAM_TABULEIRO 3
#define PECA_1 1
#define PECA_2 2

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char posicoes[TAM_TABULEIRO][TAM_TABULEIRO];
    char peca1;
    char peca2;
    char pecaVazio;
} tTabuleiro;

/**
 * Cria um tabuleiro e retorna o tabuleiro criado.
 * 
 * @return o tabuleiro criado.
 */
tTabuleiro CriaTabuleiro(){
    int larg, alt;
    tTabuleiro tabuleiro;

    tabuleiro.peca1 = 'X';
    tabuleiro.peca2 = '0';
    tabuleiro.pecaVazio = '-';

    for(alt = 0; alt < TAM_TABULEIRO; alt++){
        for(larg = 0; larg < TAM_TABULEIRO; larg++){
            tabuleiro.posicoes[larg][alt] = tabuleiro.pecaVazio;
        }
    }

    return tabuleiro;
}


/**
 * Marca uma posição do tabuleiro com a peça do jogador e retorna o tabuleiro.
 * 
 * @param tabuleiro o tabuleiro atual.
 * @param peca a peça do jogador (1 ou 2).
 * @param x a coordenada x da posição a ser marcada.
 * @param y a coordenada y da posição a ser marcada.
 * 
 * @return o tabuleiro atualizado.
 */
tTabuleiro MarcaPosicaoTabuleiro(tTabuleiro tabuleiro, int peca, int x, int y){
    if(peca == PECA_1) tabuleiro.posicoes[x][y] = tabuleiro.peca1;
    else tabuleiro.posicoes[x][y] = tabuleiro.peca2;
}


/**
 * Verifica se há alguma posição livre no tabuleiro.
 * 
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return 1 se há posição livre, 0 caso contrário.
 */
int TemPosicaoLivreTabuleiro(tTabuleiro tabuleiro){
    int larg, alt;

    for(alt = 0; alt < TAM_TABULEIRO; alt++){
        for(larg = 0; larg < TAM_TABULEIRO; larg++){
            printf("%c", tabuleiro.posicoes[larg][alt]);

            if(tabuleiro.posicoes[larg][alt] == tabuleiro.pecaVazio) return 1;
        }
        printf("\n");
    }

    return 0;
}


/**
 * Verifica se a posição do tabuleiro está marcada com a peça do jogador.
 * 
 * @param tabuleiro - o tabuleiro atual.
 * @param x a coordenada x da posição a ser verificada.
 * @param y a coordenada y da posição a ser verificada.
 * @param peca a peça do jogador (1 ou 2).
 * 
 * @return 1 se a posição está marcada com a peça do jogador, 0 caso contrário.
 */
int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro tabuleiro, int x, int y, int peca){
    if(tabuleiro.posicoes[x][y] == tabuleiro.peca1 && peca == PECA_1) return 1;
    else if(tabuleiro.posicoes[x][y] == tabuleiro.peca2 && peca == PECA_2) return 1;
    else return 0;
}


/**
 * Verifica se a posição do tabuleiro está livre.
 * 
 * @param tabuleiro o tabuleiro atual.
 * @param x a coordenada x da posição a ser verificada.
 * @param y a coordenada y da posição a ser verificada.
 * 
 * @return 1 se a posição está livre, 0 caso contrário.
 */
int EstaLivrePosicaoTabuleiro(tTabuleiro tabuleiro, int x, int y){
    if(tabuleiro.posicoes[x][y] == tabuleiro.pecaVazio) return 1;
    else return 0;
}

/**
 * Verifica se a posição do tabuleiro é válida.
 * 
 * @param x a coordenada x da posição a ser verificada.
 * @param y a coordenada y da posição a ser verificada.
 * @return 1 se a posição é válida, 0 caso contrário.
*/
int EhPosicaoValidaTabuleiro(int x, int y){
    if(x >= 0 && x < TAM_TABULEIRO && y >= 0 && y < TAM_TABULEIRO) return 1;
    else return 0;
}


/**
 * Verifica se o tabuleiro está cheio.
 * 
 * @param tabuleiro o tabuleiro atual.
 */
void ImprimeTabuleiro(tTabuleiro tabuleiro){
    int larg, alt;

    for(alt = 0; alt < TAM_TABULEIRO; alt++){
        printf("	");
        for(larg = 0; larg < TAM_TABULEIRO; larg++){
            printf("%c", tabuleiro.posicoes[larg][alt]);
        }

        printf("\n");
    }
}