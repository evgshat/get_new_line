#ifndef GET_NEW_LINE_H
# define GET_NEW_LINE_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

int			get_next_line(int fd, char **line);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strchr (const char *s, int c);

#endif
