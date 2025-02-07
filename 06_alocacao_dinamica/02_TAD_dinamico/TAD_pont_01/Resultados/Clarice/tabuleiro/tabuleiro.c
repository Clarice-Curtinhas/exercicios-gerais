#include <stdio.h>
#include <stdlib.h>

#define TAM_TABULEIRO 3
#define PECA_1 1
#define PECA_2 2

typedef struct{
    char** posicoes;
    char peca1;
    char peca2;
    char pecaVazio;
} tTabuleiro;

/**
 * Aloca e retorna uma estrutura do tipo tTabuleiro.
 * Se a alocação falhar, o programa é encerrado.
 * 
 * @return a estrutura do tipo tTabuleiro alocada.
 */
tTabuleiro* CriaTabuleiro(){
    tTabuleiro *t;
    t = (tTabuleiro*) calloc(1, sizeof(tTabuleiro));

    t->peca1 = 'X';
    t->peca2 = '0';
    t->pecaVazio = '-';

    t->posicoes = (char**) calloc(TAM_TABULEIRO+1, sizeof(char*));

    for(int i = 0; i < TAM_TABULEIRO; i++){
        t->posicoes[i] = (char*) calloc(TAM_TABULEIRO+1, sizeof(char));
    }

    for(int j = 0; j < TAM_TABULEIRO; j++){
        for(int i = 0; i < TAM_TABULEIRO; i++){
            t->posicoes[j][i] = t->pecaVazio;
        }
    }

    return t;
}


/**
 * Libera a memória de uma estrutura do tipo tTabuleiro.
 * 
 * @param tabuleiro a estrutura do tipo tTabuleiro a ser liberada.
 */
void DestroiTabuleiro(tTabuleiro* tabuleiro){
    if(tabuleiro != NULL){
        for(int i = 0; i < TAM_TABULEIRO+1; i++){
            free(tabuleiro->posicoes[i]);
        }

        free(tabuleiro->posicoes);
        free(tabuleiro);
    }
}


/**
 * Marca uma posição do tabuleiro com a peça do jogador.
 * 
 * @param tabuleiro o tabuleiro atual.
 * @param peca a peça do jogador (1 ou 2).
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 */
void MarcaPosicaoTabuleiro(tTabuleiro* tabuleiro, int peca, int x, int y){
    if(peca == PECA_1) tabuleiro->posicoes[y][x] = tabuleiro->peca1;

    else if(peca == PECA_2) tabuleiro->posicoes[y][x] = tabuleiro->peca2;
}


/**
 * Verifica se há alguma posição livre no tabuleiro.
 * 
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return 1 se há alguma posição livre, 0 caso contrário.
 */
int TemPosicaoLivreTabuleiro(tTabuleiro* tabuleiro){
    for(int j = 0; j < TAM_TABULEIRO; j++){
        for(int i = 0; i < TAM_TABULEIRO; i++){
            if(tabuleiro->posicoes[j][i] == tabuleiro->pecaVazio) return 1;
        }
    }

    return 0;
}


/**
 * Verifica se a posição do tabuleiro está marcada com a peça do jogador.
 * 
 * @param tabuleiro - o tabuleiro atual.
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 * @param peca a peça do jogador (1 ou 2).
 * 
 * @return 1 se a posição está marcada com a peça do jogador, 0 caso contrário.
 */
int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro* tabuleiro, int x, int y, int peca){
    if(peca == PECA_1){
        if(tabuleiro->posicoes[y][x] == tabuleiro->peca1) return 1;
    }

    else{
        if(tabuleiro->posicoes[y][x] == tabuleiro->peca2) return 1;
    }

    return 0;
}


/**
 * Verifica se a posição do tabuleiro está livre.
 * 
 * @param tabuleiro o tabuleiro atual.
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 * 
 * @return 1 se a posição está livre, 0 caso contrário.
 */
int EstaLivrePosicaoTabuleiro(tTabuleiro* tabuleiro, int x, int y){
    if(tabuleiro->posicoes[y][x] == tabuleiro->pecaVazio) return 1;
    else return 0;
}


/**
 * Verifica se a posição do tabuleiro é válida.
 * 
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 * 
 * @return 1 se a posição é válida, 0 caso contrário.
 */
int EhPosicaoValidaTabuleiro(int x, int y){
    if((x >= 0 && x < TAM_TABULEIRO) && (y >= 0 && y < TAM_TABULEIRO)) return 1;
    return 0;
}


/**
 * Imprime o tabuleiro.
 * 
 * @param tabuleiro o tabuleiro atual.
 */
void ImprimeTabuleiro(tTabuleiro* tabuleiro){
    for(int j = 0; j < TAM_TABULEIRO; j++){
        printf("    ");
        for(int i = 0; i < TAM_TABULEIRO; i++){
            printf("%c", tabuleiro->posicoes[j][i]);
        }
        printf("\n");
    }
}
