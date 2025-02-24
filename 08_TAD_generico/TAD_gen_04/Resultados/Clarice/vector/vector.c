#include <stdio.h>
#include <stdlib.h>

typedef void *DataType; // void pointer

typedef struct Vector{
    int tamAloc;
    int tam;
    DataType **vetor;
} Vector;

/**
 * @brief Cria um vetor vazio
 * 
 * @return A estrutura Vector inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
Vector *VectorConstruct(){
    Vector *v;

    v = (Vector*) calloc(1, sizeof(Vector));
    v->vetor = (DataType**) calloc(1, sizeof(DataType*));

    v->tam = 0;
    v->tamAloc = 1;

    return v;
}

/**
 * @brief Adiciona um elemento no final do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param val Valor a ser adicionado
*/
void VectorPushBack(Vector *v, DataType val){
    v->tamAloc++;
    v->vetor = (DataType**) realloc(v->vetor, (v->tamAloc * sizeof(DataType*)));

    v->vetor[v->tam] = val;
    v->tam++;
}

/**
 * @brief Retorna o i-ésimo elemento do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
 * @return DataType Elemento do vetor
*/
DataType VectorGet(Vector *v, int i){
    return v->vetor[i];
}

/**
 * @brief Retorna o tamanho do vetor
 * 
 * @param v Ponteiro para o vetor
 * @return int Tamanho do vetor
*/
int VectorSize(Vector *v){
    return v->tam;
}

/**
 * @brief Libera a memória alocada para o vetor
 * 
 * @param v Ponteiro para o vetor
 * @param destroy Função que libera a memória alocada para cada elemento do vetor
*/
void VectorDestroy(Vector *v, void (*destroy)(DataType)){
    for(int i = 0; i < v->tam; i++){
        destroy(v->vetor[i]);
    }

    free(v->vetor);
    free(v);
}