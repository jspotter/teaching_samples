#define _POSIX_SOURCE
#define _GNU_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sched.h>
#include <time.h>

static const int NUM_THREADS = 5;
static const int SCHED_TYPE = SCHED_RR;

static int dummy = 0;

static void *runner(void *_unused)
{
	cpu_set_t cpu;
	CPU_ZERO(&cpu);
	CPU_SET(1, &cpu);

	int policy;
	struct sched_param param;
	pthread_getschedparam(pthread_self(), &policy, &param);

	printf("policy: %d\n", policy);
	printf("should be %d\n", SCHED_TYPE);

	sched_setaffinity(0, sizeof(cpu_set_t), &cpu);

	for (int i = 1; i <= 10; i++) {
		printf("%d\n", i);
		for (int j = 0; j < 30000000; j++) {
			dummy += j * j;
		}
	}

	return NULL;
}

static void print_current_policy(pthread_attr_t *attr)
{
	int policy;

	if (pthread_attr_getschedpolicy(attr, &policy) != 0) {
		fprintf(stderr, "Unable to get policy.\n");
	} else {
		if (policy == SCHED_OTHER) {
			printf("SCHED_OTHER: %d\n", policy);
		} else if (policy == SCHED_RR) {
			printf("SCHED_RR: %d\n", policy);
		} else if (policy == SCHED_FIFO) {
			printf("SCHED_FIFO: %d\n", policy);
		}
	}
}

int main(int argc, char **argv)
{
	int i, max_prio, min_prio, mid_prio;
	pthread_t tid[NUM_THREADS];
	pthread_attr_t attr;
	cpu_set_t cpu;
	struct sched_param param;

	pthread_attr_init(&attr);
	
	pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
	pthread_attr_setschedpolicy(&attr, SCHED_TYPE);
	
	max_prio = sched_get_priority_max(SCHED_TYPE);	
  	min_prio = sched_get_priority_min(SCHED_TYPE);	
  	mid_prio = (min_prio + max_prio)/2;	
  	param.sched_priority = mid_prio;

	pthread_attr_setschedparam(&attr, &param);

	/* create threads */
	for (i = 0; i < NUM_THREADS; i++) {
		int retval;
		if ((retval = pthread_create(&tid[i], &attr, runner, NULL)) != 0) {
			fprintf(stderr, "Unable to create thread %d: %d\n", i, retval);
		}
	}

	/* join threads */
	for (i = 0; i < NUM_THREADS; i++) {
		pthread_join(tid[i], NULL);
	}

	exit(0);
}

