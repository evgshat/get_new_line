#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	char	*new_str;

	i = 0;
	while (str[i] != '\0')
		i++;
	new_str = malloc(i + 1);
	if (new_str == 0)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
