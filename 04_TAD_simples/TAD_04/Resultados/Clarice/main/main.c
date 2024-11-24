#include "aluno.h"

#include <stdio.h>
#include <stdlib.h>

int main(){
    int qntAlunos, count, qnt, ordemMatri, lugarOrdem;
    int ordenar1, ordenar2;
    tAluno lido;

    scanf("%d\n", &qntAlunos);
    ordemMatri = -(qntAlunos-1);

    tAluno alunos[qntAlunos];

    for(count = 0; count < qntAlunos; count++){
        lido = LeAluno();

        alunos[count] = CriaAluno(lido.nome, lido. matricula, lido.n1, lido.n2, lido.n3);
    }

    for(count = 0; count < qntAlunos; count++){

        for(ordenar1 = 0; ordenar1 < qntAlunos; ordenar1++){
            lugarOrdem = 0;

            for(ordenar2 = 0; ordenar2 < qntAlunos; ordenar2++){
                lugarOrdem += ComparaMatricula(alunos[ordenar1], alunos[ordenar2]);
            }

            if(lugarOrdem == ordemMatri){

                if(VerificaAprovacao(alunos[ordenar1]) == 1){
                    ImprimeAluno(alunos[ordenar1]);
                }

                break;
            }
        }

        ordemMatri += 2;
    }

    return 0;
}