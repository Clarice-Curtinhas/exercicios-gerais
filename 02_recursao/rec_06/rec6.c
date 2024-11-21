#include <stdio.h>
#include <stdlib.h>

int num1;
int num2;
int numFibonacci;

int fibonacci(int n);

int main(){
    int N;

    scanf("%d", &N);

    num1 = 0;
    num2 = 1;

    printf("%d\n", fibonacci(N));
}

int fibonacci(int n){
    if(n == 0) return 0;
    else if(n == 1) return 1;

    else{
        fibonacci(n-1);

        numFibonacci = num1 + num2;
        num1 = num2;
        num2 = numFibonacci;

        return numFibonacci;
    }
}