#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <linux/ipc.h>
#include <linux/msg.h>

#define MESSAGE_BUFFER_SIZE 1000

int open_queue(key_t keyval)
{
	int qid;

	if ((qid = msgget( keyval, IPC_CREAT | IPC_EXCL )) == -1)
	{
		return -1;
	}

	return qid;
}

int main(int argc, char **argv)
{
	int qid;
	key_t msgkey;

	// Generate our IPC key value
	msgkey = ftok(".", 'm');

	// Open/create the queue
	if ((qid = open_queue(msgkey)) == -1) {
		fprintf(stderr, "Queue already open with key %d\n", msgkey);
		exit(1);
	}

	pid_t pid = fork();
	if (pid == 0) {
		char message[MESSAGE_BUFFER_SIZE];
		sprintf(message, "%s", "Hello from the child process!\n");
		if ((msgsnd(qid, message, MESSAGE_BUFFER_SIZE, 0)) == -1) {
			fprintf(stderr, "Unable to send message.\n");
			exit(1);
		}

		exit(0);
		
	} else {
		char message[MESSAGE_BUFFER_SIZE];
		if ((msgrcv(qid, message, MESSAGE_BUFFER_SIZE, 0, 0)) == -1) {
			fprintf(stderr, "Unable to receive message.\n");
			exit(1);
		}

		printf("%s", message);
	}

	exit(0);
}

