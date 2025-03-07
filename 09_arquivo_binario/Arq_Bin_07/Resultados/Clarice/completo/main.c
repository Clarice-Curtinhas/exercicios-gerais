#include <stdio.h>
#include <stdlib.h>

#include "aluno.h"
#include "professor.h"
#include "database.h"
#include "vector.h"

int main(){
    int save, carrega;
    char string[100];
    FILE *file;
    tDatabase *d;

    d = CriaDatabase();
    LeDatabase(d);

    scanf("%s", string);

    file = fopen(string, "wb");

    save = SalvarDatabase(d, file);

    fclose(file);

    printf("Numero de bytes salvos: %d\n", save);

    DestroiDatabase(d);
    d = CriaDatabase();

    file = fopen(string, "rb");

    carrega = CarregaDatabase(d, file);

    fclose(file);

    printf("Numero de bytes lidos: %d\n\n", carrega);

    OrdenaDatabase(d);
    ImprimeDatabase(d);

    DestroiDatabase(d);

    return 0;
}