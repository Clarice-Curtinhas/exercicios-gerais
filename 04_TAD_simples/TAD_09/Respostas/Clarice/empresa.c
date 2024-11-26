#include <stdio.h>
#include <stdlib.h>

#include "funcionario.h"

typedef struct empresa {
    int id;
    tFuncionario funcionarios[20];
    int qtdFuncionarios;
} tEmpresa;

tEmpresa criaEmpresa(int id);
tEmpresa leEmpresa();
tEmpresa contrataFuncionarioEmpresa(tEmpresa empresa, tFuncionario funcionario);
void imprimeEmpresa(tEmpresa empresa);

/**
 * @brief Cria uma empresa a partir de um id.
 * 
 * @param id Id do empresa a ser criada.
 * @return TEmpresa empresa criada a partir do Id fornecido.
 */
tEmpresa criaEmpresa(int id){
    tEmpresa empresa;

    empresa = leEmpresa();
    empresa.id = id;
    imprimeFuncionario(empresa.funcionarios[0]);
    printf("\n\n");

    return empresa;
}

/**
 * @brief Le os dados de uma empresa da entrada padrao.
 * 
 * @return TEmpresa empresa criada a partir dos dados lidos.
 */
tEmpresa leEmpresa(){
    tEmpresa empresa;
    tFuncionario possivelFucionario;
    int qnt, contratado, count, tem = 0;

    scanf("%d\n", &empresa.qtdFuncionarios);

    for(qnt = 0; qnt < empresa.qtdFuncionarios - 1; qnt++){
        possivelFucionario = leFuncionario();
        imprimeFuncionario(possivelFucionario);

        for(count = 0; count < qnt; count++){
            if(getIdFuncionario(possivelFucionario) == getIdFuncionario(empresa.funcionarios[count])){
                printf("A empresa %d ja possui um funcionario com o id %d\n", empresa.id, getIdFuncionario(possivelFucionario));
                tem = 1;
                break;
            }

            else tem = 0;
        }

        if(tem == 0){
            empresa = contrataFuncionarioEmpresa(empresa, possivelFucionario);
        }
    }
    printf("\n");

    for(qnt = 0; qnt < empresa.qtdFuncionarios - 1; qnt++){
        imprimeFuncionario(empresa.funcionarios[qnt]);
    }

    return empresa;
}

/**
 * @brief Adiciona um funcionario a uma empresa caso o id do funcionario ainda nao esteja registrado na empresa.
 * 
 * @param empresa Empresa em que o funcionario deve ser adicionado.
 * @param funcionario Funcionario que deve ser adicionado a empresa.
 * @return TEmpresa empresa atualizada com a nova lista de funcionarios.
 */
tEmpresa contrataFuncionarioEmpresa(tEmpresa empresa, tFuncionario funcionario){
    int tam = 0;

    while(empresa.funcionarios[tam].id) tam++;
    empresa.funcionarios[tam] = funcionario;

    return empresa;
}

/**
 * @brief Imprime todos os dados de um empresa.
 * 
 * @param empresa Empresa a ser impressa no terminal.
 */
void imprimeEmpresa(tEmpresa empresa){
    int qnt;

    printf("Empresa %d:\n", empresa.id);

    for(qnt = 0; qnt < empresa.qtdFuncionarios; qnt++){
        imprimeFuncionario(empresa.funcionarios[qnt]);
    }
}