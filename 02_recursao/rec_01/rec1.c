#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

int numChar;

void ImprimeInvertido(char* string){

    if(numChar == -1);

    else{
        numChar--;
        printf("%c", string[numChar]);
        return ImprimeInvertido(string);
    }
}

int main(){
    char string[1000];
    numChar = 0;

    while(scanf("%c", &string[numChar]) == true){

        if(string[numChar] == ' '){
            ImprimeInvertido(string);
            printf(" ");

            numChar = -1;
        }

        numChar++;
    }

    string[numChar] = ' ';

    ImprimeInvertido(string);

    return 0;
}