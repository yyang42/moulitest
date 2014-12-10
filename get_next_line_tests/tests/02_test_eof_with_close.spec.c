#include <project.h>

UT_TEST(02_test_eof_with_close)
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
	UT_ASSERT(strequ(line, "aaa"));
	UT_ASSERT(gnl_ret == 0 || gnl_ret == 1);
}
