#define _POSIX_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>     // for true/false
#include <pthread.h>     // for mutex
#include <time.h>        // for time
#include <strings.h>     // for bzero

static const int BUFFER_SIZE = 1;
static const int MAX_PRODUCED = 20;

static int buffer[BUFFER_SIZE];
static int counter = 0;
static int in = 0;
static int out = 0;

static int next_produced = 0;

static pthread_mutex_t lock;
static pthread_cond_t item_produced;
static pthread_cond_t item_consumed;

void *producer(void *_unused)
{
	while (true) {
		pthread_mutex_lock(&lock);
		while (counter == BUFFER_SIZE) {
			printf("wait!\n");
			pthread_cond_wait(&item_consumed, &lock);
		}

		printf("About to produce %d\n", next_produced);

		buffer[in] = next_produced;
		next_produced = (next_produced + 1) % MAX_PRODUCED;
		in = (in + 1) % BUFFER_SIZE;
		counter++;

		pthread_mutex_unlock(&lock);

		usleep(rand() % 200000);
	}
}

void *consumer(void *_unused)
{
	while (true) {
		pthread_mutex_lock(&lock);
		while (counter == 0) {
			pthread_cond_wait(&item_produced, &lock);
		}

		int next_consumed = buffer[out];
		out = (out + 1) % BUFFER_SIZE;
		counter--;

		printf("Consumed %d\n", next_consumed);

		pthread_mutex_unlock(&lock);
		
		usleep(rand() % 200000);
	}
}

int main(int argc, char **argv)
{
	pthread_cond_init(&item_produced, NULL);
	pthread_cond_init(&item_consumed, NULL);

	pthread_t producer_thread, consumer_thread;
	bzero(buffer, BUFFER_SIZE * sizeof(int));
	srand(time(NULL));

	pthread_create(&consumer_thread, NULL, consumer, NULL);
	pthread_create(&producer_thread, NULL, producer, NULL);

	while (true); // loop forever

	return 0;
}

