

typedef void *DataType; // void pointer
typedef struct Vector{
    DataType **vetor;
    int aloc;
    int qnt;
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

    v->aloc = 1;
    v->qnt = 0;

    return v;
}

/**
 * @brief Adiciona um elemento no final do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param val Valor a ser adicionado
*/
void VectorPushBack(Vector *v, DataType val){
    v->vetor[v->qnt] = val;

    v->aloc++;
    v->qnt++;

    v->vetor = (DataType**) realloc(v->vetor, (v->aloc+1)*sizeof(DataType*));
}

/**
 * @brief Remove o i-ésimo elemento do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
*/
void VectorRemove(Vector *v, int i){
    for(int j = i; j < v->qnt-1; j++){
        v->vetor[j] = v->vetor[j+1];
    }

    v->qnt--;
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
    return v->qnt;
}

/**
 * @brief Libera a memória alocada para o vetor
 * 
 * @param v Ponteiro para o vetor
 * @param destroy Função que libera a memória alocada para cada elemento do vetor
*/
void VectorDestroy(Vector *v, void (*destroy)(DataType)){
    for(int i = 0; i < v->qnt; i++){
        destroy(v->vetor[i]);
    }

    free(v->vetor);
    free(v);
}
