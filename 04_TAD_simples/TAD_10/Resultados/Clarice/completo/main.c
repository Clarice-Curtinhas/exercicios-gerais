#include <stdio.h>
#include <stdlib.h>

#include "biblioteca.h"
#include "livro.h"

int main(){
    int N, operacao, foi;
    char removerLivro[100];
    tBiblioteca biblioteca;
    tLivros livro;

    biblioteca = inicializarBiblioteca();

    scanf("%d\n", &N);

    printf("Lista de operacoes:\n");
    printf("1 - Cadastrar livros.\n");
    printf("2 - Remover livros.\n");
    printf("3 - Listar todos os livros cadastrados.\n\n");

    for(int i = 0; i < N; i++){
        scanf("%d\n", &operacao);

        if(operacao == 1){
            livro = lerLivro();

            biblioteca = adicionarLivroNaBiblioteca(biblioteca, livro);
            foi = 0;
        }

        else if(operacao == 2){
            scanf("%[^\n]\n", removerLivro);

            biblioteca = removerLivroDaBiblioteca(biblioteca, removerLivro);
            foi = 0;
        }

        else if(operacao == 3){
            listarLivrosDaBiblioteca(biblioteca);
            foi = 0;
        }

        else if(foi == 0){
            printf("Operacao invalida!\n");
            foi = 1;
        }
    }

    return 0;
}