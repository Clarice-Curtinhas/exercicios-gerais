#include "temperature_conversor.h"

#include <stdio.h>
#include <stdlib.h>

int main(){
    float temperatura;
    char escalaAtual, escalaDesejada;

    scanf("%f %c %c", &temperatura, &escalaAtual, &escalaDesejada);

    if(escalaAtual == 'c'){
        if(escalaDesejada == 'k'){
            printf("Temperature: %.2fK", convert_temperature(temperatura, convert_celsius_to_kelvin));
        }

        else{
            printf("Temperature: %.2fFº", convert_temperature(temperatura, convert_celsius_to_fahrenheit));
        }
    }

    else if(escalaAtual == 'f'){
        if(escalaDesejada == 'c'){
            printf("Temperature: %.2fCº", convert_temperature(temperatura, convert_fahrenheit_to_celsius));
        }

        else{
            printf("Temperature: %.2fK",convert_temperature(temperatura, convert_fahrenheit_to_kelvin));
        }
    }

    else{
        if(escalaDesejada == 'c'){
            printf("Temperature: %.2fCº", convert_temperature(temperatura, convert_kelvin_to_celsius));
        }

        else{
            printf("Temperature: %.2fFº", convert_temperature(temperatura, convert_kelvin_to_fahrenheit));
        }
    }

    return 0;
}