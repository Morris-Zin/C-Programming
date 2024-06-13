#include <stdio.h> 

int factorial(int); 

int main (void) { 

    printf ("%d\n", factorial(10));
    return 0; 
}

int factorial(int x) { 
    static int fact = 1; 
    if(x == 1) {
        return fact; 
    } else {
        fact *= x; 
        x--; 
        return factorial(x);
    }
}
//better version 
/*
long int factorial(int x) { 
  
    if(x == 1) {
        return x; 
    } else {
        return (factorial(x - 1) * x);
    }
}
*/