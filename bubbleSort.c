#include <stdio.h> 

void swap (int *x, int *y) {
    int temp = *x; 
    *x = *y; 
    *y = temp; 
}

void bubbleSort (int size, int array[]) {
    int i,j;
    for ( i = 0; i < size; i++)
    {
        printf("%d",i);
       printf("  %d \n", array[i]); 
       for(j = i; j < size - 1; j ++){
        if(array[j] > array[j + 1]){
            swap( &array[j], &array[j + 1]);
        }
       }
    }
    
}
void printArray (int size, int array[]) { 
    int i; 
    for ( i = 0; i < size; i++)
    {   
       printf("%d ",array[i]); 
    }
    
}

int main(int argc, char const *argv[])
{
    int toSort[5] = {3,2,5,29,10}; 
    bubbleSort(5, toSort);

    printArray(5,toSort); 
    return 0;
}
