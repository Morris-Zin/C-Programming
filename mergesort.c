#include <stdio.h> 

void printArray (int size, int array[], char *Str) { 
    int i; 
    printf("%s\n", Str);
    for (i = 0; i < size; i++)
    {
        printf("%d\t", array[i]);
    }
    printf("\n");
}

void merge (int pileA[], int pileB[], int mergedArr[], int sizeA, int sizeB) {
    int i =0,j = 0,k=0; 
    while((i < sizeA) && (j < sizeB)) {
        if(pileA[i] < pileB[j]){
            mergedArr[k ++] = pileA[i ++];
        } else {
            mergedArr[k ++] = pileB[j++]; 
        }
    }
    while(i < sizeA){
        mergedArr[k ++] = pileA[i++];
    }
    while(j < sizeB){
        mergedArr[k++] = pileB[j++]; 
    }
}

void mergeSort(int key[], int howMany) {// a power of 2
    int j,k;
    int w[howMany]; 
    for(k=1; k < howMany; k *=2) {
        for ( j = 0; j < howMany - k; j += 2*k)
        {
            merge(key +j, key + j +k, w+j, k,k);
        }
        for ( j = 0; j < howMany; j++)
        {
            key[j] = w[j];
        }
        
    }
}


int main(void)
{
    const int SIZE = 4; 
    int pileA[SIZE] = {1,2,3,4}; 
    int pileB[SIZE] = {5,6,7,8}; 
    int mergedArr[2 * SIZE] ;

    merge(pileA, pileB, mergedArr, SIZE, SIZE);
    printArray(2 * SIZE, mergedArr, "Sorted Array"); 
    return 0;
}
