#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef struct{
    int x;
    int y;
}tCoordenadas;

typedef struct{
    int mapa[100][100];
}tMapa;

void Jogo(int colunas, int linhas, tMapa mapa, tCoordenadas jogador, tCoordenadas final, char *prioridade, int qntCom);
void printarPosicoes(tCoordenadas *registraPosicoes, int posicoes);

int main(){
    tCoordenadas jogador;
    tCoordenadas finalDesejado;
    tMapa mapa;

    int colunas, linhas;
    int countColunas, countLinhas;
    int qntComandos, qntPrioridades;
    char prioridade[4];

    qntComandos = 4;

    scanf("%d %d\n", &linhas, &colunas);

    for(countLinhas = 0; countLinhas < linhas; countLinhas++){
        for(countColunas = 0; countColunas < colunas; countColunas++){
            scanf("%d ", &mapa.mapa[countColunas][countLinhas]);
        }
        scanf("\n");
    }

    scanf("%d %d\n", &jogador.x, &jogador.y);

    scanf("%d %d\n", &finalDesejado.x, &finalDesejado.y);

    for(qntPrioridades = 0; qntPrioridades < qntComandos; qntPrioridades++){
        scanf("%c", &prioridade[qntPrioridades]);
    }

    Jogo(colunas, linhas, mapa, jogador, finalDesejado, prioridade, qntComandos);

    return 0;
}

void Jogo(int colunas, int linhas, tMapa mapa, tCoordenadas jogador, tCoordenadas final, char *prioridade, int qntCom){
    int qntPrio;
    int posicoes;
    int pass;
    pass = 0;

    tCoordenadas jogadorMatriz;
    tCoordenadas registraPosicoes[400];

    registraPosicoes[0].x = jogador.x;
    registraPosicoes[0].y = jogador.y;

    jogadorMatriz.x = jogador.x-1;
    jogadorMatriz.y = jogador.y-1;

    posicoes = 1;

    mapa.mapa[jogadorMatriz.y][jogadorMatriz.x] = 5;

    for(qntPrio = 0; qntPrio < qntCom; qntPrio++){

        if(prioridade[qntPrio] == 'E' && mapa.mapa[jogadorMatriz.y-1][jogadorMatriz.x] == 0 && jogadorMatriz.y-1 >= 0){
            jogador.y -= 1;
            jogadorMatriz.y -= 1;
            mapa.mapa[jogadorMatriz.y][jogadorMatriz.x] = 5;

            registraPosicoes[posicoes].x = jogador.x;
            registraPosicoes[posicoes].y = jogador.y;
            posicoes++;

            qntPrio = -1;
            pass = 0;
        }

        else if(prioridade[qntPrio] == 'D' && mapa.mapa[jogadorMatriz.y+1][jogadorMatriz.x] == 0 && jogadorMatriz.y+1 < colunas){
            jogador.y += 1;
            jogadorMatriz.y += 1;
            mapa.mapa[jogadorMatriz.y][jogadorMatriz.x] = 5;

            registraPosicoes[posicoes].x = jogador.x;
            registraPosicoes[posicoes].y = jogador.y;
            posicoes++;

            qntPrio = -1;
            pass = 0;
        }

        else if(prioridade[qntPrio] == 'B' && mapa.mapa[jogadorMatriz.y][jogadorMatriz.x+1] == 0 && jogadorMatriz.x+1 < linhas){
            jogador.x += 1;
            jogadorMatriz.x += 1;
            mapa.mapa[jogadorMatriz.y][jogadorMatriz.x] = 5;

            registraPosicoes[posicoes].x = jogador.x;
            registraPosicoes[posicoes].y = jogador.y;
            posicoes++;

            qntPrio = -1;
            pass = 0;
        }

        else if(prioridade[qntPrio] == 'C' && mapa.mapa[jogadorMatriz.y][jogadorMatriz.x-1] == 0 && jogadorMatriz.x-1 >= 0){
            jogador.x -= 1;
            jogadorMatriz.x -= 1;
            mapa.mapa[jogadorMatriz.y][jogadorMatriz.x] = 5;

            registraPosicoes[posicoes].x = jogador.x;
            registraPosicoes[posicoes].y = jogador.y;
            posicoes++;

            qntPrio = -1;
            pass = 0;
        }

        else pass++;

        if(pass == 4 || (jogador.x == final.x && jogador.y == final.y)) break;
    }

    printarPosicoes(registraPosicoes, posicoes);
}

void printarPosicoes(tCoordenadas *registraPosicoes, int posicoes){
    int qntPosicoes;

    for(qntPosicoes = 0; qntPosicoes < posicoes; qntPosicoes++){
        printf("(%d,%d) ", registraPosicoes[qntPosicoes].x, registraPosicoes[qntPosicoes].y);
    }
}