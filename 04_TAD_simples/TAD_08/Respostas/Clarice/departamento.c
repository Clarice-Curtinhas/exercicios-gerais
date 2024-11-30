#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STRING_MAX 101 // número máximo de caracteres por string

typedef struct Departamento {
    char nome [STRING_MAX];     // nome do departamento
    char c1[STRING_MAX], c2[STRING_MAX], c3[STRING_MAX];    // nomes dos cursos do departamento
    int m1, m2, m3;     // médias de notas dos cursos do departamento
    char diretor [STRING_MAX];    // nome do diretor do departamento
    float media_geral;
} tDepartamento;

tDepartamento criaDepartamento(char* c1, char* c2, char* c3, char* nome, int m1, int m2, int m3, char* diretor);
void imprimeAtributosDepartamento (tDepartamento depto);
int validaMediaDepartamento (int media);
double calculaDesvioPadraoDepartamento(tDepartamento depto);
double calculaMediaGeralDepartamento(tDepartamento depto);
void ordenaPorMediaDepartamentos(tDepartamento d[], int tamanho);

/**
 * @brief Cria um departamento a partir de valores nomes dos cursos, nome do departamento, média por curso e nome do diretor.
 * 
 * @param c1 Nome de um dos cursos do departamento.
 * @param c2 Nome de um dos cursos do departamento.
 * @param c3 Nome de um dos cursos do departamento.
 * @param nome Nome do departamento.
 * @param m1 Média do curso c1.
 * @param m2 Média do curso c2.
 * @param m3 Média do curso c3.
 * @param diretor Nome do diretor.
 * @return tDepartamento Departamento criado a partir dos valores nomes dos cursos, nome do departamento, média por curso e nome do diretor.
 */
tDepartamento criaDepartamento(char* c1, char* c2, char* c3, char* nome, int m1, int m2, int m3, char* diretor){
    tDepartamento depart;
    float media;
    int tam;

    depart.m1 = m1;
    depart.m2 = m2;
    depart.m3 = m3;

    for(tam = 0; c1[tam] != '\0'; tam++){
        depart.c1[tam] = c1[tam];
    }

    depart.c1[tam] = '\0';

    for(tam = 0; c2[tam] != '\0'; tam++){
        depart.c2[tam] = c2[tam];
    }
    
    depart.c2[tam] = '\0';

    for(tam = 0; c3[tam] != '\0'; tam++){
        depart.c3[tam] = c3[tam];
    }
    
    depart.c3[tam] = '\0';

    for(tam = 0; nome[tam] != '\0'; tam++){
        depart.nome[tam] = nome[tam];
    }
    
    depart.nome[tam] = '\0';

    for(tam = 0; diretor[tam] != '\0'; tam++){
        depart.diretor[tam] = diretor[tam];
    }
    
    depart.diretor[tam] = '\0';

    depart.media_geral = (float) calculaMediaGeralDepartamento(depart);

    return depart;
}

/**
 * @brief Imprime os atributos do departamento, sendo eles: cursos, nome do departamento, média por curso e nome do diretor.
 * 
 * @param depto Departamento cujos atributos serão impressos.
 */
void imprimeAtributosDepartamento (tDepartamento depto){
    printf("ATRIBUTOS:\n");
    printf("departamento => %s\n", depto.nome);
    printf("diretor => %s\n", depto.diretor);
    printf("curso1 => %s, media1 => %d\n", depto.c1, depto.m1);
    printf("curso2 => %s, media2 => %d\n", depto.c2, depto.m2);
    printf("curso3 => %s, media3 => %d\n", depto.c3, depto.m3);
    printf("media geral => %.2f\n", depto.media_geral);
    printf("desvio padrao => %.2f\n\n", calculaDesvioPadraoDepartamento(depto));
}

/**
 * @brief Verifica se a media inserida é valida, ou seja, pertence à [0, 10].
 * 
 * @param media Valor a ser validado.
 * @return int Se é válida (1) ou não (0).
 */
int validaMediaDepartamento (int media){
    if (media >= 0 && media <= 10) return 1;

    else return 0;
}

/**
 * @brief Calcula o Desvio Padrão das médias por curso de um departamento.
 * 
 * @param depto Departamento cujo Desvio Padrão de médias por curso deve ser calculado.
 * @return double Valor do cálculo do Desvio Padrão.
 */
double calculaDesvioPadraoDepartamento(tDepartamento depto){
    double desvio = 0;
    float somatorio = 0;

    somatorio += pow((depto.m1 - depto.media_geral), 2);
    somatorio += pow((depto.m2 - depto.media_geral), 2);
    somatorio += pow((depto.m3 - depto.media_geral), 2);

    desvio = sqrt(somatorio/3);

    return desvio;
}

/**
 * @brief Calcula a média simples das notas dos cursos do departamento.
 * 
 * @param depto Departamento cuja media simples deve ser calculada.
 * @return double Valor do calculo da média simples.
 */
double calculaMediaGeralDepartamento(tDepartamento depto){
    double media;
    float m1, m2, m3;

    m1 = depto.m1;
    m2 = depto.m2;
    m3 = depto.m3;

    media = (m1 + m2 + m3) /3;

    return media;
}

/**
 * @brief Ordena o vetor de departamentos em ordem decrescente de acordo com as médias dos departamentos.
 * 
 * @param d Vetor de departamentos a ser ordenado.
 * @param tamanho Tamanho do vetor a ser ordenado.
 */
void ordenaPorMediaDepartamentos(tDepartamento d[], int tamanho){
    int maior, pode;
    float maiorMedia;
    int ordenados[tamanho];
    tDepartamento deptoOrd[tamanho];

    for(int j = 0; j < tamanho; j++){
        maior = 0;
        maiorMedia = 0;
        pode = 1;

        for(int i = 0; i < tamanho; i++){

            for(int k = 0; k < j; k++){
                if(i != ordenados[k]) pode = 1;

                else{
                    pode = 0;
                    break;
                }
            }
                
            if(validaMediaDepartamento(d[i].media_geral) && d[i].media_geral > maiorMedia && pode == 1){
                maiorMedia = d[i].media_geral;
                maior = i;
            }
        }

        ordenados[j] = maior;
        deptoOrd[j] = d[maior];
    }

    for(int j = 0; j < tamanho; j++){
        d[j] = deptoOrd[j];
    }
}
