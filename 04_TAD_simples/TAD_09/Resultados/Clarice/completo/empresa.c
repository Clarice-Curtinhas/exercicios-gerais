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

    empresa.id = id;

    return empresa;
}

/**
 * @brief Le os dados de uma empresa da entrada padrao.
 * 
 * @return TEmpresa empresa criada a partir dos dados lidos.
 */
tEmpresa leEmpresa(){
    int qnt, tam, tem = 0, id;
    tEmpresa empTest;
    tEmpresa empresa;

    scanf("%d ", &id);
    empresa = criaEmpresa(id);

    empresa.qtdFuncionarios = 0;

    scanf("%d\n", &empTest.qtdFuncionarios);

    for(qnt = 0; qnt < empTest.qtdFuncionarios; qnt++){
        empTest.funcionarios[qnt] = leFuncionario();

        empresa.funcionarios[qnt] = criaFuncionario(-1,-1);

        for(tam = 0; tam < qnt; tam++){
            if(getIdFuncionario(empTest.funcionarios[qnt]) == getIdFuncionario(empresa.funcionarios[tam])){
                printf("A empresa %d ja possui um funcionario com o id %d\n", empresa.id, getIdFuncionario(empTest.funcionarios[tam]));
                tem = 1;
                break;
            }

            else tem = 0;
        }

        if(tem == 0){
            empresa = contrataFuncionarioEmpresa(empresa, empTest.funcionarios[qnt]);
        }
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

    while(empresa.qtdFuncionarios >= tam){

        if(getIdFuncionario(empresa.funcionarios[tam]) == -1){
            empresa.funcionarios[tam] = funcionario;
            empresa.qtdFuncionarios++;
            break;
        }

        tam++;
    }

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