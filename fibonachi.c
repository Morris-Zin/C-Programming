#include <stdio.h> 

/*
4th term

1 1 2 3 5 8 
*/

int fibo(int); 

int main(void)
{
    int n; 
    printf("Enter the nth term of fibo\n");
    scanf("%d", &n); 
    printf("%d\n",fibo(n));
    return 0;
}

int fibo(int n){ 
    if(n == 1 || n == 2){ 
        return 1; 
    }
    return (fibo(n-1) + fibo(n-2)); 
}