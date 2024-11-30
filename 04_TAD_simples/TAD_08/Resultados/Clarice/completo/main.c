#include <stdio.h>
#include <stdlib.h>

#include "departamento.h"

#define STRING_MAX 101

int main(){
    int qntDepto, m1, m2, m3;
    char nome[STRING_MAX], diretor[STRING_MAX], c1[STRING_MAX], c2[STRING_MAX], c3[STRING_MAX];

    scanf("%d\n", &qntDepto);
    tDepartamento depto[qntDepto];

    for(int i = 0; i < qntDepto; i++){
        scanf("%[^\n]\n", nome);
        scanf("%[^\n]\n", diretor);

        scanf("%[^\n]\n", c1);
        scanf("%[^\n]\n", c2);
        scanf("%[^\n]\n", c3);

        scanf("%d %d %d\n", &m1, &m2, &m3);

        depto[i] = criaDepartamento(c1, c2, c3, nome, m1, m2, m3, diretor);
    }

    ordenaPorMediaDepartamentos(depto, qntDepto);

    for(int i = 0; i < qntDepto; i++){
        imprimeAtributosDepartamento(depto[i]);
    }

    return 0;
}