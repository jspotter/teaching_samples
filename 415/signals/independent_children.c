#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static const size_t kNumChildren = 5;
static size_t numChildrenDonePlaying = 0;

static void reapChild(int sig) {
	if(waitpid(-1, NULL, 0) == -1) {
		fprintf(stderr, "waitpid failed within reapChild sighandler.\n");
	}

	numChildrenDonePlaying++;
	sleep(1); // represents time spent doing other useful work
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
			sleep(3 * kid); // sleep emulates "play" time
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

