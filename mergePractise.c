#include <stdio.h>

void merge (int pileA[], int pileB[], int merge[], int size) { 
    int i = 0, j =0,k=0; 
    while((i < size) && (j < size)) {
        if(pileA[i] < pileB[j]) {
            merge[k ++] = pileA[i ++];
        } else {
            merge[k++] = pileB[j++];
        }
    }
    while (i < size) { 
        merge[k++] = pileA[i++];
    }
    while(j < size) {
        merge[k++] = pileB[j++];
    }
}

void mergeSort(int size, int toSort[]) { 
        int k,j;

    int w[size];

    for ( k = 1; k < size; k *=2)
    {
        for ( j = 0; j < size - k; j += 2 * k)
        {
            merge(toSort + j, toSort + j + k, w + j,  k); 
        }
        for ( j = 0; j < size; j++)
        {
            toSort[j] = w[j]; 
        }
    }
}


void printArray (int x, int arr[]) { 
    int i;
    for ( i = 0; i < x; i++)
    {
      printf("%d\t ", arr[i]);
    }
}
int main(int argc, char const *argv[])
{
    const int SIZE = 4; 
    const int M = SIZE * 2;

    int pileA[] = {1,2,3,4}; 
    int pileB[] = {5,6,7,8}; 
    int sortedArray[M]; 

    int toSort[] = {4, 5, 8, 9, 10, 3, 19, 16};

    mergeSort(8, toSort);
    printArray(8, toSort);

    return 0;
}
