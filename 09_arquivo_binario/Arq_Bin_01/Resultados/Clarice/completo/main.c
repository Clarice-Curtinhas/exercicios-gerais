#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

int main(){
    int qnt = 0;
    Aluno **alunos;

    printf("Digite o numero de alunos: ");

    scanf("%d", &qnt);

    alunos = CriaVetorAlunos(qnt);

    LeAlunos(alunos, qnt);

    SalvaAlunosBinario(alunos, "./alunos.bin", qnt);

    LiberaAlunos(alunos, qnt);

    alunos = CriaVetorAlunos(qnt);

    CarregaAlunosBinario(alunos, "./alunos.bin");

    ImprimeAlunos(alunos, qnt);

    LiberaAlunos(alunos, qnt);

    return 0;
}