#include "matrix_utils.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int linhas;
    int colunas;
}tTamanho;

int main(){
    tTamanho m1, m2;
    int lerLinha, lerColuna;
    int operacao = 0, escalar;
    int matrizEscolhida;
    int result[100][100];

    scanf("%d %d\n", &m1.linhas, &m1.colunas);
    int matriz1[m1.colunas][m1.linhas];
    matrix_read(m1.linhas, m1.colunas, matriz1);

    scanf("%d %d\n", &m2.linhas, &m2.colunas);
    int matriz2[m2.colunas][m2.linhas];
    matrix_read(m2.linhas, m2.colunas, matriz2);

    while(operacao != 6){
        printf("1 - Somar matrizes\n");
        printf("2 - Subtrair matrizes\n");
        printf("3 - Multiplicar matrizes\n");
        printf("4 - Multiplicacao de uma matriz por escalar\n");
        printf("5 - Transposta de uma matriz\n");
        printf("6 - Encerrar o programa\n");
        printf("Opcao escolhida:\n");

        scanf("%d", &operacao);

        if(operacao != 6){
            if(operacao == 1){
                if(possible_matrix_sum(m1.linhas, m1.colunas, m2.linhas, m2.colunas)){
                    matrix_add(m1.linhas, m1.colunas, matriz1, m2.linhas, m2.colunas, matriz2, result);
                    matrix_print(m1.linhas, m1.colunas, result);
                }

                else printf("Erro: as dimensoes da matriz nao correspondem\n\n");
            }

            else if(operacao == 2){
                if(possible_matrix_sub(m1.linhas, m1.colunas, m2.linhas, m2.colunas)){
                    matrix_sub(m1.linhas, m1.colunas, matriz1, m2.linhas, m2.colunas, matriz2, result);
                    matrix_print(m1.linhas, m1.colunas, result);
                }

                else printf("Erro: as dimensoes da matriz nao correspondem\n\n");
            }

            else if(operacao == 3){
                if(possible_matrix_multiply(m1.colunas, m2.linhas)){
                    matrix_multiply(m1.linhas, m1.colunas, matriz1, m2.linhas, m2.colunas, matriz2, result);
                    matrix_print(m1.linhas, m2.colunas, result);
                }

                else printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n\n");
            }

            else if(operacao == 4){
                scanf("%d ", &escalar);
                scanf("%d", &matrizEscolhida);

                if(matrizEscolhida == 1){
                    scalar_multiply(m1.linhas, m1.colunas, matriz1, escalar);
                    matrix_print(m1.linhas, m1.colunas, matriz1);
                }

                else{
                    scalar_multiply(m2.linhas, m2.colunas, matriz2, escalar);
                    matrix_print(m2.linhas, m2.colunas, matriz2);
                }
            }

            else{ 
                transpose_matrix(m1.linhas, m1.colunas, matriz1, result);
                matrix_print(m1.colunas, m1.linhas, result);

                transpose_matrix(m2.linhas, m2.colunas, matriz2, result);
                matrix_print(m2.colunas, m2.linhas, result);
            }
        }
    }

    return 0;
}