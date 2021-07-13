#include "get_next_line.h"

char *get_next_line(int fd)
{
	int				byte_was_read;
	char			*buf;

	if (fd < 0 || fd > 19 || BUFFER_SIZE <= 0 || BUFFER_SIZE
	> 2000)
		return (-1);
	buf = (char *) malloc(sizeof(char) * BUFFER_SIZE + 1);
	byte_was_read = read(fd, buf, BUFFER_SIZE);
	while (!point && (byte_was_read != 0))
}