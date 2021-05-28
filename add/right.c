// из стандартного ввода
// ctrl+D
// ft_strchr (const char *s, int c)
// printf("%s\n", ost);
// gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 *.c
// gcc -D BUFFER_SIZE=32 *.c
// gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 right.c get_next_line_utils.c
// gcc -D BUFFER_SIZE=1 right.c get_next_line_utils.c
// gcc -g -D BUFFER_SIZE=32 right.c get_next_line_utils.c
#include "get_next_line.h"

static char	*check_ost(char **ost, char *line)
{
	char	*point_n;
	char	*point_zero;
	int		i;
	int		j;

	i = 0;
	point_n = NULL;
	if (*ost)
	{
		point_n = ft_strchr(*ost, '\n');
		if (point_n == NULL)
		{
			point_zero = ft_strchr(*ost, '\0');
			if (point_zero != NULL)
			{
				*ost = NULL;
				return (line);
			}
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
			printf("%s\n", line);
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

int	get_next_line(int fd, char **line)
{
	static char		*ost;
	char			*buf;
	int				byte;
	char			*point;
	int				flag;
	char			*chr_n_line;
	int				cnt;

	*line = "\0";
	chr_n_line = NULL;
	point = NULL;
	flag = 0;
	cnt = 0;
	buf = malloc(BUFFER_SIZE + 1);
	*line = check_ost(&ost, *line);
	printf("%s\n", *line);
		while (flag == 0)
		{
			byte = read(fd, buf, BUFFER_SIZE);
			buf[BUFFER_SIZE] = '\0';
			point = ft_strchr(buf, '\n');
			if (point != NULL)
			{
				*point = '\0';
				point++;
				*line = ft_strjoin(*line, buf);
				cnt = ft_strlen(point);
				ost = malloc(cnt);
				ft_strlcpy(ost, point, ft_strlen(point));
				flag = 1;
			}
			else
			{
				*line = ft_strjoin(*line, buf);
			}
		}
	if (byte == 0 && ost == NULL)
		return (0);
	return (1);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("text2.txt", O_RDONLY);
	// while (get_next_line(fd, &line) != 0)
	// 	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	// get_next_line(fd, &line);
	// printf("%s\n", line);
}
