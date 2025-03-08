#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAM_NOME 100

typedef struct Contato{
    char nome[MAX_TAM_NOME];
    unsigned long int numero;
} tContato;

/**
 * @brief Cria um novo contato.
 * 
 * @param nome Nome do contato.
 * @param telefone Telefone do contato.
 * @return tContato* Retorna um ponteiro para o contato criado. Caso não seja possível alocar memória, encerra o programa.
*/
tContato *CriarContato(char *nome, unsigned long int telefone){
    tContato *c;

    c = (tContato*) calloc(1, sizeof(tContato));

    strcpy(c->nome, nome);
    c->numero = telefone;

    return c;
}

/**
 * @brief Libera a memória alocada para um contato.
 * 
 * @param contato Ponteiro para o contato a ser liberado.
*/
void DestruirContato(tContato *contato){
    free(contato);
}

/**
 * @brief Imprime as informações de um contato.
 * Formato de impressão:
 * Nome: <nome>
 * Telefone: <telefone>
 * 
 * @param contato Ponteiro para o contato a ser impresso.
*/
void ImprimirContato(tContato *contato){
    printf("Nome: %s\n", contato->nome);
    printf("Telefone: %ld\n\n", contato->numero);
}

/**
 * @brief Salva as informações de um contato em um arquivo binario.
 * 
 * @param contato Ponteiro para o contato a ser salvo.
 * @param arquivo Ponteiro para o arquivo binario onde o contato será salvo.
*/
void SalvarContato(tContato *contato, FILE *arquivo){
    int tam = sizeof(contato->nome)+1;

    fwrite(&tam, sizeof(int), 1, arquivo);
    fwrite(&contato->nome, sizeof(char), tam, arquivo);
    fwrite(&contato->numero, sizeof(unsigned long int), 1, arquivo);
}

/**
 * @brief Le as informações de um contato da entrada padrão, primeiro lendo o nome e depois o telefone.
 * 
 * @return tContato* Retorna um ponteiro para o contato lido.
*/
tContato *LeContato(){
    char nome[MAX_TAM_NOME];
    unsigned long int telefone;

    tContato *contato;

    scanf("\n%[^\n]\n", nome);
    scanf("%ld\n", &telefone);

    contato = CriarContato(nome, telefone);

    return contato;
}

/**
 * @brief Carrega as informações de um contato de um arquivo binario, primeiro lendo o nome e depois o telefone.
 * 
 * @param arquivo Ponteiro para o arquivo binario de onde o contato será carregado.
 * @return tContato* Retorna um ponteiro para o contato carregado.
*/
tContato *CarregarContato(FILE *arquivo){
    int tam = 0;
    char nome[MAX_TAM_NOME];
    unsigned long int num;
    tContato *c;

    fread(&tam, sizeof(int), 1, arquivo);
    fread(&nome, sizeof(char), tam, arquivo);
    fread(&num, sizeof(unsigned long int), 1, arquivo);

    c = CriarContato(nome, num);

    return c;
}

/**
 * @brief Compara dois contatos pelo número de telefone.
 * 
 * @param c1 Ponteiro para o primeiro contato a ser comparado.
 * @param c2 Ponteiro para o segundo contato a ser comparado.
 * @return int Retorna 1 se os números de telefone dos contatos são iguais e 0 caso contrário.
*/
int ComparaTelefoneContato(tContato *c1, tContato *c2){
    if(c1->numero == c2->numero) return 1;
    else return 0;
}

/**
 * @brief Compara dois contatos pelo nome.
 * 
 * @param c1 Ponteiro para o primeiro contato a ser comparado.
 * @param c2 Ponteiro para o segundo contato a ser comparado.
 * @return int Retorna 1 se os nomes dos contatos são iguais e 0 caso contrário.
*/
int ComparaNomeContato(tContato *c1, tContato *c2){
    if(strcmp(c1->nome, c2->nome) == 0) return 1;
    else return 0;
}

/**
 * @brief Retorna o número de telefone de um contato.
 * 
 * @param contato Ponteiro para o contato.
 * @return unsigned long int Retorna o número de telefone do contato.
*/
unsigned long int GetTelefoneContato(tContato *contato){
    return contato->numero;
}

/**
 * @brief Retorna o nome de um contato.
 * 
 * @param contato Ponteiro para o contato.
 * @return char* Retorna o nome do contato.
*/
char *GetNomeContato(tContato *contato){
    return contato->nome;
}

