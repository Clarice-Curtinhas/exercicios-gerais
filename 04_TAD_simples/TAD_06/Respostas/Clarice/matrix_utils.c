#include <stdio.h>
#include <stdlib.h>

#define MAX_MATRIX_SIZE 10

typedef struct Matrix{
    int rows;
    int cols;
    int data[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];
} tMatrix;

/**
 * @brief Cria uma matriz com o número de linhas e colunas especificado.
 * @param rows O número de linhas na matriz.
 * @param cols O número de colunas na matriz.
 * @return A matriz criada.
 */
tMatrix MatrixCreate(int rows, int cols){
    tMatrix matrix;

    matrix.rows = rows;
    matrix.cols = cols;

    return matrix;
}

/**
 * @brief Lê uma matriz da entrada padrão.
 * @param matrix A matriz a ser lida.
 * @return A matriz lida.
 */
tMatrix MatrixRead(tMatrix matrix){
    for(int l = 0; l < matrix.rows; l++){
        for(int c = 0; c < matrix.cols; c++){
            scanf("%d%*c", &matrix.data[c][l]);
        }
    }

    return matrix;
}

/**
 * @brief Imprime uma matriz na saída padrão.
 * @param matrix A matriz a ser impressa.
 */
void MatrixPrint(tMatrix matrix){

    for(int l = 0; l < matrix.rows; l++){
        printf("|");

        for(int c = 0; c < matrix.cols; c++){
            if(c < matrix.cols-1) printf("%d ", matrix.data[c][l]);
            else printf("%d", matrix.data[c][l]);
        }

        printf("|\n");
    }

    printf("\n");
}

/**
 * @brief Verifica se é possível somar duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return 1 se for possível somar as matrizes, 0 caso contrário.
 */
int PossibleMatrixSum(tMatrix matrix1, tMatrix matrix2){
    if(matrix1.rows == matrix2.rows && matrix1.cols == matrix2.cols) return 1;
    else return 0;
}

/**
 * @brief Verifica se é possível subtrair duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return 1 se for possível subtrair as matrizes, 0 caso contrário.
 */
int PossibleMatrixSub(tMatrix matrix1, tMatrix matrix2){
    if(matrix1.rows == matrix2.rows && matrix1.cols == matrix2.cols) return 1;
    else return 0;
}

/**
 * @brief Verifica se é possível multiplicar duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return 1 se for possível multiplicar as matrizes, 0 caso contrário.
 */
int PossibleMatrixMultiply(tMatrix matrix1, tMatrix matrix2){
    if(matrix1.cols == matrix2.rows) return 1;
    else return 0;
}

/**
 * @brief Soma duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return O resultado da soma.
 */
tMatrix MatrixAdd(tMatrix matrix1, tMatrix matrix2){
    tMatrix result;

    result.rows = matrix1.rows;
    result.cols = matrix1.cols;

    for(int l = 0; l < matrix1.rows; l++){
        for(int c = 0; c < matrix1.cols; c++){
            result.data[c][l] = matrix1.data[c][l] + matrix2.data[c][l];
        }
    }

    return result;
}

/**
 * @brief Subtrai duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return O resultado da subtração.
 */
tMatrix MatrixSub(tMatrix matrix1, tMatrix matrix2){
    tMatrix result;

    result.rows = matrix1.rows;
    result.cols = matrix1.cols;

    for(int l = 0; l < matrix1.rows; l++){
        for(int c = 0; c < matrix1.cols; c++){
            result.data[c][l] = matrix1.data[c][l] - matrix2.data[c][l];
        }
    }

    return result;
}

/**
 * @brief Multiplica duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return O resultado da multiplicação.
 */
tMatrix MatrixMultiply(tMatrix matrix1, tMatrix matrix2){
    tMatrix result;

    result.rows = matrix1.rows;
    result.cols = matrix2.cols;

    for(int l = 0; l < result.rows; l++){
        for(int c = 0; c < result.cols; c++){
            result.data[c][l] = 0;

            for(int i = 0; i < matrix1.cols; i++){
                result.data[c][l] += matrix1.data[i][l] * matrix2.data[c][i];
            }
        }
    }

    return result;
}

/**
 * @brief Transpõe uma matriz.
 * @param matrix A matriz a ser transposta.
 * @return A matriz transposta.
 */
tMatrix TransposeMatrix(tMatrix matrix){
    tMatrix result;

    result.rows = matrix.cols;
    result.cols = matrix.rows;

    for(int l = 0; l < matrix.rows; l++){
        for(int c = 0; c < matrix.cols; c++){
            result.data[l][c] = matrix.data[c][l];
        }
    }

    return result;
}

/**
 * @brief Multiplica uma matriz por um escalar.
 * @param matrix A matriz a ser multiplicada.
 * @param scalar O escalar pelo qual a matriz será multiplicada.
 * @return O resultado da multiplicação.
 */
tMatrix MatrixMultiplyByScalar(tMatrix matrix, int scalar){

    for(int l = 0; l < matrix.rows; l++){
        for(int c = 0; c < matrix.cols; c++){
            matrix.data[c][l] = matrix.data[c][l] * scalar;
        }
    }

    return matrix;
}
