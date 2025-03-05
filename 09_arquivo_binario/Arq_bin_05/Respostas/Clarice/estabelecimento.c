
#include <stdio.h>
#include "produto.h"
#include "vector.h"

/**
 * @brief Estrutura para representar um estabelecimento.
 */
typedef struct Estabelecimento{
    Vector *vetor;
    int qntProdutos;
} tEstabelecimento;

/**
 * @brief Função para criar um novo estabelecimento.
 * @return Um ponteiro para o estabelecimento recém-criado. Se houver erro na alocação, o programa é encerrado.
 */
tEstabelecimento *CriaEstabelecimento(){
    tEstabelecimento *estab;

    estab = (tEstabelecimento*) calloc(1, sizeof(tEstabelecimento));

    estab->vetor = VectorConstruct();

    return estab;
}

/**
 * @brief Função para destruir um estabelecimento.
 * @param estabelecimento Um ponteiro para o estabelecimento a ser destruído.
 */
void DestroiEstabelecimento(tEstabelecimento *estabelecimento){
    VectorDestroy(estabelecimento->vetor, DestroiProduto);

    free(estabelecimento);
}

/**
 * @brief Função para adicionar um produto a um estabelecimento.
 * @param estabelecimento Um ponteiro para o estabelecimento.
 * @param produto Um ponteiro para o produto a ser adicionado.
 */
void AdicionaProdutoEstabelecimento(tEstabelecimento *estabelecimento, tProduto *produto){
    VectorPushBack(estabelecimento->vetor, produto);
}

/**
 * @brief Função para ler um estabelecimento de um arquivo binário.
 * Inicialmente, deverá ser lido o nome do arquivo binário pela entrada padrão.
 * O arquivo binário deverá ser composto por um inteiro que representa a quantidade de produtos no estabelecimento, seguido pelos produtos.
 * @param estabelecimento Um ponteiro para o estabelecimento a ser lido.
 */
void LeEstabelecimento(tEstabelecimento *estabelecimento){
    int qnt = 0;
    char string[100];
    FILE *arq;

    scanf("%[^\n]\n", string);

    arq = fopen(string, "rb");

    if(arq != NULL){
        fread(&qnt, sizeof(int), 1, arq);
    }

    estabelecimento->qntProdutos = qnt;

    for(int i = 0; i < qnt; i++){
        AdicionaProdutoEstabelecimento(estabelecimento, LeProduto(arq));
    }

    fclose(arq);
}

/**
 * @brief Função para imprimir produtos que estão faltando em um estabelecimento no seguinte formato: Codigo;Nome;Preco
 * @param estabelecimento Um ponteiro para o estabelecimento.
 */
void ImprimeProdutosEmFaltaEstabelecimento(tEstabelecimento *estabelecimento){
    int temProdutos = 0;
    printf("Produtos em falta:\n");
    printf("Codigo;Nome;Preco\n");

    for(int i = 0; i < estabelecimento->qntProdutos; i++){
        if(TemEstoqueProduto(VectorGet(estabelecimento->vetor, i)) == 0){
            ImprimeProduto(VectorGet(estabelecimento->vetor, i));
            temProdutos = 1;
        }
    }

    if(temProdutos == 0) printf("Nao ha produtos em falta!\n");
}
