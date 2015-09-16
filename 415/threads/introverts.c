#include <stdio.h> // provides printf, which is thread-safe
#include <pthread.h> // provides pthread_t type, thread functions

static void *recharge(void *args) {
	printf("I recharge by spending time alone.\n"); // printf is thread-safe
	return NULL;
}

static const size_t kNumIntroverts = 6;

int main(int argc, char *argv[]) {
	printf("Let's hear from %zu introverts.\n", kNumIntroverts);
	pthread_t introverts[kNumIntroverts];
	
	for (size_t i = 0; i < kNumIntroverts; i++)
		pthread_create(&introverts[i], NULL, recharge, NULL);

	for (size_t i = 0; i < kNumIntroverts; i++)
		pthread_join(introverts[i], NULL);
	
	printf("Everyone's recharged!\n");
	return 0;
}
