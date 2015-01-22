#include "get_next_line.h"

int				get_next_line(int const fd, char **line)
{
	(void)fd;
	(void)line;
	if (line)
		*line = strdup("");
	return (0);
}
