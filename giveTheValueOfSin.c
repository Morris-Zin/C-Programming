#include <stdio.h>
/*
    Calculation of the value of sine using Maclaurin series
    the formula goes by f(x) = f(0) + x f'(0) + x^2 f''(0) + ...
*/
// Function to calcualte the factoiral of a number
unsigned long calculateFactoiral(int x)
{
    double factorial = 1;
    for (int i = 1; i <= x; i++)
    {
        factorial *= i;
    }
    return factorial;
}

int main(void)
{
    double input = 0.0;
    printf("Enter the value between 0 and 1 to get the sine of that value. \n");
    scanf("%lf", &input);
    // I am using Maclaurin series to calculate the value of sine here
    double result = 0.0;
    // approximation up to 10 places
    int counter = 1;
    for (int i = 0; i < 10; i++)
    {
        double term = input;
        if (i != 0)
        {
            term = 1;
            counter += 2;
            for (int j = 0; j < counter; j++)
            {
                term *= input;
            }
            term = term / calculateFactoiral(counter);
        }
        // to get the minus sign here
        if (i % 2 != 0)
        {
            term = -term;
        }
        result += term;
    }
    printf("The value of sin of the input value: %lf\n", result);
    return 0;
}