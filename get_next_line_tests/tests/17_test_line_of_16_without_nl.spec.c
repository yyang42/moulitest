#include <project.h>

UT_TEST(17_test_line_of_16_without_nl)
{
	char 	*line;
	int		out;
	int		p[2];
	int		fd;

	out = dup(1);
	pipe(p);

	fd = 1;
	dup2(p[1], fd);
	write(fd, "mnopqrstuvwxyzab", 16);
	close(p[1]);
	dup2(out, fd);
	get_next_line(p[0], &line);
	UT_ASSERT(strequ(line, "mnopqrstuvwxyzab"));
}
