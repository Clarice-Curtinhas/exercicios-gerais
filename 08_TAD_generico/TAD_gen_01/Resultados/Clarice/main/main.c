#include <stdio.h>
#include <stdlib.h>

#include "tadgen.h"

int main(){
    int tam;
    Type t;
    tGeneric *generico;

    printf("tad_gen_01\n");
    printf("Digite o tipo e numero de elementos:");

    scanf("%d %d\n", &t, &tam);

    generico = CriaGenerico(t, tam);
    LeGenerico(generico);
    ImprimeGenerico(generico);
    DestroiGenerico(generico);

    return 0;
}