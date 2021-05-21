// из стандартного ввода
// ctrl+D
// ft_strchr (const char *s, int c)
//printf("%s\n", ost);
// gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c

#include "get_next_line.h"

char	*delete_ost(char *line)
{
	int		i;
	char	*p;

	i = 0;
	p = ft_strchr(line, '\n');
	if (p == NULL)
		return (line);
	while (line[i] != '\n')
		i++;
	line[i] = '\0';
	return (line);
}

char	*create_ost(char *line)
{
	int		cnt;
	int		i;
	char	*ost;
	char	*p;

	cnt = 0;
	i = 0;
	p = ft_strchr(line, '\n');
	if (p == NULL)
		return (0);
	else
		p++;
	while (p[i] != '\0')
	{
		cnt++;
		i++;
	}
	i = 0;
	ost = malloc (cnt + 1);
	while (*p != '\0')
	{
		ost[i] = *p;
		i++;
		p++;
	}
	ost[i] = '\0';
	return (ost);
}

int	get_next_line(int fd, char **line)
{
	char			*buf;
	int				byte;
	char			*point;
	char static		*ost;

	byte = 0;
	point = NULL;
	if (fd < 0 || fd > 19)
		return (0);
	*line = ft_calloc(1, 1);
	buf = malloc(BUFFER_SIZE + 1);
	byte = read(fd, buf, BUFFER_SIZE);
	while (byte != 0)
	{
		buf[byte] = '\0';
		point = ft_strchr(buf, '\n');
		if (point != NULL)
			*point = '\0';
		*line = ft_strjoin(*line, buf);
		byte = read(fd, buf, BUFFER_SIZE);
	}
	if (ost != NULL)
		*line = ft_strjoin(ost, *line);
	ost = create_ost(*line);
	*line = delete_ost(*line);
	return (1);
}
