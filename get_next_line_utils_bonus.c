#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (s == NULL)
		return (len);
	while (*s != '\0')
	{
		s++;
		len++;
	}
	s -= len;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*res;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
		{
			res = (char *)(s + i);
			return (res);
		}
		i++;
	}
	if (s[i] == (char) c)
	{
		res = (char *)(s + i);
		return (res);
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;

	i = ft_strlen(s1);
	res = malloc((i + ft_strlen(s2) + 1) * sizeof(*res));
	if (res == NULL)
		return (res);
	if (s1 == NULL)
		ft_strlcpy(res, s2, ft_strlen(s2) + 1);
	else
	{
		ft_strlcpy(res, s1, i + 1);
		j = 0;
		while (s2[j] != '\0')
		{
			res[i] = s2[j];
			i++;
			j++;
		}
		res[i] = '\0';
		free(s1);
	}
	return (res);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	if (src == NULL)
		return (0);
	i = 0;
	j = 0;
	if (dstsize > 0)
	{
		while (src[i] != '\0' && j < dstsize - 1)
		{
			dst[j] = src[i];
			i++;
			j++;
		}
		dst[j] = '\0';
	}
	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}
