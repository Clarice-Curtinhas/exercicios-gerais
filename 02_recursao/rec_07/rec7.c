#include <stdio.h>
#include <stdlib.h>

int somaDigitos(int n);

int main(){
    int N;

    scanf("%d", &N);

    printf("%d", somaDigitos(N));
}

int somaDigitos(int n){
    if(n == 0) return 0;

    else return n%10 + somaDigitos(n/10);
}