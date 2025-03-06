#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX_STRING 50

typedef struct Aluno{
    char nome[TAM_MAX_STRING];
    char data[TAM_MAX_STRING];
    char curso[TAM_MAX_STRING];
    float percent;
    float coef;
} tAluno;

/**
 * @brief Cria um novo aluno.
 * @param nome Nome do aluno.
 * @param dataNascimento Data de nascimento do aluno.
 * @param curso Curso do aluno.
 * @param prctConclusao Percentual de conclusão do curso.
 * @param cfRendimento Coeficiente de rendimento do aluno.
 * @return Um ponteiro para a estrutura do aluno criada. Caso a alocação falhe, a função termina o programa.
 */
tAluno *CriaAluno(char *nome, char *dataNascimento, char *curso, float prctConclusao, float cfRendimento){
    tAluno *aluno;

    aluno = (tAluno*) calloc(1, sizeof(tAluno));

    strcpy(aluno->nome, nome);
    strcpy(aluno->data, dataNascimento);
    strcpy(aluno->curso, curso);

    aluno->percent = prctConclusao;
    aluno->coef = cfRendimento;

    return aluno;
}

/**
 * @brief Destroi um aluno.
 * @param aluno Ponteiro para a estrutura do aluno a ser destruída.
 */
void DestroiAluno(tAluno *aluno){
    free(aluno);
}

/**
 * @brief Lê um aluno da entrada padrão.
 * @return Um ponteiro para a estrutura do aluno lida.
 */
tAluno *LeAluno(){
    tAluno *aluno;
    int i = 0;
    char nome[TAM_MAX_STRING], data[TAM_MAX_STRING], curso[TAM_MAX_STRING];
    float porct, coef;
    
    scanf("%[^\n]\n", nome);
    scanf("%[^\n]\n", data);
    scanf("%[^\n]\n", curso);


    scanf("%f\n%f\n", &porct, &coef);

    printf("%s\n", nome);

    aluno = CriaAluno(nome, data, curso, porct, coef);

    return aluno;
}

/**
 * @brief Compara o nome de dois alunos.
 * @param aluno1 Ponteiro para a estrutura do primeiro aluno.
 * @param aluno2 Ponteiro para a estrutura do segundo aluno.
 * @return Um inteiro indicando o resultado da comparação, conforme a função strcmp.
 */
int ComparaNomeAluno(tAluno *aluno1, tAluno *aluno2){
    return strcmp(aluno1->nome, aluno2->nome);
}

/**
 * @brief Salva um aluno em um arquivo binário.
 * @param aluno Ponteiro para a estrutura do aluno a ser salva.
 * @param file Ponteiro para o arquivo onde o aluno será salvo.
 * @return Um inteiro indicando o número de bytes salvos deste aluno.
 */
int SalvaAluno(tAluno *aluno, FILE *file){
    /*int numBytes = 0;
    
    numBytes += fread(aluno->nome, sizeof(char), strlen(aluno->nome), file);
    numBytes += fread(aluno->data, sizeof(char), strlen(aluno->data), file);
    numBytes += fread(aluno->curso, sizeof(char), strlen(aluno->curso), file);
    numBytes += fread(&aluno->percent, sizeof(float), 1, file);
    numBytes += fread(&aluno->coef, sizeof(float), 1, file);

    return numBytes;*/
}

/**
 * @brief Carrega um aluno de um arquivo binário.
 * @param aluno Ponteiro para a estrutura do aluno a ser carregada.
 * @param file Ponteiro para o arquivo de onde o aluno será carregado.
 * @return Um inteiro indicando o número de bytes lidos deste aluno.
 */
int CarregaAluno(tAluno *aluno, FILE *file){
    /*int numBytes = 0;
    
    numBytes += fwrite(aluno->nome, sizeof(char), TAM_MAX_STRING, file);
    numBytes += fwrite(aluno->data, sizeof(char), TAM_MAX_STRING, file);
    numBytes += fwrite(aluno->curso, sizeof(char), TAM_MAX_STRING, file);
    numBytes += fwrite(&aluno->percent, sizeof(float), 1, file);
    numBytes += fwrite(&aluno->coef, sizeof(float), 1, file);

    return numBytes;*/
}

/**
 * @brief Imprime o nome de um aluno na saída padrão.
 * @param aluno Ponteiro para a estrutura do aluno cujo nome será impresso.
 */
void ImprimeNomeAluno(tAluno *aluno){
    printf("%s\n", aluno->nome);
}
