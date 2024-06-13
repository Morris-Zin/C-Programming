#include <stdio.h> 

#define MAX_length 1000 
#define FULL (MAX_length-1)
#define EMPTY -1

typedef struct stack {
    int top; 
    char c[MAX_length]; 
}  stack; 

void push (char c, stack *item) { 
    item -> top ++; 
    item -> c[item -> top] = c;
}

char pop (stack *item) { 
    return item -> c[item -> top--]; 
}

int isEmpty (const stack *item) {
    return item -> top == EMPTY;
}

int main()
{
    int i = 0; 
    int j = 0; 
    int k = 0;
    stack stack;
    char *string = "Hello, world!";
    printf("%s\n", string);
    char reversed[14]; 

    while(string[i] != '\0') {
        push(string[i], &stack); 
        i++; 
    }
    while(!isEmpty(&stack)) {
        reversed[j] = pop(&stack); 
        j++;
    }

    for (; k < 14; k++)
    {
        printf("%c ", reversed[k]);
    }
    return 0;
}
