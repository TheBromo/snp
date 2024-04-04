//
// Created by manue on 02.04.2024.
//
#include "person.h"
#include "stdlib.h"
#include <string.h>


int person_compare(const person_t *a, const person_t *b)
{
    return strcmp(a->name, b->name) + strcmp(a->first_name, b->first_name) + (a->age - b->age);
}
