//
// Created by manue on 02.04.2024.
//

#ifndef SNP_PERSON_H
#define SNP_PERSON_H

#define NAME_LEN 20

typedef struct {
    char name[NAME_LEN];
    char first_name[NAME_LEN];
    unsigned int age;
} person_t;


#endif //SNP_PERSON_H
