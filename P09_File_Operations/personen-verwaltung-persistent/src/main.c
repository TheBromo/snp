/* ----------------------------------------------------------------------------
 * --  _____       ______  _____                                              -
 * -- |_   _|     |  ____|/ ____|                                             -
 * --   | |  _ __ | |__  | (___    Institute of Embedded Systems              -
 * --   | | | '_ \|  __|  \___ \   Zuercher Hochschule Winterthur             -
 * --  _| |_| | | | |____ ____) |  (University of Applied Sciences)           -
 * -- |_____|_| |_|______|_____/   8401 Winterthur, Switzerland               -
 * ----------------------------------------------------------------------------
 */
/**
 * @file
 * @brief Lab implementation
 */
#include <stdio.h>
#include <stdlib.h>

#include "file_io.h"
#include "person.h"
#include "list.h"

void flushStdin() {
    int c;
    while ((c = fgetc(stdin)) != '\n' && c != EOF);
}

void scan_person(person_t *person) {
    printf("Name: ");
    scanf("%20s", person->name);
    flushStdin();
    printf("Firstname: ");
    scanf("%20s", person->first_name);
    flushStdin();
    printf("Age: ");
    scanf("%u", &person->age);
    flushStdin();
}

/**
 * @brief Main entry point.
 * @param[in] argc  The size of the argv array.
 * @param[in] argv  The command line arguments...
 * @returns Returns EXIT_SUCCESS (=0) on success, EXIT_FAILURE (=1) there is an expression syntax error.
 */
int main(int argc, char* argv[])
{
	// BEGIN-STUDENTS-TO-ADD-CODE
    load_person_list();
    printf("Personenverwaltung\n");
    printf("------------------\n");
    printf("Press: I(nsert), R(emove), S(how), C(lear), E(xit)\n");

    int key;
    while ((key = getchar()) != 'e' /* ESC */) {

        flushStdin();
        switch (key) {
            case 'i': {
                printf("Insert new person.\n");
                printf("-----------------------\n");

                person_t person;
                scan_person(&person);
                node_t *ins = insertInList(&person);
                printf("%i\n", ins);
                if (ins == NULL) {
                    printf("Duplicate entry!\n");
                }

                break;
            }
            case 'r': {
                printf("Delete an existing person.\n");
                printf("-----------------------\n");

                person_t person;
                scan_person(&person);
                removeFromList(&person);

                break;
            }
            case 's': {
                showList();
                printf("\n");
                break;
            }
            case 'c': {
                clearList();
                break;
            }
        }

        printf("Personenverwaltung\n");
        printf("------------------\n");
        printf("Press key for I(nsert), R(emove), S(how), C(lear), E(xit)\n");
    }
    store_person_list();
	// END-STUDENTS-TO-ADD-CODE
    return EXIT_SUCCESS;
}
