#include "filme.h"

#include <stdio.h>
#include <stdlib.h>

#define MAX_FILMES 100


typedef struct Locadora {
    tFilme filme[MAX_FILMES]; 
    int numFilmes; 
    int lucro; 
} tLocadora;

/**
 * @brief Cria uma nova locadora.
 * @return Locadora criada.
 */
tLocadora criarLocadora (){
    tLocadora locadora;

    locadora.numFilmes = 0;
    locadora.lucro = 0;

    return locadora;
}

/**
 * @brief Verifica se um filme está cadastrado na locadora.
 * @param locadora Locadora a ser consultada.
 * @param codigo Código do filme a ser verificado.
 * @return 1 se o filme está cadastrado, 0 caso contrário.
 */
int verificarFilmeCadastrado (tLocadora locadora, int codigo){
    for(int i = 0; i < locadora.numFilmes; i++){
        if(ehMesmoCodigoFilme(locadora.filme[i], codigo)) return 1;
    }

    return 0;
}

/**
 * @brief Cadastra um filme na locadora, desde que ele não esteja cadastrado.
 * @param locadora Locadora a ser atualizada.
 * @param filme Filme a ser cadastrado.
 * @return Locadora atualizada.
*/
tLocadora cadastrarFilmeLocadora (tLocadora locadora, tFilme filme){

    locadora.filme[locadora.numFilmes] = filme;
    printf("Filme cadastrado %d - ", obterCodigoFilme(locadora.filme[locadora.numFilmes]));
    imprimirNomeFilme(locadora.filme[locadora.numFilmes]);
    printf("\n");
    locadora.numFilmes++;

    return locadora;
}

/**
 * @brief Lê o cadastro de um ou mais filmes a partir da entrada padrão e o cadastra na locadora.
 * @param locadora Locadora a ser atualizada.
 * @return Locadora atualizada.
 */
tLocadora lerCadastroLocadora (tLocadora locadora){
    int codigo;

    while(scanf("%d,", &codigo) == 1){
        if(verificarFilmeCadastrado(locadora, codigo)){
            printf("Filme ja cadastrado no estoque\n");
        }

        else{
            locadora = cadastrarFilmeLocadora(locadora, leFilme(codigo));
        }
    }

    return locadora;
}

/**
 * @brief Aluga um conjunto de filmes da locadora.
 * @param locadora Locadora a ser atualizada.
 * @param codigos Array com os códigos dos filmes a serem alugados.
 * @param quantidadeCodigos Quantidade de códigos no array.
 * @return Locadora atualizada.
 */
tLocadora alugarFilmesLocadora (tLocadora locadora, int* codigos, int quantidadeCodigos){
    int tam, qntFilme, qntAlugado = 0, custo = 0;

    for(tam = 0; tam < quantidadeCodigos; tam++){
        if(verificarFilmeCadastrado(locadora, codigos[tam])){

            for(qntFilme = 0; qntFilme < locadora.numFilmes; qntFilme++){
                if(ehMesmoCodigoFilme(locadora.filme[qntFilme], codigos[tam])){

                    if(obterQtdEstoqueFilme(locadora.filme[qntFilme]) >= 1){
                        locadora.filme[qntFilme] = alugarFilme(locadora.filme[qntFilme]);

                        custo += obterValorFilme(locadora.filme[qntFilme]);
                        qntAlugado++;
                    }

                    else{
                        printf("Filme %d - ", obterCodigoFilme(locadora.filme[qntFilme]));
                        imprimirNomeFilme(locadora.filme[qntFilme]);
                        printf(" nao disponivel no estoque. Volte mais tarde.\n");
                    }
                }                
            }
        }

        else{
            printf("Filme %d nao cadastrado.\n", codigos[tam]);
        }
    }

    if(qntAlugado > 0) printf("Total de filmes alugados: %d com custo de R$%d\n", qntAlugado, custo);

    return locadora;
}

/**
 * @brief Lê o aluguel de um conjunto de filmes a partir da entrada padrão e os aluga na locadora.
 * @param locadora Locadora a ser atualizada.
 * @return Locadora atualizada.
 */
tLocadora lerAluguelLocadora (tLocadora locadora){
    int codigo, qntCod = 0, armazena[10];

    while((scanf("%d\n", &codigo)) == 1){
        armazena[qntCod] = codigo;
        qntCod++;
    }

    locadora = alugarFilmesLocadora(locadora, armazena, qntCod);
    
    return locadora;
}

/**
 * @brief Devolve um conjunto de filmes alugados da locadora.
 * @param locadora Locadora a ser atualizada.
 * @param codigos Array com os códigos dos filmes a serem devolvidos.
 * @param quantidadeCodigos Quantidade de códigos no array.
 * @return Locadora atualizada.
 */
tLocadora devolverFilmesLocadora (tLocadora locadora, int* codigos, int quantidadeCodigos){
    int tam, qntFilme;

    for(tam = 0; tam < quantidadeCodigos; tam++){
        if(verificarFilmeCadastrado(locadora, codigos[tam])){

            for(qntFilme = 0; qntFilme < locadora.numFilmes; qntFilme++){
                if(ehMesmoCodigoFilme(locadora.filme[qntFilme], codigos[tam])){

                    if(obterQtdAlugadaFilme(locadora.filme[qntFilme]) >= 1){
                        printf("Filme %d - ", obterCodigoFilme(locadora.filme[qntFilme]));
                        imprimirNomeFilme(locadora.filme[qntFilme]);
                        printf(" Devolvido!\n");

                        locadora.lucro += obterValorFilme(locadora.filme[qntFilme]);

                        locadora.filme[qntFilme] = devolverFilme(locadora.filme[qntFilme]);
                        break;
                    }

                    else{
                        printf("Nao e possivel devolver o filme %d - ", obterCodigoFilme(locadora.filme[qntFilme]));
                        imprimirNomeFilme(locadora.filme[qntFilme]);
                        printf(".\n");
                    }
                }
            }
        }

        else{
            printf("Filme %d nao cadastrado.\n", codigos[tam]);
        }
    }

    return locadora;
}

/**
 * @brief Lê a devolução de um conjunto de filmes a partir da entrada padrão e os devolve na locadora.
 * @param locadora Locadora a ser atualizada.
 * @return Locadora atualizada.
 */
tLocadora lerDevolucaoLocadora (tLocadora locadora){
    int codigo, qntCod = 0, armazena[10];

    while((scanf("%d\n", &codigo)) == 1){
        armazena[qntCod] = codigo;
        qntCod++;
    }

    locadora = devolverFilmesLocadora(locadora, armazena, qntCod);

    return locadora;
}

/**
 * @brief Ordena os filmes da locadora por nome.
 * @param locadora Locadora a ser ordenada.
 * @return Locadora ordenada.
 */
tLocadora ordenarFilmesLocadora (tLocadora locadora){
    int menor, num, i;
    int compara, ordem[locadora.numFilmes];
    tLocadora locadoraOrdenada;

    num = locadora.numFilmes;

    locadoraOrdenada.numFilmes = locadora.numFilmes;
    locadoraOrdenada.lucro = locadora.lucro;

    for(i = 0; i < num; i++){
        ordem[i] = i;
    }
    ordem[i] = '\0';

    for(int i = 0; i < locadora.numFilmes; i++){
        menor = ordem[0];

        if(num > 1){
            for(int j = 0; j < num; j++){
                compara = compararNomesFilmes(locadora.filme[menor], locadora.filme[ordem[j]]);

                if(compara == 1){
                    menor = ordem[j];
                }

                else if(compara == -1){
                    menor = menor;
                }
            }

            locadoraOrdenada.filme[i] = locadora.filme[menor];

            for(int j = menor; j < num; j++){
                ordem[j] = ordem[j+1];
            }
        }

        else locadoraOrdenada.filme[i] = locadora.filme[menor];

        num--;
    }

    return locadoraOrdenada;
}

/**
 * @brief Imprime o estoque da locadora.
 * @param locadora Locadora a ser consultada.
 */
void consultarEstoqueLocadora (tLocadora locadora){
    printf("~ESTOQUE~\n");
    
    for(int qnt = 0; qnt < locadora.numFilmes; qnt++){
        printf("%d - ", obterCodigoFilme(locadora.filme[qnt]));
        imprimirNomeFilme(locadora.filme[qnt]);
        printf(" Fitas em estoque: %d\n", obterQtdEstoqueFilme(locadora.filme[qnt]));
    }
}

/**
 * @brief Imprime o lucro da locadora.
 * @param locadora Locadora a ser consultada.
 */
void consultarLucroLocadora (tLocadora locadora){

    if(locadora.lucro != 0){
        printf("\nLucro total R$%d\n", locadora.lucro);
    }
}