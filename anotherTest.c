#include <stdio.h>

/*
    Calculation of the value of sine using Maclaurin series
    the formula goes by f(x) = f(0) + x f'(0) + x^2 f''(0) + ...
*/

// Function to calculate the factorial of a number
unsigned long calculateFactorial(int x)
{
    unsigned long factorial = 1;
    for (int i = 1; i <= x; i++)
    {
        factorial *= i;
    }
    return factorial;
}

int main(void)
{
    double input = 0.0;
    printf("Enter a value between 0 and 1 to get the sine of that value: \n");
    scanf("%lf", &input);

    // Check if the input is within the valid range
    if (input <= 0 || input >= 1) {
        printf("Invalid input. Please enter a value between 0 and 1.\n");
        return 1;
    }

    // Using Maclaurin series to calculate the value of sine
    double result = 0.0;
    int terms = 10;  // approximation up to 10 terms

    for (int i = 0; i < terms; i++)
    {
        int exponent = 2 * i + 1;
        double term = 1.0;

        // Calculate the power of the input
        for (int j = 0; j < exponent; j++)
        {
            term *= input;
        }

        // Divide by the factorial of the exponent
        term /= calculateFactorial(exponent);

        // Apply alternating sign
        if (i % 2 != 0)
        {
            term = -term;
        }

        result += term;
    }

    printf("The sine of the input value is approximately: %lf\n", result);
    return 0;
}
