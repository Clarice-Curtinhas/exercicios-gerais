#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int x;
    int y;
    int sucesso;
} tJogada;

/**
 * Lê uma jogada e retorna uma estrutura do tipo tJogada e define o valor da variavel sucesso.
 * Se a jogada foi lida com sucesso, ou seja, foi lido um valor para x e outro para y, sucesso = 1, caso contrário, sucesso = 0.
 * @return a jogada lida.
 */
tJogada LeJogada(){
    tJogada jogada;

    jogada.x = ObtemJogadaX(jogada);
    jogada.y = ObtemJogadaY(jogada);
    jogada.sucesso = FoiJogadaBemSucedida(jogada);

    return jogada;
}


/**
 * Retorna a coordenada X da jogada.
 * 
 * @param jogada a jogada.
 * 
 * @return a coordenada X da jogada.
 */
int ObtemJogadaX(tJogada jogada){
    int x;
    scanf("%d ", &x);

    return x;
}


/**
 * Retorna a coordenada Y da jogada.
 * 
 * @param jogada a jogada.
 * 
 * @return a coordenada Y da jogada.
 */
int ObtemJogadaY(tJogada jogada){
    int y;
    scanf("%d", &y);

    return y;
}


/**
 * Retorna 1 se a jogada foi bem sucedida e 0 caso contrário.
 * 
 * @param jogada a jogada.
 * 
 * @return 1 se a jogada foi bem sucedida, 0 caso contrário.
 */
int FoiJogadaBemSucedida(tJogada jogada){
    if(jogada.x || jogada.y) return 0;
    else return 1;
}