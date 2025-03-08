#include <stdio.h>
#include <stdlib.h>

#include "lista_contato.h"
#include "contato.h"
#include "vector.h"

#define TAM_STRING 100

int main(){
    tListaContato *lista;
    char string[TAM_STRING];
    int opcao;

    lista = CriarListaContato();

    scanf("%[^\n]\n", string);

    CarregarListaContato(lista, string);

    while(1){
        printf("1 - Cadastrar contato\n");
        printf("2 - Remover contato\n");
        printf("3 - Realizar busca\n");
        printf("4 - Exibir todos os contatos\n");
        printf("0 - Sair da lista de contatos\n");
        printf("Opcao escolhida: ");
        scanf("%d\n", &opcao);
        printf("\n");

        if(opcao == 1){
            tContato *contato;
            contato = LeContato();

            AdicionarContatoListaContato(lista, contato);
        }

        else if(opcao == 2){
            RemoverContatoListaContato(lista);
        }

        else if(opcao == 3){
            int opcao;
            printf("1 - Buscar pelo nome\n");
            printf("2 - Buscar pelo numero de telefone\n");
            printf("Opcao escolhida:\n");
        
            scanf("%d\n", &opcao);

            if(opcao == 1) BuscarPorNomeListaContato(lista);
            else if(opcao == 2) BuscarPorNumeroTelefoneListaContato(lista);
        }

        else if(opcao == 4){
            ImprimirListaContato(lista);
        }

        else if(opcao == 0) break;
    }

    scanf("%[^\n]\n", string);

    SalvarListaContato(lista, string);

    DestruirListaContato(lista);

    return 0;
}