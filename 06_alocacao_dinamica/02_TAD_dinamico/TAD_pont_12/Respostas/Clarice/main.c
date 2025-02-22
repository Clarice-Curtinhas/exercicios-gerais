#include <stdio.h>
#include <stdlib.h>

#include "array.h"

int main(){
    int ondeEsta, numero;
    Array *array;

    array = CriarArray();

    LerArray(array);
    OrdenarArray(array);
    scanf("%d\n", &numero);

    ondeEsta = BuscaBinariaArray(array, numero);

    if(ondeEsta != -1) printf("Elemento %d encontrado no índice %d.\n", numero, ondeEsta);
    else printf("Elemento %d não encontrado no array (%d).\n", numero, ondeEsta);

    DestruirArray(array);

    return 0;
}