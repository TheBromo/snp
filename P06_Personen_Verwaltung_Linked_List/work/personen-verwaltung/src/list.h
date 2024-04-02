//
// Created by manue on 02.04.2024.
//

#include "person.h"

#ifndef SNP_LIST_H
#define SNP_LIST_H
typedef struct node {
    person_t content; // in diesem Knoten gespeicherte Person
    struct node *next; // Pointer auf den nächsten Knoten in der Liste
} node_t;
#endif //SNP_LIST_H
