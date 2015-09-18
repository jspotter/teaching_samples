#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

const unsigned int NUM_PRINTS = 5;
const unsigned int NUM_THREADS = 3;

void *thread_func(void *data)
{
	unsigned long id = (unsigned long) data;
	for (unsigned int i = 1; i <= NUM_PRINTS; i++) {
		printf("Thread %lu: %u\n", id, i);
	}

	return NULL;
}

int main(int argc, char **argv)
{
	pthread_t threads[NUM_THREADS];
	for (unsigned long i = 0; i < NUM_THREADS; i++) {
		pthread_create(&threads[i], NULL, thread_func, (void *) (i + 1));
	}

	for (unsigned int i = 0; i < NUM_THREADS; i++) {
		pthread_join(threads[i], NULL);
	}

	printf("All done!\n");

	exit(0);
}

