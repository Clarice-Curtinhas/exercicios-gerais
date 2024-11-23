#include "data.h"

#include <stdio.h>
#include <stdlib.h>

int main(){
    tData data, data1, data2;
    int comparacao, dias;

    scanf("%d/%d/%d", &data.dia, &data.mes, &data.ano);
    data1 = CriaData(data.dia, data.mes, data.ano);

    scanf("%d/%d/%d", &data.dia, &data.mes, &data.ano);
    data2 = CriaData(data.dia, data.mes, data.ano);

    if(VerificaDataValida(data1) && VerificaDataValida(data2)){
        printf("Primeira data: ");
        ImprimeDataExtenso(data1);

        printf("Segunda data: ");
        ImprimeDataExtenso(data2);

        comparacao = ComparaData(data1, data2);

        if(comparacao == -1) printf("A primeira data eh mais antiga\n");
        else if(comparacao == 1) printf("A segunda data eh mais antiga\n");
        else printf("As datas sao iguais\n");

        dias = CalculaDiferencaDias(data1, data2);

        if(dias >= 10) printf("A diferenca em dias entre as datas eh: %d dias\n", dias);
        else if(dias > 0 && dias < 10) printf("A diferenca em dias entre as datas eh: 0%d dias", dias);
        else printf("A diferenca em dias entre as datas eh: 00 dias\n");
    }

    else{
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
    }

    return 0;
}