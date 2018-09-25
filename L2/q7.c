/*
 * Name: Declan Simkins
 * Program: q7.c
 * Lab Section: Tuesday 2:00pm
 * Lab Instructor's Name: Stephanie Husby
 * CMPT 360
 * Instructor's Name: Cam Macdonell
 * --------------------
 * Desc: Lab 2 Question 7
 *       Creates a fork and closes STDOUT_FILENO in the child process. Then
 *	 attempts to call printf()
 *
 * Answer: The process produces no output, as the file descriptor is now
 * closed which prevents printf from accessing stdout.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int rc = fork();

	if (rc < 0) {
		fprintf(stderr, "Failed to fork.\n");
		exit(1);
	}

	else if (rc == 0) {
		close(STDOUT_FILENO);
		printf("test\n");
	}

	return 0;
}

