#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "livro.h"


#define MAX_LIVROS 10

// Estrutura que representa uma biblioteca de livros
typedef struct {
    tLivros* livros[MAX_LIVROS]; // Array de livros (Neste exemplo, o máximo suportado será 10)
    int tamanho; // Número atual de livros na biblioteca
} tBiblioteca;

/**
 * Inicializa uma biblioteca vazia.
 * Ponteiros são inicializados com NULL; 
 * @return A biblioteca inicializada.
 */
tBiblioteca* InicializarBiblioteca(){
    tBiblioteca *biblioteca;

    biblioteca = (tBiblioteca*) calloc(1, sizeof(tBiblioteca));

    for(int i = 0; i < MAX_LIVROS; i++){
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
    if(biblioteca != NULL){
        for(int i = 0; i < biblioteca->tamanho; i++){
            if(biblioteca->livros[i] != NULL){
                ApagaLivro(biblioteca->livros[i]);
            }
        }

        free(biblioteca);
    }
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
    if(biblioteca->tamanho < MAX_LIVROS){
        biblioteca->livros[biblioteca->tamanho] = livro;
        biblioteca->tamanho++;

        printf("Livro adicionado com sucesso!\n");
    }

    else{
        printf("A biblioteca esta cheia. Nao eh possivel adicionar mais livros.\n");
        ApagaLivro(livro);
    }
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
    int apagou = 0;

    for(int i = 0; i < biblioteca->tamanho; i++){

        if(VerificaTituloDoLivroNaBiblioteca(biblioteca->livros[i], titulo) == 0){
            ApagaLivro(biblioteca->livros[i]);

            for(int j = i; j < biblioteca->tamanho-1; j++){
                biblioteca->livros[j] = biblioteca->livros[j+1];
            }

            biblioteca->tamanho--;
            printf("Livro removido com sucesso!\n");

            apagou = 1;
        }
    }

    if(apagou == 0) printf("Livro nao encontrado na biblioteca.\n");
}

/**
 * Verifica se o título digitado é igual ao título do livro.
 * 
 * @param livro Ponteiro para o livro cujo título será verificado.
 * @param titulo O título digitado pelo usuário.
 * @return se o título for igual, retorna 0.
*/
int VerificaTituloDoLivroNaBiblioteca(tLivros* livro, char* titulo){
    if(strcmp(titulo, livro->titulo) == 0) return 0;
    return 1;
}

/**
 * Lista todos os livros presentes na biblioteca.
 * Se não houver livros na biblioteca, imprime "A biblioteca esta vazia!"
 *
 * @param biblioteca Ponteiro para a biblioteca cujos livros serão listados.
 */
void ListarLivrosDaBiblioteca(tBiblioteca* biblioteca){
    if(biblioteca->tamanho == 0) printf("A biblioteca esta vazia!\n");

    else{
        printf("\nLista de Livros na Biblioteca:\n");

        for(int i = 0; i < biblioteca->tamanho; i++){
            ImprimeLivro(biblioteca->livros[i]);
        }
    }
}

