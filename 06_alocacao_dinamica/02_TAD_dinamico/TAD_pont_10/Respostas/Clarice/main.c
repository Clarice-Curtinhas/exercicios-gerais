#include <stdio.h>
#include <stdlib.h>

#include "biblioteca.h"
#include "livro.h"

void CadastraLivros(tBiblioteca *biblioteca);
void RemoveLivros(tBiblioteca *biblioteca);

int main(){
    int qntOperacoes, opcao;
    char lerExtra;

    tBiblioteca *biblioteca;

    biblioteca = InicializarBiblioteca();

    scanf("%d\n", &qntOperacoes);

    printf("Lista de operacoes:\n");
    printf("1 - Cadastrar livros.\n");
    printf("2 - Remover livros.\n");
    printf("3 - Listar todos os livros cadastrados.\n\n");

    for(int i = 0; i < qntOperacoes; i++){
        scanf("%d\n", &opcao);

        if(opcao == 1) CadastraLivros(biblioteca);
        else if(opcao == 2) RemoveLivros(biblioteca);
        else if(opcao == 3) ListarLivrosDaBiblioteca(biblioteca);

        else{
            printf("Operacao invalida!\n");
            while((scanf("%c", &lerExtra)) == 1);
            break;
        }
    }

    ApagaBiblioteca(biblioteca);

    return 0;
}

void CadastraLivros(tBiblioteca *biblioteca){
    tLivros *livro;

    livro = CriaLivro();
    LerLivro(livro);

    AdicionarLivroNaBiblioteca(biblioteca, livro);
}

void RemoveLivros(tBiblioteca *biblioteca){
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
