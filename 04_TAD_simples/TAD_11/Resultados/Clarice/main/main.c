#include <stdio.h>
#include <stdlib.h>

#include "loja.h"
#include "vendedor.h"

int main(){
    int maxLojas, operacao = -1, totalLojas = 0;
    int idLoja, aluguelLoja;
    float salario, porcent, venda;
    char nome[50];
    tVendedor vendedor;

    scanf("%d\n", &maxLojas);
    tLoja lojas[maxLojas];

    while(operacao != 0){
        scanf("%d\n", &operacao);

        if(operacao == 1){

            if(totalLojas < maxLojas){
                scanf("%d %d\n", &idLoja, &aluguelLoja);
                lojas[totalLojas] = AbreLoja(idLoja, aluguelLoja);

                totalLojas++;
            }
        }

        else if(operacao == 2){
            scanf("%[^ ] %f %f\n", nome, &salario, &porcent);
            vendedor = RegistraVendedor(nome, salario, porcent);

            scanf("%d\n", &idLoja);

            for(int tam = 0; tam < totalLojas; tam++){
                if(VerificaIdLoja(lojas[tam], idLoja)){
                    lojas[tam] = ContrataVendedor(lojas[tam], vendedor);
                }
            }
        }

        else if(operacao == 3){
            scanf("%d %[^ ] %f\n", &idLoja, nome, &venda);

            for(int tam = 0; tam < totalLojas; tam++){
                if(VerificaIdLoja(lojas[tam], idLoja)){
                    lojas[tam] = RegistraVenda(lojas[tam], nome, venda);
                }
            }
        }

        else if(operacao == 4){
            for(int tam = 0; tam < totalLojas; tam++){
                lojas[tam] = CalculaLucro(lojas[tam]);
                ImprimeRelatorioLoja(lojas[tam]);
            }
        }
    }

    return 0;
}