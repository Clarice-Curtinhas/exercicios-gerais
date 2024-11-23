#include <stdio.h>
#include <stdlib.h>

typedef struct Data {
    int dia;
    int mes;
    int ano; 
} tData;

tData CriaData(int dia, int mes, int ano);
int VerificaDataValida(tData data);
void ImprimeMesExtenso(tData data);
void ImprimeDataExtenso(tData data);
int VerificaBissexto(tData data);
int NumeroDiasMes(tData data);
int ComparaData(tData data1, tData data2);
int CalculaDiasAteMes(tData data);
int CalculaDiferencaDias(tData data1, tData data2);

/**
 * @brief Cria uma data a partir de valores de dia, mês e ano.
 * 
 * @param dia Dia da data a ser criada.
 * @param mes Mês da data a ser criada.
 * @param ano Ano da data a ser criada.
 * @return tData Data criada a partir dos valores de dia, mês e ano.
 */
tData CriaData(int dia, int mes, int ano){
    tData data;
    
    data.dia = dia;
    data.mes = mes;
    data.ano = ano;

    return data;
}

/**
 * @brief Verifica se uma data é válida.
 * 
 * @param data Data a ser verificada.
 * @return int 1 se a data é válida, 0 caso contrário.
 */
int VerificaDataValida(tData data){

    if(data.ano > 0){
        if(data.mes >= 1 && data.mes <= 12){
            if(data.dia >= 1 && data.dia <= NumeroDiasMes(data)) return 1;
        }
    }

    return 0;
}

/**
 * @brief Imprime o mês de uma data em formato extenso.
 * 
 * @param data Data cujo mês será impresso em formato extenso.
 */
void ImprimeMesExtenso(tData data){
    if(data.mes == 1) printf("Janeiro");
    else if(data.mes == 2) printf("Fevereiro");
    else if(data.mes == 3) printf("Marco");
    else if(data.mes == 4) printf("Abril");
    else if(data.mes == 5) printf("Maio");
    else if(data.mes == 6) printf("Junho");
    else if(data.mes == 7) printf("Julho");
    else if(data.mes == 8) printf("Agosto");
    else if(data.mes == 9) printf("Setembro");
    else if(data.mes == 10) printf("Outubro");
    else if(data.mes == 11) printf("Novembro");
    else if(data.mes == 12) printf("Dezembro");
}

/**
 * @brief Imprime uma data em formato extenso.
 * 
 * @param data Data a ser impressa em formato extenso.
 */
void ImprimeDataExtenso(tData data){
    if(data.dia >= 10) printf("%d de ", data.dia);
    else printf("0%d de ", data.dia);

    ImprimeMesExtenso(data);

    printf(" de %d\n", data.ano);
}

/**
 * @brief Verifica se um ano é bissexto.
 * 
 * @param data Data cujo ano será verificado.
 * @return int 1 se o ano é bissexto, 0 caso contrário.
 */
int VerificaBissexto(tData data){
    if(data.ano % 100 == 0 && data.ano % 400 == 0) return 1;
    else if(data.ano % 4 == 0) return 1;

    else return 0;
}

/**
 * @brief Retorna o número de dias de um determinado mês.
 * 
 * @param data Data cujo mês terá o número de dias retornado.
 * @return int Número de dias do mês da data.
 */
int NumeroDiasMes(tData data){
    if(VerificaBissexto(data) == 1 && data.mes == 2) return 29;
    else if(data.mes == 2) return 28;

    if(data.mes <= 7){
        if(data.mes % 2 == 0)return 30;
        else if(data.mes % 2 != 0) return 31;
    }

    else if(data.mes > 7){
        if(data.mes % 2 == 0) return 31;
        else if(data.mes % 2 != 0) return 30;
    }
}

/**
 * @brief Compara duas datas.
 * 
 * @param data1 Primeira data a ser comparada.
 * @param data2 Segunda data a ser comparada.
 * @return int 1 se data1 é maior que data2, -1 se data1 é menor que data2, 0 se as datas são iguais.
 * A data ser maior significa que ela é mais recente.
 */
int ComparaData(tData data1, tData data2){
    if(data1.ano > data2.ano) return 1;
    else if(data1.ano < data2.ano) return -1;

    else{
        if(data1.mes > data2.mes) return 1;
        else if(data1.mes < data2.mes) return -1;

        else{
            if(data1.dia > data2.dia) return 1;
            else if(data1.dia < data2.dia) return -1;
            else return 0;
        }
    }
}

/**
 * @brief Calcula o número de dias até o início do mês de uma determinada data.
 * 
 * @param data Data cujo número de dias até o início do mês será calculado.
 * @return int Número de dias até o início do mês da data.
 */
int CalculaDiasAteMes(tData data){
    tData numData;
    int num, dias = 0;

    numData.dia = 1;
    numData.ano = data.ano;

    for(num = 1; num < data.mes; num++){
        numData.mes = num;
        dias += NumeroDiasMes(numData);
    }

    return dias;
}

/**
 * @brief Calcula a diferença em dias entre duas datas.
 * 
 * @param data1 Primeira data a ser comparada.
 * @param data2 Segunda data a ser comparada.
 * @return int Número de dias entre as duas datas.
 */
int CalculaDiferencaDias(tData data1, tData data2){
    tData countData;
    int comparacao, dias = 0, count;

    comparacao = ComparaData(data1, data2);
    
    if(comparacao == 0) return 0;

    else if(comparacao == 1){
        if(data1.ano > data2.ano){

            for(count = data2.ano+1; count < data1.ano; count++){
                countData.ano = count;

                if(VerificaBissexto(countData)) dias += 366;
                else dias += 365;
            }

            dias += ((365 + VerificaBissexto(data2)) - CalculaDiasAteMes(data2)) - data2.dia;
            dias += CalculaDiasAteMes(data1) + data1.dia;
        }

        else{
            if(data1.mes > data2.mes){
                countData.ano = data1.ano;

                for(count = data2.mes; count < data1.mes; count++){
                    countData.mes = count;
                    dias += NumeroDiasMes(countData);
                }

                dias -= data2.dia;
                dias += data1.dia;
            }

            else dias = data1.dia - data2.dia;
        }
    }

    else if(comparacao == -1){
        if(data2.ano > data1.ano){

            for(count = data1.ano+1; count < data2.ano; count++){
                countData.ano = count;

                if(VerificaBissexto(countData)) dias += 366;
                else dias += 365;
            }

            dias += ((365 + VerificaBissexto(data1)) - CalculaDiasAteMes(data1)) - data1.dia;
            dias += CalculaDiasAteMes(data2) + data2.dia;
        }

        else{
            if(data2.mes > data1.mes){
                countData.ano = data2.ano;

                for(count = data1.mes; count < data2.mes; count++){
                    countData.mes = count;
                    dias += NumeroDiasMes(countData);
                }

                dias -= data1.dia;
                dias += data2.dia;
            }

            else dias = data2.dia - data1.dia;
        }
    }

    return dias;
}