// в видео, вместо strlcpy исп. strcpy
// в видео исп ф-ия strnew
// проверить на утечки
// в видео исп ф-ия strclr
// видео - 40:28

#include "get_next_line.h"

char	*check_ost(char *ost, char **line)
{
	char		*pointer_n;

	pointer_n = NULL;
	if (ost)
	{
		if ((pointer_n = ft_strchr(ost, '\n')))
		{
			*pointer_n = '\0';
			*line = ft_strdup(ost);
			pointer_n++;
			ft_strlcpy = (ost, pointer_n);
			//ft_strclr(ost);
		}
		else
		{
			*line = ft_strdup(ost);
		}
	}
	else
		*line = "\0";
	return (pointer_n);
}

int	get_next_line(int fd, char **line)
{
	int			byte_was_read;
	char		buf[500 + 1];
	char		*pointer_n;
	static char	*ost;

	check_ost(ost, *line);
	while (pointer_n == 0 && (byte_was_read = read(fd, buf, 500)))
	{
		buf[byte_was_read] = '\0';
		if ((pointer_n = ft_strchr(buf, '\n')))
		{
			*pointer_n = '\0';
			pointer_n++;
			ost = ft_strdup(pointer_n);
		}
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
	get_next_line(fd, &line);
	printf("%s\n", line);
	// get_next_line(fd, &line);
	// printf("%s\n", line);
}
