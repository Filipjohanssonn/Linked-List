#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "node.h"

#define FMAX 10 // Storlek för registret

/* Skriver ut meny */
void printMeny();

/* Tar input till meny på ett säkert sätt så inte programmet krashar. */
int menyInmatning();

/* Skriver ut den länkade listan. */
void printList(struct node *head);

/* Skriver ut listans storlek */
void printListSize();

/* Lägger till en ny nod sist i den länkade listan. */
void addLast(struct node **head);

/* Lägger till en ny nod på vald plats i listan. */
void addNodeAtChoosenIndex(struct node **head);

/* Källa: https://www.log2base2.com/data-structures/linked-list/deleting-a-node-in-linked-list.html 
   Tar input från användaren och tar bort den första noden med det värdet. */
void deleteNode(struct node **head);

/* Tar bort noden på den angivna positionen i listan. */
void deleteNodeAtChoosenIndex(struct node **head);

/* Tar bort alla noder i listan förutom head */
void deleteList(struct node **head);

/* Function to reverse the linked list 
   https://www.geeksforgeeks.org/reverse-a-linked-list/ 
   Ex: 
   Före: HEAD->1->2->3->4->NULL
   Efter: NULL<-1<-2<-3<-4<-HEAD 
*/
void reverse(struct node** head);

/* We are using a double pointer head
   here because we change head of the linked
   list inside this function.
   https://www.geeksforgeeks.org/move-first-element-to-end-of-a-given-linked-list/ */
void shiftLeft(struct node** head);
void shiftRight(struct node **head);

/* Bubble sort the linked list with a bubblesort. */
void sortList(struct node *start);

/* Skriver ut head adress. */
void printStartAdress(struct node* head);

/* Tar input från användaren.  */
int listInput();

/* Tar input från användaren för att ange index. */
int indexInput();
