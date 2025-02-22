#include <stdio.h>
#include <stdlib.h>

int main(){
    int N, numero;
    int linhas, colunas;

    numero = 1;

    scanf("%d", &N);
    
    for(linhas = 1; linhas <= N; linhas++){
        for(colunas = 1; colunas <= linhas; colunas++){

            printf("%d ", numero);
            numero++;
        }

        printf("\n");
    }

    return 0;
}