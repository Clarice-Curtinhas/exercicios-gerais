#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "filme.h"
#include "locadora.h"

int main(){
    int i = 0;
    char opcao[15];
    tLocadora *locadora;

    locadora = CriarLocadora();

    while((scanf("%[^\n]\n", opcao)) == 1){

        if((strcmp(opcao, "Cadastrar") == 0) || (strcmp(opcao, "Cadastrar ") == 0)){
            LerCadastroLocadora(locadora);
            printf("\n");
        }

        else if((strcmp(opcao, "Alugar") == 0) || (strcmp(opcao, "Alugar ") == 0)){
            LerAluguelLocadora(locadora);
            printf("\n");
        }

        else if((strcmp(opcao, "Devolver") == 0) || (strcmp(opcao, "Devolver ") == 0)){
            LerDevolucaoLocadora(locadora);
            printf("\n");
        }
        
        else if(strcmp(opcao, "Estoque") == 0){
            OrdenarFilmesLocadora(locadora);
            ConsultarEstoqueLocadora(locadora);
            printf("\n");
        }

        else if(strcmp(opcao, "#") == 0) continue;

        scanf("\n");
    }

    ConsultarLucroLocadora(locadora);

    DestruirLocadora(locadora);

    return 0;
}