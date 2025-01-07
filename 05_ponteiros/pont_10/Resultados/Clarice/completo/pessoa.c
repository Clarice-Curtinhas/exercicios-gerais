#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pessoa tPessoa;

struct Pessoa{
    char nome[100];
    tPessoa *pai;
    tPessoa *mae;
    tPessoa *irmao;
};

/**
 * @brief Cria uma nova pessoa com nome vazio (primeiro caractere igual a '\0') e inicializa os ponteiros para pai, mae e irmao com NULL.
 * 
 * @return Uma nova pessoa e sem pais e irmao.
 */
tPessoa CriaPessoa(){
    tPessoa p;

    p.nome[0] = '\0';

    p.pai = NULL;
    p.mae = NULL;
    p.irmao = NULL;

    return p;
}

/**
 * @brief Lê os dados de uma pessoa.
 * 
 * @param pessoa Ponteiro para a pessoa a ser lida.
 */
void LePessoa(tPessoa *pessoa){
    scanf("\n%[^\n]\n", pessoa->nome);
}

/**
 * @brief Verifica se uma pessoa tem pai e/ou mae associado(s).
 * Ou seja, verifica pelo menos um dos ponteiros pai e mae é diferente de NULL.
 * 
 * @param pessoa Ponteiro para a pessoa a ser verificada.
 * 
 * @return 1 se a pessoa tiver pai e/ou mae associado(s) e 0 caso contrário.
*/
int VerificaSeTemPaisPessoa(tPessoa *pessoa){
    return (pessoa->mae != NULL || pessoa->pai != NULL);
}

/**
 * @brief Imprime os dados de uma pessoa caso tenha pai e/ou mae associado(s).
 * Dica: use a função VerificaSeTemPaisPessoa para verificar se a pessoa tem pai e/ou mae associado(s).
 * Alem disso, imprimir o nome do irmao caso exista.
 * 
 * @param pessoa Ponteiro para a pessoa a ser impressa.
 */
void ImprimePessoa(tPessoa *pessoa){

    if(VerificaSeTemPaisPessoa(pessoa)){
        printf("NOME COMPLETO: %s\n", pessoa->nome);

        if(pessoa->pai == NULL) printf("PAI: NAO INFORMADO\n");
        else printf("PAI: %s\n", pessoa->pai->nome);

        if(pessoa->mae == NULL) printf("MAE: NAO INFORMADO\n");
        else printf("MAE: %s\n", pessoa->mae->nome);

        if(pessoa->irmao == NULL) printf("IRMAO: NAO INFORMADO\n");
        else printf("IRMAO: %s\n", pessoa->irmao->nome);
        printf("\n");
    }
}

/**
 * @brief Verifica se duas pessoas são irmãos, ou seja, se os ponteiros pai e mae são iguais.
 * 
 * @param pessoa1 Ponteiro para a primeira pessoa.
 * @param pessoa2 Ponteiro para a segunda pessoa.
 * 
 * @return 1 se as pessoas forem irmãos e 0 caso contrário.
*/
int VerificaIrmaoPessoa(tPessoa *pessoa1, tPessoa *pessoa2){
    if(strcmp(pessoa1->mae->nome, pessoa2->mae->nome) == 0){
        if(strcmp(pessoa1->pai->nome, pessoa2->pai->nome) == 0) return 1;
    }

    return 0;
}


/**
 * @brief Le as associciacoes da entrada padrao e altera as pessoas de forma a representar as associacoes lidas
 * 
 * Apos a associado dos pais, voce deve verificar se ha irmaos e associar os irmaos.
 * 
 * @param pessoas Ponteiro para a lista de pessoas a serem associadas.
 * @param numPessoas Numero de pessoas a serem associadas (tamanho do vetor).
 */
void AssociaFamiliasGruposPessoas(tPessoa *pessoas, int numPessoas){
    int qnt, idMae, idPai, idFilho;
    
    scanf("%d\n", &qnt);

    for(int i = 0; i < qnt; i++){
        scanf("mae: %d, pai: %d, filho: %d\n", &idMae, &idPai, &idFilho);

        if(idPai >= 0) pessoas[idFilho].pai = &pessoas[idPai];
        if(idMae >= 0) pessoas[idFilho].mae = &pessoas[idMae];
    }

    for(int i = 0; i < numPessoas; i++){
        if(VerificaSeTemPaisPessoa(&pessoas[i])){

            for(int j = 0; j < numPessoas; j++){

                if(VerificaSeTemPaisPessoa(&pessoas[j]) && i != j){
                    if(VerificaIrmaoPessoa(&pessoas[i], &pessoas[j])){

                        pessoas[i].irmao = &pessoas[j];
                        pessoas[j].irmao = &pessoas[i];
                    }
                }
            }
        }
    }
}
