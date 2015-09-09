#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	pid_t pid;

	if (argc < 2) {
		printf("Usage: ./myexec <program> <args...>\n");
		exit(1);
	}

	pid = fork();
	if (pid == 0) {
		int exec_result = execvp(argv[1], &argv[1]);
		if (exec_result < 0) {
			printf("An error occurred executing %s\n", argv[1]);
			exit(1);
		}

		exit(0);
	} else {
		int exit_status;
		pid_t wait_result = waitpid(pid, &exit_status, 0);
		if (wait_result < 0) {
			printf("An error occurred waiting for process %d\n", pid);
			exit(1);
		}
	}

	exit(0);
}

