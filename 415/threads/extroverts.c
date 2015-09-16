#include <stdio.h> // provides printf, which is thread-safe
#include <pthread.h> // provides pthread_t type, thread functions

static const char *kExtroverts[] = {
	"Jon", "Pam", "Lauren", "Frank",
	"Julie", "Jack", "Tagalong Introvert"
};

static const size_t kNumExtroverts = sizeof(kExtroverts) / sizeof(kExtroverts[0]) - 1;

static void *recharge(void *args) {
	const char *name = kExtroverts[*(size_t *)args];
	printf("Hey, I'm %s. Empowered to meet you.\n", name);
	return NULL;
}

int main() {
	printf("Let's hear from %zu extroverts.\n", kNumExtroverts);
	pthread_t extroverts[kNumExtroverts];

	// Uh oh! All threads are sharing the same copy of i.
	// This means that i might get incremented multiple
	// times between calls to printf.
	for (size_t i = 0; i < kNumExtroverts; i++)
		pthread_create(&extroverts[i], NULL, recharge, &i);

	for (size_t j = 0; j < kNumExtroverts; j++)
		pthread_join(extroverts[j], NULL);

	printf("Everyone's recharged!\n");
	return 0;
}

