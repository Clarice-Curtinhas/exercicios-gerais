#include <stdio.h>
#include <stdlib.h>
#include "utils_char2.h"

int main(){
    char *vetor;
    int *tamanho;
    tamanho = 10;

    vetor = CriaVetorTamPadrao();
    vetor = LeVetor(vetor, &tamanho);

    ImprimeString(vetor);
    LiberaVetor(vetor);

    return 0;
}