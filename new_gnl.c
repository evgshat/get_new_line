#include "get_next_line.h"

char	*check_ost(char *ost, char **line)
{
	char	*point;

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
			ost = NULL;
		}
	}
	else
		*line = ft_strdup("");
	return (point);
}

char	*get_next_line(int fd)
{
	int		byte_was_read;
	char	*buf;
	char	*point;
	char	*line;
	int		size_of_line;
	char	*ost;

	point = NULL;
	line = ft_strdup("");
	if (fd < 0 && BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *) malloc(sizeof(char) * BUFFER_SIZE + 1);
	byte_was_read = read(fd, buf, BUFFER_SIZE);
	if (byte_was_read == 0)
		return (NULL);
	while (point == NULL && byte_was_read != 0)
	{
		buf[byte_was_read] = '\0';
		point = ft_strchr(buf, '\n');
		if (point != NULL)
		{
			point++;
			*point = '\0';
			ost = ft_strdup(point);
		}
		line = ft_strjoin(line, buf);
		size_of_line = ft_strlen(line);
		line[size_of_line] = '\0';
		if (point != NULL)
			return (line);
		byte_was_read = read(fd, buf, BUFFER_SIZE);
	}
	return (line);
}
