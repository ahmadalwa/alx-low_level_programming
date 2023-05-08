#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Read text file prinedt to STDOUT.
 * @filename: text file being readed
 * @letters: number of letters to be readed
 * Return: w- actual number of bytes read and print
 *        0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t fd;
	ssize_t wr;
	ssize_t tr;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	tr = read(fd, buf, letters);
	wr = write(STDOUT_FILENO, buf, t);

	free(buf);
	close(fd);
	return (wr);
}

