#include <stdio.h>
#include "get_next_line.h"

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

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	fd = open("text3", O_RDONLY);
	while ((i = get_next_line(fd, &line) != 0))
	{
		printf("i = %d |%s|\n", i, line);
		free(line);
	}
	if (line)
	{
		printf("i = %d |%s|\n", i, line);
		free(line);
	}
}
