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
#include "person.h"
#include "list.h"
#include <stdlib.h>
#include <stdbool.h>

// End: das Programm wird beendet
void end();
// Show: eine komplette Liste aller gespeicherten Personen wird in alphabetischer Reihenfolge ausgegeben
void show_p();
person_t find_person();

/**
 * @brief Main entry point.
 * @param[in] argc  The size of the argv array.
 * @param[in] argv  The command line arguments...
 * @returns Returns EXIT_SUCCESS (=0) on success, EXIT_FAILURE (=1) there is an expression syntax error.
 */
int main(int argc, char *argv[])
{
    // BEGIN-STUDENTS-TO-ADD-CODE
    bool running = true;

    while (running)
    {
        printf("I(nsert), R(emove), S(how), C(lear), E(nd):\n");

        int c = getchar();
        // clear out stdin
        while (getchar() != '\n');

        switch (c)
        {
        case 'e' | 'E':
            running = false;
            break;
        case 'i' | 'I':
        {
            person_t person;
            person = create_person();
            insert_p(person);
        }
        break;
        case 'r' | 'R':
        {
            person_t person;
            person = find_person();
            remove_p(person);
        }
        break;
        case 's' | 'S':
            show_p();
            break;
        case 'c' | 'C':
            clear_p();
            break;
        default:
            printf("what?");
            break;
        }
    }

    // END-STUDENTS-TO-ADD-CODE
    return EXIT_SUCCESS;
}

void show_p()
{
}

person_t find_person()
{
    return ;
}

void end()
{
}
