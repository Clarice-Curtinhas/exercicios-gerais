#include <stdio.h>
#include <stdlib.h>

typedef enum {
    FLOAT = 0,
    INT = 1
} Type;

typedef struct generic{
    void *lista;
    Type tipo;
    int numElem;
} tGeneric;

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar tanto inteiros quanto floats
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tGeneric* CriaGenerico(Type type, int numElem){
    tGeneric *gen;

    gen = (tGeneric*) calloc(1, sizeof(tGeneric));

    if(type == INT){
        gen->lista = (int*) calloc(numElem+1, sizeof(int));
    }

    else if(type == FLOAT){
        gen->lista = (float*) calloc(numElem+1, sizeof(float));
    }

    gen->tipo = type;
    gen->numElem = numElem;

    return gen;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param gen - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiGenerico(tGeneric* gen){
    free(gen->lista);
    free(gen);
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param gen - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LeGenerico(tGeneric* gen){
    int inte;
    float flo;

    printf("\nDigite o vetor:\n");

    for(int i = 0; i < gen->numElem; i++){

        if(gen->tipo == INT){
            scanf("%d ", &inte);
            ((int*)gen->lista)[i] = inte;
        }

        else if(gen->tipo == FLOAT){
            scanf("%f ", &flo);
            ((float*)gen->lista)[i] = flo;
        }
    }
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param gen - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimeGenerico(tGeneric* gen){
    int inte;
    float flo;

    for(int i = 0; i < gen->numElem; i++){
        if(gen->tipo == INT){
            inte = ((int*)gen->lista)[i];
            printf("%d ", inte);
        }

        else if(gen->tipo == FLOAT){
            flo = ((float*)gen->lista)[i];
            printf("%.2f ", flo);
        }
    }
}

