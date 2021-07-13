#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	//fd = 0;
	while (get_next_line(fd, &line) != 0)
		printf("|%s|\n", line);
	printf("|%s|\n", line);
}

// int	get_next_line(int fd, char **line) // рпрошлый прототип