#include <project.h>

UT_TEST(14_test_few_lines_of_4)
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
	write(fd, "efgh\n", 5);
	write(fd, "ijkl\n", 5);
	write(fd, "mnop\n", 5);
	write(fd, "qrst\n", 5);
	write(fd, "uvwx\n", 5);
	write(fd, "yzab\n", 5);
	close(p[1]);
	dup2(out, fd);
	get_next_line(p[0], &line);
	UT_ASSERT(strequ(line, "abcd"));
	get_next_line(p[0], &line);
	UT_ASSERT(strequ(line, "efgh"));
	get_next_line(p[0], &line);
	UT_ASSERT(strequ(line, "ijkl"));
	get_next_line(p[0], &line);
	UT_ASSERT(strequ(line, "mnop"));
	get_next_line(p[0], &line);
	UT_ASSERT(strequ(line, "qrst"));
	get_next_line(p[0], &line);
	UT_ASSERT(strequ(line, "uvwx"));
	get_next_line(p[0], &line);
	UT_ASSERT(strequ(line, "yzab"));
	ret = get_next_line(p[0], &line);
	UT_ASSERT(ret == 0);
}
