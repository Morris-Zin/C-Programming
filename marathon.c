#include <stdio.h> 
#define CONST 1.60934

int main(void) {
    double miles = 0, yards = 0; 
    printf("Enter the miles \n"); 
    scanf("%lf", &miles);
    printf("Enter the yards \n"); 
    scanf("%lf", &yards); 
    double kilometers = CONST * ( miles + (yards/ 1760.0)); 
    printf("\n The Kilometers is %lf \n", kilometers); 
    return 0; 
}