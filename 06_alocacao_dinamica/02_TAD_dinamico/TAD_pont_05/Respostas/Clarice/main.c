#include <stdio.h>
#include <stdlib.h>

#include "banco.h"

int main(){
    tBanco *banco;
    char opcao;

    banco = CriaBanco();

    while(1){
        scanf("%c\n", &opcao);

        if(opcao == 'A') AbreContaBanco(banco);
        else if(opcao == 'D') DepositoContaBanco(banco);
        else if(opcao == 'S') SaqueContaBanco(banco);
        else if(opcao == 'T') TransferenciaContaBanco(banco);
        else if(opcao == 'R') ImprimeRelatorioBanco(banco);

        else if(opcao == 'F') break;
    }

    DestroiBanco(banco);

    return 0;
}