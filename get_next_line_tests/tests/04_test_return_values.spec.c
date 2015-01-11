#include <project.h>

static void simple_string(t_test *test)
{
	char 	*line;
	int		out;
	int		p[2];
	int		fd;
	int		gnl_ret;

	out = dup(1);
	pipe(p);

	fd = 1;
	dup2(p[1], fd);
	write(fd, "abc\n\n", 5);
	close(p[1]);
	dup2(out, fd);

	/* Read abc and new line */
	gnl_ret = get_next_line(p[0], &line);
	mt_assert(gnl_ret == 1);
	mt_assert(strcmp(line, "abc") == 0);

	/* Read new line */
	gnl_ret = get_next_line(p[0], &line);
	mt_assert(gnl_ret == 1);
	mt_assert(line == NULL || *line == '\0');

	/* Read again, but meet EOF */
	gnl_ret = get_next_line(p[0], &line);
	mt_assert(gnl_ret == 0);
	mt_assert(line == NULL || *line == '\0');

	/* Let's do it once again */
	gnl_ret = get_next_line(p[0], &line);
	mt_assert(gnl_ret == 0);
	mt_assert(line == NULL || *line == '\0');
}

void	suite_04_test_return_values(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_string);
}
