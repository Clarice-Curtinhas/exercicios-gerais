#include <stdio.h>
#include <stdlib.h>
#include "pessoa.h"

int main(){
    int numPessoas, numAssocia;

    scanf("%d\n", &numPessoas);

    tPessoa pessoas[numPessoas];

    for(int i = 0; i < numPessoas; i++){
        pessoas[i] = CriaPessoa();

        LePessoa(&pessoas[i]);
    }

    AssociaFamiliasGruposPessoas(&pessoas);
    
    for(int i = 0; i < numPessoas; i++){
        ImprimePessoa(&pessoas[i]);
    }

    return 0;
}