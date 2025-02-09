#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "livro.h"
#include "biblioteca.h"


#define NUM_INICIAL_LIVROS 5

// Estrutura que representa uma biblioteca de livros
/*typedef struct {
    tLivros** livros; // Array de livros 
    int tamanho; // Número atual de livros na biblioteca
    int tam_max_atual; //Número máximo atual de livros suportados pela biblioteca
} tBiblioteca;*/

/**
 * Inicializa uma biblioteca vazia.
 * Ponteiros são inicializados com NULL; 
 * @return A biblioteca inicializada.
 */
tBiblioteca* InicializarBiblioteca(){
    tBiblioteca *biblioteca;

    biblioteca = (tBiblioteca*) calloc(1, sizeof(tBiblioteca));
    biblioteca->livros = (tLivros**) calloc(NUM_INICIAL_LIVROS, sizeof(tLivros*));

    biblioteca->tam_max_atual = NUM_INICIAL_LIVROS;
    
    for(int i = 0; i < biblioteca->tam_max_atual; i++){
        biblioteca->livros[i] = NULL;
    }

    biblioteca->tamanho = 0;

    return biblioteca;
}

/**
 * Apaga toda a memória alocada dinamicamente dentro de uma biblioteca
 * Ponteiros são inicializados com NULL; 
 * @return A biblioteca inicializada.
 */
void ApagaBiblioteca(tBiblioteca* biblioteca){
    for(int i = 0; i < biblioteca->tamanho; i++){
        ApagaLivro(biblioteca->livros[i]);
    }

    free(biblioteca->livros);
    free(biblioteca);
}

/**
 * Adiciona um livro à biblioteca.
 * Se estiver dentro do tamanho máximo de livros, imprime "Livro adicionado com sucesso!"
 * Senão, imprime "A biblioteca está cheia. Não é possível adicionar mais livros."
 *
 * @param biblioteca Ponteiro para a biblioteca onde o livro será adicionado.
 * @param livro Ponteiro para o livro a ser adicionado.
 */
void AdicionarLivroNaBiblioteca(tBiblioteca* biblioteca, tLivros* livro){
    if(biblioteca->tamanho == biblioteca->tam_max_atual){
        biblioteca->tam_max_atual += NUM_INICIAL_LIVROS;
        biblioteca->livros = (tLivros**) realloc(biblioteca->livros, (biblioteca->tam_max_atual)*sizeof(tLivros*));
    }

    biblioteca->livros[biblioteca->tamanho] = livro;
    biblioteca->tamanho++;

    printf("Livro adicionado com sucesso!\n");
}

/**
 * Remove um livro da biblioteca pelo título. 
 * Se o título for encontrado, imprime "Livro removido com sucesso!",
 * Senão, imprime "Livro não encontrado na biblioteca."
 *
 * @param biblioteca Ponteiro para a biblioteca da qual o livro será removido.
 * @param titulo O título do livro a ser removido.
 */
void RemoverLivroDaBiblioteca(tBiblioteca* biblioteca, char *titulo){
    int removeu = 0;

    for(int i = 0; i < biblioteca->tamanho; i++){
        if(VerificaTituloDoLivroNaBiblioteca(biblioteca->livros[i], titulo) == 0){
            ApagaLivro(biblioteca->livros[i]);

            for(int j = i; j < biblioteca->tamanho-1; j++){
                biblioteca->livros[j] = biblioteca->livros[j+1];
            }

            biblioteca->tamanho--;

            printf("Livro removido com sucesso!\n");
            removeu = 1;
        }
    }

    if(removeu == 0){
        printf("Livro nao encontrado na biblioteca.\n");
    }
}

/**
 * Verifica se o título digitado é igual ao título do livro.
 * 
 * @param livro Ponteiro para o livro cujo título será verificado.
 * @param titulo O título digitado pelo usuário.
 * @return se o título for igual, retorna 0.
*/
int VerificaTituloDoLivroNaBiblioteca(tLivros* livro, char* titulo){
    if(strcmp(livro->titulo, titulo) == 0) return 0;
    else return 1;
}

/**
 * Lista todos os livros presentes na biblioteca.
 * Se não houver livros na biblioteca, imprime "A biblioteca esta vazia!"
 *
 * @param biblioteca Ponteiro para a biblioteca cujos livros serão listados.
 */
void ListarLivrosDaBiblioteca(tBiblioteca* biblioteca){
    if(biblioteca->tamanho > 0){
        printf("Lista de Livros na Biblioteca:\n");

        for(int i = 0; i < biblioteca->tamanho; i++){
            ImprimeLivro(biblioteca->livros[i]);
        }
    }

    else printf("A biblioteca esta vazia!\n");
}


