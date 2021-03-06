#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

static const unsigned int kNumPhilosophers = 5;
static const unsigned int kNumForks = kNumPhilosophers;
static const unsigned int kNumMeals = 3;
static pthread_mutex_t forks[kNumForks];
static unsigned int numAllowed = kNumPhilosophers - 1; // impose limit to avoid deadlock
static pthread_mutex_t numAllowedLock;

static int getSleepTime()
{
	return rand() % 20000;
}

static int getEatTime()
{
	return rand() % 10000;
}

static int getThinkTime()
{
	return rand() % 30000;
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

static void waitForPermission() {
	while (1) {
		pthread_mutex_lock(&numAllowedLock);
		if (numAllowed > 0) break;
		pthread_mutex_unlock(&numAllowedLock);
		usleep(10);
	}
	numAllowed--;
	pthread_mutex_unlock(&numAllowedLock);
}

static void grantPermission() {
	pthread_mutex_lock(&numAllowedLock);
	numAllowed++;
	pthread_mutex_unlock(&numAllowedLock);
}

static void eat(unsigned int id) {
	unsigned int left = id;
	unsigned int right = (id + 1) % kNumForks;
	waitForPermission();

	pthread_mutex_lock(&forks[left]);
	usleep(getPickupDelayTime());
	pthread_mutex_lock(&forks[right]);
	printf("%u starts eating om nom nom nom.\n", id);
	
	usleep(getEatTime());
	printf("%u all done eating.\n", id);
	grantPermission();
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
	pthread_t philosophers[kNumPhilosophers];

	pthread_mutex_init(&numAllowedLock, NULL);
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

