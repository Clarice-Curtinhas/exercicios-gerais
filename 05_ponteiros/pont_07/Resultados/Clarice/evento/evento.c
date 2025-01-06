#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EVENTOS 10

//Estrutura para representar um evento no calendário. 
typedef struct {
    char nome[50]; // Nome do evento.
    int dia;       // Dia do evento.
    int mes;       // Mês do evento.
    int ano;       // Ano do evento.
} Evento;

/**
 * Cadastra um novo evento no calendário e o insere na próxima posição do array.
 *
 * @param eventos Array de eventos onde o novo evento será cadastrado.
 * @param numEventos Ponteiro para o número atual de eventos cadastrados.
 */
void cadastrarEvento(Evento* eventos, int* numEventos){
    if(*numEventos < MAX_EVENTOS){
        scanf("\n%[^\n]\n", eventos[*numEventos].nome);
        scanf("%d %d %d\n", &eventos[*numEventos].dia, &eventos[*numEventos].mes, &eventos[*numEventos].ano);

        printf("Evento cadastrado com sucesso!\n");
        *numEventos+=1;
    }

    else if(*numEventos >= MAX_EVENTOS) printf("Limite de eventos atingido!\n");
}

/**
 * Exibe todos os eventos cadastrados no calendário.
 *
 * @param eventos Array de eventos a serem exibidos.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void exibirEventos(Evento* eventos, int* numEventos){
    if(*numEventos > 0){
        printf("Eventos cadastrados:\n");

        for(int i = 0; i < *numEventos; i++){
            printf("%d - %s - %d/%d/%d\n", i, eventos[i].nome, eventos[i].dia, eventos[i].mes, eventos[i].ano);
        }
    }

    else printf("Nenhum evento cadastrado.\n");
}

/**
 * Troca a data de um evento específico no calendário.
 *
 * @param eventos Array de eventos onde o evento será modificado.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void trocarDataEvento(Evento* eventos, int* numEventos){
    int event;
    int dia, mes, ano;

    scanf("%d\n", &event);
    scanf("%d %d %d\n", &dia, &mes, &ano);

    if(event < *numEventos){
        eventos[event].dia = dia;
        eventos[event].mes = mes;
        eventos[event].ano = ano;

        printf("Data modificada com sucesso!\n");
    }

    else printf("Indice invalido!\n");
}

/**
 * Troca a posição de dois eventos, a partir do índice, dentro do array de eventos.
 *
 * @param eventos Array de eventos onde a troca será realizada.
 * @param indiceA Ponteiro para o primeiro índice.
 * @param indiceB Ponteiro para o segundo índice.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void trocarIndicesEventos(Evento* eventos, int* indiceA, int* indiceB, int* numEventos){
    Evento eventoMuda;

    if(*indiceA > *numEventos || *indiceB > *numEventos){
        strcpy(eventoMuda.nome, eventos[*indiceA].nome);

        eventoMuda.dia = eventos[*indiceA].dia;
        eventoMuda.mes = eventos[*indiceA].mes;
        eventoMuda.ano = eventos[*indiceA].ano;

        strcpy(eventos[*indiceA].nome, eventos[*indiceB].nome);

        eventos[*indiceA].dia = eventos[*indiceB].dia;
        eventos[*indiceA].mes = eventos[*indiceB].mes;
        eventos[*indiceA].ano = eventos[*indiceB].ano;

        strcpy(eventos[*indiceB].nome, eventos[*indiceA].nome);

        eventos[*indiceB].dia = eventos[*indiceA].dia;
        eventos[*indiceB].mes = eventos[*indiceA].mes;
        eventos[*indiceB].ano = eventos[*indiceA].ano;
    }

    else printf("Indice invalido!\n");

}
