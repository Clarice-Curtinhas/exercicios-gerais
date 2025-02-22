#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int lerBaseDecimal();
int gerarNumOctal(int decimal);

int main(){
    int baseDecimal, baseOctal;

    baseDecimal = lerBaseDecimal();
    baseOctal = gerarNumOctal(baseDecimal);

    printf("%d", baseOctal);

    return 0;
}

int lerBaseDecimal(){
    int num;

    scanf("%d", &num);

    return num;
}

int gerarNumOctal(int decimal){
    int octal, qntAlga, repete;
    int algarismo, baseDez;

    octal = 0;
    algarismo = 0;
    baseDez = decimal;

    if(decimal < 8){
        octal = decimal;
    }

    else{
        while(baseDez > 7){
            octal += (baseDez%8)*pow(10, algarismo);
            baseDez = baseDez/8;
            algarismo++;
        }

        if(baseDez > 0){
            octal += baseDez*pow(10, algarismo);
        }
    }

    return octal;
}