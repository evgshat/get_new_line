#include "libft.h"

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	i;
	size_t	cnt;

	cnt = 0;
	i = 0;
	if (dst == 0 || src == 0)
		return (0);
	while (src[cnt] != '\0')
		cnt++;
	if (dstsize > 0)
	{
		while (i < (dstsize - 1) && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (cnt);
}
