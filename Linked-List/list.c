#include "list.h"
#include "node.h"

int countListSize(struct node *head)
{
    struct node *temp = head;
    int counter = 0;

    //iterate the entire linked list and print the data
    while(temp != NULL)
    {
        counter++;
        temp = temp->next;
    }
    
    return counter;
}

int checkIfListIsEmpty(struct node *head)
{
    if(head == NULL)
        return 1;
    else
        return 0;
}

static node* getNode (node* head, int index)
{
    node* n = head;
    for(int i = 1; i < index; i++)
    {
        n = n->next;
    }
    return n;
}

int checkForElementInList(struct node **head, int key)
{
    /* current is used to iterate in Linked list to find key. */
    struct node *current  = *head;
    /* Search for the key to detect if node is in list while next node != NULL */
    while(current->next != NULL)
    {
        /* If current->next->data == holds the key to be deleted. Return true. */ 
        if(current->next->data == key)
        {
            return 1;
            break;
        }
        /* Otherwise, move the current node and proceed */
        else
        {
            current = current->next;
        }
        
    }
    
    return 0;
}

/* Källa: https://www.log2base2.com/data-structures/linked-list/deleting-a-node-in-linked-list.html */
int returnPosition(struct node **head, int key)
{
    int pos;
    
    /* If head node itself holds the key to be deleted */
    
    if((*head)->data == key)
    {
        pos = 0;
    }
    else
    {
        /* current is used to iterate in Linked list to find key. */
        struct node *current  = *head;
        while(current->next != NULL)
        {
            pos++;
            
            /* If current->next->data == holds the key to be deleted, delete node. */ 
            if(current->data == key)
            {
                break;
            }
            /* Otherwise, move the current node and proceed */
            else
            {
                current = current->next;
            }
        }
        return pos;
    }
}
    
 
    

void addNodeAtIndex(struct node **head, int value, int index)
{
    // If linked list is empty or index is bigger or lower then index. 
   if (*head == NULL || index < 0 || index > countListSize(*head))
   {
       return;
   }
    
   // Store head node
   struct node *previousNode = *head;
 

    /* Find previous node of the soon to be inserted node. */
    for (int i=0; previousNode!=NULL && i<index-1; i++)
    {
        previousNode = previousNode->next;
    }
    
    if(index == 0)
    {
        //create a new node
       struct node *newNode = malloc(sizeof(struct node));
       newNode->data = value;
       newNode->next = *head;
       *head = newNode;
    }
    
    if(index != 0 )
    {
        /* Create an new node and insert it between (i-1) and (i) */
        struct node *newNode = malloc(sizeof(struct node));
        newNode->data = value;
        newNode->next = previousNode->next;
        previousNode->next = newNode;
    }
    
    if(previousNode->next == NULL)
    {
        addNodeLast(head, value);
    }
}

/* https://www.geeksforgeeks.org/delete-a-linked-list-node-at-a-given-position/ */
void deleteNodeAtIndex(struct node **head, int index)
{
    // If linked list is empty
   if (*head == NULL)
      return;
 
   // Store head node
   struct node* temp = *head;
 
    // If head needs to be removed
    if (index == 0)
    {
        *head = temp->next;   // Change head
        free(temp);               // free old head
        return;
    }
 
    // Find previous node of the node to be deleted
    for (int i=0; temp!=NULL && i<index-1; i++)
         temp = temp->next;
 
    // If index is more than number of nodes
    if (temp == NULL || temp->next == NULL)
         return;
 
    // Node temp->next is the node to be deleted
    // Store pointer to the next of node to be deleted
    struct node *next = temp->next->next;
 
    // Unlink the node from linked list
    free(temp->next);  // Free memory
 
    temp->next = next;  // Unlink the deleted node from list
}

void swap(struct node *a, struct node *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

/* Bubble sort the given linked list */
void bubbleSort(struct node *start)
{
    int swapped, i;
    struct node *ptr1;
    struct node *lptr = NULL;
  
    /* Checking for empty list */
    if (start == NULL)
        return;
    do
    {
        swapped = 0;
        ptr1 = start;
  
        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            { 
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}

void addNodeLast(struct node **head, int value)
{
    //create a new node
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    //if head is NULL, it is an empty list
    if(*head == NULL)
         *head = newNode;
    //Otherwise, find the last node and add the newNode
    else
    {
        struct node *lastNode = *head;

        //last node's next address will be NULL.
        while(lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }

        //add the newNode at the end of the linked list
        lastNode->next = newNode;
    }
}

