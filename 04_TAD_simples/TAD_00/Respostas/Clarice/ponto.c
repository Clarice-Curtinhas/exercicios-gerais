#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/* TAD: Ponto (x,y) */

/* Tipo exportado */
struct ponto {
	float x;
	float y;
};

typedef struct ponto Ponto;

Ponto pto_cria (float x, float y);
float pto_acessa_x (Ponto p);
float pto_acessa_y (Ponto p);
Ponto pto_atribui_x (Ponto p, float x);
Ponto pto_atribui_y (Ponto p, float y);
float pto_distancia (Ponto p1, Ponto p2);

/* Funcoes exportadas */

/* Funcao cria 
** Retorna um ponto com coordenadas (x,y)
*/
Ponto pto_cria (float x, float y){
    Ponto p;

    p = pto_atribui_x(p, x);
    p = pto_atribui_y(p, y);

    return p;
}

/* Funcao acessa x
** Retorna o valor da coordenada x de um ponto
*/
float pto_acessa_x (Ponto p){
    return p.x;
}

/* Funcao acessa y
** Retorna o valor da coordenada x de um ponto
*/
float pto_acessa_y (Ponto p){
    return p.y;
}

/* Funcao atribui x
** Atribui novo valor as coordenada x de um ponto
*/
Ponto pto_atribui_x (Ponto p, float x){
    p.x = x;
    return p;
}

/* Funcao atribui y
** Atribui novo valor as coordenada x de um ponto
*/
Ponto pto_atribui_y (Ponto p, float y){
    p.y = y;
    return p;
}

/* Funcao distancia
** Retorna a distancia entre dois pontos
*/
float pto_distancia (Ponto p1, Ponto p2){
    float dist;

    dist = pow((pto_acessa_x(p1) - pto_acessa_x(p2)), 2) + pow((pto_acessa_y(p1) - pto_acessa_y(p2)), 2);

    return sqrt(dist);
}