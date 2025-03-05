
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
    int quant;
} tProduto;

/**
 * @brief Função para criar um novo produto.
 * @param codigo O código do produto.
 * @param nome O nome do produto.
 * @param preco O preço do produto.
 * @param quantidade A quantidade do produto em estoque.
 * @return Um ponteiro para o produto recém-criado. Se houver erro na alocação de memória, a função aborta o programa.
 */
tProduto *CriaProduto(int codigo, char *nome, float preco, int quantidade){
    tProduto *p;

    p = (tProduto*) calloc(1, sizeof(tProduto));

    p->codigo = codigo;

    strcpy(p->nome, nome);

    p->preco = preco;
    p->quant = quantidade;

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
    int codigo, estoque;
    char nome[MAX_TAM_NOME];
    float preco;

    fread(&codigo, sizeof(int), 1, arquivo);
    fread(&nome, sizeof(char), MAX_TAM_NOME, arquivo);
    fread(&preco, sizeof(float), 1, arquivo);
    fread(&estoque, sizeof(int), 1, arquivo);

    p = CriaProduto(codigo, nome, preco, estoque);
}

/**
 * @brief Função para verificar se um produto tem estoque.
 * @param produto Um ponteiro para o produto.
 * @return 1 se o produto tem estoque, 0 caso contrário.
 */
int TemEstoqueProduto(tProduto *produto){
    if(produto->quant > 0) return 1;
    else return 0;
}

/**
 * @brief Função para imprimir um produto no formato "Codigo;Nome;Preco".
 * @param produto Um ponteiro para o produto a ser impresso.
 */
void ImprimeProduto(tProduto *produto){
    printf("%d;%s;%.2f\n", produto->codigo, produto->nome, produto->preco);
}
