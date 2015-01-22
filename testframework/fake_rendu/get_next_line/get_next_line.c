#include "get_next_line.h"
#include <stdlib.h>

static char		*ft_strchr_nl(const char *s)
{
	return (s);
}

static int		ft_read_buffer(int fd, char **s_str, char **line)
{
	int		ret;
	char	*temp;
	char	buf[BUFF_SIZE + 1];

	ret = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(temp = 0))
			return (-1);
		strcpy(temp, *line);
		*line = temp;
		if (ft_strchr_nl(buf))
		{
			strcpy(*s_str, ft_strchr_nl(buf));
			strncat(*line, buf, ft_strchr_nl(buf) - buf);
			strcpy(*s_str, *s_str + 1);
			return (1);
		}
		strcat(*line, buf);
	}
	return (ret < 0 ? -1 : 0);
}

int				do_get_next_line(int const fd, char **line)
{
	static char		*s_str[MAX_PARALLEL_FILES];
	int				ret;

	*line = malloc(BUFF_SIZE + 1);
	if (!s_str[fd])
		s_str[fd] = malloc(BUFF_SIZE + 1);
	if (!*line || !s_str[fd])
		return (-1);
	if (ft_strchr_nl(s_str[fd]))
	{
		strncpy(*line, s_str[fd], ft_strchr_nl(s_str[fd]) - s_str[fd]);
		strcpy(s_str[fd], ft_strchr_nl(s_str[fd]));
		strcpy(s_str[fd], s_str[fd] + 1);
		return (1);
	}
	strcat(*line, s_str[fd]);
	ret = ft_read_buffer(fd, &s_str[fd], line);
	if (ret == 1)
		return (1);
	if (ret == -1)
		return (-1);
	if (ret == 0 && strlen(*line) == 0 && strlen(s_str[fd]) == 0)
		**line = '\0';
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	if (BUFF_SIZE > MAX_BUFF_SIZE
		|| fd < 0
		|| BUFF_SIZE <= 0
		|| !line)
		return (-1);
	return (do_get_next_line(fd, line));
}