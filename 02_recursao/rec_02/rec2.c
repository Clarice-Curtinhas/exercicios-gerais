#include <stdio.h>
#include <stdlib.h>

int SomaElementosPares(int *vet, int numElementos);

int main(){
    int N, QTD;
    int qntDeVetores, qntDeNumeros;

    scanf("%d", &N);

    for(qntDeVetores = 0; qntDeVetores < N; qntDeVetores++){
        scanf("%d", &QTD);
        int vet[QTD];

        for(qntDeNumeros = 0; qntDeNumeros < QTD; qntDeNumeros++){
            scanf("%d", &vet[qntDeNumeros]);
        }
        vet[qntDeNumeros] = '\0';
        
        printf("%d\n", SomaElementosPares(vet, QTD));
    }

    return 0;
}

int SomaElementosPares(int *vet, int numElementos){
    if(numElementos < 0) return 0;

    else{
        if(vet[numElementos]%2 != 0){
            SomaElementosPares(vet, numElementos-1);
        }

        else return vet[numElementos] + SomaElementosPares(vet, numElementos-1);
    }
}