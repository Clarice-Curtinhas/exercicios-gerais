#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Array {
    int *data;
    int tamanho;
} Array;

/**
 * @brief Inicializa um novo array, apontando data para NULL e tamanho para 0.
 * @return Ponteiro para a estrutura Array criada ou encerra caso não seja possível alocar memória.
 */
Array *CriarArray(){
    Array *array;

    array = (Array*) calloc(1, sizeof(Array));
    array->data = (int*) calloc(1, sizeof(int));
    array->data = NULL;
    array->tamanho = 0;

    return array;
}


/**
 * @brief Libera a memória alocada para o array.
 * @param array Ponteiro para a estrutura Array a ser destruída.
 */
void DestruirArray(Array *array){
    free(array->data);
    free(array);
}

/**
 * @brief Lê os elementos do array a partir da entrada padrão e aloca memória para eles.
 * @details A leitura é feita até encontrar um ponto final (.) na entrada.
 * @param array Ponteiro para a estrutura Array a ser preenchida.
 */
void LerArray(Array *array){
    char buff;

    while((scanf("%d%c", &array->data[array->tamanho], &buff) == 2) && (buff != '.')){
        array->tamanho++;
        array->data = (int*) realloc(array->data, (array->tamanho+1)*sizeof(int));
    }

    array->data[array->tamanho] = '\0';
}

/**
 * @brief Ordena os elementos do array em ordem crescente.
 * @param array Ponteiro para a estrutura Array a ser ordenada.
 */
void OrdenarArray(Array *array){
    int num;

    for(int i = 0; i < array->tamanho; i++){
        for(int j = i; j < array->tamanho; j++){
            if(array->data[i] > array->data[j]){
                num = array->data[i];

                array->data[i] = array->data[j];
                array->data[j] = num;
            }
        }
    }
}

/**
 * @brief Realiza uma busca binária no array pelo elemento especificado.
 * @param array Ponteiro para a estrutura Array a ser buscada.
 * @param elementoBuscado Elemento a ser buscado no array.
 * @return Índice do elemento buscado no array, ou -1 caso não seja encontrado.
 */
int BuscaBinariaArray(Array *array, int elementoBuscado){
    int num = array->tamanho, qnt = 1;

    while(1){
        if(qnt < array->tamanho){
            if(array->data[num] < elementoBuscado){
                num = abs(num/2);
            }

            else if(array->data[num] > elementoBuscado){
                num = abs((num/2) *qnt);
            }
        }

        if(array->data[num] == elementoBuscado) break;

        else{
            num = -1;
        }

        qnt++;
    }

    return num;
}
