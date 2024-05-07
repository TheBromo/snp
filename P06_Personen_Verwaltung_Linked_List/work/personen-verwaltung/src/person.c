//
// Created by manue on 02.04.2024.
//
#include "person.h"
#include "stdlib.h"
#include <stdio.h>
#include <string.h>

int person_compare(const person_t *a, const person_t *b)
{
    return strcmp(a->name, b->name) + strcmp(a->first_name, b->first_name) + (a->age - b->age);
}

bool create_person(person_t *result)
{
    char name[NAME_LEN];
    char c = 'z';
    char firstname[NAME_LEN];
    unsigned int age;

    printf("\nEnter Name Firstname Age\n");
    scanf("%s%s%u", name, firstname, &age);

    if (strlen(name) > NAME_LEN || strlen(firstname) > NAME_LEN || age <= 0)
    {
        printf("wrong\n");
        return false;
    }

    result->age = age;
    strcpy(result->first_name, firstname);
    strcpy(result->name, name);

    return true;
}