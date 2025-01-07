#include <stdio.h>
#include <stdlib.h>

#include "calculadora.h"

float adicao(float n1, float n2);
float subtracao(float n1, float n2);
float multiplicacao(float n1, float n2);
float divisao(float n1, float n2);

int main(){
    char operacao, simbolo;
    float n1, n2;
    CalculatoraCallback *matematica;

    scanf("%c\n", &operacao);

    while(operacao != 'f'){
        scanf("%f %f\n", &n1, &n2);

        if(operacao == 'a'){
            matematica = adicao;
            simbolo = '+';
        }

        else if(operacao == 's'){
            matematica = subtracao;
            simbolo = '-';
        }

        else if(operacao == 'm'){
            matematica = multiplicacao;
            simbolo = 'x';
        }

        else if(operacao == 'd'){
            matematica = divisao;
            simbolo = '/';
        }

        printf("%.2f %c %.2f = %.2f\n", n1, simbolo, n2, Calcular(n1, n2, matematica));
        scanf("%c\n", &operacao);
    }

    return 0;
}


float adicao(float n1, float n2){
    return n1 + n2;
}

float subtracao(float n1, float n2){
    return n1 - n2;
}

float multiplicacao(float n1, float n2){
    return n1 * n2;
}

float divisao(float n1, float n2){
    return n1 / n2;
}
