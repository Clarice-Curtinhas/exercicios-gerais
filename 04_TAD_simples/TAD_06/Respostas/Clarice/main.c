#include <stdio.h>
#include <stdlib.h>

#include "matrix_utils.h"

int main(){
    int rows1, cols1, rows2, cols2;
    int operacao = -1, escalar, matrixMultiplicada;
    tMatrix m1, m2, r;

    scanf("%d %d\n", &rows1, &cols1);
    m1 = MatrixCreate(rows1, cols1);
    m1 = MatrixRead(m1);

    scanf("%d %d\n", &rows2, &cols2);
    m2 = MatrixCreate(rows2, cols2);
    m2 = MatrixRead(m2);

    while(operacao != 6){
        printf("1 - Somar matrizes\n");
        printf("2 - Subtrair matrizes\n");
        printf("3 - Multiplicar matrizes\n");
        printf("4 - Multiplicacao de uma matriz por escalar\n");
        printf("5 - Transposta de uma matriz\n");
        printf("6 - Encerrar o programa\n");
        printf("Opcao escolhida: ");

        scanf("%d\n", &operacao);
        printf("\n");

        if(operacao == 1){
            if(PossibleMatrixSum(m1, m2)){
                r = MatrixAdd(m1, m2);
                MatrixPrint(r);
            }

            else printf("Erro: as dimensoes da matriz nao correspondem\n\n");
        }

        else if(operacao == 2){
            if(PossibleMatrixSub(m1, m2)){
                r = MatrixSub(m1, m2);
                MatrixPrint(r);
            }

            else printf("Erro: as dimensoes da matriz nao correspondem\n\n");
        }

        else if(operacao == 3){
            if(PossibleMatrixMultiply(m1, m2)){
                r = MatrixMultiply(m1, m2);
                MatrixPrint(r);
            }

            else printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n\n");
        }

        else if(operacao == 4){
            scanf("%d %d\n", &escalar, &matrixMultiplicada);

            if(matrixMultiplicada == 1){
                m1 = MatrixMultiplyByScalar(m1, escalar);
                MatrixPrint(m1);
            }

            else if(matrixMultiplicada == 2){
                m2 = MatrixMultiplyByScalar(m2, escalar);
                MatrixPrint(m2);
            }
        }

        else if(operacao == 5){
            r = TransposeMatrix(m1);
            MatrixPrint(r);

            r = TransposeMatrix(m2);
            MatrixPrint(r);
        }

    }

    return 0;
}