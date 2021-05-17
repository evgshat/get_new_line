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

void	ft_strclr(char *str)
{
	str = NULL;
}

char	*ft_strcpy (char *s1, const char *s2)
{
	char	*s;

	*s = *s1;
	while (*s1 != 0 && *s2 != 0)
	{
		s1++;
		s2++;
	}
	return (s1);
}

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

size_t	ft_strlen (const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_s;
	int		i;
	int		j;
	int		cnt_s1;
	int		cnt_s2;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	cnt_s1 = ft_strlen(s1);
	cnt_s2 = ft_strlen(s2);
	new_s = (char *) malloc(cnt_s1 + cnt_s2 + 1);
	if (new_s == NULL)
		return (NULL);
	while (s1[i] != '\0')
		new_s[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		new_s[j++] = s2[i++];
	new_s[j] = '\0';
	return (new_s);
}


