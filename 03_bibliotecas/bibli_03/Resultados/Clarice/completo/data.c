#include <stdio.h>
#include <stdlib.h>

int verificaDataValida(int dia, int mes, int ano);
void imprimeMesExtenso(int mes);
void imprimeDataExtenso(int dia, int mes, int ano);
int verificaBissexto(int ano);
int numeroDiasMes(int mes, int ano);
int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2);
int calculaDiasAteMes(int mes, int ano);
int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2);


/**
 * @brief Verifica se uma data é válida.
 * 
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 * @return int Retorna 1 se a data é válida e 0 caso contrário.
 */
int verificaDataValida(int dia, int mes, int ano){

    if(ano > 0){
        if(mes > 0 && mes <= 12){
            if(dia > 0 && dia <= numeroDiasMes(mes, ano)) return 1;
        }
    }

    return 0;
}

/**
 * @brief Imprime o nome do mês por extenso.
 * 
 * @param mes Mês a ser impresso.
 */
void imprimeMesExtenso(int mes){
    if(mes == 1) printf("Janeiro");

    else if(mes == 2) printf("Fevereiro");

    else if(mes == 3) printf("Marco");

    else if(mes == 4) printf("Abril");

    else if(mes == 5) printf("Maio");

    else if(mes == 6) printf("Junho");
    
    else if(mes == 7) printf("Julho");
    
    else if(mes == 8) printf("Agosto");
    
    else if(mes == 9) printf("Setembro");
    
    else if(mes == 10) printf("Outubro");
    
    else if(mes == 11) printf("Novembro");
    
    else printf("Dezembro");
}

/**
 * @brief Imprime a data por extenso.
 * 
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 */
void imprimeDataExtenso(int dia, int mes, int ano){
    if(dia < 10) printf("0%d de ", dia);
    else printf("%d de ", dia);

    imprimeMesExtenso(mes);

    if(ano < 10) printf(" de 000%d", ano);
    else if(ano < 100) printf(" de 00%d", ano);
    else if(ano < 1000) printf(" de 0%d", ano);
    else printf(" de %d\n", ano);
}

/**
 * @brief Verifica se um ano é bissexto.
 * 
 * @param ano Ano a ser verificado.
 * @return int Retorna 1 se o ano é bissexto e 0 caso contrário.
 */
int verificaBissexto(int ano){
    if(ano % 100 == 0 && ano % 400 == 0) return 1;
    else if(ano % 4 == 0) return 1;

    else return 0;
}

/**
 * @brief Calcula o número de dias de um mês.
 * 
 * @param mes Mês a ser verificado.
 * @param ano Ano da data.
 * @return int Retorna o número de dias do mês.
 */
int numeroDiasMes(int mes, int ano){
    if(verificaBissexto(ano)){
        if(mes == 2) return 29;
    }
    else if(mes == 2) return 28;

    if(mes <= 7 && mes % 2 != 0) return 31;
    else if(mes <= 7 && mes % 2 == 0) return 30;
    else if(mes > 7 && mes % 2 == 0) return 31;
    else if(mes > 7 && mes % 2 != 0) return 30;
}

/**
 * @brief Compara duas datas.
 * 
 * @param dia1 Dia da primeira data.
 * @param mes1 Mês da primeira data.
 * @param ano1 Ano da primeira data.
 * @param dia2 Dia da segunda data.
 * @param mes2 Mês da segunda data.
 * @param ano2 Ano da segunda data.
 * @return int Retorna 1 se a primeira data é maior que a segunda, -1 se a primeira data é menor que a segunda
 * e 0 se as datas são iguais.
 * A data ser "maior" significa que ela está mais no futuro.
 */
int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
    if(ano1 > ano2) return 1;
    else if(ano1 < ano2) return -1;

    else{
        if(mes1 > mes2) return 1;
        else if(mes1 < mes2) return -1;

        else{
            if(dia1 > dia2) return 1;
            else if(dia1 < dia2) return -1;
            else return 0;
        }
    }
}


/**
 * @brief Calcula o número de dias até o mês.
 * 
 * @param mes Mês a ser verificado.
 * @param ano Ano da data.
 * @return int Retorna o número de dias até o mês.
*/
int calculaDiasAteMes(int mes, int ano){
    int tam, dias = 0;

    for(tam = 1; tam < mes; tam++){
        dias += numeroDiasMes(tam, ano);
    }

    return dias;
}

/**
 * @brief Calcula a diferença em dias entre duas datas.
 * 
 * @param dia1 Dia da primeira data.
 * @param mes1 Mês da primeira data.
 * @param ano1 Ano da primeira data.
 * @param dia2 Dia da segunda data.
 * @param mes2 Mês da segunda data.
 * @param ano2 Ano da segunda data.
 * @return int Retorna o número de dias de diferença entre as datas.
 */
int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
    int comparacao, diferenca = 0;
    int difMes, difAno;

    comparacao = comparaData(dia1, mes1, ano1, dia2, mes2, ano2);

    if(comparacao == 0){
        diferenca = 0;
    }

    else if(comparacao == 1){

        if(ano1 == ano2){
            if(mes1 == mes2){
                diferenca = dia1 - dia2;
            }

            else{
                diferenca += numeroDiasMes(mes2, ano1) - dia2;

                for(difMes = mes2+1; difMes < mes1; difMes++){
                    diferenca += numeroDiasMes(difMes, ano1);
                }

                diferenca += dia1;
            }
        }

        else{
            for(difAno = ano2; difAno < ano1; difAno++){
                if(verificaBissexto(difAno)) diferenca += 366;
                else diferenca += 365;
            }

            diferenca -= (calculaDiasAteMes(mes2, ano2) + dia2);

            diferenca += calculaDiasAteMes(mes1, ano1) + dia1;
        }
    }

    else if(comparacao == -1){

        if(ano1 == ano2){
            if(mes1 == mes2){
                diferenca = dia2 - dia1;
            }

            else{
                diferenca += numeroDiasMes(mes1, ano1) - dia1;

                for(difMes = mes1+1; difMes < mes2; difMes++){
                    diferenca += numeroDiasMes(difMes, ano1);
                }

                diferenca += dia2;
            }
        }

        else{
            for(difAno = ano1; difAno < ano2; difAno++){
                if(verificaBissexto(difAno)) diferenca += 366;
                else diferenca += 365;
            }

            diferenca -= (calculaDiasAteMes(mes1, ano1) + dia1);

            diferenca += calculaDiasAteMes(mes2, ano2) + dia2;
        }
    }

    return diferenca;
}
