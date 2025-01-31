#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main(){
    int linhas, colunas;
    int **m;

    scanf("%d %d\n", &linhas, &colunas);

    m = CriaMatriz(linhas, colunas);

    LeMatriz(m, linhas, colunas);

    ImprimeMatrizTransposta(m, linhas, colunas);

    LiberaMatriz(m, linhas);

    return 0;
}