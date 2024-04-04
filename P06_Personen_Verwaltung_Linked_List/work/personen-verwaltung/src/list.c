//
// Created by manue on 02.04.2024.
//

#include "list.h"
#include <stdlib.h>
#include "person.h"

node_t headElement;
node_t * const anchor = &headElement;

// Remove: der Benutzer wird aufgefordert, die Daten einer zu löschenden Person einzugeben
void remove_p(person_t person)
{
    //TODO check when end is reached
    node_t *current = anchor->next;
    node_t *previous;
    while (person_compare(&current->content, &current->next->content) != 0 || current->next == NULL)
    {
        previous = current;
        current = current->next;
    }

    previous->next = current->next;
    free(current);
}


// Clear: alle Personen werden gelöscht
void clear_p()
{ 
   node_t *current = anchor->next; 
   while (current->next != NULL)
   {
        node_t *temp = current;
        current = current->next;
        free(temp);
   }
   anchor->next = NULL;
}

// Insert: der Benutzer wird aufgefordert, eine Person einzugeben
void insert_p(person_t person)
{
    //check when end is reached
    node_t *current = anchor->next;
    node_t *previous;
    while (person_compare(&current->content, &current->next->content) > 0 || current->next == NULL)
    {
        previous = current;
        current = current->next;
    }
     


}

node_t *nalloc()
{
    return (node_t *)malloc(sizeof(node_t));
}
