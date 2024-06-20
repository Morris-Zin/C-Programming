#include <stdio.h>
#include <stdlib.h>

typedef struct node { 
    int d; 
    struct node *left;
    struct node *right;
} node; 

typedef struct node *BTree; 

void inOrder (BTree root) { 
    if(root != NULL ) { 
        inOrder(root -> left); 
        printf("%3d", root -> d); 
        inOrder(root -> right);
    }
}

BTree newNode(void) { 
    return malloc(sizeof(node));
}

BTree initializeTree (int d, BTree left, BTree right) { 
    BTree n = newNode();
    n -> d = d; 
    n -> left = left;
    n -> right = right;
    return n; 
}

BTree createTree (int d[], int i, int size){ 
    if(i>=size) return  NULL; 
    else return (initializeTree(d[i], createTree(d, 2*i +1 , size), createTree(d, 2*i+2, size)));
}

int main(void)
{
    int d[] = {3,2,1,4,5,9}; 
    BTree b; 
    b = createTree(d, 0, 6);
    inOrder(b); 
    
    return 0;
}
