#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "filme.h"
#include "locadora.h"

/*typedef struct Locadora {
    tFilme** filme; 
    int numFilmes; 
    int lucro; 
} tLocadora;*/

/**
 * @brief Cria uma nova instância de tLocadora e inicializa filme como NULL, numFilmes como 0 e lucro como 0.
 * 
 * @return tLocadora* Ponteiro para a nova instância de tLocadora criada ou encerra o programa caso não haja memória suficiente.
 */
tLocadora* CriarLocadora (){
    tLocadora *locadora;

    locadora = (tLocadora*) calloc(1, sizeof(tLocadora));

    locadora->filme = (tFilme**) calloc(1, sizeof(tFilme*));
    locadora->filme[0] = NULL;

    locadora->numFilmes = 0;
    locadora->lucro = 0;

    return locadora;
}

/**
 * @brief Destrói uma instância de tLocadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser destruída.
 */
void DestruirLocadora (tLocadora* locadora){
    for(int i = 0; i < locadora->numFilmes; i++){
        DestruirFilme(locadora->filme[i]);
    }

    free(locadora->filme);
    free(locadora);
}

/**
 * @brief Verifica se um filme está cadastrado na locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser verificada.
 * @param codigo Código do filme a ser verificado.
 * @return int 1 se o filme está cadastrado, 0 caso contrário.
 */
int VerificarFilmeCadastrado (tLocadora* locadora, int codigo){
    for(int i = 0; i < locadora->numFilmes; i++){
        if(EhMesmoCodigoFilme(locadora->filme[i], codigo) == 1){
            return 1;
        }
    }

    return 0;
}

/**
 * @brief Cadastra um novo filme na locadora caso ele não esteja cadastrado.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 * @param filme Ponteiro para o filme a ser cadastrado.
 */
void CadastrarFilmeLocadora (tLocadora *locadora, tFilme *filme){
    int jaCadastrado = 0;

    for(int i = 0; i < locadora->numFilmes; i++){
        if(EhMesmoCodigoFilme(locadora->filme[i], ObterCodigoFilme(filme)) == 1){
            jaCadastrado = 1;
            printf("Filme ja cadastrado no estoque\n");
            DestruirFilme(filme);
            break;
        }
    }

    if(jaCadastrado == 0){
        locadora->filme[locadora->numFilmes] = filme;

        locadora->numFilmes++;

        locadora->filme = (tFilme**) realloc(locadora->filme, (locadora->numFilmes+1)*sizeof(tFilme*));

        printf("Filme cadastrado %d - ", ObterCodigoFilme(filme));
        ImprimirNomeFilme(filme);
        printf("\n");
    }
}

/**
 * @brief Lê os dados de cadastro de um filme e o cadastra na locadora.
 * 
 * @param Locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerCadastroLocadora (tLocadora* Locadora){
    int codigo;

    while((scanf("%d,", &codigo)) == 1){
        tFilme *filme;

        filme = CriarFilme();
        LeFilme(filme, codigo);

        CadastrarFilmeLocadora(Locadora, filme);
    }

    scanf("%*c");
}

/**
 * @brief Aluga um ou mais filmes da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 * @param codigos Vetor contendo os códigos dos filmes a serem alugados.
 * @param quantidadeCodigos Número de códigos de filmes a serem alugados.
 */
void AlugarFilmesLocadora (tLocadora* locadora, int* codigos, int quantidadeCodigos){
    int count = 0, valor = 0, alugado = 0;

    for(int i = 0; i < quantidadeCodigos; i++){
        for(int j = 0; j < locadora->numFilmes; j++){

            if(EhMesmoCodigoFilme(locadora->filme[j], codigos[i]) == 1){
                if(ObterQtdEstoqueFilme(locadora->filme[j]) > 0){
                    AlugarFilme(locadora->filme[j]);

                    valor += ObterValorFilme(locadora->filme[j]);
                    count++;

                    alugado = 1;
                }

                else{
                    printf("Filme %d - ", ObterCodigoFilme(locadora->filme[j]));
                    ImprimirNomeFilme(locadora->filme[j]);
                    printf(" nao disponivel no estoque. Volte mais tarde.\n");
                    alugado = 1;
                }

                break;
            }
        }

        if(alugado == 0){
            printf("Filme %d nao cadastrado.\n", codigos[i]);
        }

        alugado = 0;
    }

    if(count != 0){
        printf("Total de filmes alugados: %d com custo de R$%d\n", count, valor);
    }
}

/**
 * @brief Lê o aluguel de um conjunto de filmes a partir da entrada padrão e os aluga na locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerAluguelLocadora (tLocadora* locadora){
    int *codigos, qntCodigos = 0;

    codigos = (int*) calloc(1, sizeof(int));

    while((scanf("%d\n", &codigos[qntCodigos])) == 1){
        qntCodigos++;
        codigos = (int*) realloc(codigos, (qntCodigos+1)*sizeof(int));
    }

    scanf("%*c");

    AlugarFilmesLocadora(locadora, codigos, qntCodigos);

    free(codigos);
}

/**
 * @brief Devolve um ou mais filmes alugados da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 * @param codigos Vetor contendo os códigos dos filmes a serem devolvidos.
 * @param quantidadeCodigos Número de códigos de filmes a serem devolvidos.
 */
void DevolverFilmesLocadora (tLocadora* locadora, int* codigos, int quantidadeCodigos){
    int devolveu = 0;

    for(int i = 0; i < quantidadeCodigos; i++){
        for(int j = 0; j < locadora->numFilmes; j++){

            if(EhMesmoCodigoFilme(locadora->filme[j], codigos[i]) == 1){
                if(ObterQtdAlugadaFilme(locadora->filme[j]) > 0){
                    DevolverFilme(locadora->filme[j]);

                    printf("Filme %d - ", ObterCodigoFilme(locadora->filme[j]));
                    ImprimirNomeFilme(locadora->filme[j]);
                    printf(" Devolvido!\n");

                    locadora->lucro += ObterValorFilme(locadora->filme[j]);
                }

                else{
                    printf("Nao e possivel devolver o filme %d - ", codigos[i]);
                    ImprimirNomeFilme(locadora->filme[j]);
                    printf(".\n");
                }
                
                devolveu = 1;

                break;
            }
        }

        if(devolveu == 0){
            printf("Filme %d nao cadastrado.\n", codigos[i]);
        }

        devolveu = 0;
    }
}

/**
 * @brief Lê os dados de devolução de um ou mais filmes e os devolve na locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerDevolucaoLocadora (tLocadora* locadora){
    int *codigos, qntCodigos = 0;

    codigos = (int*) calloc(1, sizeof(int));

    while((scanf("%d\n", &codigos[qntCodigos])) == 1){
        qntCodigos++;
        codigos = (int*) realloc(codigos, (qntCodigos+1)*sizeof(int));
    }

    scanf("%*c");

    DevolverFilmesLocadora(locadora, codigos, qntCodigos);

    free(codigos);
}

/**
 * @brief Ordena os filmes cadastrados na locadora por ordem alfabética.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void OrdenarFilmesLocadora (tLocadora* locadora){

    for(int i = 0; i < locadora->numFilmes; i++){
        for(int j = i+1; j < locadora->numFilmes; j++){
            if(CompararNomesFilmes(locadora->filme[i], locadora->filme[j]) == 1){
                tFilme *filme;

                filme = locadora->filme[i];

                locadora->filme[i] = locadora->filme[j];
                locadora->filme[j] = filme;
            }
        }
    }
}

/**
 * @brief Consulta o estoque de filmes da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser consultada.
 */
void ConsultarEstoqueLocadora (tLocadora* locadora){
    printf("~ESTOQUE~\n");

    for(int i = 0; i < locadora->numFilmes; i++){
        printf("%d - ", ObterCodigoFilme(locadora->filme[i]));
        ImprimirNomeFilme(locadora->filme[i]);
        printf(" Fitas em estoque: %d\n", ObterQtdEstoqueFilme(locadora->filme[i]));
    }
}

/**
 * @brief Consulta o lucro da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser consultada.
 */
void ConsultarLucroLocadora (tLocadora* locadora){
    if(locadora->lucro != 0){
        printf("\nLucro total R$%d\n", locadora->lucro);
    }
}
