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
// Show: eine komplette Liste aller gespeicherten Personen wird in alphabetischer Reihenfolge ausgegeben
void show_p();

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
    char c;

    while (running)
    {
        printf("I(nsert), R(emove), S(how), C(lear), E(nd):\n");
        scanf(" %c", &c);

        switch (c)
        {
        case 'e' | 'E':
            running = false;
            continue;
        case 'i' | 'I':
        {
            person_t person;
            if (create_person(&person))
            {
                insert_p(person);
            }
        }
        break;
        case 'r' | 'R':
        {
            person_t person;
            if (create_person(&person))
            {
                remove_p(person);
            }
        }
        break;
        case 's' | 'S':
            show_p();
            break;
        case 'c' | 'C':
            clear_p();
            break;
        default:
            printf("what?\n");
            break;
        }
    }

    // END-STUDENTS-TO-ADD-CODE
    return EXIT_SUCCESS;
}
