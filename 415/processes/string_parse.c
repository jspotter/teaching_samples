#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define MAX_TOKENS 5

static char buffer[BUFFER_SIZE];

int main(int argc, char **argv)
{

	// This needs to accomodate ONE MORE THAN
	// the maximum number of tokens. The last value
	// in this array must be NULL.
	char *args[MAX_TOKENS + 1];

	printf("Enter a string: ");
	fgets(buffer, BUFFER_SIZE, stdin);

	// Get rid of the trailing newline character.
	char *pos;
	if ((pos = strchr(buffer, '\n')) != NULL) {
		*pos = '\0';
	}

	printf("The original string was: %s\n", buffer);

	// Use strtok_r to break the string into tokens.
	// Note that this destructively modifies the original
	// string! It puts a null character wherever it finds
	// a space.
	char *save_ptr;
	char *next_ptr = strtok_r(buffer, " ", &save_ptr);
	for (int i = 0; i <= MAX_TOKENS; i++) {
		args[i] = next_ptr;
		if (next_ptr == NULL) {
			break;
		}
		next_ptr = strtok_r(NULL, " ", &save_ptr);
	}

	// The last argument has to be NULL. 
	args[MAX_TOKENS] = NULL;

	// Print the tokens!
	for (int i = 0; i <= MAX_TOKENS; i++) {
		if (args[i] == NULL) {
			printf("Token %d: NULL\n", i + 1);
			break;
		}
		printf("Token %d: %s\n", i + 1, args[i]);
	}

	exit(0);
}

