#define _POSIX_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>     // for true/false
#include <pthread.h>     // for mutex
#include <time.h>        // for time
#include <strings.h>     // for bzero

static const int BUFFER_SIZE = 10;
static const int MAX_PRODUCED = 20;

static int buffer[BUFFER_SIZE];
static int counter = 0;
static int in = 0;
static int out = 0;

static int next_produced = 0;

void *producer(void *_unused)
{
	while (true) {
		while (counter == BUFFER_SIZE); // do nothing

		printf("About to produce %d\n", next_produced);

		buffer[in] = next_produced;
		next_produced = (next_produced + 1) % MAX_PRODUCED;
		in = (in + 1) % BUFFER_SIZE;
		counter++;

		usleep(rand() % 200000);
	}
}

void *consumer(void *_unused)
{
	while (true) {
		while (counter == 0); // do nothing

		int next_consumed = buffer[out];
		out = (out + 1) % BUFFER_SIZE;
		counter--;

		printf("Consumed %d\n", next_consumed);
		
		usleep(rand() % 200000);
	}
}

int main(int argc, char **argv)
{
	pthread_t producer_thread, consumer_thread;
	bzero(buffer, BUFFER_SIZE * sizeof(int));
	srand(time(NULL));

	pthread_create(&consumer_thread, NULL, consumer, NULL);
	pthread_create(&producer_thread, NULL, producer, NULL);

	while (true); // loop forever

	return 0;
}

