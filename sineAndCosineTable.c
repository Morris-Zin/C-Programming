#include <stdio.h> 
#include <math.h> 
/* 
    a C program that has a function that prints a table of values for sine and cosine between (0, 1)
*/
int main(void) { 
    printf("Sine Values                                   Cosine Values\n");
        double i; 
    for (i = 0.0; i < 1; i = i + 0.1)
    {
        printf("sin(%lf)  -   (%lf)              consin(%lf)  -  (%lf)\n", i,sin(i),i,cos(i));
    }
    
    return (0); //
}