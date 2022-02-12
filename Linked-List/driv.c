#include "driv.h"
#include "list.c"
#include "node.h"

void printMeny()
{
    printf("--------------------------------------------\n");
    printf("0: Avsluta\n");
    printf("1: Skriv ut listan\n");
    printf("2: skriv ut listans storlek\n");
    printf("3: Lägg till ett heltal sist i listan\n");
    printf("4: Lägg till ett heltal (valfri plats\n");
    printf("5: Ta bort ett givet heltal\n");
    printf("6: Ta bort ett heltal (valfri plats)\n");
    printf("7: Töm listan\n");
    printf("8: Vänd på listan\n");
    printf("9: Skifta listan ett steg åt vänster (och lägg första heltalet sist)\n");
    printf("10: Skifta listan ett steg åt höger (och lägg sista heltalet först)\n");
    printf("11: Sortera listan (lägsta heltalet först)\n");
    printf("12: Skriv ut startadress för listan\n");
    printf("--------------------------------------------\n");
}

int menyInmatning()
{
    char menyval[FMAX];
    char i;

    printf("Välj menyval mellan 0-12: "); fgets(menyval, FMAX-1, stdin);
    
    for(i=0; i < strlen(menyval)-1; i++)
    {
        if(isdigit(menyval[i]) == 0)
        {
            return 0;
        }
    }
    return atoi(menyval);
}

void printList(struct node *head)
{
    
    struct node *temp = head;

    //iterate the entire linked list and print the data
    while(temp != NULL)
    {
         printf("%d->", temp->data);
         temp = temp->next;
    }
    printf("NULL\n");
}

void printListSize(struct node *head)
{
    int size = countListSize(head);
    printf("Storleken på listan är: %d\n", size);
}


void addLast(struct node **head)
{
    int value = listInput();
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

void addNodeAtChoosenIndex(struct node **head)
{
    addNodeAtIndex(head, listInput(), indexInput());
    //addNodeAtIndex(struct node **head, int value, int index, int listSize)
}

void deleteNode(struct node **head)
{
    int key = listInput();
      //temp is used to freeing the memory
      struct node *temp;
    
      /* If head node itself holds the key to be deleted */
      if((*head)->data == key)
      {
          /* head gets value of next item in Linked list. */
          temp = *head; 
          /* Changed head to head->next */
          *head = (*head)->next;
          /* free old head */
          free(temp);
      }
      /* If head node itself != holds the key to be deleted */
      else
      {
          /* current is used to iterate in Linked list to find key. */
          struct node *current  = *head;
          /* Search for the key to be deleted while next node != NULL */
          while(current->next != NULL)
          {
              /* If current->next->data == holds the key to be deleted, delete node. */ 
              if(current->next->data == key)
              {
                  /* Unlink the node from linked list and free old node. */
                  temp = current->next;
                  current->next = current->next->next;
                  free(temp);
                  break;
              }
              /* Otherwise, move the current node and proceed */
              else
              {
                  current = current->next;
              }
          }
      }
}

/* https://www.geeksforgeeks.org/delete-a-linked-list-node-at-a-given-position/ */
void deleteNodeAtChoosenIndex(struct node **head)
{
    deleteNodeAtIndex(head, indexInput());
}


/* Deletes all nodes of the linked list
 * https://www.geeksforgeeks.org/write-a-function-to-delete-a-linked-list/
 */
void deleteList(struct node **head)
{
    /* deref head to get the real head */
   struct node* current = *head;
   struct node* next;
 
   while (current != NULL)
   {
       next = current->next;
       free(current);
       current = next;
   }
   
   /* deref head to affect the real head back
      in the caller. */
   *head = NULL;
}

void reverse(struct node** head)
{
    struct node* prev = NULL;
    struct node* current = *head;
    struct node* next = NULL;
    while (current != NULL) 
    {
        // Store next
        next = current->next;
 
        // Reverse current node's pointer
        current->next = prev;
 
        // Move pointers one step forward.
        prev = current;
        current = next;
    }
    // Point head to prev. Head will point to last element before reverse. 
    *head = prev;
}

void shiftLeft(struct node** head)
{
    /* If linked list is empty, or it contains
       only one node, then nothing needs to be
       done, simply return */
    if (*head == NULL || (*head)->next == NULL)
        return;
 
    /* Initialize first and last pointers */
    struct node* first = *head;
    struct node* last = *head;
 
    /*After this loop last contains address
    of last node in Linked List */
    while (last->next != NULL) {
        last = last->next;
    }
 
    /* Change the head pointer to point
       to second node now */
    *head = first->next;
 
    /* Set the next of first as NULL */
    first->next = NULL;
 
    /* Set the next of last as first */
    last->next = first;
}

void shiftRight(struct node **head)
{
    /* If linked list is empty, or it contains
       only one node, then nothing needs to be
       done, simply return */
    if(*head == NULL || (*head)->next == NULL)
    {
        return;
    }
    
    /* Initialize first, last and beforeLast pointers */
    struct node* first = *head;
    struct node* last = *head;
    struct node* beforeLast = *head;
    
    /* Loop through Linked list to find last node in list
       and store in last. */
    while(last->next != NULL)
    {
        last = last->next;
    }
    while(beforeLast->next->next != NULL)
    {
        beforeLast = beforeLast->next;
    }
    
    /* Change the last pointer to point
       to head now */
    last->next = *head;
    
    /* Change the head pointer to point
       to second node now */
    *head = last;
    
    /* Set the beforeLast node to NULL */
    beforeLast->next = NULL;
}

void sortList(struct node *head)
{
   bubbleSort(head);
}

void printStartAdress(struct node* head)
{
    if(head == NULL)
    {
        return;
    }
    else
    {
        printf("The address of the first node is: %p\n",head);
    }
}

int listInput()
{
    char input[FMAX];
    char i;

    printf("Ange heltal: "); fgets(input, FMAX-1, stdin);
    
    for(i=0; i < strlen(input)-1; i++)
    {
        if(isdigit(input[i]) == 0)
        {
            return 0;
        }
    }
    return atoi(input);
}

int indexInput()
{
    char input[FMAX];
    char i;

    printf("Ange index: "); fgets(input, FMAX-1, stdin);
    
    for(i=0; i < strlen(input)-1; i++)
    {
        if(isdigit(input[i]) == 0)
        {
            return 0;
        }
    }
    return atoi(input);
}




