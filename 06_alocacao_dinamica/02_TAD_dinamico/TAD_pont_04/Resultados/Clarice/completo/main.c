#include <stdio.h>
#include <stdlib.h>

#include "aluno.h"

int main(){
    int qntAlunos, qntMatriculas, iMatricula = 0;

    scanf("%d\n", &qntAlunos);

    qntMatriculas = qntAlunos;

    tAluno *alunos[qntAlunos];
    
    for(int i = 0; i < qntAlunos; i++){
        alunos[i] = CriaAluno();
        LeAluno(alunos[i]);
    }

    for(int i = 0; i < qntAlunos; i++){
        iMatricula = 0;

        for(int j = 0; j < qntMatriculas; j++){
            if(ComparaMatricula(alunos[iMatricula], alunos[j]) == 1){
                iMatricula = j;
            }
        }

        if(VerificaAprovacao(alunos[iMatricula]) == 1){
            ImprimeAluno(alunos[iMatricula]);
        }

        ApagaAluno(alunos[iMatricula]);

        for(int j = iMatricula; j < qntMatriculas-1; j++){
            alunos[j] = alunos[j+1];
        }

        qntMatriculas--;
    }

    return 0;
}