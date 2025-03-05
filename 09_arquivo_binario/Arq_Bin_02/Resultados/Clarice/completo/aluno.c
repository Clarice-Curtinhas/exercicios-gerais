#define MAX_TAM_NOME 100
#define MAX_TAM_DATA 11
#define MAX_TAM_CURSO 50

#include <stdio.h>
#include <string.h>

/**
 * @brief Estrutura para representar um aluno.
 */
typedef struct Aluno{
    char nome[MAX_TAM_NOME];
    char data[MAX_TAM_DATA];
    char curso[MAX_TAM_CURSO];
    int periodo;
    float rendimento;
} tAluno;

/**
 * @brief Função para criar um novo aluno.
 * 
 * @param nome Nome do aluno.
 * @param dataNascimento Data de nascimento do aluno.
 * @param curso Curso em que o aluno está matriculado.
 * @param periodo Período do curso em que o aluno está.
 * @param coeficienteRendimento Coeficiente de rendimento do aluno.
 * @return Um ponteiro para o aluno recém-criado. Se houver erro na alocação de memória, o programa é encerrado.
 */
tAluno* CriarAluno(char* nome, char* dataNascimento, char* curso, int periodo, float coeficienteRendimento){
    tAluno *a;

    a = (tAluno*) calloc(1, sizeof(tAluno));

    strcpy(a->nome, nome);
    strcpy(a->data, dataNascimento);
    strcpy(a->curso, curso);

    a->periodo = periodo;
    a->rendimento = coeficienteRendimento;

    return a;
}

/**
 * @brief Função para destruir um aluno.
 * 
 * @param aluno O aluno a ser destruído.
 */
void DestruirAluno(tAluno* aluno){
    free(aluno);
}

/**
 * @brief Função para ler um aluno de um arquivo binário.
 * 
 * @param arquivo_binario O arquivo binário para ler o aluno.
 * @return Um ponteiro para o aluno lido.
 */
tAluno *LeAluno(FILE *arquivo_binario){
    char nome[MAX_TAM_NOME], data[MAX_TAM_DATA], curso[MAX_TAM_CURSO];
    int periodo;
    float coef;

    fread(&nome, sizeof(char), MAX_TAM_NOME, arquivo_binario);
    fread(&data, sizeof(char), MAX_TAM_DATA, arquivo_binario);
    fread(&curso, sizeof(char), MAX_TAM_CURSO, arquivo_binario);
    fread(&periodo, sizeof(int), 1, arquivo_binario);
    fread(&coef, sizeof(float), 1, arquivo_binario);

    return CriarAluno(nome, data, curso, periodo, coef);
}

/**
 * @brief Função para obter o coeficiente de rendimento de um aluno.
 * 
 * @param aluno O aluno para obter o coeficiente de rendimento.
 * @return O coeficiente de rendimento do aluno.
 */
float GetCoeficienteRendimentoAluno(tAluno* aluno){
    return aluno->rendimento;
}
