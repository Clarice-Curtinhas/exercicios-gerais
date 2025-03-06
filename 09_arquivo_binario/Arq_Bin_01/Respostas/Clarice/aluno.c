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
    Aluno **alunos;

    alunos = (Aluno**) calloc(numeroAlunos, sizeof(Aluno*));

    return alunos;
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
        qntBytes += fwrite(&numeroAlunos, sizeof(int), 1, arq);
        for(int i = 0; i < numeroAlunos; i++){
            //qntBytes += fwrite(alunos[i], sizeof(Aluno), 1, arq);

            tam = strlen(alunos[i]->nome)+1;
            qntBytes += fwrite(&tam, sizeof(int), 1, arq);
            qntBytes += fwrite(&alunos[i]->nome, sizeof(char), tam, arq);

            tam = strlen(alunos[i]->dataDeNasc)+1;
            qntBytes += fwrite(&tam, sizeof(int), 1, arq);
            qntBytes += fwrite(&alunos[i]->dataDeNasc, sizeof(char), tam, arq);

            tam = strlen(alunos[i]->curso)+1;
            qntBytes += fwrite(&tam, sizeof(int), 1, arq);
            qntBytes += fwrite(&alunos[i]->curso, sizeof(char), tam, arq);

            tam = strlen(alunos[i]->periodo)+1;
            qntBytes += fwrite(&tam, sizeof(int), 1, arq);
            qntBytes += fwrite(&alunos[i]->periodo, sizeof(char), tam, arq);

            qntBytes += fwrite(&alunos[i]->porcentConcl, sizeof(int), 1, arq);
            qntBytes += fwrite(&alunos[i]->cra, sizeof(float), 1, arq);
        }
    }

    fclose(arq);

    printf("Numero de bytes salvos: %d\n", qntBytes);
}

void CarregaAlunosBinario(Aluno **alunos, char *fileName){
    char nome[TAM_STRING], data[TAM_STRING], curso[TAM_STRING], period[TAM_STRING];
    int porcent, i = 0, tam, numeroAlunos;
    float cra;

    FILE *arq;

    arq = fopen(fileName, "rb");

    if(arq != NULL){
        fread(&numeroAlunos, sizeof(int), 1, arq);

        for(int i = 0; i < numeroAlunos; i++){
            Aluno *a;

            fread(&tam, sizeof(int), 1, arq);
            fread(&nome, sizeof(char), tam, arq);

            fread(&tam, sizeof(int), 1, arq);
            fread(&data, sizeof(char), tam, arq);

            fread(&tam, sizeof(int), 1, arq);
            fread(&curso, sizeof(char), tam, arq);

            fread(&tam, sizeof(int), 1, arq);
            fread(&period, sizeof(char), tam, arq);

            fread(&porcent, sizeof(int), 1, arq);
            fread(&cra, sizeof(float), 1, arq);

            a = CriaAluno(nome, data, curso, period, porcent, cra);

            alunos[i] = a;
        }
    }

    fclose(arq);
}

void ImprimeAlunos(Aluno** alunos, int numeroAlunos){
    for(int i = 0; i < numeroAlunos; i++){
        printf("Aluno %d:\n", i);
        printf("Nome: %s\n", alunos[i]->nome);
        printf("Data Nascimento: %s\n", alunos[i]->dataDeNasc);
        printf("Curso: %s\n", alunos[i]->curso);
        printf("Periodo Ingresso: %s\n", alunos[i]->periodo);
        printf("%% Conclusao do Curso: %d\n", alunos[i]->porcentConcl);
        printf("CRA: %.2f\n", alunos[i]->cra);
    }
}