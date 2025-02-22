#include <stdio.h>
#include <stdlib.h>

#define MAX_MATRIX_SIZE 10

typedef struct Matrix{
    int rows;
    int cols;
    int **data;
} tMatrix;

/**
 * @brief Cria uma matriz com o número de linhas e colunas especificado. Alocar dinamicamente o espaço na memória para a matriz bidimensional
 * @param rows O número de linhas na matriz.
 * @param cols O número de colunas na matriz.
 * @return A matriz criada.
 */
tMatrix* MatrixCreate(int rows, int cols){
    tMatrix *matriz;

    matriz = (tMatrix*) calloc(1, sizeof(tMatrix));

    matriz->rows = rows;
    matriz->cols = cols;

    matriz->data = (int**) calloc(cols, sizeof(int*));

    for(int i = 0; i < matriz->cols; i++){
        matriz->data[i] = (int*) calloc(rows, sizeof(int));
    }

    return matriz;
}

/**
 * @brief Libera toda a memória alocada por uma matriz
 * @param matrix O ponteiro para a estrutura que armazena uma matriz.
 */
void MatrixFree(tMatrix* matrix){
    for(int i = 0; i < matrix->cols; i++){
        free(matrix->data[i]);
    }

    free(matrix->data);
    free(matrix);
}

/**
 * @brief Lê uma matriz da entrada padrão.
 * @param matrix A matriz a ser lida.
 */
void MatrixRead(tMatrix* matrix){
    for(int i = 0; i < matrix->cols; i++){
        for(int j = 0; j < matrix->rows; j++){
            scanf("%d%*c", &matrix->data[i][j]);
        }
    }
}

/**
 * @brief Imprime uma matriz na saída padrão.
 * @param matrix A matriz a ser impressa.
 */
void MatrixPrint(tMatrix* matrix){

    for(int i = 0; i < matrix->cols; i++){
        for(int j = 0; j < matrix->rows; j++){
            printf("%d", matrix->data[i][j]);

            if(j < matrix->rows-1){
                printf(" ");
            }
        }

        printf("\n");
    }
}

/**
 * @brief Verifica se é possível somar duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return 1 se for possível somar as matrizes, 0 caso contrário.
 */
int PossibleMatrixSum(tMatrix* matrix1, tMatrix* matrix2){
    if((matrix1->cols == matrix2->cols) && (matrix1->rows == matrix2->rows)) return 1;
    return 0;
}

/**
 * @brief Verifica se é possível subtrair duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return 1 se for possível subtrair as matrizes, 0 caso contrário.
 */
int PossibleMatrixSub(tMatrix* matrix1, tMatrix* matrix2){
    if((matrix1->cols == matrix2->cols) && (matrix1->rows == matrix2->rows)) return 1;
    return 0;
}

/**
 * @brief Verifica se é possível multiplicar duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return 1 se for possível multiplicar as matrizes, 0 caso contrário.
 */
int PossibleMatrixMultiply(tMatrix* matrix1, tMatrix* matrix2){
    if((matrix1->cols == matrix2->rows)) return 1;
    return 0;
}

/**
 * @brief Soma duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return O resultado da soma.
 */
tMatrix* MatrixAdd(tMatrix* matrix1, tMatrix* matrix2){
    tMatrix *mat;

    mat = MatrixCreate(matrix1->rows, matrix1->cols);

    for(int i = 0; i < mat->cols; i++){
        for(int j = 0; j < mat->rows; j++){
            mat->data[i][j] = matrix1->data[i][j] + matrix2->data[i][j];
        }
    }

    return mat;
}

/**
 * @brief Subtrai duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return O resultado da subtração.
 */
tMatrix* MatrixSub(tMatrix* matrix1, tMatrix* matrix2){
    tMatrix *mat;

    mat = MatrixCreate(matrix1->rows, matrix1->cols);

    for(int i = 0; i < mat->cols; i++){
        for(int j = 0; j < mat->rows; j++){
            mat->data[i][j] = matrix1->data[i][j] - matrix2->data[i][j];
        }
    }

    return mat;
}

/**
 * @brief Multiplica duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return O resultado da multiplicação.
 */
tMatrix* MatrixMultiply(tMatrix* matrix1, tMatrix* matrix2){
    tMatrix *mat;

    mat = MatrixCreate(matrix1->cols, matrix2->rows);

    for(int i = 0; i < mat->cols; i++){
        for(int j = 0; j < mat->rows; j++){
            mat->data[i][j] = matrix1->data[j][i] * matrix2->data[i][j];
        }
    }

    return mat;
}

/**
 * @brief Transpõe uma matriz.
 * @param matrix A matriz a ser transposta.
 * @return A matriz transposta.
 */
tMatrix* TransposeMatrix(tMatrix* matrix){
    tMatrix *mat;

    mat = MatrixCreate(matrix->cols, matrix->rows);

    for(int i = 0; i < mat->cols; i++){
        for(int j = 0; j < mat->rows; j++){
            mat->data[i][j] = matrix->data[j][i];
        }
    }

    return mat;
}

/**
 * @brief Multiplica uma matriz por um escalar.
 * @param matrix A matriz a ser multiplicada.
 * @param scalar O escalar pelo qual a matriz será multiplicada.
 * @return O resultado da multiplicação.
 */
tMatrix* MatrixMultiplyByScalar(tMatrix* matrix, int scalar){
    for(int i = 0; i < matrix->cols; i++){
        for(int j = 0; j < matrix->rows; j++){
            matrix->data[i][j] = matrix->data[i][j]*scalar;
        }
    }

    return matrix;
}

