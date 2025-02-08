#include <stdio.h>
#include <stdlib.h>

// Estrutura que representa um livro
typedef struct {
    char* titulo; // Título do livro
    char* autor;   // Autor do livro
    int anoPublicacao; // Ano de publicação do livro
} tLivros;

/**
 * Cria um livro "vazio". Ponteiros devem receber null e os atributos numéricos valor -1;
 *
 * @return Um ponteiro para um livro livro "vazio"
 */
tLivros* CriaLivro(){
    tLivros *livro;

    livro = (tLivros*) calloc(1, sizeof(tLivros));
    livro->autor = (char*) calloc(1, sizeof(char));
    livro->titulo = (char*) calloc(1, sizeof(char));
    
    livro->anoPublicacao = -1;

    return livro;
}

/**
 * Lê os atributos de um livro a partir da entrada padrão (teclado).
 *
 * @param livro Um ponteiro para um livro que receberá os atributos lidos
 */
void LerLivro(tLivros* livro){
    int i = 0, j = 0;

    while((scanf("%c", &livro->titulo[i]) == 1) && livro->titulo[i] != '\n'){
        i++;
        livro->titulo = (char*) realloc(livro->titulo, (i+1)*sizeof(char));
    }

    livro->titulo[i] = '\0';

    while((scanf("%c", &livro->autor[j]) == 1) && livro->autor[j] != '\n'){
        j++;
        livro->autor = (char*) realloc(livro->autor, (j+1)*sizeof(char));
    }

    livro->autor[j] = '\0';

    scanf("%d\n", &livro->anoPublicacao);
}

/**
 * Imprime os atributos da TAD tLivros (título, autor e ano de publicação).
 * 
 * @param livro Um ponteiro para o livro cujos atributos serão impressos
*/
void ImprimeLivro(tLivros* livro){
    printf("Titulo: %s\n", livro->titulo);
    printf("Autor: %s\n", livro->autor);
    printf("Ano de Publicacao: %d\n", livro->anoPublicacao);
}

/**
 * Função para liberar toda a memória alocada por um livro
 * 
 * @param livro Um ponteiro para o livro cujos atributos serão apagados/liberados
*/
void ApagaLivro(tLivros* livro){
    free(livro->titulo);
    free(livro->autor);
    free(livro);
}

