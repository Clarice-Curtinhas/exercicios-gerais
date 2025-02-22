#include <stdio.h>
#include <stdlib.h>

#include "funcionario.h"

typedef struct empresa {
  int id;
  tFuncionario** funcionarios; //Ponteiro duplo pois será um vetor (alocado dinamicamente) para ponteiros de Funcionarios
  int qtdFuncionarios;
} tEmpresa;

/**
 * @brief Cria uma empresa "vazia"
 * 
 * Seus atributos devem ser inicializados com NULL (ponteiros), ou -1 caso contrário
 * @return TEmpresa* Ponteiro para empresa criada a partir do Id fornecido.
 */
tEmpresa* CriaEmpresa(){
  tEmpresa *empresa;
  
  empresa = (tEmpresa*) calloc(1, sizeof(tEmpresa));
  empresa->funcionarios = (tFuncionario**) calloc(1, sizeof(tFuncionario*));

  empresa->funcionarios[0] = NULL;

  empresa->id = -1;
  empresa->qtdFuncionarios = -1;

  return empresa;

}

/**
 * @brief Le os dados de uma empresa da entrada padrao.
 * @param *empresa - ponteiro para empresa que terá seus dados preenchidos
 */
void LeEmpresa(tEmpresa* empresa){
  scanf("%d ", &empresa->id);

  empresa->qtdFuncionarios = 0;
}

/**
 * @brief Libera toda a memória alocada dinamicamente para uma empresa
 * @param *empresa - ponteiro para empresa que terá seus dados apagados e memória liberada
 */
void ApagaEmpresa(tEmpresa* empresa){
  for(int i = 0; i < empresa->qtdFuncionarios; i++){
    ApagaFuncionario(empresa->funcionarios[i]);
  }

  free(empresa->funcionarios);
  free(empresa);
}


/**
 * @brief Adiciona um funcionario a uma empresa caso o id do funcionario ainda nao esteja registrado na empresa.
 * 
 * @param empresa Ponteiro para Empresa em que o funcionario deve ser adicionado.
 * @param funcionario Ponteiro para Funcionario que deve ser adicionado a empresa.
*/
void ContrataFuncionarioEmpresa(tEmpresa* empresa, tFuncionario* funcionario){
  int existe = 0, count = 0;

  for(int i = 0; i < empresa->qtdFuncionarios; i++){
    if(empresa->funcionarios[i] != NULL){
      if(GetIdFuncionario(funcionario) == GetIdFuncionario(empresa->funcionarios[i])){
        printf("A empresa %d ja possui um funcionario com o id %d\n", empresa->id, GetIdFuncionario(funcionario));
        
        existe = 1;
        break;
      }
    }
  }

  if(existe == 0){
    empresa->qtdFuncionarios++;
    empresa->funcionarios = (tFuncionario**) realloc(empresa->funcionarios, (empresa->qtdFuncionarios+1)*sizeof(tFuncionario*));
    empresa->funcionarios[empresa->qtdFuncionarios] = funcionario;
  }
}

/**
 * @brief Imprime todos os dados de um empresa.
 * 
 * @param empresa Ponteiro para Empresa a ser impressa no terminal.
 */
void ImprimeEmpresa(tEmpresa *empresa){
  printf("Empresa %d:\n", empresa->id);

  for(int i = 0; i < empresa->qtdFuncionarios; i++){
    ImprimeFuncionario(empresa->funcionarios[i]);
  }
}
