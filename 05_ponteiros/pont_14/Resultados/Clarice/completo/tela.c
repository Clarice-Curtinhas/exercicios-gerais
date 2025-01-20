#include <stdio.h>
#include <stdlib.h>
#include "botao.h"

#define MAX_BOTOES 10 

typedef struct {
    int altura; 
    int largura; 
    Botao botoes[MAX_BOTOES]; 
    int qntBotoes;
} Tela;

/**
 * @brief Cria uma nova tela com a altura e largura especificadas e botões vazios (zero).
 * 
 * @param altura Altura da tela em pixels.
 * @param largura Largura da tela em pixels.
 * @return Tela Retorna a tela criada.
 */
Tela CriarTela(int altura, int largura){
    Tela tela;

    tela.altura = altura;
    tela.largura = largura;
    tela.qntBotoes = 0;

    return tela;
}

/**
 * @brief Registra um botão na tela especificada se houver espaço.
 * 
 * @param t Ponteiro para a tela em que o botão será registrado.
 * @param b Botão a ser registrado na tela.
 */
void RegistraBotaoTela(Tela *t, Botao b){
    if(t->qntBotoes < MAX_BOTOES){
        t->botoes[t->qntBotoes] = CriarBotao(b.texto, b.tamFonte, b.corHex, b.tipo, b.executa);
        t->qntBotoes++;
    }
}

/**
 * @brief Desenha a tela especificada na saída padrão se houver botões registrados.
 * 
 * @param t Tela a ser desenhada.
 */
void DesenhaTela(Tela t){
    if(t.qntBotoes > 0){
        printf("##################\n");
        for(int i = 0; i < t.qntBotoes; i++){
            DesenhaBotao(t.botoes[i], i);
            printf("\n");
        }
        printf("##################\n");
        printf("- Escolha sua acao: ");
    }
}

/**
 * @brief Espera o usuário clicar em um botão da tela especificada e executa a ação correspondente.
 * se o usuário clicar em um botão que não existe, o programa é encerrado.
 * 
 * @param t Tela em que o usuário deve clicar em um botão.
 */
void OuvidorEventosTela(Tela t){
    int acao;

    scanf("%d", &acao);

    if(acao >= 0 && acao < t.qntBotoes){
        ExecutaBotao(t.botoes[acao]);
    }
}

