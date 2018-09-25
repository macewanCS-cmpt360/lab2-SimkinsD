/*
 * Name: Declan Simkins
 * Program: q3.c
 * Lab Section: Tuesday 2:00pm
 * Lab Instructor's Name: Stephanie Husby
 * CMPT 360
 * Instructor's Name: Cam Macdonell
 * --------------------
 * Desc: Lab 2 Question 3
 *       Forks, then prints two messages, one from the child and one from
 *	the parent process. Attempts to ensure that the child's message is
 *       printed first by using I/O.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	int rc = fork();

	if (rc < 0) {
		fprintf(stderr, "Failed to fork.\n");
		exit(1);
	} else if (rc == 0) {
		printf("hello\n");
	} else {
		char fname[] = ".q3temp";
		/* Use I/O to force context switch if processes are
		 * on the same cpu
		 * Otherwise, I/O causes significant enough delay anyways
		 */
		int fd = open(fname, O_RDONLY | O_CREAT, 0200);

		printf("goodbye\n");
		close(fd);
		remove(fname);
	}
	return 0;
}
