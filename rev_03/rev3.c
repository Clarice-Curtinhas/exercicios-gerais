#include <stdio.h>
#include <stdlib.h>

int lerNumero();
void analisaNumero(int *codigosLivros, int num);
void ordenaLivros(int *livrosUnicos, int existe);

int main(){
    int N;
    int qntLivros;

    N = lerNumero();

    int codigosLivros[N];

    for(qntLivros = 0; qntLivros < N; qntLivros++){
        scanf("%d", &codigosLivros[qntLivros]);
    }

    analisaNumero(codigosLivros, N);

    return 0;
}

int lerNumero(){
    int num;

    scanf("%d", &num);

    return num;
}

void analisaNumero(int *codigosLivros, int num){
    int analisa, numAtual;
    int repete, existe;

    int livrosUnicos[num];

    existe = 0;

    for(numAtual = 0; numAtual < num; numAtual++){
        repete = 0;

        for(analisa = 0; analisa < num; analisa++){
            if(codigosLivros[analisa] == codigosLivros[numAtual]){
                repete++;
            }
        }

        if(repete == 1){
            livrosUnicos[existe] = codigosLivros[numAtual];
            existe++;
        }
    }

    if(existe == 0){
        printf("NENHUM");
    }

    else{
        ordenaLivros(livrosUnicos, existe);
    }
}

void ordenaLivros(int *livrosUnicos, int existe){
    int menorNum, codigoMenor;
    int num, qntDeCodigos, restante, numArray;

    restante = existe;

    for(qntDeCodigos = 0; qntDeCodigos < existe; qntDeCodigos++){

        menorNum = livrosUnicos[0];

        for(num = 0; num < restante; num++){
            if(menorNum >= livrosUnicos[num]){
                menorNum = livrosUnicos[num];
                codigoMenor = num;
            }
        }

        printf("%d ", menorNum);

        for(numArray = 0; numArray < restante; numArray++){
            if(numArray >= codigoMenor){
                livrosUnicos[numArray] = livrosUnicos[numArray+1];
            }
        }

        restante--;
    }
}