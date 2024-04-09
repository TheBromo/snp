//
#include <stdio.h>
#include "list.h"
#include <stdlib.h>
#include "person.h"

node_t start;
node_t *anchor = &start;
node_t *palloc();

// Remove: der Benutzer wird aufgefordert, die Daten einer zu löschenden Person einzugeben
void remove_p(person_t person)
{
    if (!exists_p(person))
    {
        return;
    }
    
    node_t *current = anchor->next;
    node_t *previous = anchor;
    while (current != NULL && person_compare(&current->content, &person) != 0 )
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
    while (current != NULL)
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
    if (exists_p(person))
    {
        return;
    }

    node_t *current = anchor->next;
    node_t *previous = anchor;

    while (current != NULL && person_compare(&current->content, &person) > 0)
    {
        previous = current;
        current = current->next;
    }
    node_t *new = palloc();
    new->content = person;
    new->next = current;
    
    previous->next = new;
}

bool *exists_p(person_t person)
{
    node_t *current = anchor;
    while (current != NULL)
    {
        if (person_compare(&person, &current->content) == 0)
        {
            return true;
        }
        current = current->next;
    } 
    return false;
}

node_t *palloc()
{
    return (node_t *)malloc(sizeof(node_t));
}

void show_p()
{
    node_t *current = anchor->next;
    while (current != NULL)
    {
        person_t person = current->content;
        printf("%s %s %d\n", person.name, person.first_name, person.age);
        current = current->next;
    }
}
