#include <stdlib.h>
#include <stdio.h>
#include "vetor.h"

int soma(int n1, int n2);
int multiplica(int n1, int n2);

int main(){
    Operation *operacao;
    Vetor vetor;

    LeVetor(&vetor);

    operacao = soma;
    printf("Soma: %d\n", AplicarOperacaoVetor(&vetor, operacao));

    operacao = multiplica;
    printf("Produto: %d\n", AplicarOperacaoVetor(&vetor, operacao));

    return 0;
}

int soma(int n1, int n2){
    return n1 + n2;
}

int multiplica(int n1, int n2){
    return n1 * n2;
}