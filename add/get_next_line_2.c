// в видео, вместо strlcpy исп. strcpy
// в видео исп ф-ия strnew
// проверить на утечки
// в видео исп ф-ия strclr
// проверить на -1

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
			ft_strcpy(ost, ++pointer_n);
		}
		else
		{
			*line = ft_strdup(ost);
			ft_strclr(ost);
		}
	}
	else
		*line = "\0";
	return (pointer_n);
}

int	get_next_line(int fd, char **line)
{
	int			byte_was_read;
	char		buf[10000000 + 1];
	char		*pointer_n;
	static char	*ost;
	char		*tmp;

	pointer_n = check_ost(ost, line);
	while (pointer_n == 0 && (byte_was_read = read(fd, buf, 10000000)))
	{
		buf[byte_was_read] = '\0';
		if ((pointer_n = ft_strchr(buf, '\n')))
		{
			*pointer_n = '\0';
			pointer_n++;
			ost = ft_strdup(pointer_n);
		}
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		//free(tmp);
	}
	if (byte_was_read != '\0' || ft_strlen(ost) != 0 || ft_strlen(*line) != 0)
		return (1);
	else
		return (0);
}

int	main(void)
{
	char	*line;
	int		fd;

	fd = open ("text.txt", O_RDONLY);
	while (get_next_line(fd, &line))
		printf("%s\n\n", line);
}
