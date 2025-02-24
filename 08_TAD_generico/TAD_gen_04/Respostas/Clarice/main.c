#include <stdio.h>
#include <stdlib.h>

#include "banco.h"
#include "agencia.h"
#include "conta.h"

#define agencia 'A'
#define conta 'C'
#define finaliza 'F'

int main(){
    int nAgencia;
    char opcao;
    tBanco *b;

    b = CriaBanco();
    LeBanco(b);

    while((scanf("%c\n", &opcao)) && opcao != finaliza){
        if(opcao == agencia){
            tAgencia *a;
            a = CriaAgencia();
            LeAgencia(a);

            AdicionaAgencia(b, a);
        }

        if(opcao == conta){
            tConta *c;
            c = CriaConta();
            LeConta(c);
            scanf("%d\n", &nAgencia);

            InsereContaBanco(b, nAgencia, c);
        }
    }

    ImprimeRelatorioBanco(b);
    DestroiBanco(b);

    return 0;
}