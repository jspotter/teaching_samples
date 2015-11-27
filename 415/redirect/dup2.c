#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char **argv)
{
	int out, saved_out;
  
	// use O_TRUNC to rewrite file, O_APPEND to append to file
	out = open("newout.txt", O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);

  // replace standard output with output file
	saved_out = dup(STDOUT_FILENO);
  dup2(out, STDOUT_FILENO);

  // close unused file descriptors
  close(out);

	printf("This should get printed to the file!\n");
	fflush(stdout);

	// restore old standard output
	dup2(saved_out, STDOUT_FILENO);
	close(saved_out);

	printf("This should get printed to the console!\n");
	
	return 0;
}

