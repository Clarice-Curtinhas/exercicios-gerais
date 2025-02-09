#include <stdio.h>
#include <stdlib.h>

#include "biblioteca.h"
#include "livro.h"

void CadastrarLivro(tBiblioteca *biblioteca);
void RemoverLivro(tBiblioteca *biblioteca);

int main(){
    char limparExtra;
    int opcoes, qntOperacoes;
    tBiblioteca *biblioteca;

    biblioteca = InicializarBiblioteca();

    scanf("%d\n", &qntOperacoes);

    printf("Lista de operacoes:\n");
    printf("1 - Cadastrar livros.\n");
    printf("2 - Remover livros.\n");
    printf("3 - Listar todos os livros cadastrados.\n");

    for(int i = 0; i < qntOperacoes; i++){
        scanf("%d\n", &opcoes);

        if(opcoes == 1) CadastrarLivro(biblioteca);
        else if(opcoes == 2) RemoverLivro(biblioteca);
        else if(opcoes == 3) ListarLivrosDaBiblioteca(biblioteca);

        else{
            printf("Operacao invalida!\n");
            while(scanf("%c", &limparExtra) == 1);
            break;
        }
    }

    ApagaBiblioteca(biblioteca);

    return 0;
}

void CadastrarLivro(tBiblioteca *biblioteca){
    tLivros *livro;

    livro = CriaLivro();
    LerLivro(livro);

    AdicionarLivroNaBiblioteca(biblioteca, livro);
}

void RemoverLivro(tBiblioteca *biblioteca){
    int i = 0;
    char *titulo;

    titulo = (char*) calloc(1, sizeof(char));

    while((scanf("%c", &titulo[i]) == 1) && (titulo[i] != '\n')){
        i++;
        titulo = (char*) realloc(titulo, (i+1)*sizeof(char));
    }

    titulo[i] = '\0';

    RemoverLivroDaBiblioteca(biblioteca, titulo);

    free(titulo);
}