#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX_STRING 50

typedef struct Professor{
    char nome[TAM_MAX_STRING];
    char data[TAM_MAX_STRING];
    char departamento[TAM_MAX_STRING];
} tProfessor;

/**
 * @brief Cria um novo professor.
 * @param nome Nome do professor.
 * @param dataNascimento Data de nascimento do professor.
 * @param departamento Departamento do professor.
 * @return Um ponteiro para a estrutura do professor criada. Caso a alocação falhe, a função termina o programa.
 */
tProfessor *CriaProfessor(char *nome, char *dataNascimento, char *departamento){
    tProfessor *p;

    p = (tProfessor*) calloc(1, sizeof(tProfessor));

    strcpy(p->nome, nome);
    strcpy(p->data, dataNascimento);
    strcpy(p->departamento, departamento);

    return p;
}

/**
 * @brief Destroi um professor.
 * @param prof Ponteiro para a estrutura do professor a ser destruída.
 */
void DestroiProfessor(tProfessor *prof){
    free(prof);
}

/**
 * @brief Lê um professor da entrada padrão.
 * @return Um ponteiro para a estrutura do professor lida.
 */
tProfessor *LeProfessor(){
    char nome[TAM_MAX_STRING], data[TAM_MAX_STRING], depart[TAM_MAX_STRING];
    tProfessor *p;

    scanf("\n%[^\n]\n", nome);
    scanf("%[^\n]\n", data);
    scanf("%[^\n]\n", depart);

    p = CriaProfessor(nome, data, depart);

    return p;
}

/**
 * @brief Compara o nome de dois professores.
 * @param prof1 Ponteiro para a estrutura do primeiro professor.
 * @param prof2 Ponteiro para a estrutura do segundo professor.
 * @return Um inteiro indicando o resultado da comparação, conforme a função strcmp.
 */
int ComparaNomeProfessor(tProfessor *prof1, tProfessor *prof2){
    return strcmp(prof1->nome, prof2->nome);
}

/**
 * @brief Salva um professor em um arquivo binário.
 * @param prof Ponteiro para a estrutura do professor a ser salva.
 * @param file Ponteiro para o arquivo onde o professor será salvo.
 * @return Um inteiro indicando o número de bytes salvos deste professor.
 */
int SalvaProfessor(tProfessor *prof, FILE *file){
    int numBytes = 0, tam;

    tam = sizeof(prof->nome)+1;
    fwrite(&tam, sizeof(int), 1, file);
    numBytes += fwrite(prof->nome, sizeof(char), tam, file);
    printf("%s\n\n", prof->nome);

    tam = sizeof(prof->data)+1;
    fwrite(&tam, sizeof(int), 1, file);
    numBytes += fwrite(prof->data, sizeof(char), tam, file);

    tam = sizeof(prof->departamento)+1;
    fwrite(&tam, sizeof(int), 1, file);
    numBytes += fwrite(prof->departamento, sizeof(char), tam, file);


    return numBytes;
}

/**
 * @brief Carrega um professor de um arquivo binário.
 * @param prof Ponteiro para a estrutura do professor a ser carregada.
 * @param file Ponteiro para o arquivo de onde o professor será carregado.
 * @return Um inteiro indicando o número de bytes lidos deste professor.
 */
int CarregaProfessor(tProfessor *prof, FILE *file){
    int numBytes = 0, tam;

    fread(&tam, sizeof(int), 1, file);
    numBytes += fread(prof->nome, sizeof(char), tam, file);
    printf("%s\n\n", prof->nome);

    fread(&tam, sizeof(int), 1, file);
    numBytes += fread(prof->data, sizeof(char), tam, file);

    fread(&tam, sizeof(int), 1, file);
    numBytes += fread(prof->departamento, sizeof(char), tam, file);

    return numBytes;
}

/**
 * @brief Imprime o nome de um professor.
 * @param prof Ponteiro para a estrutura do professor cujo nome será impresso.
 */
void ImprimeNomeProfessor(tProfessor *prof){
    printf("%s\n", prof->nome);
}
