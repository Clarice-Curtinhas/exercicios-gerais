#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
/**
 * @brief Estrutura para representar uma base de alunos.
 */
typedef struct BaseAlunos{
    tAluno **alunos;
    int qntAlunos;
    int alocs;
} tBaseAlunos;

/**
 * @brief Função para criar uma nova base de alunos.
 * 
 * @return Um ponteiro para a base de alunos recém-criada. Se houver erro na alocação de memória, o programa é encerrado.
 */
tBaseAlunos* CriarBaseAlunos(){
    tBaseAlunos *baseAlunos;

    baseAlunos = (tBaseAlunos*) calloc(1, sizeof(tBaseAlunos));

    baseAlunos->alunos = (tAluno**) calloc(1, sizeof(tAluno*));

    baseAlunos->qntAlunos = 0;
    baseAlunos->alocs = 1;

    return baseAlunos;
}

/**
 * @brief Função para destruir uma base de alunos.
 * 
 * @param baseAlunos A base de alunos a ser destruída.
 */
void DestruirBaseAlunos(tBaseAlunos* baseAlunos){
    for(int i = 0; i < baseAlunos->qntAlunos; i++){
        DestruirAluno(baseAlunos->alunos[i]);
    }

    free(baseAlunos->alunos);
    free(baseAlunos);
}

/**
 * @brief Função para ler uma base de alunos de um arquivo binário.
 * 
 * @param baseAlunos A base de alunos para ler o arquivo.
 * @param nomeArquivo O nome do arquivo a ser lido.
 */
void LerBaseAlunos(tBaseAlunos* baseAlunos, char* nomeArquivo){
    int qntAlunos;
    FILE *arq;

    arq = fopen(nomeArquivo, "rb");

    if(arq != NULL){
        fread(&qntAlunos, sizeof(int), 1, arq);
        baseAlunos->qntAlunos = qntAlunos;
        baseAlunos->alunos = (tAluno**) realloc(baseAlunos->alunos, baseAlunos->qntAlunos * sizeof(tAluno*));

        for (int i = 0; i < baseAlunos->qntAlunos; i++){
            baseAlunos->alunos[i] = LeAluno(arq);
        }
        
    }

    fclose(arq);
}

/**
 * @brief Função para obter o coeficiente de rendimento médio de uma base de alunos.
 * 
 * @param baseAlunos A base de alunos para obter o coeficiente de rendimento médio.
 * @return O coeficiente de rendimento médio da base de alunos.
 */
float GetCoeficienteRendimentoMedioBaseAlunos(tBaseAlunos* baseAlunos){
    float coefMedio, soma = 0;

    for (int i = 0; i < baseAlunos->qntAlunos; i++){
        soma += GetCoeficienteRendimentoAluno(baseAlunos->alunos[i]);
    }

    coefMedio = soma / baseAlunos->qntAlunos;

    return coefMedio;
}
