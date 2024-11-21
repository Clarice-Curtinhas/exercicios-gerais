#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

int numTamanho;
int numInicio;

int palindromo(char *string, int tamanho);
int printarIf(char *string, int tamanho);

int main(){
    char string[100];
    int tamanho;
    tamanho = 0;

    while(scanf("%c", &string[tamanho]) == true){
        
        if(string[tamanho] == '\n'){
            tamanho = printarIf(string, tamanho);
        }

        tamanho++;
    }

    tamanho = printarIf(string, tamanho);

    return 0;
}

int palindromo(char *string, int tamanho){

    if(tamanho == 0) return true;
    
    else{
        if(string[numInicio] == string[numTamanho]){
            numInicio++;
            numTamanho--;
            return palindromo(string, tamanho-1);
        }

        else return false;
    }
}

int printarIf(char *string, int tamanho){
    int palin;

    numInicio = 0;
    numTamanho = tamanho-1;

    if(tamanho%2 == 0){
        palin = palindromo(string, (tamanho)/2);
    }

    else{
        palin = palindromo(string, (tamanho-1)/2);
    }

    if(palin == true) printf("SIM\n");
    else printf("NAO\n");

    return -1;
}