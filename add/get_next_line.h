#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

int			get_next_line(int fd, char **line);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strchr (const char *s, int c);
char		*ft_strdup(const char *str);
char		*ft_strcpy(char *s1, const char *s2);
void		ft_strclr(char *str);
size_t		ft_strlen (const char *str);
void	*ft_calloc(size_t number, size_t size);

#endif
