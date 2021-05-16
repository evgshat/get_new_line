#include "libft.h"

char	*ft_strchr (const char *s, int c)
{
	char	*new_s;
	char	ch;

	new_s = (char *)s;
	ch = (char)c;
	if (ch == '\0')
	{
		while (*new_s)
			new_s++;
		return (new_s);
	}
	while (*new_s)
	{
		if (*new_s == ch)
			return (new_s);
		new_s++;
	}
	return (NULL);
}
