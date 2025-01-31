#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main(){
    int tam, *v;
    float media;

    scanf("%d\n", &tam);

    v = CriaVetor(tam);

    LeVetor(v, tam);

    media = CalculaMedia(v, tam);
    
    printf("%.2f\n", media);

    LiberaVetor(v);

    return 0;
}