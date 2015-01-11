#include <project.h>

static void simple_string(t_test *test)
{
	char *line;
	int		out;
	int		p[2];
	int		fd;
	int		gnl_ret;

	fd = 1;
	out = dup(fd);
	pipe(p);
	dup2(p[1], fd);
	write(fd, "aaa", 3);
	close(p[1]);
	dup2(out, fd);
	gnl_ret = get_next_line(p[0], &line);
	mt_assert(strcmp(line, "aaa") == 0);
	mt_assert(gnl_ret == 0 || gnl_ret == 1);
}

void	suite_02_test_eof_with_close(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_string);
}
