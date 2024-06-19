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
    printf("%s", string);
    if(list == NULL) return; 
    else { 
        printf("%d ", list->number);
        printList(list ->next, ":");
    }

}

list* createList(int d) { 
    list *newList = malloc(sizeof(list)); 
    newList -> number = d; 
    newList -> next = NULL;
    return newList; 
}


list* addToTheFront(int d, list *l)  {
     list *head =  createList(d);
     head -> next = l; 
     return head; 
}
 
list* arrayToList (int array[], int size){ 
    list *head = createList(array[0]); 
    for(int i = 1; i < size; i ++) { 
        head = addToTheFront(array[i], head); 
    }
    return head; 
}

void addAtTheEnd (int d, list *head)  {
    list *temporary = createList(d); 
    list *ptr; 
    ptr = head; 
    while(ptr -> next != NULL) { 
        ptr = ptr -> next; 
    }
    ptr -> next = temporary; 
}

int main(void)
{
    int data[8] = {1,2,3,4,5,6,7,8}; 
    list *head = arrayToList(data, 8); 
    addAtTheEnd(132, head); 
    printf("Linked List\n"); 
    printList(head, "Printed the single linekd List "); 
    return 0;
}
