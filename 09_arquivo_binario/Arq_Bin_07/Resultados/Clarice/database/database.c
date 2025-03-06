#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aluno.h"
#include "professor.h"
#include "vector.h"

typedef struct Database{
    tAluno **aluno;
    tProfessor **prof;
} tDatabase;

/**
 * @brief Cria um nova database.
 * @return Um ponteiro para a estrutura database criada. Caso a alocação falhe, a função termina o programa.
 */
tDatabase *CriaDatabase(){
    tDatabase *data;

    data = (tDatabase*) calloc(1, sizeof(tDatabase));

    data->aluno = VectorConstruct();
    data->prof = VectorConstruct();

    return data;
}

/**
 * @brief Destroi uma database.
 * @param db Ponteiro para a estrutura da database a ser destruída.
 */
void DestroiDatabase(tDatabase *db){
    VectorDestroy(db->aluno, DestroiAluno);
    VectorDestroy(db->prof, DestroiProfessor);

    free(db);
}

/**
 * @brief Lê uma database da entrada padrão.
 * @param db Ponteiro para a estrutura da database a ser lida.
 */
void LeDatabase(tDatabase *db){
    int qnt;

    scanf("%d\n", &qnt);

    for(int i = 0; i < qnt; i++){
        tAluno *a;

        a = LeAluno();

        VectorPushBack(db->aluno, a);
    }

    scanf("%d\n", &qnt);

    for(int i = 0; i < qnt; i++){
        tProfessor *p;
        
        p = LeProfessor();

        VectorPushBack(db->prof, p);
    }
}

/**
 * @brief Ordena uma database, primeiro os alunos e depois os professores, de acordo com o nome.
 * @param db Ponteiro para a estrutura da database a ser ordenada.
 */
void OrdenaDatabase(tDatabase *db){
    for(int i = 0; i < VectorSize(db->aluno); i++){
        if(ComparaNomeAluno(VectorGet(db->aluno, i), VectorGet(db->aluno, i+1)) == -1){
            VectorSwap(db->aluno, i, i+1);
        }
    }

    for(int i = 0; i < VectorSize(db->prof); i++){
        if(ComparaNomeProfessor(VectorGet(db->prof, i), VectorGet(db->prof, i+1)) == -1){
            VectorSwap(db->prof, i, i+1);
        }
    }
}

/**
 * @brief Salva uma database em um arquivo binário.
 * @param db Ponteiro para a estrutura da database a ser salva.
 * @param file Ponteiro para o arquivo onde a database será salva.
 * @return Um inteiro indicando o total de bytes salvos.
 */
int SalvarDatabase(tDatabase *db, FILE *file){
    int numBytes = 0;

    for(int i = 0; i < VectorSize(db->aluno); i++){
        numBytes += SalvaAluno(VectorGet(db->aluno, i), file);
    }

    for(int i = 0; i < VectorSize(db->prof); i++){
        numBytes += SalvaProfessor(VectorGet(db->prof, i), file);
    }

    return numBytes;
}

/**
 * @brief Carrega uma database de um arquivo binário.
 * @param db Ponteiro para a estrutura da database a ser carregada.
 * @param file Ponteiro para o arquivo de onde a database será carregada.
 * @return Um inteiro indicando o total de bytes lidos.
 */
int CarregaDatabase(tDatabase *db, FILE *file){
    int numBytes = 0;

    for(int i = 0; i < VectorSize(db->aluno); i++){
        numBytes += CarregaAluno(VectorGet(db->aluno, i), file);
    }

    for(int i = 0; i < VectorSize(db->prof); i++){
        numBytes += CarregaProfessor(VectorGet(db->prof, i), file);
    }

    return numBytes;
}

/**
 * @brief Imprime uma database, primeiro os alunos e depois os professores. Apenas os nomes são impressos.
 * @param db Ponteiro para a estrutura da database a ser impressa.
 */
void ImprimeDatabase(tDatabase *db){
    for(int i = 0; i < VectorSize(db->aluno); i++){
        ImprimeNomeAluno(VectorGet(db->aluno, i));
    }

    for(int i = 0; i < VectorSize(db->prof); i++){
        ImprimeNomeProfessor(VectorGet(db->prof, i));
    }
}
