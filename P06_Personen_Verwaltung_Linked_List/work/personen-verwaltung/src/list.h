//
// Created by manue on 02.04.2024.
//

#ifndef SNP_LIST_H
#define SNP_LIST_H

//
// Created by manue on 02.04.2024.
//

#include "person.h"

typedef struct linked_list {
    struct node *anchor;
} linked_list_t;

typedef struct node {
    person_t content; // in diesem Knoten gespeicherte Person
    struct node *next; // Pointer auf den nächsten Knoten in der Liste
} node_t;


//Remove: der Benutzer wird aufgefordert, die Daten einer zu löschenden Person einzugeben
void remove_p(person_t person);

//Clear: alle Personen werden gelöscht
void clear_p();

//Insert: der Benutzer wird aufgefordert, eine Person einzugeben
void insert_p(person_t person);

#endif //SNP_LIST_H
