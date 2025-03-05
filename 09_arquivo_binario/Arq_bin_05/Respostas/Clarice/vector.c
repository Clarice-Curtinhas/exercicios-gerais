
typedef void *DataType; // void pointer
typedef struct Vector{
    void **vetor;
    int alocs;
    int qntUsada;
} Vector;

/**
 * @brief Cria um vetor vazio
 * 
 * @return A estrutura Vector inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
Vector *VectorConstruct(){
    Vector *vetor;

    vetor = (Vector*) calloc(1, sizeof(Vector));

    vetor->vetor = (void**) calloc(1, sizeof(void*));

    vetor->alocs = 1;
    vetor->qntUsada = 0;

    return vetor;
}

/**
 * @brief Adiciona um elemento no final do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param val Valor a ser adicionado
*/
void VectorPushBack(Vector *v, DataType val){
    v->vetor[v->qntUsada] = val;

    v->alocs++;
    v->qntUsada++;

    v->vetor = (void**) realloc(v->vetor, (v->alocs+1)*sizeof(void*));
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
    return v->qntUsada;
}

/**
 * @brief Libera a memória alocada para o vetor
 * 
 * @param v Ponteiro para o vetor
 * @param destroy Função que libera a memória alocada para cada elemento do vetor
*/
void VectorDestroy(Vector *v, void (*destroy)(DataType)){
    for(int i = 0; i < v->qntUsada; i++){
        destroy(v->vetor[i]);
    }

    free(v->vetor);
    free(v);
}
