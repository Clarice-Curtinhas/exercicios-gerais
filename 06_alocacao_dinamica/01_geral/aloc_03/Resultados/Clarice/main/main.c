#include <stdio.h>
#include <stdlib.h>
#include "utils_char.h"

int main(){
    char *vetor;
    int tam;

    scanf("%d%*c", &tam);

    vetor = CriaVetor(tam);

    ImprimeString(vetor, tam);
    LeVetor(vetor, tam);
    ImprimeString(vetor, tam);
    LiberaVetor(vetor);

    return 0;
}