//
// Created by manue on 02.04.2024.
//

#include "list.h"
#include <stdlib.h>
const linked_list_t linked_list;

// Remove: der Benutzer wird aufgefordert, die Daten einer zu löschenden Person einzugeben
void remove_p(person_t person)
{
}

// Clear: alle Personen werden gelöscht
void clear_p()
{
}

// Insert: der Benutzer wird aufgefordert, eine Person einzugeben
void insert_p(person_t person){
}

node_t *nalloc()
{
    return (node_t *)malloc(sizeof(node_t));
}

void create_linked_list()
{
    node_t *anchor = nalloc();
    linked_list_t linked_list = {
        anchor};
}