// из стандартного ввода
// ctrl+D

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char		*buf;
	int			byte_was_read;
	int			cnt;
	static char	*tmp;
	int			size_buf;

	size_buf = 60;
	buf = malloc(size_buf);
	*buf = '\0';
	buf++;
	byte_was_read = read(fd, buf, size_buf);
	if (byte_was_read == 0)
		return (0);
	else
		*line = buf;
	return (1);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n", line);
}
