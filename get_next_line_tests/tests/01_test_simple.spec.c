#include <project.h>

static void simple_string(t_test *test)
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
	mt_assert(strcmp(line, "aaa") == 0);
	get_next_line(p[0], &line);
	mt_assert(strcmp(line, "bbb") == 0);
	get_next_line(p[0], &line);
	mt_assert(strcmp(line, "ccc") == 0);
	get_next_line(p[0], &line);
	mt_assert(strcmp(line, "ddd") == 0);
	(void)test;
}

void	suite_01_test_simple(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_string);
}
