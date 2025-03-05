#include <stdio.h>
#include <stdlib.h>

#include "aluno.h"
#include "base_alunos.h"

int main(){
    char string[50];
    tBaseAlunos *base;

    scanf("%[^\n]\n", string);
    base = CriarBaseAlunos();

    LerBaseAlunos(base, string);

    printf("Coeficiente de Rendimento Medio da base de alunos: %.2f\n", GetCoeficienteRendimentoMedioBaseAlunos(base));

    DestruirBaseAlunos(base);
    
    return 0;
}