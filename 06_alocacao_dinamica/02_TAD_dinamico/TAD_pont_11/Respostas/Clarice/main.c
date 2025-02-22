#include <stdio.h>
#include <stdlib.h>

#include "loja.h"
#include "vendedor.h"

int NovaLoja(tLoja **loja, int lojasExistentes);
void Contrata(tLoja **loja, int lojasExistentes);
void Vendas(tLoja **loja, int lojasExistentes);
void Relatorio(tLoja **loja, int lojasExistentes);

int main(){
    int maxLojas, lojasExistes = 0, opcao;
    tLoja **loja;

    scanf("%d\n", &maxLojas);

    loja = (tLoja**) calloc(maxLojas, sizeof(tLoja*));

    while((scanf("%d\n", &opcao) == 1) && opcao != 0){
        if(opcao == 1){
            if(lojasExistes < maxLojas){
                lojasExistes = NovaLoja(loja, lojasExistes);
            }
        }

        else if(opcao == 2) Contrata(loja, lojasExistes);
        else if(opcao == 3) Vendas(loja, lojasExistes);
        else if(opcao == 4) Relatorio(loja, lojasExistes);

        else break;
    }

    for(int i = 0; i < lojasExistes; i++){
        ApagaLoja(loja[i]);
    }

    free(loja);

    return 0;
}

int NovaLoja(tLoja **loja, int lojasExistentes){
    int id;
    float aluguel;

    scanf("%d %d\n", &id, &aluguel);

    loja[lojasExistentes] = AbreLoja(id, aluguel);

    lojasExistentes++;

    return lojasExistentes;
}

void Contrata(tLoja **loja, int lojasExistentes){
    int j = 0, idLoja;
    float salario, porcentagem;
    char *nome;

    tVendedor *vendedor;

    nome = (char*) calloc(1, sizeof(char));

    while((scanf("%c", &nome[j]) == 1) && (nome[j] != ' ')){
        j++;
        nome = (char*) realloc(nome, (j+1)*sizeof(char));
    }

    nome[j] = '\0';

    scanf("%f %f\n", &salario, &porcentagem);
    scanf("%d\n", &idLoja);

    vendedor = RegistraVendedor(nome, salario, porcentagem);

    for(int i = 0; i < lojasExistentes; i++){
        if(VerificaIdLoja(loja[i], idLoja) == 1){
            ContrataVendedor(loja[i], vendedor);
            break;
        }
    }

    free(nome);
}

void Vendas(tLoja **loja, int lojasExistentes){
    int idLoja, j = 0;
    float venda;
    char *nome;

    scanf("%d ", &idLoja);

    nome = (char*) calloc(1, sizeof(char));

    while((scanf("%c", &nome[j]) == 1) && (nome[j] != ' ')){
        j++;
        nome = (char*) realloc(nome, (j+1)*sizeof(char));
    }

    nome[j] = '\0';

    scanf("%f\n", &venda);

    for(int i = 0; i < lojasExistentes; i++){
        if(VerificaIdLoja(loja[i], idLoja) == 1){
            CalculaLucro(loja[i]);
            RegistraVenda(loja[i], nome, venda);
            break;
        }
    }

    free(nome);
}

void Relatorio(tLoja **loja, int lojasExistentes){
    for(int i = 0; i < lojasExistentes; i++){
        ImprimeRelatorioLoja(loja[i]);
    }
}