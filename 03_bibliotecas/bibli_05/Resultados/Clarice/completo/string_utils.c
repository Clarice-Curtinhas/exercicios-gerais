#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Retorna o tamanho de uma string.
 * @param str A string para obter o tamanho.
 * @return O tamanho da string.
 */
int string_length(char *str){
    int tam = 0;

    while(str[tam] != '\n') tam++;

    return tam + 2;
}

/**
 * @brief Copia uma string de origem para destino.
 * @param src A string de origem.
 * @param dest A string de destino.
 */
void string_copy(char *src, char *dest){
    int tam, total;

    total = string_length(src) - 2;

    for(tam = 0; tam < total; tam++){
        dest[tam] = src[tam];
    }
    
    dest[tam] = '\0';
}

/**
 * @brief Converte todos os caracteres de uma string para maiúsculas.
 * @param str A string para converter.
 */
void string_upper(char *str){
    int qnt = 0;

    while(str[qnt] != '\0'){
        if(str[qnt] >= 97 && str[qnt] <= 122){
            str[qnt] -= 32;
        }

        qnt++;
    }
}

/**
 * @brief Converte todos os caracteres de uma string para minúsculas.
 * @param str A string para converter.
 */
void string_lower(char *str){
    int qnt = 0;

    while(str[qnt] != '\0'){
        if(str[qnt] >= 65 && str[qnt] <= 90){
            str[qnt] += 32;
        }

        qnt++;
    }
}

/**
 * @brief Inverte uma string.
 * @param str A string para inverter.
 */
void string_reverse(char *str){
    int qnt = 0, tam;
    tam = string_length(str) - 3;

    char invertido[tam];

    while(tam >= 0){
        invertido[tam] = str[qnt];
        qnt++;
        tam--;
    }

    invertido[qnt] = '\0';
    qnt--;

    while(qnt >= 0){
        str[qnt] = invertido[qnt];
        qnt--;
    }
}