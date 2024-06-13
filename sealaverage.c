#include <stdio.h> 
#include <stdlib.h>

void printArray(int size, int array[]) {
    int i; 
    for ( i = 0; i < size; i++)
    {
        printf("%d\t ", array[i]);
    }
    
}

void putDataIntoArray(int array[], int size) { 
    //a pointer to point at the file;
    FILE *file = fopen("./data.txt", "r"); 
    int i = 0;
    //content to store the 7 lenght of the read data
    char content[7]; 
    while(fgets(content, 7, file) != NULL){ 
        //atoi converts the string to int
        array[i ++] = atoi(content);
    };
    //dimissing the pointer
    fclose(file); 
}

double calculateAverage(int array[], int size) {  
    int i; long double sum = 0; 
    for ( i = 0; i < size; i++)
    {
        sum += array[i]; 
    }
    return (sum / size); 
}
int main()
{
   const long int SIZE = 1000;
    int sealData[SIZE]; 
    putDataIntoArray(sealData, SIZE);
    double average = calculateAverage(sealData, SIZE);
    printf("%lf average \t ", average); 
    return 0;
}
