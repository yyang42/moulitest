/* Thank you bwyyoung for pointing out the problem. */
#include <project.h>

UT_TEST(04_test_return_values)
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
	UT_ASSERT(gnl_ret == 1);
	UT_ASSERT(strequ(line, "abc"));

	/* Read new line */
	gnl_ret = get_next_line(p[0], &line);
	UT_ASSERT(gnl_ret == 1);
	UT_ASSERT(line == NULL || *line == '\0');

	/* Read again, but meet EOF */
	gnl_ret = get_next_line(p[0], &line);
	UT_ASSERT(gnl_ret == 0);
	UT_ASSERT(line == NULL || *line == '\0');

	/* Let's do it once again */
	gnl_ret = get_next_line(p[0], &line);
	UT_ASSERT(gnl_ret == 0);
	UT_ASSERT(line == NULL || *line == '\0');
}
