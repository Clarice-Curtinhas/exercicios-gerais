#include "string_utils.h"

#include <stdio.h>
#include <stdlib.h>

int main(){
    int tam = 0, escolha = 0;
    char string[100];
    char copia[100];

    scanf("%c", &string[0]);

    while(string[tam] != '\n'){
        tam++;
        scanf("%c", &string[tam]);
    }


    while(escolha != 6){
        printf("1 - Tamanho da string\n");
        printf("2 - Copiar string\n");
        printf("3 - Converter string para letras maiusculas\n");
        printf("4 - Converter string para letras minusculas\n");
        printf("5 - Imprimir string ao contrario\n");
        printf("6 - Encerrar o programa\n");
        printf("Opcao escolhida:\n");

        scanf("%d", &escolha);

        if(escolha == 1) printf("Tamanho da string: %d\n\n", string_length(string));

        else if(escolha == 2){
            string_copy(string, copia);
            printf("String copiada: %s\n\n", copia);
        }

        else if(escolha == 3){
            string_upper(string);
            printf("String convertida para maiusculas: %s\n", string);
        }

        else if(escolha == 4){
            string_lower(string);
            printf("String convertida para minusculas: %s\n", string);
        }

        else if(escolha == 5){
            string_reverse(string);
            printf("String invertida: %s\n", string);
        }
    }

    return 0;
}