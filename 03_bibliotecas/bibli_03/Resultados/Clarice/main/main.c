#include "data.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int dia;
    int mes;
    int ano;
}tData;

int main(){
    tData data1, data2;
    int comparacao, difDias;

    scanf("%d/%d/%d\n", &data1.dia, &data1.mes, &data1.ano);
    scanf("%d/%d/%d", &data2.dia, &data2.mes, &data2.ano);


    if(verificaDataValida(data1.dia, data1.mes, data1.ano) && verificaDataValida(data2.dia, data2.mes, data2.ano)){
        printf("Primeira data: ");
        imprimeDataExtenso(data1.dia, data1.mes, data1.ano);
        //printf("\n");

        printf("Segunda data: ");
        imprimeDataExtenso(data2.dia, data2.mes, data2.ano);
        //printf("\n");

        comparacao = comparaData(data1.dia, data1.mes, data1.ano, data2.dia, data2.mes, data2.ano);

        if(comparacao == 1){
            printf("A segunda data eh mais antiga\n");
            difDias = calculaDiferencaDias(data1.dia, data1.mes, data1.ano, data2.dia, data2.mes, data2.ano);
            printf("A diferenca em dias entre as datas eh: ");

            if(difDias < 10){
                printf("0%d dias\n", difDias);
            }

            else{
                printf("%d dias\n", difDias);
            }
        }

        else if(comparacao == -1){
            printf("A primeira data eh mais antiga\n");
            difDias = calculaDiferencaDias(data1.dia, data1.mes, data1.ano, data2.dia, data2.mes, data2.ano);
            printf("A diferenca em dias entre as datas eh: ");
            
            if(difDias < 10){
                printf("0%d dias\n", difDias);
            }

            else{
                printf("%d dias\n", difDias);
            }
        }

        else{
            printf("As datas sao iguais\n");
            printf("A diferenca em dias entre as datas eh: 00 dias\n");
        }
    }

    else{
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
    }

    return 0;
}