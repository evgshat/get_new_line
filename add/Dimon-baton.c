#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static char	*previous_line;
	char		*eol_position;
	static char	*current_line;
	int			current_line_len;
	char		*buffer;
	int			byte_was_read;
	int			flag = 1;

	if (line == NULL || fd < 0 || fd > 19 || BUFFER_SIZE < 0 || BUFFER_SIZE > 2000)
		return (-1);
	if (current_line)
	{
		free (current_line);
	}
	if (previous_line)
	{
		buffer = ft_strdup(previous_line);
		free (previous_line);
	}
	else
	{
		buffer = (char *) malloc (sizeof(char) * (BUFFER_SIZE + 1));
		if (buffer == 0)
			return (-1);
		byte_was_read = read(fd, buffer, BUFFER_SIZE);
		buffer[byte_was_read] = '\0';
		if (byte_was_read < BUFFER_SIZE)
		{
			flag = 0;
		}
	}
	eol_position = ft_strchr(buffer, '\n');
	while (eol_position == NULL && flag == 1)
	{
		char *temp_buffer;
		char *tmp;
		temp_buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (temp_buffer == 0)
			return (-1);
		byte_was_read = read(fd, temp_buffer, BUFFER_SIZE);
		temp_buffer[byte_was_read] = '\0';
		if (byte_was_read < BUFFER_SIZE)
		{
			flag = 0;
		}

		tmp = buffer;
		buffer = ft_strjoin(tmp, temp_buffer);
		free(tmp);
		free(temp_buffer);

		eol_position = ft_strchr(buffer, '\n');
	}

	if (eol_position == NULL)
	{
		eol_position = buffer + ft_strlen(buffer);
	}

	current_line_len = eol_position - buffer + 1;
	current_line = (char *) malloc (sizeof(char) * current_line_len);
	if (current_line == 0)
		return (-1);
	ft_memcpy(current_line, buffer, current_line_len);
	current_line[current_line_len - 1] = '\0';
	*line = current_line;

	int previous_line_len = ft_strlen(buffer) - current_line_len + 1;
	if (previous_line_len != 0)
	{
		previous_line = (char *) malloc (sizeof(char) * previous_line_len);
		if (previous_line == 0)
			return (-1);
		ft_memcpy(previous_line, eol_position + 1, previous_line_len);
	}
	else
	{
		if (flag == 0)
		{
			free (buffer);
			return (0);
		}
	}
	free (buffer);
	return (1);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("tt.txt", O_RDONLY);
	while (get_next_line(fd, &line) != 0)
		printf("%s\n", line);
	printf("%s\n", line);
}
