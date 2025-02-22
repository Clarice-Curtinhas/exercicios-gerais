#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    float x;
    float y;
    float raio;
} tCirculo;

tCirculo lerCirculo();
float distEntreEles(tCirculo tiro, tCirculo alvo);

int main(){
    float distanciaMax;

    tCirculo tiro;
    tCirculo alvo;

    tiro = lerCirculo();
    alvo = lerCirculo();

    distanciaMax = tiro.raio + alvo.raio;

    if(distanciaMax >= distEntreEles(tiro, alvo)) printf("ACERTOU");

    else printf("ERROU");

    return 0;
}

tCirculo lerCirculo(){
    tCirculo c;

    scanf("%f %f %f", &c.x, &c.y, &c.raio);

    return c;
}

float distEntreEles(tCirculo tiro, tCirculo alvo){
    float distancia;

    distancia = sqrt(pow((tiro.x - alvo.x), 2) + pow((tiro.y - alvo.y), 2));
    
    return distancia;
}