
#include "conta.h"
#include "vector.h"

/**
 * @brief Estrutura para representar uma agência bancária.
 */
typedef struct Agencia{
    int num;
    char *nome;
    Vector *contas;
} tAgencia;

/**
 * @brief Função para criar uma nova agência bancária.
 * @return Um ponteiro para a nova agência bancária criada. Se a memória não puder ser alocada, a função imprime uma mensagem de erro e termina o programa.
 */
tAgencia *CriaAgencia(){
    tAgencia *agencia;

    agencia = (tAgencia*) calloc(1, sizeof(tAgencia));

    agencia->contas = VectorConstruct();
    agencia->nome = (char*) calloc(1, sizeof(char));

    return agencia;
}

/**
 * @brief Função para destruir uma agência bancária.
 * @param agencia A agência bancária a ser destruída.
 */
void DestroiAgencia(DataType agencia){
    VectorDestroy(((tAgencia*)agencia)->contas, DestroiConta);
    free(((tAgencia*)agencia)->nome);
    free(((tAgencia*)agencia));
}

/**
 * @brief Função para ler uma agência bancária no formato "numero;nome".
 * @param agencia A agência bancária a ser lida.
 */
void LeAgencia(tAgencia *agencia){
    int i = 0;
    scanf("%d;", &agencia->num);

    while((scanf("%c", &agencia->nome[i]) == 1) && (agencia->nome[i] != '\n')){
        i++;
        agencia->nome = (char*) realloc(agencia->nome, (i+1)*sizeof(char));
    }

    agencia->nome[i] = '\0';
}

/**
 * @brief Função para adicionar uma conta bancária a uma agência bancária.
 * @param agencia A agência bancária.
 * @param conta A conta bancária a ser adicionada.
 */
void AdicionaConta(tAgencia *agencia, tConta *conta){
    VectorPushBack(agencia->contas, conta);
}

/**
 * @brief Função para comparar um número de agência bancária com uma agência bancária.
 * @param numAgencia O número da agência bancária.
 * @param agencia2 A agência bancária a ser comparada.
 * @return 1 se os números forem iguais, 0 caso contrário.
 */
int ComparaAgencia(int numAgencia, tAgencia *agencia2){
    if(numAgencia == agencia2->num) return 1;
    return 0;
}

/**
 * @brief Função para obter o saldo médio das contas de uma agência bancária.
 * @param agencia A agência bancária.
 * @return O saldo médio das contas da agência.
 */
float GetSaldoMedioAgencia (tAgencia *agencia){
    float media = 0;

    for(int i = 0; i < VectorSize(agencia->contas); i++){
        media += GetSaldoConta(((tConta*)VectorGet(agencia->contas, i)));
    }

    media = media/VectorSize(agencia->contas);

    return media;
}

/**
 * @brief Função para imprimir os dados de uma agência bancária (nome, número, número de contas cadastradas e saldo médio).
 * @param agencia A agência bancária.
 */
void ImprimeDadosAgencia(tAgencia *agencia){
    printf("	Nome: %s\n", agencia->nome);
    printf("	Numero: %d\n", agencia->num);
    printf("	Numero de contas cadastradas: %d\n", VectorSize(agencia->contas));
    printf("	Saldo médio: R$%.2f\n\n", GetSaldoMedioAgencia(agencia));
}
