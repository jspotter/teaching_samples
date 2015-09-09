#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

static const size_t kNumChildren = 5;
static size_t numChildrenDonePlaying = 0;

static void reapChild(int sig) {
	pid_t pid;
	while (1) {
		pid = waitpid(-1, NULL, WNOHANG);
		if (pid <= 0) break;
		numChildrenDonePlaying++;
	}
	
	if (pid != 0 && errno != ECHILD) {
		fprintf(stderr, "waitpid failed within reapChild sighandler.\n");
	}

	sleep(1); // represents time that useful work might be done
}

int main(int argc, char *argv[]) {
	printf("Let my five children play while I take a nap.\n");
	if (signal(SIGCHLD, reapChild) == SIG_ERR) {
		fprintf(stderr, "Failed to install SIGCHLD handler.\n");
	}

	for (size_t kid = 1; kid <= 5; kid++) {
		pid_t pid = fork();
		if(pid == -1) {
			fprintf(stderr, "Child #%zu doesn't want to play.\n", kid);
		}

		if (pid == 0) {
			sleep(3); // sleep emulates "play" time
			printf("Child #%zu tired... returns to dad.\n", kid);
			return 0;
		}
	}

	while (numChildrenDonePlaying < kNumChildren) {
		printf("At least one child still playing, so dad nods off.\n");
		sleep(5);
		printf("Dad wakes up! ");
	}

	printf("All children accounted for. Good job, dad!\n");
	return 0;
}

