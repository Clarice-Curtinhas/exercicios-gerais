
#include "vector.h"

/**
 * @brief Estrutura para representar uma conta bancária.
 */
typedef struct Conta{
    int numConta;
    char *nome;
    float saldo;
} tConta;

/**
 * @brief Função para criar uma nova conta bancária.
 * @return Um ponteiro para a nova conta bancária criada. Se a memória não puder ser alocada, a função imprime uma mensagem de erro e termina o programa.
 */
tConta *CriaConta(){
    tConta *c;

    c = (tConta*) calloc(1, sizeof(tConta));
    c->nome = (char*) calloc(1, sizeof(char));

    return c;
}

/**
 * @brief Função para destruir uma conta bancária.
 * @param conta A conta bancária a ser destruída.
 */
void DestroiConta(DataType conta){
    free(((tConta*)conta)->nome);
    free((tConta*)conta);
}

/**
 * @brief Função para ler uma conta bancária no formato "numero;nome do cliente;saldo inicial".
 * @param conta A conta bancária a ser lida.
 */
void LeConta(tConta *conta){
    int i = 0;

    scanf("%d;", &conta->numConta);
    while((scanf("%c", &conta->nome[i]) == 1) && (conta->nome[i] != ';')){
        conta->nome = (char*) realloc(conta->nome, (i+2 * sizeof(char)));
        i++;
    }

    scanf("%f\n", &conta->saldo);
}

/**
 * @brief Função para obter o saldo de uma conta bancária.
 * @param conta A conta bancária.
 * @return O saldo da conta bancária.
 */
float GetSaldoConta(tConta *conta){
    return conta->saldo;
}
