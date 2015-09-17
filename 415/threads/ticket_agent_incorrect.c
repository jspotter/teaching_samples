#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

static const unsigned int kBaseIDNumber = 101;
static const unsigned int kNumAgents = 10;
static const unsigned int kNumTickets = 100;
static unsigned int remainingTickets = kNumTickets;

static void ticketAgent(size_t id) {
  while (1) {
    if (remainingTickets == 0) break;
		unsigned int curRemainingTickets = remainingTickets;
		usleep(5000);
		remainingTickets = curRemainingTickets - 1;
    printf("Agent #%zu sold a ticket! (%u  more to be sold).\n", id, remainingTickets);
		usleep(20000);
  }
	printf("Agent #%zu notices all tickets are sold, and goes home!\n", id);
}

static void *ticketAgentFunction(void *data)
{
	ticketAgent((size_t) data);
	return NULL;
}

int main(int argc, const char *argv[]) {
  pthread_t agents[kNumAgents];
  for (size_t i = 0; i < kNumAgents; i++)
		pthread_create(&agents[i], NULL, ticketAgentFunction, (void *) (kBaseIDNumber + i));
  for (size_t i = 0; i < kNumAgents; i++) 
    pthread_join(agents[i], NULL);
  printf("End of business day!\n");
  return 0;
}

