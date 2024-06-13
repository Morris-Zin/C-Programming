#include <stdio.h>


int main()
{
    FILE *file;
    int i, sum = 0;
    double average;
    int weightData[1000]; // Array to store weight data

    file = fopen("data.txt", "r"); // Open the dataset file
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }
    for (i = 0; i < 1000; i++)
    {
        fscanf(file, "%d", &weightData[i]); // Read and assign each individual weight
    }

    fclose(file); // Close the file to free memory

    for (i = 0; i < 1000; i++)
    {
        sum += weightData[i]; // Calculate the sum of weights
    }

    average = (double)sum / 1000.0; // Compute the average (using double division)

    printf("Average weight of 1000 elephant seals is %.2lf\n", average);

    return 0;
}