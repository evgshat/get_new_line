// из стандартного ввода
// ctrl+D
// ft_strchr (const char *s, int c)
//printf("%s\n", ost);

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char			*buf;
	int				byte;
	char			*point;
	int				flag;

	byte = 0;
	flag = 0;
	while (flag == 0)
	{
		buf = malloc(BUFFER_SIZE + 1);
		byte = read(fd, buf, BUFFER_SIZE);
		point = ft_strchr(buf, '\n');
		if (point != NULL)
			flag = 1;
		*line = ft_strjoin(*line, buf);
	}
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
