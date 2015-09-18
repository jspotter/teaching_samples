#define _POSIX_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <stdbool.h>

static sigset_t mask;
static pid_t child_pid;

void child_handler(int _unused)
{
	printf("Child got a signal!\n");
	sleep(2);
	kill(getppid(), SIGUSR1);
}

void parent_handler(int _unused)
{
	printf("Parent got a signal!\n");
	sleep(2);
	kill(child_pid, SIGUSR1);
}

int main(int argc, char **argv)
{
	// What happens when we get rid of signal masking?
	sigemptyset(&mask);
	sigaddset(&mask, SIGUSR1);
	sigprocmask(SIG_BLOCK, &mask, NULL);

	signal(SIGUSR1, parent_handler);

	pid_t pid = fork();
	if (pid == 0) {
		signal(SIGUSR1, child_handler);
		sigprocmask(SIG_UNBLOCK, &mask, NULL);

		kill(getppid(), SIGUSR1);
		while(true);
	} else {
		// What happens if we uncomment this line?
		// sleep(5);
		child_pid = pid;		
		sigprocmask(SIG_UNBLOCK, &mask, NULL);
		while(true);
	}

	exit(0);
}

