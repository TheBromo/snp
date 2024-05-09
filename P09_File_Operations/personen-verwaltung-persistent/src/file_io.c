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

void perror_and_exit(const char *context)
{
	perror(context);
	exit(EXIT_FAILURE);
} // das muss noch an einen anderen Ort, scia

// May divide your code in further functions
// BEGIN-STUDENTS-TO-ADD-CODE
FILE *f;
// END-STUDENTS-TO-ADD-CODE

void store_person_list(void)
{
	// BEGIN-STUDENTS-TO-ADD-CODE
	f= fopen("person-list.csv", "w");

	if (!f)
	{
		perror_and_exit("coudlnt open person-list.csv");
	}

	person_t* person = list_getFirst();
	char *buffer;

	while (person != NULL)
	{
		buffer = malloc(255 * sizeof(char));

		person_to_csv_string(person, buffer);
		fputs(buffer, f);
		fputs("\n", f);
		person = list_getNext();
	}
	fclose(f);
	// END-STUDENTS-TO-ADD-CODE
}

void load_person_list(void)
{
	// BEGIN-STUDENTS-TO-ADD-CODE
	f = fopen("person-list.csv", "r");
	if (!f)
	{
		perror_and_exit("coudlnt open person-list.csv");
	}

	char buffer[255];
	while (fgets(buffer, 255, f) != NULL)
	{
		person_t *person = malloc(sizeof(person_t));
		person_from_csv_string(person, buffer);
		list_insert(person);
	}
	fclose(f);
	// END-STUDENTS-TO-ADD-CODE
}
