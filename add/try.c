// из стандартного ввода
// ctrl+D
// ft_strchr (const char *s, int c)
//printf("%s\n", ost);

#include "get_next_line.h"

char	*delete_ost(char *line)
{
	int	i;

	i = 0;
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

	cnt = 0;
	i = 0;
	while (*line != '\n')
		line++;
	line++;
	while (line[i] != '\0')
	{
		cnt++;
		i++;
	}
	i = 0;
	ost = malloc (cnt + 1);
	while (*line != '\0')
	{
		ost[i] = *line;
		i++;
		line++;
	}
	return (ost);
}

int	get_next_line(int fd, char **line)
{
	char			*buf;
	int				byte;
	char			*point;
	int				flag;
	char static		*ost;

	byte = 0;
	flag = 0;
	*line = ft_calloc(1, 1);
	while (flag == 0)
	{
		buf = malloc(BUFFER_SIZE + 1);
		byte = read(fd, buf, BUFFER_SIZE);
		buf[byte] = '\0';
		point = ft_strchr(buf, '\n');
		if (point != NULL)
			flag = 1;
		*line = ft_strjoin(*line, buf);
	}
	if (ost != NULL)
		*line = ft_strjoin(ost, *line);
	ost = create_ost(*line);
	*line = delete_ost(*line);
	if (byte == 0 || ost == 0)
		return (0);
	else
		return (1);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	while (get_next_line(fd, &line) != 0)
		printf("%s\n", line);
}
