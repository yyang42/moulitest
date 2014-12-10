#include <project.h>

UT_TEST(12_test_line_of_4)
{
	char 	*line;
	int		out;
	int		p[2];
	int		fd;
	int		ret;

	out = dup(1);
	pipe(p);

	fd = 1;
	dup2(p[1], fd);
	write(fd, "abcd\n", 5);
	close(p[1]);
	dup2(out, fd);
	get_next_line(p[0], &line);
	UT_ASSERT(strequ(line, "abcd"));
	ret = get_next_line(p[0], &line);
	UT_ASSERT(ret == 0);
}
