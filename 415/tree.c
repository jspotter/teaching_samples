#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>

#define NUMBER_BASE 10
#define MAX_DIGITS 10

void printSomeNumbers()
{
	for (int i = 1; i <= 10; i++) {
		printf("%d\n", i);
	}
}

int main(int argc, char **argv)
{
	unsigned long breadth, depth;
	char *endp;

	if (argc < 3) {
		printf("Usage: ./tree <breadth> <depth>\n");
		exit(1);
	}

	breadth = strtoul(argv[1], &endp, NUMBER_BASE);
	depth = strtoul(argv[2], &endp, NUMBER_BASE);

	if (log(breadth) > MAX_DIGITS) {
		printf("Error: the breadth exceeds the maximum number of digits.\n");
		exit(1);
	}

	if (log(depth) > MAX_DIGITS) {
		printf("Error: the depth exceeds the maximum number of digits.\n");
		exit(1);
	}

	if (depth == 0) {
		printSomeNumbers();
		exit(0);
	}

	pid_t pids[breadth];
	for (int i = 0; i < breadth; i++) {
		pid_t pid = fork();
		if (pid == 0) {
			char breadth_buffer[MAX_DIGITS + 1];
			char depth_buffer[MAX_DIGITS + 1];

			sprintf(breadth_buffer, "%lu", breadth);
			sprintf(depth_buffer, "%lu", depth - 1);

			ssize_t exec_result = execlp("./tree", "./tree", breadth_buffer, depth_buffer, NULL);
			if (exec_result < 0) {
				printf("Error executing ./tree.\n");
				exit(1);
			}

			exit(0);
		} else {
			pids[i] = pid;
		}
	}

	for (int i = 0; i < breadth; i++) {
		int exit_status;
		pid_t wait_result = waitpid(pids[i], &exit_status, 0);
		if (wait_result < 0) {
			printf("Error occurred waiting for process %d\n", pids[i]);
		}
	}

	exit(0);
}

