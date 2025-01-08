#include <stdio.h>
#include <stdlib.h>
#define TAMANHO_MAXIMO 10

/**
 * @brief Ponteiro para função que recebe dois inteiros e realiza uma operação matemática.
 * 
 * return int Resultado da operação matemática.
*/
typedef int (*Operation)(int, int);

typedef struct vetor {
    int elementos[TAMANHO_MAXIMO];
    int tamanhoUtilizado;
} Vetor;


/**
 * Lê um vetor da entrada padrão.
 * 
 * @param vetor Ponteiro para o vetor que será lido.
 */
void LeVetor(Vetor *vetor){
    scanf("%d\n", &vetor->tamanhoUtilizado);

    for(int i = 0; i < vetor->tamanhoUtilizado; i++){
        scanf("%d ", &vetor->elementos[i]);
    }
}

/**
 * Aplica uma operação em um vetor.
 * 
 * @param vetor Ponteiro para o vetor que será utilizado.
 * @param op Ponteiro para a função que será aplicada.
 * @return O resultado da operação.
*/
int AplicarOperacaoVetor(Vetor *vetor, Operation op){
    int result = 0;

    for(int i = 0; i < vetor->tamanhoUtilizado; i++){
        if(i != 0) result = op(result, vetor->elementos[i]);
            
        else{ 
            result = op(vetor->elementos[0], vetor->elementos[1]);
            i = 1;
        }
    }

    return result;
}