#define _POSIX_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>     // for true/false
#include <pthread.h>     // for mutex
#include <semaphore.h>   // for semaphores
#include <strings.h>     // for bzero
#include <time.h>        // for time

static const int NUM_TASKS = 30;
static const int NUM_THREADS = 10;

static int tasks[NUM_TASKS];
static pthread_mutex_t lock;
static int next_task = 0;
static sem_t *semaphore;

void *worker(void *_unused)
{
	while (true) {
		// Figure out which task we are responsible for
		int my_task;
		pthread_mutex_lock(&lock);
		my_task = next_task;
		next_task++;
		pthread_mutex_unlock(&lock);

		if (my_task < NUM_TASKS) {
			// This represents doing some useful work
			// related to the "task" we are doing.
			usleep(rand() % 20000);

			// Mark that the task has been done!
			tasks[my_task] = 1;
			printf("Done with task %d!\n", my_task);
			sem_post(semaphore);
		}
	}
}

int main(int argc, char **argv)
{
	pthread_t threads[NUM_THREADS];
	pthread_mutex_init(&lock, NULL);
	semaphore = sem_open("x", O_CREAT, 0644, 0);
	bzero(tasks, NUM_TASKS * sizeof(int));
	srand(time(NULL));

	for (int i = 0; i < NUM_THREADS; i++) {
		pthread_create(&threads[i], NULL, worker, NULL);
	}

	for (int i = 0; i < NUM_TASKS; i++) {
		sem_wait(semaphore);
	}

	for (int i = 0; i < NUM_TASKS; i++) {
		if (tasks[i] == 0) {
			printf("Uh oh, looks like task %d got skipped!\n", i);
		}
	}

	printf("All done!\n");
	sem_close(semaphore);
	return 0;
}

