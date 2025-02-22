#include <stdio.h>
#include <stdlib.h>

#include "empresa.h"
#include "funcionario.h"

int main(){
    int qntEmpresas, qntFuncionarios;
    tEmpresa **empresas;

    scanf("%d\n", &qntEmpresas);

    empresas = (tEmpresa**) calloc(qntEmpresas, sizeof(tEmpresa*));

    for(int i = 0; i < qntEmpresas; i++){
        empresas[i] = CriaEmpresa();
        LeEmpresa(empresas[i]);

        //scanf("%d\n", &qntFuncionarios);
        printf("\n%d\n", qntFuncionarios);
        printf("%d\n", empresas[i]->qtdFuncionarios);

        for(int j = 0; j < qntFuncionarios; j++){
            tFuncionario *funcionario;

            funcionario = CriaFuncionario();
            LeFuncionario(funcionario);

            ContrataFuncionarioEmpresa(empresas[i], funcionario);
        }
    }

    for(int i = 0; i < qntEmpresas; i++){
        ImprimeEmpresa(empresas[i]);
        ApagaEmpresa(empresas[i]);
    }

    free(empresas);

    return 0;
}