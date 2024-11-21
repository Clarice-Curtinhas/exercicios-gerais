#include "data.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int dia;
    int mes;
    int ano;
}tData;

int main(){
    tData data;

    scanf("%d/%d/%d", &data.dia, &data.mes, &data.ano);

    if(verificaDataValida(data.dia, data.mes, data.ano) == 0) printf("A data informada eh invalida");

    else{
        printf("Data informada: ");
        imprimeDataExtenso(data.dia, data.mes, data.ano);

        if(verificaBissexto(data.ano)) printf("O ano informado eh bissexto\n");
        else printf("O ano informado nao eh bissexto\n");

        printf("O mes informado possui %d dias\n", numeroDiasMes(data.mes, data.ano));
        printf("A data seguinte eh: ");
        imprimeProximaData(data.dia, data.mes, data.ano);
    }

    return 0;
}