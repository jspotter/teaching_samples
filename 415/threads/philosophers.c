#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static const unsigned int kNumPhilosophers = 5;
static const unsigned int kNumForks = kNumPhilosophers;
static const unsigned int kNumMeals = 3;
static mutex forks[kNumForks];
static unsigned int numAllowed = kNumPhilosophers - 1; // impose limit to avoid deadlock
static mutex numAllowedLock;

static void think(unsigned int id) {
	cout << oslock << id << " starts thinking." << endl << osunlock;
	sleep_for(getThinkTime());
	cout << oslock << id << " all done thinking. " << endl << osunlock;
}

static void waitForPermission() {
	while (true) {
		numAllowedLock.lock();
		if (numAllowed > 0) break;
		numAllowedLock.unlock();
		sleep_for(10);
	}
	numAllowed--;
	numAllowedLock.unlock();
}

static void grantPermission() {
	numAllowedLock.lock();
	numAllowed++;
	numAllowedLock.unlock();
}

static void eat(unsigned int id) {
	unsigned int left = id;
	unsigned int right = (id + 1) % kNumForks;
	waitForPermission();
	
	forks[left].lock();
	forks[right].lock();
	cout << oslock << id << " starts eating om nom nom nom." << endl << osunlock;
	
	sleep_for(getEatTime());
	cout << oslock << id << " all done eating." << endl << osunlock;
	grantPermission();
	forks[left].unlock();
	forks[right].unlock();
}

int main(int argc, char **argv)
{


	exit(0);
}

