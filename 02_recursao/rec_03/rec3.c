#include <stdio.h>
#include <stdlib.h>

int ContaOcorrencias(int* vet, int numElementos, int numeroProcurado);

int main(){
    int N, qtdElementos;
    int numeroX, qtdInteiros;
    int qntDeCasos;

    scanf("%d", &N);

    for(qntDeCasos = 0; qntDeCasos < N; qntDeCasos++){
        scanf("%d", &numeroX);
        scanf("%d", &qtdElementos);
        int vet[qtdElementos];

        for(qtdInteiros = 0; qtdInteiros < qtdElementos; qtdInteiros++){
            scanf("%d", &vet[qtdInteiros]);
        }

        printf("%d\n", ContaOcorrencias(vet, qtdElementos-1, numeroX));
    }

    return 0;
}

int ContaOcorrencias(int* vet, int numElementos, int numeroProcurado){
    if(numElementos < 0) return 0;

    else{
        if(vet[numElementos] != numeroProcurado) ContaOcorrencias(vet, numElementos-1, numeroProcurado);

        else{
            return 1 + ContaOcorrencias(vet, numElementos-1, numeroProcurado);
        }
    }
}