// gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 right.c get_next_line_utils.c
// gcc -g -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c
#include "get_next_line.h"

static char	*check_ost(char **ost, char *line, int *flag)
{
	char	*point_n;
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	*flag = 0;
	point_n = NULL;
	if (*ost)
	{
		point_n = ft_strchr(*ost, '\n');
		if (point_n == NULL)
		{
			free(line);
			line = ft_strdup(*ost);
			free(ost);
			*ost = NULL;  // это обязательно?
			return (line);
		}
		else
		{
			*point_n = '\0';
			free(line);
			line = ft_strdup(*ost);
			free(*ost);
			*ost = ft_strdup(++point_n);
			*flag = 1;
			return (line);
		}
	}
	else
	return (line);
}

int	check_read_on_zero(int fd, char **ost)
{
	int		byte;
	char	*buf;
	char	*tmp;

	buf = malloc(BUFFER_SIZE + 1);
	byte = read(fd, buf, BUFFER_SIZE);
	if (byte > 0)
	{
		buf[byte] = '\0';
		if (*ost != NULL)
		{
			tmp = *ost;
			*ost = ft_strjoin(*ost, buf);
			free(*ost);
		}
		else
		{
			tmp = *ost;
			*ost = ft_strdup(buf);
			free(tmp);
		}
		free(buf);
		return (1);
	}
	free(buf);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char		*ost;
	char			*buf;
	int				byte;
	char			*point;
	int				flag;
	int				cnt;
	char			*tmp;

	if (line == NULL || fd < 0 || fd > 19 || BUFFER_SIZE < 0)
		return (-1);
	flag = 0;
	point = NULL;
	buf = malloc(BUFFER_SIZE + 1);
	*line = ft_strdup("");
	*line = check_ost(&ost, *line, &flag);
	while (flag == 0)
	{
		byte = read(fd, buf, BUFFER_SIZE);
		if (byte == 0)
			flag = 1;
		buf[byte] = '\0';
		point = ft_strchr(buf, '\n');
		if (point != NULL)
		{
			*point = '\0';
			point++;
			tmp = *line;
			*line = ft_strjoin(*line, buf);
			free(tmp);
			cnt = ft_strlen(point);
			if (*point == '\0')
			{
				free(ost);
				ost = NULL;
			}
			else
				ost = ft_strdup(point);
			free(buf);
			return (1);
		}
		else
		{
			tmp = *line;
			*line = ft_strjoin(*line, buf);
			free(tmp);
		}
	}
	free (buf);
	byte = check_read_on_zero(fd, &ost);
	if (byte == 0 && ost == NULL)
		return (0);
	return (1);
}
