#include <stdlib.h>
#include <stdio.h>
#include "pessoa.h"

int main(){
    int qntPessoas;

    scanf("%d\n", &qntPessoas);
    tPessoa pessoas[qntPessoas];

    for(int i = 0; i < qntPessoas; i++){
        pessoas[i] = CriaPessoa();
        LePessoa(&pessoas[i]);
    }

    AssociaFamiliasGruposPessoas(&pessoas, qntPessoas);

    for(int i = 0; i < qntPessoas; i++){
        ImprimePessoa(&pessoas[i]);
    }
    
    return 0;
}