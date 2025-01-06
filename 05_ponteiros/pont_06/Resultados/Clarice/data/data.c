#include <stdio.h>
#include <stdlib.h>

typedef struct Data {
    int dia;
    int mes; 
    int ano; 
} tData;

int InformaQtdDiasNoMes( tData *data );

/**
 * @brief Inicializa uma data com os valores passados como parâmetro.
 * 
 * Esta função recebe como parâmetro o dia, mês e ano de uma data e inicializa a estrutura tData correspondente com esses valores.
 * 
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 * @param data Ponteiro para a estrutura tData que será inicializada.
 */
void InicializaDataParam( int dia, int mes, int ano, tData *data){
    data->dia = dia;
    data->mes = mes;
    data->ano = ano;
}

/**
 * @brief Lê uma data do usuário.
 * 
 * Esta função lê do usuário o dia, mês e ano de uma data e armazena esses valores na estrutura tData correspondente.
 * 
 * @param data Ponteiro para a estrutura tData que será preenchida com os valores lidos.
 */
void LeData( tData *data ){
    scanf("%d %d %d\n", &data->dia, &data->mes, &data->ano);

    if(data->mes > 12) data->mes = 12;
    if(data->dia > InformaQtdDiasNoMes(data)) data->dia = InformaQtdDiasNoMes(data);
}

/**
 * @brief Imprime uma data na tela.
 * 
 * Esta função recebe como parâmetro uma estrutura tData e imprime na tela o dia, mês e ano correspondentes.
 * 
 * @param data Ponteiro para a estrutura tData que será impressa.
 */
void ImprimeData( tData *data ){
    if(data->dia < 10) printf("'0%d/", data->dia);
    else printf("'%d/", data->dia);

    if(data->mes < 10) printf("0%d/", data->mes);
    else printf("%d/", data->mes);

    printf("%d'", data->ano);
}

/**
 * @brief Verifica se um ano é bissexto.
 * 
 * Esta função recebe como parâmetro uma estrutura tData e verifica se o ano correspondente é bissexto.
 * 
 * @param data Ponteiro para a estrutura tData que será verificada.
 * @return 1 se o ano é bissexto, 0 caso contrário.
 */
int EhBissexto( tData *data ){
    if((data->ano%4) == 0) return 1;
    else return 0;
}

/**
 * @brief Informa a quantidade de dias no mês de uma data.
 * 
 * Esta função recebe como parâmetro uma estrutura tData e informa a quantidade de dias no mês correspondente.
 * 
 * @param data Ponteiro para a estrutura tData que será verificada.
 * @return Quantidade de dias no mês correspondente.
 */
int InformaQtdDiasNoMes( tData *data ){
    if((data->mes) == 2){
        if(EhBissexto(data) == 1) return 29;
        else return 28;
    }

    else{
        if(((data->mes) < 8) && ((data->mes)%2 == 0)) return 30;
        else if(((data->mes) < 8) && ((data->mes)%2 != 0)) return 31;

        else if(((data->mes) >= 8) && ((data->mes)%2 == 0)) return 31;
        else if(((data->mes) >= 8) && ((data->mes)%2 != 0)) return 30;
    }
}

/**
 * @brief Avança uma data para o dia seguinte.
 * 
 * Esta função recebe como parâmetro uma estrutura tData e avança a data correspondente para o dia seguinte.
 * 
 * @param data Ponteiro para a estrutura tData que será avançada.
 */
void AvancaParaDiaSeguinte( tData *data ){
    if(InformaQtdDiasNoMes(data) <= (data->dia)){
        data->dia = 1;

        if((data->mes) == 12){
            data->mes = 1;
            data->ano++;
        }

        else{
            data->mes++;
        }
    }

    else{
        data->dia++;
    }
}

/**
 * @brief Verifica se duas datas são iguais.
 * 
 * Esta função recebe como parâmetro duas estruturas tData e verifica se elas representam a mesma data.
 * 
 * @param data1 Ponteiro para a primeira estrutura tData que será comparada.
 * @param data2 Ponteiro para a segunda estrutura tData que será comparada.
 * @return 1 se as datas são iguais, 0 caso contrário.
 */
int EhIgual( tData *data1, tData *data2 ){
    if((data1->dia == data2->dia) && (data1->mes == data2->mes) && (data1->ano == data2->ano)) return 1;
    else return 0;
}