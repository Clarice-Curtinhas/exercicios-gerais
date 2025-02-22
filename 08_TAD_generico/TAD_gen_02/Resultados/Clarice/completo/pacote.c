#include <stdio.h>
#include <stdlib.h>

typedef enum {
    INT = 1,
    CHAR = 2
} Type;

typedef struct pacote{
    Type tipo;
    int numElem;
    void *lista;
    int soma;
} tPacote;

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar um pacote a ser transmitido
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tPacote* CriaPacote(Type type, int numElem){
    tPacote *pac;

    pac = (tPacote*) calloc(1, sizeof(tPacote));

    if(type == INT){
        pac->lista = (int*) calloc(numElem+1, sizeof(int));
    }

    else if(type == CHAR){
        pac->lista = (char*) calloc(numElem+1, sizeof(char));
    }

    pac->numElem = numElem;
    if(type == CHAR) pac->tipo = CHAR;
    else if(type == INT) pac->tipo = INT;
    pac->soma = 0;

    return pac;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param pac - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiPacote(tPacote* pac){
    free(pac->lista);
    free(pac);
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param pac - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LePacote(tPacote* pac){
    int i;

    printf("\nDigite o conteúdo do vetor/mensagem:");
    scanf("\n");

    if(pac->tipo == INT){
        int inte;

        for(i = 0; i < pac->numElem; i++){
            scanf("%d ", &inte);
            ((int*)pac->lista)[i] = inte;
        }
    }

    else if(pac->tipo == CHAR){
        char carac;

        for(i = 0; i < pac->numElem; i++){
            scanf("%c", &carac);
            if(carac == '\n') break;
            ((char*)pac->lista)[i] = carac;
        }

        ((char*)pac->lista)[i] = '\0';
    }
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param pac - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimePacote(tPacote* pac){
    CalculaSomaVerificacaoPacote(pac);
    printf("%d ", pac->soma);

    if(pac->tipo == INT){
        int inte;

        for(int i = 0; i < pac->numElem; i++){
            inte = ((int*)pac->lista)[i];
            printf("%d ", inte);
        }
    }

    else if(pac->tipo == CHAR){
        char carac;

        for(int i = 0; i < pac->numElem; i++){
            carac = ((char*)pac->lista)[i];
            printf("%c", carac);
        }
    }

    printf("\n");
}

/**
 * @brief Calcula a soma de verificacao de um pacote e a armazena internamente
 *
 * @param pac - O vetor genérico que terá sua soma de verificacao calculada
 */
void CalculaSomaVerificacaoPacote(tPacote* pac){
    for(int i = 0; i < pac->numElem; i++){
        if(pac->tipo == INT){
            int inte;
            inte = ((int*)pac->lista)[i];
            pac->soma += inte;
        }

        else if(pac->tipo == CHAR){
            char carac;
            carac = ((char*)pac->lista)[i];
            pac->soma += carac;
        }
    }
}

