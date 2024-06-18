#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int number; 
    struct list *next;
} list; 

int isEmpty (const list *list) { 
    return (list == NULL); 
}

void printList(list *list, char *string) { 
    printf("%s\n", string);

    if(list == NULL) return; 
    else { 
        printf("%d ", list->number);
        printList(list ->next, ":");
    }

}

int main(void)
{
    list liseOfInts; 
    list *head = NULL; 
    head = malloc(sizeof(list));
    head -> number = 8; 
    head -> next = NULL; 
    printf("Single Linked List\n"); 
    printList(head, "Printed the single linekd List\n"); 
    return 0;
}
