#include <project.h>

UT_TEST(01_test_simple)
{
	char 	*line;
	int		out;
	int		p[2];
	int		fd;

	fd = 1;
	out = dup(fd);
	pipe(p);

	dup2(p[1], fd);
	write(fd, "aaa\nbbb\nccc\nddd\n", 16);
	dup2(out, fd);
	close(p[1]);
	get_next_line(p[0], &line);
	UT_ASSERT(strequ(line, "aaa"));
	get_next_line(p[0], &line);
	UT_ASSERT(strequ(line, "bbb"));
	get_next_line(p[0], &line);
	UT_ASSERT(strequ(line, "ccc"));
	get_next_line(p[0], &line);
	UT_ASSERT(strequ(line, "ddd"));
}
