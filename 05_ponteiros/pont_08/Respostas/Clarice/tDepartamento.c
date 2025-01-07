#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_MAX 50

typedef struct departamento {
    char curso1[STRING_MAX];
    char curso2[STRING_MAX];
    char curso3[STRING_MAX];
    char diretor[STRING_MAX];
    char nome[STRING_MAX];
    int m1, m2, m3;
} tDepartamento;

/**
 * @brief Cria um departamento com os dados passados via parâmetro
 *
 *
 * @param *curso1 Ponteiro para string que contém o nome do primeiro curso do departamento
 * @param *curso2 Ponteiro para string que contém o nome do segundo curso do departamento
 * @param *curso3 Ponteiro para string que contém o nome do terceiro curso do departamento
 * @param *nome Ponteiro para string que contém o nome do departamento
 * @param m1 Nota do primeiro curso (curso1)
 * @param m2 Nota do segundo curso (curso2)
 * @param m3 Nota do terceiro curso (curso3)
 * @param *diretor Ponteiro para string que contém o nome do diretor/chefe do departamento
 */
tDepartamento CriaDepartamento( char *curso1, char *curso2, char *curso3, char *nome, int m1, int m2, int m3, char *diretor ){
    tDepartamento depto;

    strcpy(depto.nome, nome);
    strcpy(depto.diretor, diretor);

    strcpy(depto.curso1, curso1);
    strcpy(depto.curso2, curso2);
    strcpy(depto.curso3, curso3);

    depto.m1 = m1;
    depto.m2 = m2;
    depto.m3 = m3;

    return depto;
}

/**
 * @brief Imprime os atributos de um departamento em tela
 *
 * @param depto - Um departamento que terá seus dados impressos em tela
 */

void ImprimeAtributosDepartamento(tDepartamento depto){
    float media;

    media = ((float)depto.m1 + (float)depto.m2 + (float)depto.m3)/3;

    printf("\nDepartamento: %s\n", depto.nome);
    printf("	Diretor: %s\n", depto.diretor);

    printf("	1o curso: %s\n", depto.curso1);
    printf("	Media do 1o curso: %d\n", depto.m1);

    printf("	2o curso: %s\n", depto.curso2);
    printf("	Media do 2o curso: %d\n", depto.m2);

    printf("	3o curso: %s\n", depto.curso3);
    printf("	Media do 3o curso: %d\n", depto.m3);

    printf("	Media dos cursos: %.2f", media);
}

/**
 * @brief Ordena os departamentos de acordo com as médias das notas de cada um dos seus três cursos (da maior para a menor).
 *
 * @param *vetor_deptos - Ponteiro para um vetor de departamentos
 * @param num_deptos - O número de departamentos contidos no vetor_deptos
 */
void OrdenaDepartamentosPorMedia(tDepartamento *vetor_deptos, int num_deptos){
    tDepartamento vetorOrde[num_deptos];
    float medias[num_deptos], mediasOrde[num_deptos];
    int idOrdenado[num_deptos];
    int z, i, ordenada = 0;

    for(i = 0; i < num_deptos; i++){
        medias[i] = ((float)vetor_deptos[i].m1 + (float)vetor_deptos[i].m2 + (float)vetor_deptos[i].m3)/3;
    }

    for(i = 0; i < num_deptos; i++){
        if(i == 0){
            mediasOrde[i] = medias[i];
            idOrdenado[i] = i;
        }

        else{
            for(int j = 0; j < i; j++){
                if(mediasOrde[j] < medias[i]){
                    for(z = i+1; z > j; z--){
                        mediasOrde[z] = mediasOrde[z-1];
                        idOrdenado[z] = idOrdenado[z-1];
                    }

                    mediasOrde[z] = medias[i];
                    idOrdenado[z] = i;
                    ordenada = 1;
                    break;
                }
            }

            if(ordenada == 0){
                mediasOrde[i] = medias[i];
                idOrdenado[i] = i;
            }

            ordenada = 0;
        }
    }

    for(i = 0; i < num_deptos; i++){
        vetorOrde[i] = CriaDepartamento(vetor_deptos[idOrdenado[i]].curso1, vetor_deptos[idOrdenado[i]].curso2, vetor_deptos[idOrdenado[i]].curso3, vetor_deptos[idOrdenado[i]].nome, vetor_deptos[idOrdenado[i]].m1, vetor_deptos[idOrdenado[i]].m2, vetor_deptos[idOrdenado[i]].m3, vetor_deptos[idOrdenado[i]].diretor);
    }

    for(z = 0; z < num_deptos; z++){
        vetor_deptos[z] = CriaDepartamento(vetorOrde[z].curso1, vetorOrde[z].curso2, vetorOrde[z].curso3, vetorOrde[z].nome, vetorOrde[z].m1, vetorOrde[z].m2, vetorOrde[z].m3, vetorOrde[z].diretor);
    }
}
