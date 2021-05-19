#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char			*buf;
	int				byte;
	char			*point;

	buf = malloc(BUFFER_SIZE + 1);
	byte = read(fd, buf, BUFFER_SIZE);
	*line = buf;
	// *line = ft_strjoin(*line, buf);
	return (byte);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
}
