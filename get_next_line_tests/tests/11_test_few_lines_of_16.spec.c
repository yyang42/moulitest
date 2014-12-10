#include <project.h>

UT_TEST(11_test_few_lines_of_16)
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
	write(fd, "ghijklmnopqrstuv\n", 17);
	write(fd, "wxyzabcdefghijkl\n", 17);
	write(fd, "mnopqrstuvwxyzab\n", 17);
	write(fd, "cdefghijklmnopqr\n", 17);
	write(fd, "stuvwxzabcdefghi\n", 17);
	close(p[1]);
	dup2(out, fd);
	get_next_line(p[0], &line);
	UT_ASSERT(strequ(line, "abcdefghijklmnop"));
	get_next_line(p[0], &line);
	UT_ASSERT(strequ(line, "qrstuvwxyzabcdef"));
	get_next_line(p[0], &line);
	UT_ASSERT(strequ(line, "ghijklmnopqrstuv"));
	get_next_line(p[0], &line);
	UT_ASSERT(strequ(line, "wxyzabcdefghijkl"));
	get_next_line(p[0], &line);
	UT_ASSERT(strequ(line, "mnopqrstuvwxyzab"));
	get_next_line(p[0], &line);
	UT_ASSERT(strequ(line, "cdefghijklmnopqr"));
	get_next_line(p[0], &line);
	UT_ASSERT(strequ(line, "stuvwxzabcdefghi"));
	ret = get_next_line(p[0], &line);
	UT_ASSERT(ret == 0);
}
