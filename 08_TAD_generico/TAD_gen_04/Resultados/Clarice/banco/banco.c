/**
 * @file banco.h
 * @brief Este arquivo contém a declaração da estrutura tBanco e suas funções relacionadas.
 */


#include "agencia.h"
#include "vector.h"

/**
 * @brief Estrutura para representar um banco.
 */
typedef struct Banco{
    char *nome;
    Vector *agencias;
} tBanco;

/**
 * @brief Função para criar um novo banco.
 * @return Um ponteiro para o novo banco criado. Se a memória não puder ser alocada, a função imprime uma mensagem de erro e termina o programa.
 */
tBanco *CriaBanco(){
    tBanco *banco;

    banco = (tBanco*) calloc(1, sizeof(tBanco));
    banco->nome = (char*) calloc(1, sizeof(char));
    banco->agencias = VectorConstruct();

    return banco;
}

/**
 * @brief Função para destruir um banco.
 * @param banco O banco a ser destruído.
 */
void DestroiBanco(tBanco *banco){
    VectorDestroy(banco->agencias, DestroiAgencia);
    free(banco->nome);
    free(banco);
}

/**
 * @brief Função para ler o nome de um banco.
 * @param banco O banco a ser lido.
 */
void LeBanco(tBanco *banco){
    int i = 0;

    while((scanf("%c", &banco->nome[i]) == 1) && (banco->nome[i] != '\n')){
        i++;
        banco->nome = (char*) realloc(banco->nome, (i+2) * sizeof(char)); 
    }

    banco->nome[i] = '\0';
}

/**
 * @brief Função para adicionar uma agência a um banco.
 * @param banco O banco.
 * @param agencia A agência a ser adicionada.
 */
void AdicionaAgencia(tBanco *banco, tAgencia *agencia){
    VectorPushBack(banco->agencias, agencia);
}

/**
 * @brief Função para inserir uma conta em uma agência pertencente ao banco.
 * @param banco O banco.
 * @param numAgencia O número da agência.
 * @param cliente A conta a ser inserida.
 * @pre A agência deve pertencer ao banco.
*/
void InsereContaBanco(tBanco *banco, int numAgencia, tConta *cliente){
    int i = 0;

    for(i = 0; i < VectorSize(banco->agencias); i++){
        if(ComparaAgencia(numAgencia, VectorGet(banco->agencias, i)) == 1) break;
    }

    AdicionaConta(VectorGet(banco->agencias, i), cliente);
}

/**
 * @brief Função para imprimir o relatório de um banco, com o nome do banco e a lista de agências.
 * @param banco O banco.
 */
void ImprimeRelatorioBanco(tBanco *banco){
    printf("%s\n", banco->nome);
    printf("Lista de agencias:\n");

    for(int i = 0; i < VectorSize(banco->agencias); i++){
        ImprimeDadosAgencia(VectorGet(banco->agencias, i));
    }
}
