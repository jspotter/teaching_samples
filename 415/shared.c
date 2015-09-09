#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/stat.h>

#define SHARED_BUFFER_SIZE 1000

int main(int argc, char **argv)
{
	int shm_id = shmget(IPC_PRIVATE , SHARED_BUFFER_SIZE, S_IRUSR | S_IWUSR);
	char *shared_memory = (char *) shmat(shm_id, NULL, 0);

	pid_t pid = fork();
	if (pid == 0) {
		sprintf(shared_memory, "%s", "Hello from the child process!");
	} else {
		int exit_status;
		pid_t wait_result = waitpid(pid, &exit_status, 0);
		if (wait_result < 0) {
			printf("An error occurred waiting for process %d\n", pid);
			exit(1);
		}

		printf("%s\n", shared_memory);
	}

	// BOTH the parent and the child execute at this point!
	shmdt(shared_memory);

	exit(0);
}

