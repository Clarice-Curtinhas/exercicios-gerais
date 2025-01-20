#include <stdlib.h>
#include <stdio.h>

#include "botao.h"
#include "tela.h"

#define ALTURA 400
#define LARGURA 200
#define BOTOES 3

void Salvar();
void Excluir();
void Opcoes();

int main(){
    Tela t;
    Botao b;

    t = CriarTela(ALTURA, LARGURA);

    RegistraBotaoTela(&t, CriarBotao("Salvar", 12, "FFF", 1, Salvar));
    RegistraBotaoTela(&t, CriarBotao("Excluir", 18, "000", 1, Excluir));
    RegistraBotaoTela(&t, CriarBotao("Opcoes", 10, "FF0000", 2, Opcoes));

    DesenhaTela(t);
    OuvidorEventosTela(t);

    return 0;
}

void Salvar(){
    printf("- Botao de SALVAR dados ativado!\n");
}

void Excluir(){
    printf("- Botao de EXCLUIR dados ativado!\n");
}

void Opcoes(){
    printf("- Botao de OPCOES ativado!\n");
}