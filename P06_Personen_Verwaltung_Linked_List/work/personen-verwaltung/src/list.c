//
// Created by manue on 02.04.2024.
//

#include "list.h"
#include <stdlib.h>

node_t headElement;
node_t * const anchor = &headElement;

// Remove: der Benutzer wird aufgefordert, die Daten einer zu löschenden Person einzugeben
void remove_p(person_t person)
{
}

// Clear: alle Personen werden gelöscht
void clear_p()
{ 
   node_t *current = anchor->next; 
   while (current != anchor)
   {
        node_t *temp = current;
        current = current->next;
        free(temp);
   }
   anchor->next = anchor;
}

// Insert: der Benutzer wird aufgefordert, eine Person einzugeben
void insert_p(person_t person)
{
}

node_t *nalloc()
{
    return (node_t *)malloc(sizeof(node_t));
}
