#include <stdio.h>
#include <stdlib.h>

#include "data.h"

int main(){
    int diff = 0;
    tData *d1, *d2;

    d1 = CriaData();
    LeData(d1);

    d2 = CriaData();
    LeData(d2);

    if(VerificaDataValida(d1) == 1 && VerificaDataValida(d2)){
        printf("Primeira data: ");
        ImprimeDataExtenso(d1);

        printf("Segunda data: ");
        ImprimeDataExtenso(d2);

        if(ComparaData(d1, d2) == 1) printf("A segunda data eh mais antiga\n");
        else if(ComparaData(d1, d2) == -1) printf("A primeira data eh mais antiga\n");
        else printf("As datas sao iguais\n");

        printf("A diferenca em dias entre as datas eh: ");
        diff = CalculaDiferencaDias(d1, d2);

        if(diff >= 10) printf("%d dias", diff);
        else if(diff < 10) printf("0%d dias", diff);
    }

    else printf("A primeira e/ou segunda data(s) invalida(s)");

    LiberaData(d1);
    LiberaData(d2);

    return 0;
}