#include "get_next_line.h"

static char	*ft_create_last(char *text, char **line, char *buf)
{
	char	*pos;

	free(buf);
	pos = ft_strchr(text, '\0');
	*line = malloc((pos - text + 1) * sizeof(**line));
	if (*line == NULL)
	{
		free(text);
		return (NULL);
	}
	ft_strlcpy(*line, text, pos - text + 1);
	free(text);
	return (NULL);
}

static int	ft_create_line(char *text, char **line, char *buf)
{
	char	*pos;
	int		i;

	free(buf);
	pos = ft_strchr(text, '\n');
	if (pos != NULL)
	{
		*line = malloc((pos - text + 1) * sizeof(**line));
		if (*line == NULL)
		{
			free(text);
			return (-1);
		}
		ft_strlcpy(*line, text, pos - text + 1);
		i = 0;
		while (pos[i + 1] != '\0')
		{
			text[i] = pos[i + 1];
			i++;
		}
		text[i] = '\0';
	}
	return (1);
}

static int	ft_rd_zero(char **text, char **line, char *buf)
{
	*text = ft_create_last(*text, line, buf);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	int			rd;
	static char	*text;
	char		*buf;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	buf = malloc(sizeof(*buf) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (-1);
	rd = 1;
	while (rd > 0 && ft_strchr(text, '\n') == NULL)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd < 0)
		{
			free(buf);
			return (-1);
		}
		buf[rd] = '\0';
		text = ft_strjoin(text, buf);
	}
	if (rd == 0)
		return (ft_rd_zero(&text, line, buf));
	ft_create_line(text, line, buf);
	return (1);
}
