// gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 right.c get_next_line_utils.c
// gcc -g -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c
#include "get_next_line.h"

static char	*check_ost(char **ost, char *line)
{
	char	*point_n;
	int		i;
	int		j;

	i = 0;
	j = 0;
	point_n = NULL;
	if (*ost)
	{
		point_n = ft_strchr(*ost, '\n');
		if (point_n == NULL)
		{
			line = ft_strdup(*ost);
			*ost = NULL;
			return (line);
		}
		else
		{
			while (ost[i][j] != '\n')
				j++;
			line = malloc(i + 1);
			j = 0;
			while (ost[i][j] != '\n')
			{
				line[j] = ost[i][j];
				j++;
			}
			line[j] = '\0';
			*ost = ++point_n;
			return (line);
		}
	}
	else
	{
		line = "\0";
		return (line);
	}
}

int	check_read_on_zero(int fd, char **ost)
{
	int		byte;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	byte = read(fd, buf, BUFFER_SIZE);
	if (byte > 0)
	{
		buf[byte] = '\0';
		if (*ost != NULL)
			*ost = ft_strjoin(*ost, buf);
		else
			*ost = ft_strdup(buf);
		return (1);
	}
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

	*line = "\0";
	flag = 0;
	point = NULL;
	buf = malloc(BUFFER_SIZE + 1);
	*line = check_ost(&ost, *line);
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
			*line = ft_strjoin(*line, buf);
			cnt = ft_strlen(point);
			ost = malloc(cnt);
			if (*point == '\0')
				ost = NULL;
			else
				ft_strlcpy(ost, point, ft_strlen(point));
			flag = 1;
		}
		else
		{
			*line = ft_strjoin(*line, buf);
		}
	}
	byte = check_read_on_zero(fd, &ost);
	if (byte == 0 && ost == NULL)
		return (0);
	return (1);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("text2.txt", O_RDONLY);
// 	while (get_next_line(fd, &line) != 0)
// 	{
// 		printf("%s\n", line);
// 	}
// }

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("text2.txt", O_RDONLY);
// 	get_next_line(fd, &line);
// 	printf("%s\n", line);
// }

// int	main(void)
// {
// 	int		ret;
// 	char	*line;
// 	int		fd;

// 	fd = open("text2.txt", O_RDONLY);
// 	line = 0;
// 	ret = get_next_line(fd, &line);
// 	while (ret > 0)
// 	{
// 		write(1, line, ft_strlen(line));
// 		write(1, "\n", 1);
// 		free(line);
// 		line = 0;
// 		ret = get_next_line(0, &line);
// 	}
// 	if (ret == 0)
// 	{
// 		write(1, line, ft_strlen(line));
// 		write(1, "\n", 1);
// 		free(line);
// 		line = 0;
// 	}
// }

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = 0;
// 	get_next_line(fd, &line);
// 	printf("%s\n", line);
// }