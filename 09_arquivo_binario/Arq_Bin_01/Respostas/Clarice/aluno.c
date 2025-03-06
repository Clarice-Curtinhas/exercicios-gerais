#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define TAM_STRING 50

typedef struct aluno{
    char nome[TAM_STRING], dataDeNasc[TAM_STRING], curso[TAM_STRING], periodo[TAM_STRING];
    int porcentConcl;
    float cra;
} Aluno;

Aluno** CriaVetorAlunos(int numeroAlunos){
    Aluno **divos;

    divos = (Aluno**) calloc(numeroAlunos, sizeof(Aluno*));

    return divos;
}

Aluno* CriaAluno(char *nome, char *dtNasc, char *cursoUfes, char* periodoIngresso, int percConclusao, float CRA){
    Aluno *aluno;

    aluno = (Aluno*) calloc(1, sizeof(Aluno));

    strcpy(aluno->nome, nome);
    strcpy(aluno->dataDeNasc, dtNasc);
    strcpy(aluno->curso, cursoUfes);
    strcpy(aluno->periodo, periodoIngresso);

    aluno->porcentConcl = percConclusao;
    aluno->cra = CRA;

    return aluno;
}

void LeAlunos(Aluno** vetorAlunos, int numeroAlunos){
    char nome[TAM_STRING], data[TAM_STRING], curso[TAM_STRING], period[TAM_STRING];
    int porcent;
    float cra;

    for(int i = 0; i < numeroAlunos; i++){
        scanf("\n%[^\n]\n", nome);
        scanf("%[^\n]\n", data);
        scanf("%[^\n]\n", curso);
        scanf("%[^\n]\n", period);
        scanf("%d\n", &porcent);
        scanf("%f\n", &cra);

        vetorAlunos[i] = CriaAluno(nome, data, curso, period, porcent, cra);
    }
}

void LiberaAlunos(Aluno** alunos, int numeroAlunos){
    for(int i = 0; i < numeroAlunos; i++){
        free(alunos[i]);
    }

    free(alunos);
}

void SalvaAlunosBinario(Aluno **alunos, char *fileName, int numeroAlunos){
    int qntBytes = 0;
    char c = '\0';
    int tam;
    FILE *arq;

    arq = fopen(fileName, "wb");

    if(arq != NULL){
        for(int i = 0; i < numeroAlunos; i++){
            tam = strlen(alunos[i]->nome);
            qntBytes += fwrite(&alunos[i]->nome, sizeof(char), tam, arq);
            fwrite(&c, sizeof(char), 1, arq);

            tam = strlen(alunos[i]->dataDeNasc);
            qntBytes += fwrite(&alunos[i]->dataDeNasc, sizeof(char), tam, arq);
            fwrite(&c, sizeof(char), 1, arq);

            tam = strlen(alunos[i]->curso);
            qntBytes += fwrite(&alunos[i]->curso, sizeof(char), tam, arq);
            fwrite(&c, sizeof(char), 1, arq);

            tam = strlen(alunos[i]->periodo);
            qntBytes += fwrite(&alunos[i]->periodo, sizeof(char), tam, arq);
            fwrite(&c, sizeof(char), 1, arq);
            
            qntBytes += fwrite(&alunos[i]->porcentConcl, sizeof(int), 1, arq);
            qntBytes += fwrite(&alunos[i]->cra, sizeof(float), 1, arq);
        }
    }

    fclose(arq);

    printf("Numero de bytes salvos: %d\n", qntBytes);
}

void CarregaAlunosBinario(Aluno **alunos, char *fileName){
    char nome[TAM_STRING], data[TAM_STRING], curso[TAM_STRING], period[TAM_STRING];
    int porcent, i = 0;
    float cra;

    FILE *arq;

    nome[0] = '\0';
    data[0] = '\0';
    curso[0] = '\0';
    period[0] = '\0';

    arq = fopen(fileName, "rb");

    if(arq != NULL){
        while(1){
            Aluno *a;

            fread(&nome, sizeof(char), TAM_STRING, arq);
            fread(&data, sizeof(char), TAM_STRING, arq);
            fread(&curso, sizeof(char), TAM_STRING, arq);
            fread(&period, sizeof(char), TAM_STRING, arq);
            fread(&porcent, sizeof(int), 1, arq);
            fread(&cra, sizeof(float), 1, arq);

            a = CriaAluno(nome, data, curso, period, porcent, cra);

            alunos[i] = a;
            i++;
        }
    }

    fclose(arq);
}

void ImprimeAlunos(Aluno** alunos, int numeroAlunos){
    for(int i = 0; i < numeroAlunos; i++){
        printf("Aluno %d:", i);
        printf("Nome: %s\n", alunos[i]->nome);
        printf("Data Nascimento: %s\n", alunos[i]->dataDeNasc);
        printf("Curso: %s\n", alunos[i]->curso);
        printf("Periodo Ingresso: %s\n", alunos[i]->periodo);
        printf("%% Conclusao do Curso: %d\n", alunos[i]->porcentConcl);
        printf("CRA: %.2f\n", alunos[i]->cra);
    }
}