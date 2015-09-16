#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

static int i;

void *rabbit_season(void *_unused)
{
	while (i < 10) {
		
		// If i gets to -10, we lost...
		if (i == -10) {
			return NULL;
		}

		// Try to get i to 10!
		i++;
		usleep(rand() % 10000);
	}

	printf("Rabbit season!\n");
	return NULL;
}

void *duck_season(void *_unused)
{
	while (i > -10) {

		// If i gets to 10, we lost...
		if (i == 10) {
			return NULL;
		}

		// Try to get i to -10!
		i--;
		usleep(rand() % 10000);
	}

	printf("Duck season!\n");
	return NULL;
}

int main(int argc, char **argv)
{
	i = 0;
	
	pthread_t rabbit_thread, duck_thread;

	pthread_create(&rabbit_thread, NULL, rabbit_season, NULL);
	pthread_create(&duck_thread, NULL, duck_season, NULL);

	pthread_join(rabbit_thread, NULL);
	pthread_join(duck_thread, NULL);

	exit(0);
}

