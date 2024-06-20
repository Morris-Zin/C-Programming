#include <stdio.h>
#include <stdlib.h>

void printArray(int array[], int size) { 
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

double calculateAverage(int* array, int size) { 
    double sum = 0.0; 
    for (int i = 0; i < size; i++) {   
        sum += array[i]; 
    }
    return sum / size; 
}   

int* fileToArray(FILE *file, int *size) { 
    int i = 0; 
    fscanf(file, "%d", size); // Read the size of the array

    int *array = malloc((*size) * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    while (i < *size && fscanf(file, "%d", &array[i]) != EOF) { 
        i++;
    }

    // Reset file pointer to beginning for subsequent operations
    fseek(file, 0, SEEK_SET);

    return array; 
}

void writeToTheFile(FILE *toWrite, double average, int max) { 
    fprintf(toWrite, "Average: %.2f\n", average); 
     fprintf(toWrite, "Max: %d\n", max); 

}

int main(int argc, char const *argv[]) {
    FILE *file = fopen("./integers.txt", "r");
    if (file == NULL) {
        printf("Error: Couldn't open file\n");
        exit(1);
    }

    int size;
    int *array = fileToArray(file, &size);
    fclose(file); // Close the file after reading

    printf("Array contents: ");
    printArray(array, size);
    int max = -99; 
    for (int i = 0; i < size; i++)
    {
       if(array[i] > max) { 
        max = array[i]; 
       }
    }
    
    FILE *toWrite = fopen("answer-hw3.txt", "w");
    if (toWrite == NULL) {
        printf("Error: Couldn't write to file\n");
        exit(1); 
    }

    double average = calculateAverage(array, size); 
    writeToTheFile(toWrite, average, max);

    fclose(toWrite); // Close the file after writing
    free(array); // Free dynamically allocated memory

    return 0;
}