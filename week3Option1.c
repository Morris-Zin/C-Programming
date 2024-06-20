#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef struct list
{
    int data;
    struct list *next;
} list;
//creating a node
list *createNode(int d)
{
    list *node = malloc(sizeof(list));
    node->data = d;
    node->next = NULL;
    return node;
}
// add to the front of the list
list *addFront(list *head, int data)
{
    //head = NULL handles the edge case
    if (head == NULL)
    {
        return head = createNode(data);
    }

    list *newNode = createNode(data);
    newNode->next = head;
    return newNode;
}
// randomly generate integers between 0 to 200; 
list *generateIntegers(list *head)
{
    srand(time(NULL));
    for (int i = 0; i < 100; i++)
    {
        int d = rand() % 200;
        head = addFront(head, d);
    }
    return head;
}
//swap two nodes ,just their data
void swapNodes (list *a, list *b) { 
    list *t = malloc(sizeof(list));
    t->data = a -> data; 

    a -> data = b -> data; 
    b -> data = t -> data; 

}

//print the linked list
void printLists(list *head)
{
    int i = 1;
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
        if (i % 20 == 0)
        {
            printf("\n\n");
        }
        i++;
    }
}

list *sorting(list *head)
{
    list *ptr = head; 

    // setting 10000 to make sure that everything is sorted
    for (int i = 0; i < 10000; i++)
    {
        //handles when the ptr reaches the end of the list
        if(ptr == NULL || ptr -> next == NULL) { 
            ptr = head;
        }

        if( (ptr -> next -> data) < (ptr-> data)) { 
            swapNodes(ptr, ptr -> next);
        } 
     
        ptr = ptr -> next; 
    }
    
   return head; 
}
int main(void)
{
    list *head = NULL;
    // head = generateIntegers(head);
    head = generateIntegers(head); 

    printLists(head);
    printf("\n################################\n");
    printf("After Sorting \n");
    printf("\n################################\n");
    head = sorting(head);
    printLists(head);
    return 0;
}
