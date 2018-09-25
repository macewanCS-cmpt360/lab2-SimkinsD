/*
 * Name: Declan Simkins
 * Program: q1.c
 * Lab Section: Tuesday 2:00pm
 * Lab Instructor's Name: Stephanie Husby
 * CMPT 360
 * Instructor's Name: Cam Macdonell
 * --------------------
 * Desc: Lab 2 Question 1
 *       Creates a fork, accesses the same variable from child and parent
 *	processes to examine the effect
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	char *cmdline;
	char *token = NULL;
	int i, rc;
	char *args[10] = {""};
	unsigned short running = 1, wait_for_child;

	while (running) {
		wait_for_child = 1;
		cmdline = calloc(1, 1024);
		i = 0;

		printf("prompt> ");
		fgets(cmdline, 1024, stdin);
		//fprintf(stderr, "[debug] cmdline = *%s*\n", cmdline);

		token = strtok(cmdline, "\n ");
		while (token != NULL) {
			if (strcmp(token, "&") == 0)
				wait_for_child = 0;
			else if (strcmp(token, "quit") == 0)
				exit(1);
			else
				args[i] = strdup(token);

			token = strtok(NULL, "\n ");
			i++;
		}
		args[i] = NULL;
		if (strcmp(args[0], "quit") == 0)
			exit(1);

		rc = fork();

		if (rc < 0) {
			fprintf(stderr, "Failed to fork.\n");
			exit(1);
		} else if (rc == 0) {
			execvp(args[0], args);
		} else {
			/* If there is a '&', don't wait */
			if (wait_for_child)
				wait(NULL);
		}
		free(cmdline);
	}

	return 0;
}

