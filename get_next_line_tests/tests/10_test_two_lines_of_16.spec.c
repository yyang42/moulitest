#include <project.h>

UT_TEST(10_test_two_lines_of_16)
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
	write(fd, "abcdefghijklmnop\n", 17);
	write(fd, "qrstuvwxyzabcdef\n", 17);
	close(p[1]);
	dup2(out, fd);
	get_next_line(p[0], &line);
	UT_ASSERT(strequ(line, "abcdefghijklmnop"));
	get_next_line(p[0], &line);
	UT_ASSERT(strequ(line, "qrstuvwxyzabcdef"));
	ret = get_next_line(p[0], &line);
	UT_ASSERT(ret == 0);
}
