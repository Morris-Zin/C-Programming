#include <stdio.h> 

void swap (int *a, int *b);

int main(int argc, char const *argv[])
{
    int a = 3, b = 5; 
    swap(&a, &b);
    printf("swapping a = 3 becomes a = %d, b = %d\n", a, b); 
    return 0;
}

void swap (int *a, int *b){ 
    int temporary = *a; 
    *a = *b; 
    *b = temporary; 
}