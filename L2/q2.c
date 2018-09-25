/*
 * Name: Declan Simkins
 * Program: q2.c
 * Lab Section: Tuesday 2:00pm
 * Lab Instructor's Name: Stephanie Husby
 * CMPT 360
 * Instructor's Name: Cam Macdonell
 * --------------------
 * Desc: Lab 2 Question 2
 *       Opens a file, forks, then attempts to access the file descriptor
 *       from both the parent and child
 * Answer: Yes, both process can access the file descriptor returned by
 * open(); however, they are accessing their own copy of this file descriptor
 * (which is simply an unsigned int). Both processes write to the file in
 * sequence.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	int fd = open("q2test.txt", O_WRONLY | O_CREAT, 0200);
	int rc = fork();

	sleep(2);

	if (rc < 0) {
		fprintf(stderr, "Failed to fork.\n");
		exit(1);
	} else if (rc == 0) {
		char childToWrite[] = "CHILD WRITING TO Q2TEST.TXT\n";

		write(fd, childToWrite, sizeof(childToWrite) - sizeof(char));
	} else {
		char parentToWrite[] = "PARENT WRITING TO Q2TEST.TXT\n";

		write(fd, parentToWrite, sizeof(parentToWrite) - sizeof(char));
	}

	close(fd);
	return 0;
}
