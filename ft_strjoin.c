#include "libft.h"

static int	f_cnt(char const *s1)
{
	size_t	i;

	i = 0;
	while (s1[i] != 0)
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
	cnt_s1 = f_cnt(s1);
	cnt_s2 = f_cnt(s2);
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
