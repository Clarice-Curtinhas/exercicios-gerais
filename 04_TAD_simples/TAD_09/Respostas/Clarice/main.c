#include <stdio.h>
#include <stdlib.h>

#include "empresa.h"
#include "funcionario.h"

int main(){
    int qtdEmpresas, id, count;

    scanf("%d\n\n", &qtdEmpresas);

    tEmpresa empresa[qtdEmpresas];

    for(count = 0; count < qtdEmpresas; count++){
        scanf("%d ", &id);

        empresa[count] = criaEmpresa(id);
    }

    for(count = 0; count < qtdEmpresas; count++){
        imprimeEmpresa(empresa[count]);
    }

    return 0;
}