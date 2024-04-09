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
 * @brief Test suite for the given package.
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#include <assert.h>
#include <CUnit/Basic.h>
#include "test_utils.h"
#include "list.h"
#include "person.h"

#ifndef TARGET // must be given by the make file --> see test target
#error missing TARGET define
#endif

/// @brief alias for EXIT_SUCCESS
#define OK EXIT_SUCCESS
/// @brief alias for EXIT_FAILURE
#define FAIL EXIT_FAILURE

/// @brief The name of the STDOUT text file.
#define OUTFILE "stdout.txt"
/// @brief The name of the STDERR text file.
#define ERRFILE "stderr.txt"

#define TRACE_INDENT "\n                " ///< allow for better stdout formatting in case of error

// setup & cleanup
static int setup(void)
{
	remove_file_if_exists(OUTFILE);
	remove_file_if_exists(ERRFILE);
	return 0; // success
}

static int teardown(void)
{
	// Do nothing.
	// Especially: do not remove result files - they are removed in int setup(void) *before* running a test.
	return 0; // success
}

// tests
static void test_person_compare(void)
{
	// BEGIN-STUDENTS-TO-ADD-CODE
	// arrange
	person_t person_1 = {
		"max",
		"muster",
		20};
	person_t person_2 = {
		"peter",
		"muster",
		20};
	person_t person_3 = {
		"max",
		"example",
		20};
	person_t person_4 = {
		"max",
		"muster",
		21};
	person_t person_5 = {
		"AAA",
		"AAA",
		20};
	person_t person_6 = {
		"BBB",
		"BBB",
		20};
	// act
	int result1 = person_compare(&person_1, &person_1);
	int result2 = person_compare(&person_1, &person_2);
	int result3 = person_compare(&person_1, &person_3);
	int result4 = person_compare(&person_1, &person_4);
	int result5 = person_compare(&person_5, &person_6);
	int result6 = person_compare(&person_6, &person_5);
	// assert
	CU_ASSERT(result1 == 0);
	CU_ASSERT(result2 != 0);
	CU_ASSERT(result3 != 0);
	CU_ASSERT(result4 != 0);
	CU_ASSERT(result5 < 0);
	CU_ASSERT(result6 > 0);
	// END-STUDENTS-TO-ADD-CODE
}

static void test_list_insert(void)
{
	// BEGIN-STUDENTS-TO-ADD-CODE
	// arrange
	person_t person_1 = {
		"max",
		"muster",
		20};
	person_t person_2 = {
		"peter",
		"muster",
		20};
	// act
	insert_p(person_1);
	insert_p(person_2);
		
	// assert
	CU_ASSERT(exists_p(person_1));	
	CU_ASSERT(exists_p(person_2));	
	// END-STUDENTS-TO-ADD-CODE
}

static void test_list_remove(void)
{
	// BEGIN-STUDENTS-TO-ADD-CODE
	// arrange
	person_t person_1 = {
		"max",
		"muster",
		20};
	person_t person_2 = {
		"peter",
		"muster",
		20};
	
	// act
	insert_p(person_1);
	insert_p(person_2);
	remove_p(person_1);
	remove_p(person_2);

	// assert
	CU_ASSERT(!exists_p(person_1));	
	CU_ASSERT(!exists_p(person_2));	
	
	// END-STUDENTS-TO-ADD-CODE
}

static void test_list_clear(void)
{
	// BEGIN-STUDENTS-TO-ADD-CODE
	person_t person_1 = {
		"max",
		"muster",
		20};
	person_t person_2 = {
		"peter",
		"muster",
		20};
	
	// act
	insert_p(person_1);
	insert_p(person_2);
	clear_p();

	// assert
	CU_ASSERT(!exists_p(person_1));	
	CU_ASSERT(!exists_p(person_2));	

	// END-STUDENTS-TO-ADD-CODE
}

/**
 * @brief Registers and runs the tests.
 * @returns success (0) or one of the CU_ErrorCode (>0)
 */
int main(void)
{
	// setup, run, teardown
	TestMainBasic("lab test", setup, teardown, test_person_compare, test_list_insert, test_list_remove, test_list_clear);
}
