#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

const unsigned int NUM_PRINTS = 1000;

void *thread_func(void *_unused) {
	for (unsigned int i = 0; i < NUM_PRINTS; i++) {
		printf("%d\n", i);
		usleep(rand() % 100000);
	}

	return NULL;
}

int main(int argc, char **argv)
{
	srand(time(NULL));

	pthread_t thread;
	pthread_create(&thread, NULL, thread_func, NULL);

	usleep(rand() % 10000000);

	pthread_cancel(thread);

	exit(0);
}

