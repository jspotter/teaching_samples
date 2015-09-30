#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	pid_t pid = fork();
	if (pid == 0) {
		printf("1\n");
	} else {
		printf("2\n");
		wait(NULL);
	}


	exit(0);
}

