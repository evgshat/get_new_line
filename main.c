#include "get_next_line.h"

 int	main(void)
 {
 	int		fd;
 	char	*line;

 	fd = open("add/text.txt", O_RDONLY);
 	while (get_next_line(fd, &line) != 0)
 		printf("%s\n", line);
 }
