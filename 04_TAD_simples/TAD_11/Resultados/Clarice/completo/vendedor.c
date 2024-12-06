#include <stdio.h>
#include <stdlib.h>

typedef struct Vendedor {
    char nome[50]; /**< Nome do vendedor */
    float valor_vendido; /**< Valor total vendido pelo vendedor */
    float salario; /**< Salário base do vendedor */
    float prct_comissao; /**< Porcentagem de comissão do vendedor */
} tVendedor;

/**
 * @brief Registra um novo vendedor.
 * 
 * @param nome Nome do vendedor.
 * @param salario Salário base do vendedor.
 * @param prct_comissao Porcentagem de comissão do vendedor.
 * @return tVendedor Retorna a estrutura do tipo tVendedor com os dados do vendedor registrado.
 */
tVendedor RegistraVendedor(char nome[50], float salario, float prct_comissao){
    int tam;
    tVendedor vendedor;
    
    for(tam = 0; nome[tam] != '\0'; tam++){
        vendedor.nome[tam] = nome[tam];
    }
    vendedor.nome[tam] = '\0';

    vendedor.salario = salario;
    vendedor.prct_comissao = prct_comissao;
    vendedor.valor_vendido = 0;

    return vendedor;
}

/**
 * @brief Verifica se o nome de um vendedor é igual a outro.
 * 
 * @param vendedor Estrutura do tipo tVendedor contendo os dados do vendedor a ser verificado.
 * @param nome Nome do vendedor a ser comparado.
 * @return int Retorna 1 se o nome do vendedor é igual ao nome passado como parâmetro, ou 0 caso contrário.
 */
int VerificaNomeVendedor(tVendedor vendedor, char nome[50]){
    int iguais = 1;

    for(int tam = 0; nome[tam] != '\0'; tam++){
        if(vendedor.nome[tam] != nome[tam]){
            iguais = 0;
            break;
        }
    }

    return iguais;
}

/**
 * @brief Contabiliza uma venda para um vendedor.
 * 
 * @param vendedor Estrutura do tipo tVendedor contendo os dados do vendedor.
 * @param valor Valor da venda a ser contabilizada.
 * @return tVendedor Retorna a estrutura do tipo tVendedor atualizada com o valor da venda contabilizada.
 */
tVendedor ContabilizaVenda(tVendedor vendedor, float valor){
    vendedor.valor_vendido += valor;
    return vendedor;
}

/**
 * @brief Obtém o salário de um vendedor.
 * 
 * @param vendedor Estrutura do tipo tVendedor contendo os dados do vendedor.
 * @return float Retorna o salário do vendedor.
 */
float GetSalario(tVendedor vendedor){
    return vendedor.salario;
}

/**
 * @brief Obtém a comissão de um vendedor.
 * 
 * @param vendedor Estrutura do tipo tVendedor contendo os dados do vendedor.
 * @return float Retorna a comissão do vendedor.
 */
float GetComissao(tVendedor vendedor){
    return (vendedor.valor_vendido * vendedor.prct_comissao);
}

/**
 * @brief Obtém o total vendido por um vendedor.
 * 
 * @param vendedor Estrutura do tipo tVendedor contendo os dados do vendedor.
 * @return float Retorna o total vendido pelo vendedor.
 */
float GetTotalVendido(tVendedor vendedor){
    return vendedor.valor_vendido;
}

/**
 * @brief Obtém o total recebido por um vendedor.
 * 
 * @param vendedor Estrutura do tipo tVendedor contendo os dados do vendedor.
 * @return float Retorna o total recebido pelo vendedor (salário + comissão).
 */
float GetTotalRecebido(tVendedor vendedor){
    return (vendedor.salario + GetComissao(vendedor));
}

/**
 * @brief Imprime o relatório de um vendedor.
 * 
 * @param vendedor Estrutura do tipo tVendedor contendo os dados do vendedor.
 */
void ImprimeRelatorioVendedor(tVendedor vendedor){
    printf("	%s > Total vendido: R$%.2f\n", vendedor.nome, vendedor.valor_vendido);
    printf("		Total recebido: R$%.2f\n", GetTotalRecebido(vendedor));
}