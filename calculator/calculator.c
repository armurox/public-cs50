#include <stdio.h>
#include <cs50.h>

int main(void){
    long x = get_int("What is x? ");
    long y = get_int("What is y ");
    double n = (double) x / (double) y;

    printf("X divided by Y is equal to %0.20f\n", n);
}