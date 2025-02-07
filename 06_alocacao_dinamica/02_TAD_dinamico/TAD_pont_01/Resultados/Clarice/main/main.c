#include <stdio.h>
#include <stdlib.h>

#include "jogo.h"

int main(){

    while(1){
        tJogo *jogo;

        jogo = CriaJogo();
        ComecaJogo(jogo);

        DestroiJogo(jogo);

        if(ContinuaJogo(jogo) == 0) break;
    }

    return 0;
}