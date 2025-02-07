#include <stdio.h>
#include <stdlib.h>

#include "jogador.h"
#include "tabuleiro.h"
#include "jogo.h"

/*typedef struct{
    tTabuleiro* tabuleiro;
    tJogador* jogador1;
    tJogador* jogador2;
    
} tJogo;*/

/**
 * Aloca e retorna uma estrutura do tipo tJogo.
 * Se a alocação falhar, o programa é encerrado.
 * 
 * @return a estrutura do tipo tJogo alocada.
 */
tJogo* CriaJogo(){
    tJogo *jogo;

    jogo = (tJogo*) calloc(1, sizeof(tJogo));

    return jogo;
}


/**
 * Inicia o jogo, definindo o tabuleiro e os jogadores.
 * 
 * @param jogo o jogo a ser iniciado.
 */
void ComecaJogo(tJogo* jogo){
    int vez;

    vez = 1;

    jogo->tabuleiro = CriaTabuleiro();
    jogo->jogador1 = CriaJogador(1);
    jogo->jogador2 = CriaJogador(2);

    while(AcabouJogo(jogo) == 0){
        if(vez == 1){
            JogaJogador(jogo->jogador1, jogo->tabuleiro);
            vez++;
        }

        else if(vez == 2){
            JogaJogador(jogo->jogador2, jogo->tabuleiro);
            vez--;
        }

        ImprimeTabuleiro(jogo->tabuleiro);
    }

    if((VenceuJogador(jogo->jogador1, jogo->tabuleiro)) == 1) printf("JOGADOR 1 Venceu!\n");
    else if((VenceuJogador(jogo->jogador2, jogo->tabuleiro)) == 1) printf("JOGADOR 2 Venceu!\n");
    else printf("Sem vencedor!\n");
}


/**
 * Verifica se o jogo acabou (se não há mais posições livres no tabuleiro).
 * 
 * @param jogo o jogo atual.
 * 
 * @return 1 se o jogo acabou, 0 caso contrário.
 */
int AcabouJogo(tJogo* jogo){
    if(TemPosicaoLivreTabuleiro(jogo->tabuleiro) == 0) return 1;

    else if((VenceuJogador(jogo->jogador1, jogo->tabuleiro)) == 1) return 1;

    else if((VenceuJogador(jogo->jogador2, jogo->tabuleiro)) == 1) return 1;

    return 0;
}


/**
 * Verifica se o usuário deseja jogar novamente.
 * 
 * @return 1 se o usuário deseja jogar novamente, 0 caso contrário.
 */
int ContinuaJogo(){
    char opcao;

    printf("Jogar novamente? (s,n)\n");
    while((scanf("%c", &opcao)) == 1 && (opcao != 's' && opcao != 'n'));
    scanf("\n");

    return (opcao == 's');
}


/**
 * Libera a memória de uma estrutura do tipo tJogo.
 * 
 * @param jogo a estrutura do tipo tJogo a ser liberada.
 */
void DestroiJogo(tJogo* jogo){

    DestroiTabuleiro(jogo->tabuleiro);
    DestroiJogador(jogo->jogador1);
    DestroiJogador(jogo->jogador2);

    free(jogo);
}
