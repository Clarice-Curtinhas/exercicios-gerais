#include <stdio.h>
#include <stdlib.h>

#include "vector.h"
#include "aluno.h"
#include "relatorio.h"

int main(){
    int i, tam;

    Vector *v;

    v = VectorConstruct();

    scanf("%d\n", &tam);

    for(i = 0; i < tam; i++){
        tAluno *a;
        
        a = CriaAluno();
        LeAluno(a);

        VectorPushBack(v, a);
    }

    ImprimeRelatorio(v);

    VectorDestroy(v, DestroiAluno);

    return 0;
}