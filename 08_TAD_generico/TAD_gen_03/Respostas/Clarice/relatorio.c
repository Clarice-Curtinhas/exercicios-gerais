#include "vector.h"
#include "aluno.h"

/**
 * @brief Imprime o relatorio de uma coleção de alunos.
 * O relatorio deve possuir a media das notas, porcentagem de alunos aprovados e porcentagem de cada gênero.
 * 
 * @param alunos Ponteiro para o vetor de alunos.
*/
void ImprimeRelatorio(Vector *alunos){
    float mediaGeral = 0, porcentAprov = 0, nota;
    float porcentMasc = 0, porcentFemi = 0, porcentOutro = 0;
    int tam = VectorSize(alunos);

    for(int i = 0; i < tam; i++){
        nota = GetNotaAluno(VectorGet(alunos, i));

        if(GetGeneroAluno(VectorGet(alunos, i)) == 'F'){
            porcentFemi++;
            if(nota >= 6) porcentAprov++;
        }

        else if(GetGeneroAluno(VectorGet(alunos, i)) == 'M'){
            porcentMasc++;
            if(nota >= 6) porcentAprov++;
        }

        else{
            porcentOutro++;
            if(nota >= 6) porcentAprov++;
        }

        mediaGeral += nota;
    }

    mediaGeral = mediaGeral/tam;

    porcentFemi = (porcentFemi*100)/tam;
    porcentMasc = (porcentMasc*100)/tam;
    porcentOutro = (porcentOutro*100)/tam;

    porcentAprov = (porcentAprov*100)/tam;

    printf("Media das notas: %.2f\n", mediaGeral);
    printf("Porcentagem de alunos aprovados: %.2f%%\n", porcentAprov);
    printf("Porcentagem de cada genero:\n");
    printf("Masculino: %.2f%%\n", porcentMasc);
    printf("Feminino: %.2f%%\n", porcentFemi);
    printf("Outro: %.2f%%\n", porcentOutro);
}

