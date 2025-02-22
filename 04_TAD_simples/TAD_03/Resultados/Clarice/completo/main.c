#include <stdio.h>
#include <stdlib.h>

#include "locadora.h"
#include "filme.h"

int main(){
    int acao, para, id;
    char hashtag;
    char tipos[4][11] = {"Cadastrar", "Estoque", "Alugar", "Devolver"};
    char opcao[11];

    tLocadora locadora;
    tFilme filme;

    locadora = criarLocadora();

    while((scanf("%[^\n]\n", opcao)) == 1){
        acao = 0;

        for(int l = 0; l < 4; l++){
            acao += 1;
            para = 0;

            for(int i = 0; opcao[i] != '\0'; i++){

                if(opcao[i] != tipos[l][i]){
                    para = 1;
                    break;
                }
            }

            if(para == 0){
                break;
            }
        }

        if(acao == 1){
            locadora = lerCadastroLocadora(locadora);
        }

        else if(acao == 2){
            locadora = ordenarFilmesLocadora(locadora);
            consultarEstoqueLocadora(locadora);
        }

        else if(acao == 3){ 
            locadora = lerAluguelLocadora(locadora);
        }

        else if(acao == 4){
            locadora = lerDevolucaoLocadora(locadora);
        }
        
        if(para == 0) printf("\n");
    }

    return 0;
}