#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Use the linear linked list code to store a randomly generated set of 100 integers.  Now write a routine that will rearrange the list in sorted order of these values. Note you might want to use bubble sort to do this. Print these values in rows of 5 on the screen.

How will this work? Compare two adjacent list elements and if they are out of order swap them. After a first pass the largest element will have bubbled to the end of the list. Each pass can look at one less element as the end of a list stays sorted.
*/

//Define the list Abstract Data Type (ADT)
struct list{ int data; struct list *next;};

typedef struct list list;

//Initializes a list with an element d
list* create_list(int d)
{
	list *head = malloc(sizeof(list));
	head-> data = d;
	head-> next = NULL;
	return head;
}

//Appends an element to the list
list* add_to_front(int d, list *p)
{
	list *new_head = create_list(d);
	new_head-> next = p;
	return new_head;
}

//Takes in an array of ints and returns a linked list made from those ints
list* create_list_from_array(int ints[], int size)
{
	int i;
	list *head = create_list(ints[0]);

	for (i = 1; i < size; i++)
	{
		head = add_to_front(ints[i], head);
	}

	return head;
}

//prints the linked list, 5 in one line
void print_list(list *head)
{
	int count = 0;

	while (head != NULL)
	{
		printf("%05d ", head-> data);
		head = head-> next;
		count = count + 1;
		if (count % 5 == 0)
			printf("\n");
	}

	printf("\n\n");
}

//Takes an array and populates it with 'size'(amount) random integers
void populate_array(int *p, int size)
{
	int i;
	
	for (i = 0; i < size; i++)
	{
		p[i] = rand();
	}
}

// Takes in the list element being looked at (current), the list element before it (prev), and the list element after it (after)
// swaps the current and after elements, making sure to update the reference of the prev element.
void swap(list *prev, list *current, list *after)
{

	list *temp = after -> next;
	after -> next = current;
	current -> next = temp;
	if (prev != NULL)
		prev -> next = after;
}

//implements the bubble sort algorithm for linked lists.
//Looks at the current head and next element, checks if it needs to be swapped, swaps if needed, or moves on if not
list* bubble_sort(list *h, int length)
{
	int i;
	int j;
	//This new_head just keeps track of the head of the list in case we swap the first 2 elements in the list
	list *new_head = h;

	list *current_head = new_head;
	list *next_head = current_head -> next;
	list *prev_head = NULL;

	//we make n (n = length of list) passes through the linked list, looking at one less element each time
	for (j = length; j > -1; j--)
	{
		i = 0;

		//updates the pointers for the next pass through the list
		current_head = new_head;
		next_head = current_head-> next;
		prev_head = NULL;

		//loop runs through the list looking at each element and swapping if needed. Stops when we reach the end,
		//or when we've looked at j elements
		while (next_head != NULL)
		{
			//this condition executes when the current and next element are out of sorting order
			if ((current_head-> data) > (next_head-> data))
			{	
				if (i == 0)
					//one time condition to update the head of the list if we are swapping the first two elements
					new_head = next_head;
				swap(prev_head, current_head, next_head);

				//update references after swapping
				prev_head = next_head;
				next_head = current_head -> next;
			}
			//this executes if current and next elements are in order already
			else
			{
				//updates references for next iteration of while loop
				prev_head = current_head;
				current_head = next_head;
				next_head = next_head-> next;
			}
			i = i + 1;
			//stop if we've looked at j elements
			if (i == j)
				break;
		}
	}
	
	return new_head;

}

int main(void)
{
	//make sure we get random integers on every call of this program
	srand(time(NULL));
	list *head;
	
	//make an array of size 100 with random integers
	int *integers = malloc(100 * sizeof(int));
	populate_array(integers, 100);

	//create a linked list from this array
	head = create_list_from_array(integers, 100);
	printf("Before Sorting: \n\n");
	print_list(head);

	//sort the list, and get its new head
	head = bubble_sort(head, 100);
	printf("After Sorting: \n\n");
	print_list(head);
	return 0;
}




