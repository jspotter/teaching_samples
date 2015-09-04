#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>

#define BUFFER_SIZE 1024

ssize_t write_all(int fd, void *buffer, ssize_t num_bytes)
{
	ssize_t total_bytes_written = 0, bytes_written = 0;

	while (total_bytes_written < num_bytes) {
		bytes_written = write(fd, &buffer[bytes_written], num_bytes - bytes_written);
		if (bytes_written < 0) {
			return bytes_written;
		}

		total_bytes_written += num_bytes;
	}

	return total_bytes_written;
}

int main(int argc, char **argv)
{
	int fd;
	ssize_t bytes_read, bytes_written;
	char buffer[BUFFER_SIZE];

	if (argc < 2) {
		printf("Usage: ./mycat <filename>\n");
		exit(1);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd < 0) {
		printf("Unable to open file %s\n", argv[1]);
		exit(1);
	}

	while (TRUE) {
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0) {
			if (bytes_read < 0) {
				printf("An error occurred while reading the file.\n");
				exit(1);
			}
			break;
		}

		bytes_written = write_all(STDOUT_FILENO, buffer, bytes_read);
		if (bytes_written < 0) {
			printf("An error occurred while printing to stdout.\n");
			exit(1);
		}
	}
}

