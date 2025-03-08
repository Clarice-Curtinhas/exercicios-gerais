#include <stdio.h>
#include "contato.h"
#include "vector.h"

#define MAX_TAM_NOME 100

typedef struct ListaContato{
    tContato **lista;
} tListaContato;

/**
 * @brief Cria uma lista de contatos.
 * 
 * @return tListaContato* Retorna um ponteiro para a lista de contatos criada. Caso não seja possível alocar memória, encerra o programa.
*/
tListaContato *CriarListaContato(){
    tListaContato *lista;

    lista = (tListaContato*) calloc(1, sizeof(tListaContato));
    lista->lista = VectorConstruct();

    return lista;
}

/**
 * @brief Libera a memória alocada para uma lista de contatos.
 * 
 * @param l Ponteiro para a lista de contatos a ser liberada.
*/
void DestruirListaContato(tListaContato *l){
    VectorDestroy(l->lista, DestruirContato);
    free(l);
}

/**
 * @brief Adiciona um contato a uma lista de contatos, somente se o contato ainda não existir na lista 
 * (não pode haver dois contatos com o mesmo nome e/ou número de telefone).
 * 
 * @param l Ponteiro para a lista de contatos.
 * @param contato Ponteiro para o contato a ser adicionado.
*/
void AdicionarContatoListaContato(tListaContato *l, tContato *contato){
    int achou = 0, a;

    for(int i = 0; i < VectorSize(l->lista); i++){
        if((ComparaNomeContato(contato, VectorGet(l->lista, i)) == 1) || (ComparaTelefoneContato(contato, VectorGet(l->lista, i)) == 1)){
            achou = 1;
            break;
        }
    }

    if(achou == 0) VectorPushBack(l->lista, contato);
    else{
        DestruirContato(contato);
        printf("\nJa existe um contato com esse nome e/ou numero de telefone\n");
    }
}

/**
 * @brief Carrega uma lista de contatos de um arquivo binário.
 * Se o arquivo não existir, a lista de contatos permanece vazia.
 * Dica: Se o arquivo não existir, o ponteiro para o arquivo será NULL. Portanto, se o ponteiro for NULL, a função deve retornar sem fazer nada.
 * 
 * Formato do arquivo binário (caso exista):
 * - int: quantidade de contatos
 * - para cada contato:
 *  - char[100]: nome
 *  - char[20]: telefone
 * 
 * @param l Ponteiro para a lista de contatos.
 * @param nomeArquivo Nome do arquivo binário de onde a lista de contatos será carregada.
*/
void CarregarListaContato(tListaContato *l, char* nomeArquivo){
    int num;
    FILE *arq;
    arq = fopen(nomeArquivo, "rb");

    if(arq != NULL){
        fread(&num, sizeof(int), 1, arq);

        for(int i = 0; i < num; i++){
            tContato *c;

            c = CarregarContato(arq);

            VectorPushBack(l->lista, c);
        }

        fclose(arq);
    }
}

/**
 * @brief Salva uma lista de contatos em um arquivo binário.
 * 
 * Formato do arquivo binário:
 * - int: quantidade de contatos
 * - para cada contato:
 *  - char[100]: nome
 *  - char[20]: telefone
 * 
 * @param l Ponteiro para a lista de contatos.
 * @param nomeArquivo Nome do arquivo binário onde a lista de contatos será salva.
*/
void SalvarListaContato(tListaContato *l, char* nomeArquivo){
    int num = VectorSize(l->lista);
    FILE *arq;

    arq = fopen(nomeArquivo, "wb");

    if(arq != NULL){
        fwrite(&num, sizeof(int), 1, arq);

        for(int i = 0; i < num; i++){
            SalvarContato(VectorGet(l->lista, i), arq);
        }
    }

    fclose(arq);
}

/**
 * @brief Busca um contato na lista de contatos pelo número de telefone e imprime as informações do contato na tela.
 * Se o contato não existir, imprime "Contato nao encontrado".
 * 
 * @param l Ponteiro para a lista de contatos.
*/
void BuscarPorNumeroTelefoneListaContato(tListaContato *l){
    int tam = VectorSize(l->lista), achou = 0;
    unsigned long int telefone;

    scanf("\n%ld\n", &telefone);

    tContato *compara;

    compara = CriarContato("buff", telefone);

    for(int i = 0; i < tam; i++){
        if(ComparaTelefoneContato(compara, VectorGet(l->lista, i)) == 1){
            ImprimirContato(VectorGet(l->lista, i));
            achou = 1;
            break;
        }
    }

    DestruirContato(compara);

    if(achou == 0) printf("Contato nao encontrado\n");
}

/**
 * @brief Busca um contato na lista de contatos pelo nome e imprime as informações do contato na tela.
 * Se o contato não existir, imprime "Contato nao encontrado".
 * 
 * @param l Ponteiro para a lista de contatos.
*/
void BuscarPorNomeListaContato(tListaContato *l){
    int tam = VectorSize(l->lista), achou = 0;
    char nome[MAX_TAM_NOME];

    scanf("\n%[^\n]\n", nome);

    tContato *compara;

    compara = CriarContato(nome, 0);

    for(int i = 0; i < tam; i++){
        if(ComparaNomeContato(compara, VectorGet(l->lista, i)) == 1){
            ImprimirContato(VectorGet(l->lista, i));
            achou = 1;
            break;
        }
    }

    DestruirContato(compara);

    if(achou == 0) printf("Contato nao encontrado\n");
}

/**
 * @brief Imprime a lista de contatos na tela.
 * 
 * @param l Ponteiro para a lista de contatos.
*/
void ImprimirListaContato(tListaContato *l){
    int tam = VectorSize(l->lista);

    printf("\nLista de contatos cadastrados\n");

    for(int i = 0; i < tam; i++){

        ImprimirContato(VectorGet(l->lista, i));
    }
}

/**
 * @brief Remove um contato da lista de contatos caso ele exista.
 * 
 * @param l Ponteiro para a lista de contatos.
*/
void RemoverContatoListaContato(tListaContato *l){
    unsigned long int numero;

    int tam = VectorSize(l->lista), achou = 0;
    unsigned long int telefone;

    scanf("\n%ld", &telefone);

    tContato *compara;

    compara = CriarContato("buff", telefone);

    for(int i = 0; i < tam; i++){
        if(ComparaTelefoneContato(compara, VectorGet(l->lista, i)) == 1){
            DestruirContato(VectorGet(l->lista, i));
            VectorRemove(l->lista, i);
            printf("\nContato removido com sucesso\n");
            achou = 1;
            break;
        }
    }

    DestruirContato(compara);

    if(achou == 0) printf("Nao existe um contato cadastrado com esse numero de telefone\n");
}
