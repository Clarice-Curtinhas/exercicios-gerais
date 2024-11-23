#include <stdio.h>
#include <stdlib.h>

#include "conta.h"
#include "usuario.h"

int main(){
    char nome[20], CPF[15];
    int nomeTam, CPFTam, numero, count;
    float valor;
    int maxContas, operacao = -1, cadastros = 0;
    int numConta, achaConta;

    scanf("%d\n", &maxContas);
    tUsuario user[maxContas];
    tConta conta[maxContas];
    
    while(operacao != 0){
        scanf("%d\n", &operacao);

        if(operacao == 3 && cadastros < maxContas){
            for(nomeTam = 0; nome[nomeTam-1] != ' '; ){
                scanf("%c", &nome[nomeTam]);
                nomeTam++;
            }
            nome[nomeTam] = '\0';

            for(CPFTam = 0; CPF[CPFTam-1] != ' '; ){
                scanf("%c", &CPF[CPFTam]);
                CPFTam++;
            }
            CPF[CPFTam] = '\0';

            user[cadastros] = CriaUsuario(nome, CPF);

            scanf("%d\n", &numero);

            conta[cadastros] = CriaConta(numero, user[cadastros]);
            cadastros++;
        }

        else if(operacao == 1){
            scanf("%d %f\n", &numConta, &valor);

            for(achaConta = 0; achaConta < cadastros; achaConta++){

                if(VerificaConta(conta[achaConta], numConta) == 1){
                    conta[achaConta] = SaqueConta(conta[achaConta], valor);
                    break;
                }
            }
        }

        else if(operacao == 2){
            scanf("%d %f\n", &numConta, &valor);

            for(achaConta = 0; achaConta < cadastros; achaConta++){
                
                if(VerificaConta(conta[achaConta], numConta) == 1){
                    conta[achaConta] = DepositoConta(conta[achaConta], valor);
                    break;
                }
            }
        }

        else if(operacao == 4){
            printf("===| Imprimindo Relatorio |===\n");

            for(count = 0; count < cadastros; count++){
                ImprimeConta(conta[count]);
            }
        }

    }

    return 0;
}