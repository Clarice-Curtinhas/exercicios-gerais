
#include <stdio.h>
#include "produto.h"
#include "vector.h"

/**
 * @brief Estrutura para representar um estabelecimento.
 */
typedef struct Estabelecimento{
    Vector *v;
    int qnt;
} tEstabelecimento;

/**
 * @brief Função para criar um novo estabelecimento.
 * @return Um ponteiro para o estabelecimento recém-criado. Se houver erro na alocação, o programa é encerrado.
 */
tEstabelecimento *CriaEstabelecimento(){
    tEstabelecimento *e;

    e = (tEstabelecimento*) calloc(1, sizeof(tEstabelecimento));

    e->v = VectorConstruct();

    return e;
}

/**
 * @brief Função para destruir um estabelecimento.
 * @param estabelecimento Um ponteiro para o estabelecimento a ser destruído.
 */
void DestroiEstabelecimento(tEstabelecimento *estabelecimento){
    VectorDestroy(estabelecimento->v, DestroiProduto);
    free(estabelecimento);
}

/**
 * @brief Função para adicionar um produto a um estabelecimento.
 * @param estabelecimento Um ponteiro para o estabelecimento.
 * @param produto Um ponteiro para o produto a ser adicionado.
 */
void AdicionaProdutoEstabelecimento(tEstabelecimento *estabelecimento, tProduto *produto){
    VectorPushBack(estabelecimento->v, produto);
}

/**
 * @brief Função para ler um estabelecimento de um arquivo binário.
 * Inicialmente, deverá ser lido o nome do arquivo binário pela entrada padrão.
 * O arquivo binário deverá ser composto por um inteiro que representa a quantidade de produtos no estabelecimento, seguido pelos produtos.
 * @param estabelecimento Um ponteiro para o estabelecimento a ser lido.
 */
void LeEstabelecimento(tEstabelecimento *estabelecimento){
    FILE *arq;
    int qnt;
    char string[100];

    scanf("%[^\n]\n", string);

    arq = fopen(string, "rb");

    if(arq != NULL){
        fread(&qnt, sizeof(int), 1, arq);

        estabelecimento->qnt = qnt;

        for(int i = 0; i < qnt; i++){
            VectorPushBack(estabelecimento->v, LeProduto(arq));
        }
    }

    fclose(arq);
}

/**
 * @brief Função para obter o valor total de produtos vendidos em um estabelecimento.
 * @param estabelecimento Um ponteiro para o estabelecimento.
 * @return O valor total de produtos vendidos.
*/
float GetValorTotalVendidoEstabelecimento(tEstabelecimento *estabelecimento){
    float qntVendida = 0;

    for(int i = 0; i < estabelecimento->qnt; i++){
        qntVendida += (GetQuantidadeVendidaProduto(VectorGet(estabelecimento->v, i)) * GetPrecoProduto(VectorGet(estabelecimento->v, i)));
    }

    return qntVendida;
}

/**
 * @brief Função para imprimir na tela um relatório de um estabelecimento, cotendo o valor total vendido e a porcentagem de cada produto relativo ao total vendido.
 * Formato: Codigo;Nome;Preco;Quantidade vendida
 * @param estabelecimento Um ponteiro para o estabelecimento.
*/
void ImprimeRelatorioEstabelecimento(tEstabelecimento *estabelecimento){
    float total = GetValorTotalVendidoEstabelecimento(estabelecimento);
    float valorProd = 0, porcent;

    printf("Valor total vendido: R$ %.2f\n", total);
    printf("Produtos vendidos:\n");
    printf("Codigo;Nome;Preco;Quantidade vendida;Porcentagem\n");

    for(int i = 0; i < estabelecimento->qnt; i++){
        ImprimeProduto(VectorGet(estabelecimento->v, i));

        valorProd = (GetQuantidadeVendidaProduto(VectorGet(estabelecimento->v, i)) * GetPrecoProduto(VectorGet(estabelecimento->v, i)));

        porcent = (valorProd*100)/total;

        printf(";%.2f%%\n", porcent);
    }
}

