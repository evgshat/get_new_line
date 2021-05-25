// из стандартного ввода
// ctrl+D
// ft_strchr (const char *s, int c)
//printf("%s\n", ost);
// gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 *.c
// gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 right.c get_next_line_utils.c
// gcc -D BUFFER_SIZE=32 right.c get_next_line_utils.c
#include "get_next_line.h"

char *check_ost(char *ost, char **line)
{
	char *point;

	point = NULL;
	if (ost)
	{
		point = ft_strchr(ost, '\n');
		if (point != NULL)
		{
			*point = '\0';
			*line = ft_strdup(ost);
			point++;
			ft_strlcpy(ost, point, ft_strlen(point) + 1);
		}
		else
		{
			*line = ft_strdup(ost);
			free(ost);
			ost = NULL;
		}
	}
	else
	{
		*line = "\0";
	}
	retur (*line);
}

int	get_next_line(int fd, char **line)
{
	static char		*ost;
	char			*buf;
	int				byte;
	char			*point;
	int				flag;

	flag = 1;
	check_ost(ost, *line);
	buf = malloc(BUFFER_SIZE + 1);
	byte = read(fd, buf, BUFFER_SIZE);
	while (byte != 0 && flag != 0)
	{
		buf[byte] = '\0';
		point = ft_strchr(buf, '\n');
		if (point != NULL)
		{
			*point = '\0';
			flag = 0;
			point++;
			ost = ft_strdup(point);
		}
		*line = ft_strjoin(*line, buf);
		byte = read(fd, buf, BUFFER_SIZE);
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
