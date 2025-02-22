#include <stdio.h>
#include <stdlib.h>

#include "gerenciadorpacotes.h"
#include "pacote.h"

int main(){
    int opcao;
    int tipo, numElemento, indice;
    Type type;
    tGerenciador *geren;
    tPacote *pac;

    printf("tad_gen_02\n\n");

    geren = CriaGerenciador();

    while(1){
        printf("Escolha uma opcao:\n");
        printf("	(1) Cadastrar um novo pacote\n");
        printf("	(2) Imprimir um pacote específico\n");
        printf("	(3) Imprimir todos os pacotes e sair\n");

        scanf("%d\n", &opcao);

        if(opcao == 1){
            printf("Digite o tipo (0-char, 1-int) e o numero de elementos do pacote/mensagem:");
            scanf("%d %d\n", &tipo, &numElemento);

            if(tipo == 0 || tipo == 1){
                if(tipo == 0){
                    type = CHAR;
                    pac = CriaPacote(type, numElemento);
                }

                else if(tipo == 1){
                    type = INT;
                    pac = CriaPacote(INT, numElemento);
                }

                LePacote(pac);
                AdicionaPacoteNoGerenciador(geren, pac);
                printf("\n");
            }

            else{
                printf("\nDigite um tipo valido!\n");
            }
        }

        else if(opcao == 2){
            scanf("%d\n", &indice);
            ImprimirPacoteNoIndice(geren, indice);
        }

        else if(opcao == 3){
            ImprimirTodosPacotes(geren);
            break;
        }

        else{
            printf("Escolha uma opcao valida para o menu!\n");
        }
    }

    DestroiGerenciador(geren);

    return 0;
}