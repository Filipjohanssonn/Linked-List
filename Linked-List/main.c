#include "driv.h"
#include "node.h"

int main()
{
    /* Handtaget */
    struct node *head = NULL;
    while(1)
    {
       int val;
       printMeny();
       val = menyInmatning();
       switch (val)
       {
           case 0:  /* Avsluta */
                    printf("Du har valt val: 0\n"); exit(-1); break;
               
           case 1:  /* Skriv ut listan */
                    printf("Du har valt val: 1\n");
                    printList(head); 
                    break;
           
           case 2:  /* Skriv ut listans storlek*/
                    printf("Du har valt val: 2\n"); 
                    printListSize(); break;
           
           case 3:  /* Lägg till ett heltal sist i listan */
                    printf("Du har valt val: 3\n");
                    addLast(&head); break;

           case 4:  /* Lägg till ett heltal (valfri plats */
                    printf("Du har valt val: 4\n"); 
                    addNodeAtChoosenIndex(&head); break;

           case 5:  /* Ta bort ett givet heltal */
                    printf("Du har valt val: 5\n"); 
                    deleteNode(&head); break; 

           case 6:  /* Ta bort ett heltal (valfri plats) */
                    printf("Du har valt val: 6\n"); 
                    deleteNodeAtChoosenIndex(&head); break;

           case 7:  /* Töm listan */             
                    printf("Du har valt val: 7\n"); 
                    deleteList(&head); break;

           case 8:  /* Vänd på listan */
                    printf("Du har valt val: 8\n"); 
                    reverse(&head); break;

           case 9:  /* Skifta listan ett steg åt vänster (och lägg första heltalet sist) */
                    printf("Du har valt val: 9\n"); 
                    shiftLeft(&head); break;

           case 10: /* Skifta listan ett steg åt höger (och lägg sista heltalet först) */
                    printf("Du har valt val: 10\n"); 
                    shiftRight(&head); break;
        
           case 11:  /* Sortera listan (lägsta heltalet först) */
                    printf("Du har valt val: 11\n"); 
                    sortList(head); break;

           case 12:  /* Skriv ut startadress för listan */
                    printf("Du har valt val: 12\n");
                    printStartAdress(head); break;      
            
           default:    printf("Okänt val! Se meny för valbara alterlativ\n"); break;
           break;
        }
    }
    return 0;
}   
