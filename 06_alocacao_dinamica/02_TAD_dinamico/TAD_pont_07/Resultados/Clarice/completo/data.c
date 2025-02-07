#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "data.h"

/*typedef struct Data {
    int dia;
    int mes;
    int ano; 
} tData;*/

/**
 * @brief Aloca dinamicamente uma estrutura do tipo tData, e a retorna. 
 * Os campos dessa estrutura devem ser preenchidos inicialmente com -1.
 * 
 * @return tData - Data "Vazia"
 */
tData* CriaData(){
    tData *d;

    d = (tData*) calloc(1, sizeof(tData));

    d->dia = -1;
    d->mes = -1;
    d->ano = -1;

    return d;
}

/**
 * @brief Lê o dia, mês e ano e armazena em uma estrutura tData alocada dinamicamente.
 * 
 * @param data - Ponteiro para a estrutura onde os dados serão armazenados. Lembre-se: Não pode ter valor NULL.
 */
void LeData(tData* data){
    scanf("%d/%d/%d\n", &data->dia, &data->mes, &data->ano);
}

/**
 * @brief Libera a memória alocada dinamicamente para uma estrutura do tipo tData, passada como parâmetro
 * @param data - Ponteiro para a estrutura onde os dados estão armazenados. 
*/
void LiberaData(tData* data){
    free(data);
}

/**
 * @brief Verifica se uma data é válida.
 * 
 * @param data Data a ser verificada.
 * @return int 1 se a data é válida, 0 caso contrário.
 */
int VerificaDataValida(tData* data){
    if(data->dia > NumeroDiasMes(data) || data->dia < 1) return 0;
    else if(data->mes > 12 || data->mes < 1) return 0;
    return 1;
}

/**
 * @brief Imprime o mês de uma data em formato extenso.
 * 
 * @param data Data cujo mês será impresso em formato extenso.
 */
void ImprimeMesExtenso(tData* data){
    if(data->mes == 1) printf("Janeiro");
    else if(data->mes == 2) printf("Fevereiro");
    else if(data->mes == 3) printf("Marco");
    else if(data->mes == 4) printf("Abril");
    else if(data->mes == 5) printf("Maio");
    else if(data->mes == 6) printf("Junho");
    else if(data->mes == 7) printf("Julho");
    else if(data->mes == 8) printf("Agosto");
    else if(data->mes == 9) printf("Setembro");
    else if(data->mes == 10) printf("Outubro");
    else if(data->mes == 11) printf("Novembro");
    else if(data->mes == 12) printf("Dezembro");
}

/**
 * @brief Imprime uma data em formato extenso.
 * 
 * @param data Data a ser impressa em formato extenso.
 */
void ImprimeDataExtenso(tData* data){
    if(data->dia < 10) printf("0");
    printf("%d de ", data->dia);
    ImprimeMesExtenso(data);
    printf(" de %d\n", data->ano);
}

/**
 * @brief Verifica se um ano é bissexto.
 * 
 * @param data Data cujo ano será verificado.
 * @return int 1 se o ano é bissexto, 0 caso contrário.
 */
int VerificaBissexto(tData* data){
    if((data->ano%4) == 0) return 1;
    return 0;
}

/**
 * @brief Retorna o número de dias de um determinado mês.
 * 
 * @param data Data cujo mês terá o número de dias retornado.
 * @return int Número de dias do mês da data.
 */
int NumeroDiasMes(tData* data){
    if(data->mes == 2 && VerificaBissexto(data) == 1) return 29;
    else if(data->mes == 2) return 28;

    if((data->mes%2) == 0){
        if(data->mes <= 7) return 30;
        else return 31;
    }

    else{
        if(data->mes <= 7) return 31;
        else return 30;
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
int ComparaData(tData* data1, tData* data2){
    if(data1->ano > data2->ano) return 1;
    else if(data2->ano > data1->ano) return -1;

    else{
        if(data1->mes > data2->mes) return 1;
        else if(data2->mes > data1->mes) return -1;

        else{
            if(data1->dia > data2->dia) return 1;
            else if(data2->dia > data1->dia) return -1;
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
int CalculaDiasAteMes(tData* data){
    int falta;

    falta = NumeroDiasMes(data) - data->dia;

    return falta;
}

/**
 * @brief Calcula a diferença em dias entre duas datas.
 * 
 * @param data1 Primeira data a ser comparada.
 * @param data2 Segunda data a ser comparada.
 * @return int Número de dias entre as duas datas.
 */
int CalculaDiferencaDias(tData* data1, tData* data2){
    tData *dataIntermed;
    int diffDias = 0;

    dataIntermed = CriaData();

    if(ComparaData(data1, data2) == -1){
        dataIntermed->dia = data1->dia;
        dataIntermed->mes = data1->mes;
        dataIntermed->ano = data1->ano;

        if(data1->ano < data2->ano){
            diffDias += CalculaDiasAteMes(dataIntermed);

            for(dataIntermed->mes = data1->mes+1; dataIntermed->mes <= 12; dataIntermed->mes++){
                diffDias += NumeroDiasMes(dataIntermed);
            }

            for(dataIntermed->ano = data1->ano+1; dataIntermed->ano < data2->ano; dataIntermed->ano++){
                diffDias += 365 + (VerificaBissexto(dataIntermed));
            }

            for(dataIntermed->mes = 1; dataIntermed->mes < data2->mes; dataIntermed->mes++){
                diffDias += NumeroDiasMes(dataIntermed);
            }

            diffDias += data2->dia;
        }

        else if (data1->mes < data2->mes){
            diffDias += CalculaDiasAteMes(dataIntermed);

            for(dataIntermed->mes = data1->mes+1; dataIntermed->mes < data2->mes; dataIntermed->mes++){
                diffDias += NumeroDiasMes(dataIntermed);
            }

            diffDias += data2->dia;
        }

        else{
            diffDias = data2->dia - data1->dia;
        }
    }

    if(ComparaData(data1, data2) == 1){
        dataIntermed->dia = data2->dia;
        dataIntermed->mes = data2->mes;
        dataIntermed->ano = data2->ano;

        if(data2->ano < data1->ano){
            diffDias += CalculaDiasAteMes(dataIntermed);

            for(dataIntermed->mes = data2->mes+1; dataIntermed->mes <= 12; dataIntermed->mes++){
                diffDias += NumeroDiasMes(dataIntermed);
            }

            for(dataIntermed->ano = data2->ano+1; dataIntermed->ano < data1->ano; dataIntermed->ano++){
                diffDias += 365 + (VerificaBissexto(dataIntermed));
            }

            for(dataIntermed->mes = 1; dataIntermed->mes < data1->mes; dataIntermed->mes++){
                diffDias += NumeroDiasMes(dataIntermed);
            }

            diffDias += data1->dia;
        }

        else if (data2->mes < data1->mes){
            diffDias += CalculaDiasAteMes(dataIntermed);

            for(dataIntermed->mes = data2->mes+1; dataIntermed->mes < data1->mes; dataIntermed->mes++){
                diffDias += NumeroDiasMes(dataIntermed);
            }

            diffDias += data1->dia;
        }

        else{
            diffDias = data1->dia - data2->dia;
        }
    }

    LiberaData(dataIntermed);

    return abs(diffDias);
}
