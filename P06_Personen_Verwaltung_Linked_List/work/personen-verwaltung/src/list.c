//

#include "list.h"
#include <stdlib.h>
#include "person.h"

node_t headElement = {
    {"name",
     "name",
     1},
    NULL};
node_t *const anchor = &headElement;

node_t *nalloc();

// Remove: der Benutzer wird aufgefordert, die Daten einer zu löschenden Person einzugeben
void remove_p(person_t person)
{
    node_t *current = anchor->next;
    node_t *previous;
    while (person_compare(&current->content, &current->next->content) != 0 || current->next != NULL)
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
    node_t *current = anchor->next;
    node_t *previous;
    //aaaa
    while (current->next == NULL || person_compare(&current->content, &current->next->content) > 0)

    {
        previous = current;
        current = current->next;
    }
    node_t *new = nalloc();
    new->content = person;
    new->next = current;
    previous->next = new;
}

person_t *find_p(person_t person)
{
    return 0;
}

node_t *nalloc()
{
    return (node_t *)malloc(sizeof(node_t));
}

void show_p()
{
}
