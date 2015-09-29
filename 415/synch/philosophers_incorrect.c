#define _POSIX_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>       // for time

static const unsigned int kNumPhilosophers = 5;
static const unsigned int kNumForks = kNumPhilosophers;
static const unsigned int kNumMeals = 3;
static pthread_mutex_t forks[kNumForks];

static int getSleepTime()
{
	return rand() % 200000;
}

static int getEatTime()
{
	return rand() % 100000;
}

static int getThinkTime()
{
	return rand() % 300000;
}

static int getPickupDelayTime()
{
	return 200000;
}

static void think(unsigned int id) {
	printf("%u starts thinking.\n", id);
	usleep(getThinkTime());
	printf("%u all done thinking.\n", id);
}

static void eat(unsigned int id) {
	unsigned int left = id;
	unsigned int right = (id + 1) % kNumForks;

	pthread_mutex_lock(&forks[left]);
	usleep(getPickupDelayTime());
	pthread_mutex_lock(&forks[right]);
	printf("%u starts eating om nom nom nom.\n", id);
	
	usleep(getEatTime());
	printf("%u all done eating.\n", id);
	pthread_mutex_unlock(&forks[left]);
	pthread_mutex_unlock(&forks[right]);
}

static void *philosopher(void *data)
{
	for (unsigned int i = 0; i < kNumMeals; i++) {
		think((unsigned int) data);
		eat((unsigned int) data);
	}
	return NULL;
}

int main(int argc, char **argv)
{
	srand(time(NULL));
	pthread_t philosophers[kNumPhilosophers];

	for (unsigned int i = 0; i < kNumForks; i++) {
		pthread_mutex_init(&forks[i], NULL);
	}

	for (unsigned int i = 0; i < kNumPhilosophers; i++) {
		pthread_create(&philosophers[i], NULL, philosopher, (void *) i);
	}

	for (unsigned int i = 0; i < kNumPhilosophers; i++) {
		pthread_join(philosophers[i], NULL);
	}

	exit(0);
}

