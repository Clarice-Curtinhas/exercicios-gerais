#include "candidato.h"
#include "eleicao.h"
#include "eleitor.h"

#include <stdio.h>
#include <stdlib.h>

int main(){
    tEleicao eleicao;

    eleicao = InicializaEleicao();
    eleicao = RealizaEleicao(eleicao);

    if(eleicao.totalEleitores != 0){
        ImprimeResultadoEleicao(eleicao);
    }

    return 0;
}