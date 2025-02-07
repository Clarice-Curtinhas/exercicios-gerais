#include <stdio.h>
#include <stdlib.h>

#include "conta.h"

typedef struct Banco {
    tConta **contas;
    int qtdContas;
    int contasAlocadas;
} tBanco;

/**
 * @brief Cria um novo banco, com 5 contas alocadas e nenhuma conta aberta.
 * Se não for possível alocar memória, o programa é encerrado.
 * 
 * @return Um ponteiro para o novo banco criado.
 */
tBanco *CriaBanco(){
    tBanco *banco;

    banco = (tBanco*) calloc(1, sizeof(tBanco));

    banco->contas = (tConta**) calloc(5, sizeof(tConta*));

    banco->contasAlocadas = 5;
    banco->qtdContas = 0;

    return banco;
}

/**
 * @brief Desaloca a memória de um banco e de todas as suas contas.
 * 
 * @param banco Ponteiro para o banco a ser destruído.
 */
void DestroiBanco(tBanco *banco){
    for(int i = 0; i < banco->qtdContas; i++){
        DestroiConta(banco->contas[i]);
    }

    free(banco->contas);
    free(banco);
}

/**
 * @brief Abre uma nova conta no banco e a adiciona ao vetor de contas.
 * 
 * @param banco Ponteiro para o banco onde a conta será aberta.
 */
void AbreContaBanco(tBanco *banco){
    
    if(banco->qtdContas < banco->contasAlocadas){
        banco->contas[banco->qtdContas] = CriaConta();
        LeConta(banco->contas[banco->qtdContas]);
        banco->qtdContas++;
    }

    else{
        banco->contas = (tConta**) realloc(banco->contas, (banco->contasAlocadas+2)*sizeof(tConta*));
        banco->contasAlocadas = banco->contasAlocadas + 2;

        banco->contas[banco->qtdContas] = CriaConta();
        LeConta(banco->contas[banco->qtdContas]);
        banco->qtdContas++;
    }
}

/**
 * @brief Realiza um saque em uma conta do banco se ela existir e tiver saldo suficiente.
 * 
 * @param banco Ponteiro para o banco onde a conta será sacada.
 */
void SaqueContaBanco(tBanco *banco){
    int numConta, valorSacado;

    scanf("%d %d\n", &numConta, &valorSacado);

    for(int i = 0; i < banco->qtdContas; i++){
        if(VerificaConta(banco->contas[i], numConta) == 1){
            SaqueConta(banco->contas[i], valorSacado);
            break;
        }
    }
}

/**
 * @brief Realiza um depósito em uma conta do banco se ela existir.
 * 
 * @param banco Ponteiro para o banco onde a conta será depositada.
 */
void DepositoContaBanco(tBanco *banco){
    int numConta, valorDepositado;

    scanf("%d %d\n", &numConta, &valorDepositado);

    for(int i = 0; i < banco->qtdContas; i++){
        if(VerificaConta(banco->contas[i], numConta) == 1){
            DepositoConta(banco->contas[i], valorDepositado);
            break;
        }
    }
}

/**
 * @brief Realiza uma transferência entre duas contas do banco se elas existirem e a conta de origem tiver saldo suficiente.
 * 
 * @param banco Ponteiro para o banco onde as contas estão.
 */
void TransferenciaContaBanco(tBanco *banco){
    int origem, receptor, valorTransf;

    scanf("%d %d %d\n", &receptor, &origem, &valorTransf);

    for(int i = 0; i < banco->qtdContas; i++){
        if(VerificaConta(banco->contas[i], origem) == 1){

            for(int j = 0; j < banco->qtdContas; j++){
                if(VerificaConta(banco->contas[j], receptor) == 1){
                    TransferenciaConta(banco->contas[j], banco->contas[i], valorTransf);
                    break;
                }
            }

            break;
        }
    }
}

/**
 * @brief Imprime o relatório do banco, com todas as contas e seus respectivos dados.
 * 
 * @param banco Ponteiro para o banco a ser impresso.
 */
void ImprimeRelatorioBanco(tBanco *banco){
    printf("===| Imprimindo Relatorio |===\n");

    for(int i = 0; i < banco->qtdContas; i++){
        ImprimeConta(banco->contas[i]);
    }
}
