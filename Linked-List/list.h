#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "node.h"

/*  – Beräkna storleken på en lista och returnera denna
    Pre: If listsize < 1. Function will return NULL. 
    Post: Function return number of elements in Linked list. */
int countListSize(struct node *head);

/*  - Bestämma huruvida en lista är tom eller inte och returnera resultatet 
    Post: If list is empy, function will return 1. Else 0. */
int checkIfListIsEmpty(struct node *head);

/*  - Returnera elementet på en viss plats i en lista 
    Pre: 1 <= index <= listsize
    Post: return node at index in Linked list.
    Source: https://kauplay.kau.se/media/t/0_edvxe1ug */
static node * getNode(node *head, int index);

/* – Bestämma huruvida ett element finns i listan eller inte och returnera resultatet 
    Pre: 1 <= key <= listsize. 
    Post: return 1 if element is found in list. Else return 0. 
    Source: https://www.log2base2.com/data-structures/linked-list/deleting-a-node-in-linked-list.html */
int checkForElementInList(struct node **head, int key);

/* - Returnera platsen för första förekomst av ett visst element i en lista
    Källa: https://www.log2base2.com/data-structures/linked-list/deleting-a-node-in-linked-list.html */
int returnPosition(struct node **head, int key);



/* – Lägga till ett element på en viss plats i en lista
    Pre: 0 < index <= listsize. 
    Post: adds node to Linked list at given index. */
void addNodeAtIndex(struct node **head, int value, int index);

/* – Ta bort elementet på en viss plats i en lista
    Pre: *head != NULL
    Post: delete node from linked list at index. 
    Source: https://www.geeksforgeeks.org/delete-a-linked-list-node-at-a-given-position/ */
void deleteNodeAtIndex(struct node **head, int index);

/* Pre: listsize >= 2
   Post: Swaps node a with b. Help function for the bubblesort function. 
   Source: https://www.geeksforgeeks.org/c-program-bubble-sort-linked-list/ */
void swap(struct node *a, struct node *b);

/* – Sortera elementen i en lista (lägst först)
    Pre: list is not empty. 
    Post: After function is done, the Linked list will sorted from low -> high 
    Source: https://www.geeksforgeeks.org/c-program-bubble-sort-linked-list/ */
void bubbleSort(struct node *start);
    
/* add node at last position. */
void addNodeLast(struct node **head, int value);



