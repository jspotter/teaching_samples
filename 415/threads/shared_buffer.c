#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define BUFFER_SIZE 3
#define NUM_ITERATIONS 3
#define NUM_THREADS 3

static int buffer[BUFFER_SIZE];
pthread_mutex_t mutexes[BUFFER_SIZE];

void *thread_func(void *thread_num_ptr)
{
	int thread_num = *((int *) thread_num_ptr);

	printf("Thread %d started!\n", thread_num);

	for (int iteration = 0; iteration < NUM_ITERATIONS; iteration++) {
		for (int buffer_idx = 0; buffer_idx < BUFFER_SIZE; buffer_idx++) {
			pthread_mutex_lock(&mutexes[buffer_idx]);
			int old_number = buffer[buffer_idx];

			int sleep_for = rand() % 3;
			// int sleep_for = 0;
			printf("Thread %d sleeping for %d seconds...\n", thread_num, sleep_for);
			sleep(sleep_for);

			printf("Thread %d: %d (at index %d) is now %d\n", thread_num, buffer_idx, old_number, old_number + 1);
			buffer[buffer_idx] = old_number + 1;
			pthread_mutex_unlock(&mutexes[buffer_idx]);
		}
	}

	return NULL;
}

int main(int argc, char **argv)
{
	pthread_t my_threads[NUM_THREADS];
	int my_thread_nums[NUM_THREADS];

	for (int i = 0; i < BUFFER_SIZE; i++) {
		pthread_mutex_init(&mutexes[i], NULL);
	}
	
	for (int i = 0; i < NUM_THREADS; i++) {
		my_thread_nums[i] = i + 1;
		pthread_create(&my_threads[i], NULL, thread_func, &my_thread_nums[i]);
	}

	for (int i = 0; i < NUM_THREADS; i++) {
		pthread_join(my_threads[i], NULL);
	}

	for (int i = 0; i < BUFFER_SIZE; i++) {
		printf("%d ", buffer[i]);
	}

	printf("\n");

	exit(0);
}

