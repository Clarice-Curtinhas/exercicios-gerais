#include <stdio.h>
#include <stdlib.h>

int verificaDataValida(int dia, int mes, int ano);
void imprimeData(int dia, int mes, int ano);
void imprimeMesExtenso(int mes);
void imprimeDataExtenso(int dia, int mes, int ano);
int verificaBissexto(int ano);
int numeroDiasMes(int mes, int ano);
int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2);
int calculaDiasAteMes(int mes, int ano);
int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2);
void imprimeProximaData(int dia, int mes, int ano);

/**
 * @brief Verifica se uma data é válida.
 * 
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 * @return Retorna 1 se a data é válida e 0 caso contrário.
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
 * @brief Imprime uma data no formato DD/MM/AAAA.
 * 
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 */
void imprimeData(int dia, int mes, int ano){
    if(dia < 10) printf("0%d/", dia);
    else printf("%d/", dia);

    if(mes < 10) printf("0%d/", mes);
    else printf("%d/", mes);

    if(ano < 10) printf("000%d", ano);
    else if(ano < 100) printf("00%d", ano);
    else if(ano < 1000) printf("0%d", ano);
    else printf("%d", ano);
}

/**
 * @brief Imprime o nome do mês por extenso.
 * 
 * @param mes Mês da data.
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
    else if(mes == 12) printf("Dezembro");
}

/**
 * @brief Imprime uma data por extenso no formato "DD de NOME_DO_MES de AAAA".
 * 
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 */
void imprimeDataExtenso(int dia, int mes, int ano){
    if(dia < 10) printf("0%d de ", dia);
    else printf("%d de ", dia);

    imprimeMesExtenso(mes);

    if(ano < 10) printf(" de 000%d\n", ano);
    else if(ano < 100) printf(" de 00%d\n", ano);
    else if(ano < 1000) printf(" de 0%d\n", ano);
    else printf(" de %d\n", ano);
}

/**
 * @brief Verifica se um ano é bissexto.
 * 
 * @param ano Ano a ser verificado.
 * @return Retorna 1 se o ano é bissexto e 0 caso contrário.
 */
int verificaBissexto(int ano){
    if(ano % 100 == 0 && ano % 400 == 0) return 1;
    else if(ano % 4 == 0) return 1;

    else return 0;
}

/**
 * @brief Retorna o número de dias de um determinado mês.
 * 
 * @param mes Mês a ser verificado.
 * @param ano Ano da data.
 * @return Retorna o número de dias do mês.
 */
int numeroDiasMes(int mes, int ano){
    if(mes == 2){
        if(verificaBissexto(ano)) return 29;
        else return 28;
    }

    if(mes <= 7 && mes % 2 == 0) return 30;
    else if(mes <= 7 && mes % 2 != 0) return 31;
    else if(mes > 7 && mes % 2 == 0) return 31;
    else return 30;
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
 * @return Retorna 1 se a primeira data é maior que a segunda, -1 se a primeira data é menor que a segunda e 0 se as datas são iguais.
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
 * @brief Calcula o número de dias até o início de um determinado mês.
 * 
 * @param mes Mês a ser verificado.
 * @param ano Ano da data.
 * @return Retorna o número de dias até o início do mês.
 */
int calculaDiasAteMes(int mes, int ano){
    int qntMes, diasAteMes = 0;

    for(qntMes = 1; qntMes < mes; qntMes++){
        diasAteMes += numeroDiasMes(qntMes, ano);
    }

    return diasAteMes;
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
 * @return Retorna o número de dias de diferença entre as datas.
 */
int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
    int comparacao, difDias = 0, anos;

    comparacao = comparaData(dia1, mes1, ano1, dia2, mes2, ano2);

    if(comparacao == 0) return 0;

    else if(comparacao == 1){
        if(ano1 == ano2){
            if(mes1 == mes2) difDias = dia1 - dia2;

            else difDias += (numeroDiasMes(mes1, ano1) - dia1) - (numeroDiasMes(mes2, ano2) - dia2);
        }

        else{
            for(anos = ano2; anos < ano1; anos++){
                if(verificaBissexto(anos)) difDias += 366;
                else difDias += 365;
            }

            difDias -= (calculaDiasAteMes(mes2, ano2) + dia2);
            difDias += calculaDiasAteMes(mes1, ano1) + dia1;
        }
    }

    else if(comparacao == -1){
        if(ano1 == ano2){
            if(mes1 == mes2) difDias = dia2 - dia1;

            else difDias = (numeroDiasMes(mes2, ano2) - dia2) - (numeroDiasMes(mes1, ano1) - dia1);
        }

        else{
            for(anos = ano1; anos < ano2; anos++){
                if(verificaBissexto(anos)) difDias += 366;
                else difDias += 365;
            }

            difDias -= (calculaDiasAteMes(mes1, ano1) + dia1);
            difDias += calculaDiasAteMes(mes2, ano2) + dia2;
        }
    }
}

/**
 * @brief Imprime a próxima data no formato DD/MM/AAAA.
 * 
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 */
void imprimeProximaData(int dia, int mes, int ano){
    int diaSegue, mesSegue, anoSegue;

    if(dia < numeroDiasMes(mes, ano)){
        diaSegue = dia + 1;
        mesSegue = mes;
        anoSegue = ano;
    }

    else{
        if(mes < 12){
            diaSegue = 1;
            mesSegue = mes + 1;
            anoSegue = ano;
        }

        else{
            diaSegue = 1;
            mesSegue = 1;
            anoSegue = ano + 1;
        }
    }

    imprimeData(diaSegue, mesSegue, anoSegue);
}