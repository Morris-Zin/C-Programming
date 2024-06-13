#include <stdio.h> 

int main (void) { 

    int i; 
    double x; 
    double avg = 0.0; 
    double sum = 0.0; 
    double navg; 
    printf("%5s%17s%17s%17s\n%5s%17s%17s%17s\n\n", "Count", "Item", "Average", "Naive average", "___+", "___", "___", "___");

    for (i = 1; scanf("%lf", &x) == 1; i++)
    {
        avg = avg + (x-avg) /i; 
        sum += x; 
        navg = sum/i; 
        printf("%5d%17e%17e%17e\n", i,x,avg,sum); 
        /* code */
    }
    return 0;
}