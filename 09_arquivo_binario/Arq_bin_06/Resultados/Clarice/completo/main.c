#include <stdio.h>
#include <stdlib.h>

#include "estabelecimento.h"
#include "vector.h"
#include "produto.h"

int main(){
    tEstabelecimento *e;

    e = CriaEstabelecimento();

    LeEstabelecimento(e);
    ImprimeRelatorioEstabelecimento(e);
    DestroiEstabelecimento(e);

    return 0;
}