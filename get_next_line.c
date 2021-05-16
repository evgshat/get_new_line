#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	int		byte_was_read;
	char	buf[5];

	*line = "\0";
	while ((byte_was_read = read(fd, buf, 5)))
	{
		if (ft_strchr(buf, '\n'))
			break ;
		buf[byte_was_read] = '\0';
		*line = ft_strjoin(*line, buf);
	}
	return (0);
}

int	main(void)
{
	char	*line;
	int		fd;

	fd = open ("text.txt", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n", line);
}
