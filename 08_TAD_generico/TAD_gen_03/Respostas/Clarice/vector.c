

typedef void *data_type; // void pointer


typedef struct Vector{
    int tam;
    int tamAloc;
    data_type **vetor;
} Vector;

/**
 * @brief Cria um vetor vazio
 * 
 * @return A estrutura Vector inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
Vector *VectorConstruct(){
    Vector *vet;

    vet = (Vector*) calloc(1, sizeof(Vector));
    vet->vetor = (data_type*) calloc(1, sizeof(data_type*));

    vet->tamAloc = 1;
    vet->tam = 0;

    return vet;
}

/**
 * @brief Adiciona um elemento no final do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param val Valor a ser adicionado
*/
void VectorPushBack(Vector *v, data_type val){
    v->tamAloc++;
    v->vetor = (data_type**) realloc(v->vetor, (v->tamAloc * sizeof(data_type*)));

    v->vetor[v->tam] = val;
    v->tam++;
}

/**
 * @brief Retorna o i-ésimo elemento do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
 * @return data_type Elemento do vetor
*/
data_type VectorGet(Vector *v, int i){
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
void VectorDestroy(Vector *v, void (*destroy)(data_type)){
    for(int i = 0; i < v->tam; i++){
        destroy(v->vetor[i]);
    }

    free(v->vetor);
    free(v);
}

