
#include <stdio.h>
#include <string.h>

#define MAX_TAM_NOME 50

/**
 * @brief Estrutura para representar um produto.
 */
typedef struct Produto{
    int codigo;
    char nome[MAX_TAM_NOME];
    float preco;
    int qntVendida;
} tProduto;

/**
 * @brief Função para criar um novo produto.
 * @param codigo O código do produto.
 * @param nome O nome do produto.
 * @param preco O preço do produto.
 * @param quantidade A quantidade do produto em estoque.
 * @return Um ponteiro para o produto recém-criado. Se houver erro na alocação de memória, a função aborta o programa.
 */
tProduto *CriaProduto(int codigo, char *nome, float preco, int quantidadeVendida){
    tProduto *p;

    p = (tProduto*) calloc(1, sizeof(tProduto));

    p->codigo = codigo;
    strcpy(p->nome, nome);
    p->preco = preco;
    p->qntVendida = quantidadeVendida;

    return p;
}

/**
 * @brief Função para destruir um produto.
 * @param produto Um ponteiro para o produto a ser destruído.
 */
void DestroiProduto(tProduto *produto){
    free(produto);
}

/**
 * @brief Função para ler um produto de um arquivo binário.
 * @param arquivo O arquivo de onde o produto será lido.
 * Formato do arquivo: 
 * Código (int) 
 * Nome (string) 
 * Preço (float) 
 * Quantidade (int).
 * @return Um ponteiro para o produto lido.
 */
tProduto *LeProduto(FILE *arquivo){
    tProduto *p;

    int codigo, qnt;
    float preco;
    char nome[MAX_TAM_NOME];

    fread(&codigo, sizeof(int), 1, arquivo);
    fread(&nome, sizeof(char), MAX_TAM_NOME, arquivo);
    fread(&preco, sizeof(float), 1, arquivo);
    fread(&qnt, sizeof(int), 1, arquivo);

    p = CriaProduto(codigo, nome, preco, qnt);

    return p;
}

/**
 * @brief Função para imprimir um produto no formato "Codigo;Nome;Preco;Quantidade vendida".
 * @param produto Um ponteiro para o produto a ser impresso.
 */
void ImprimeProduto(tProduto *produto){
    printf("%d;%s;R$ %.2f;%d", produto->codigo, produto->nome, produto->preco, produto->qntVendida);
}

/**
 * @brief Função para obter a quantidade vendida de um produto.
 * @param produto Um ponteiro para o produto.
 * @return A quantidade vendida do produto.
 */
int GetQuantidadeVendidaProduto(tProduto *produto){
    return produto->qntVendida;
}

/**
 * @brief Função para obter o preço de um produto.
 * @param produto Um ponteiro para o produto.
 * @return O preço do produto.
*/
float GetPrecoProduto(tProduto *produto){
    return produto->preco;
}

