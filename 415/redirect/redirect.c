#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * Executes the command "grep party < /usr/share/dict/words > out.txt".
 *
 * @author Jim Glenn
 * @version 0.1 9/23/2004
 *
 * Slight modifications made by Jonathan Potter
 * on 11/18/2015.
 *
 * Original source can be found at:
 *
 * http://www.cs.loyola.edu/~jglenn/702/S2005/Examples/dup2.html
 */

int main(int argc, char **argv)
{
  int in, out, saved_in, saved_out;
  char *grep_args[] = {"grep", "party", NULL};

  // open input and output files
	// for output file, use O_TRUNC to rewrite file, O_APPEND to append to it
  in = open("/usr/share/dict/words", O_RDONLY);
  out = open("out.txt", O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);

  // replace standard input with input file
	saved_in = dup(STDIN_FILENO);
  dup2(in, STDIN_FILENO);

  // replace standard output with output file
	saved_out = dup(STDOUT_FILENO);
  dup2(out, STDOUT_FILENO);

  // close unused file descriptors

  close(in);
  close(out);

	printf("This should get printed to the file!\n");
	fflush(stdout);

  // execute grep
	if (fork() == 0)
  	execvp("grep", grep_args);
	else {
		dup2(saved_in, STDIN_FILENO);
		dup2(saved_out, STDOUT_FILENO);
		close(saved_in);
		close(saved_out);

		printf("This should get printed to the console!\n");
	}
}

