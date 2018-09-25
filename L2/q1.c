/*
 * Name: Declan Simkins
 * Program: q1.c
 * Lab Section: Tuesday 2:00pm
 * Lab Instructor's Name: Stephanie Husby
 * CMPT 360
 * Instructor's Name: Cam Macdonell
 * ----------------------
 * Desc: Lab 2 Question 1
 *       Creates a fork, accesses the same variable from child and parent
 *	processes to examine the effect
 * Answer: The parent and child processes have seperate address spaces;
 * therefore, the variable 'x' exists independently in each process and the
 * changes made to it in one process are not reflected in the other process.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int x = 100;

	printf("Initial x: %d\n", x);
	int rc = fork();

	if (rc < 0) {
		fprintf(stderr, "Failed to fork.\n");
		exit(1);
	} else if (rc == 0) {
		printf("Child process x: %d\n", x);
		x++;
		printf("Child process modified x: %d\n", x);
	} else {
		printf("Parent process x: %d\n", x);
		x--;
		printf("Parent process modified x: %d\n", x);
	}

	return 0;
}

