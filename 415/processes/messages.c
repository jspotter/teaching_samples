#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <linux/ipc.h>
#include <linux/msg.h>
#include <errno.h>

#define MESSAGE_BUFFER_SIZE 100
#define MESSAGE_TYPE 1

struct mymsgbuf {
	long mtype;
	int request;
	char content[MESSAGE_BUFFER_SIZE];
};

int open_queue(key_t keyval)
{
	int qid;

	if ((qid = msgget(keyval, IPC_CREAT | 0660)) == -1)
	{
		return -1;
	}

	return qid;
}

int main(int argc, char **argv)
{
	int qid;
	key_t msgkey;
	struct mymsgbuf msg;

	// Generate our IPC key value
	msgkey = ftok(".", 'b');
		
	// Open/create the queue
	if ((qid = open_queue(msgkey)) == -1) {
		fprintf(stderr, "Unable to open queue: %d.\n", errno);
		exit(1);
	}

	pid_t pid = fork();
	if (pid == 0) {
		msg.mtype = MESSAGE_TYPE;
		msg.request = 1;
		sprintf(msg.content, "%s", "Hello from the child process!\n");

		if ((msgsnd(qid, &msg, sizeof(struct mymsgbuf) - sizeof(long), 0)) == -1) {
			fprintf(stderr, "Unable to send message: %d.\n", errno);
			exit(1);
		}

		exit(0);
		
	} else {
		if ((msgrcv(qid, &msg, sizeof(struct mymsgbuf) - sizeof(long), MESSAGE_TYPE, 0)) == -1) {
			fprintf(stderr, "Unable to receive message: %d.\n", errno);
			exit(1);
		}

		printf("%s", msg.content);
	}

	exit(0);
}

