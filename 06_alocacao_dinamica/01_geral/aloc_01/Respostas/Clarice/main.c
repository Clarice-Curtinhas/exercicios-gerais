#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main(){
    int tam, *v;

    scanf("%d\n", &tam);

    *v = CriaVetor(tam);

    /*LeVetor(&v, tam);

    CalculaMedia(&v, tam);*/

    LiberaVetor(&v);

    return 0;
}