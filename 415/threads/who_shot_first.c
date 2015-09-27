#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <signal.h>
#include <time.h>

static pthread_t han_solo, greedo;
static sem_t semaphore;

void sighand(int signo)
{
  pthread_t self = pthread_self();
	if (self == han_solo) {
		printf("Greedo shot first!\n");
	} else if (self == greedo) {
		printf("Han Solo shot first!\n");
	} else {
		printf("Something weird happend.\n");
	}

  pthread_exit(0);
}

void *han_solo_function(void *_unused)
{
	sem_wait(&semaphore);

	usleep(rand() % 1110000);
	pthread_kill(greedo, SIGALRM);
	pthread_exit(0);
}

void *greedo_function(void *_unused)
{
	sem_wait(&semaphore);

	usleep(rand() % 1000000);
	pthread_kill(han_solo, SIGALRM);
	pthread_exit(0);
}

int main(int argc, char **argv)
{
	srand(time(NULL));
	sem_init(&semaphore, 0, 0);
	signal(SIGALRM, sighand);

	pthread_create(&han_solo, NULL, han_solo_function, NULL);
	pthread_create(&greedo, NULL, greedo_function, NULL);

	sem_post(&semaphore);
	sem_post(&semaphore);

	pthread_join(han_solo, NULL);
	pthread_join(greedo, NULL);

	exit(0);
}

