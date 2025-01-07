#include <stdio.h>
#include <stdlib.h>
#include "tDepartamento.h"


int main(){
    tDepartamento departa;
    int qntDepto, total = 0;

    scanf("%d\n", &qntDepto);
    printf("\n");

    tDepartamento deptos[qntDepto];

    for(int i = 0; total < qntDepto; i++){
        scanf("%[^\n]\n", departa.nome);
        scanf("%[^\n]\n", departa.diretor);

        scanf("%[^\n]\n", departa.curso1);
        scanf("%[^\n]\n", departa.curso2);
        scanf("%[^\n]\n", departa.curso3);

        scanf("%d %d %d\n", &departa.m1, &departa.m2, &departa.m3);

        if(departa.m1 < 0 || departa.m2 < 0 || departa.m3 < 0){
            printf("Digite um departamento com médias válidas");
        }

        else{
            deptos[total] = CriaDepartamento(departa.curso1, departa.curso2, departa.curso3, departa.nome, departa.m1, departa.m2, departa.m3, departa.diretor);
            total++;
        }
    }

    OrdenaDepartamentosPorMedia(&deptos, total);

    for(int i = 0; i < total; i++){
        ImprimeAtributosDepartamento(deptos[i]);
    }

    return 0;
}