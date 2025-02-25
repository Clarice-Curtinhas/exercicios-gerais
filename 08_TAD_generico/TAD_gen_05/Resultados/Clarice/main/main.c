#include <stdio.h>
#include <stdlib.h>

#include "agendatarefas.h"
#include "tarefaimprime.h"
#include "tarefamultiplica.h"
#include "tarefasoma.h"

#define errada 'e'
#define certa 'c'

char *scanString();

int main(){
    int qntTarefas, prioridade, n1, n2;
    char tarefa, entrada = certa;
    tAgendaTarefas *agenda;

    printf("Digite o numero de tarefas:");
    scanf("%d\n", &qntTarefas);

    agenda = CriaAgendaDeTarefas(qntTarefas);

    for(int i = 0; i < qntTarefas; i++){
        scanf("%d %c ", &prioridade, &tarefa);

        if(tarefa == 'I'){
            char *string;
            tImpr *imprime;
            string = scanString();

            imprime = CriaTarefaImprimir(string);
            CadastraTarefaNaAgenda(agenda, prioridade, imprime, ExecutaTarefaImprimir, DestroiTarefaImprimir);

            free(string);
        }

        else if(tarefa == 'M'){
            scanf("%f %f\n", &n1, &n2);
            tMult *mult;

            mult = CriaTarefaMultiplicar(n1, n2);
            CadastraTarefaNaAgenda(agenda, prioridade, mult, ExecutaTarefaMultiplicar, DestroiTarefaMultiplicar);
        }

        else if(tarefa == 'S'){
            scanf("%f %f\n", &n1, &n2);
            tSoma *soma;

            soma = CriaTarefaSoma(n1, n2);
            CadastraTarefaNaAgenda(agenda, prioridade, soma, ExecutaTarefaSoma, DestroiTarefaSoma);
        }

        else{
            entrada = errada;
            while((scanf("%c", &tarefa)) == 1);
            break;
        }
    }

    if(entrada == certa) ExecutarTarefasDaAgenda(agenda);
    else printf("Digite um tipo de tarefa suportado (I/S/M))\n");
    DestroiAgendaDeTarefas(agenda);

    return 0;
}

char *scanString(){
    char *string;
    int k = 0;

    string = (char*) calloc(1, sizeof(char));

    while((scanf("%c", &string[k]) == 1) && (string != '\n')){
        k++;
        string = (char*) realloc(string, (k+1)*sizeof(char));
    }

    string[k] = '\0';

    return string;
}