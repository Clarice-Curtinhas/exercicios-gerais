#include "ponto.h"

#include <stdio.h>
#include <stdlib.h>

int main(){
    float x, y;
    Ponto p1, p2;

    scanf("%f %f ", &x, &y);
    p1 = pto_cria(x, y);

    scanf("%f %f ", &x, &y);
    p2 = pto_cria(x, y);

    printf("%g", pto_distancia(p1, p2));
}